#!/usr/bin/python

import socket
import os
import sys
import struct
import binascii
import textwrap
import time


def wireshark_open(filename):

    """
    Global Header
    
    typedef struct pcap_hdr_s {
        guint32 magic_number;   /* magic number */ (4 bytes) I
        guint16 version_major;  /* major version number */ (2 bytes) H
        guint16 version_minor;  /* minor version number */ (2 bytes) H
        gint32  thiszone;       /* GMT to local correction */ (4 bytes)
        guint32 sigfigs;        /* accuracy of timestamps */ (4 bytes) I
        guint32 snaplen;        /* max length of captured packets, in octets */ (4 bytes) I
        guint32 network;        /* data link type */ (4 bytes) I
    } pcap_hdr_t;
    """
    name = filename
    n, ext = name.split(".")
    if ext != "pcap":
        return

    wshark_file = open(filename, "wb")
    wshark_file.write(struct.pack("@IHHIIII", 0xA1B2C3D4, 2, 3, 0, 0, 65535, 1))

    return wshark_file


def wireshark_write(file_object, data):

    """ 
    Record (Packet) Header
    
    typedef struct pcaprec_hdr_s {
        guint32 ts_sec;         /* timestamp seconds */ (4 bytes)
        guint32 ts_usec;        /* timestamp microseconds */ (4 bytes)
        guint32 incl_len;       /* number of octets of packet saved in file */ (4 bytes)
        guint32 orig_len;       /* actual length of packet */ (4 bytes)
    } pcaprec_hdr_t;
    """

    ts_sec, ts_usec = str(time.time()).split(".")
    ts_sec = int(ts_sec)
    ts_usec = int(ts_usec)
    incl_len = len(data)
    file_object.write(struct.pack("@ I I I I", ts_sec, ts_usec, incl_len, incl_len))
    file_object.write(data)


def wireshark_close(file_object):

    file_object.close()


def met_http_header(recv, tam):

    print("\t\t\tHTTP Header:")

    try:
        http_dado = recv.decode("utf-8")

    except:
        http_dado = recv

    i = http_dado.split("\n")
    s = "\n".join("\t\t\t\t\t" + lin for lin in textwrap.wrap(http_dado, 90))
    print("\t\t\t\tHTTP Data:\n%s" % s)

    return http_dado


def met_tcp_header(recv, tam):

    """
    0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |          Source Port          |       Destination Port        |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |                        Sequence Number                        |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |                    Acknowledgment Number                      |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |  Data |           |U|A|P|R|S|F|                               |
    | Offset| Reserved  |R|C|S|S|Y|I|            Window             |
    |       |           |G|K|H|T|N|N|                               |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |           Checksum            |         Urgent Pointer        |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |                    Options                    |    Padding    |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |                             data                              |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    """
    tcp_header = struct.unpack("!2H2I4H", recv[:20])
    source_port = tcp_header[0]
    destination_port = tcp_header[1]
    sequence_number = tcp_header[2]
    acknowledgment_number = tcp_header[3]
    """ Data Offset: This indicates where
            the data begins.  The TCP header (even one including options) is an
            integral number of 32 bits long. """
    data_offset = tcp_header[4] >> 12
    reserved = (tcp_header[4] >> 6) & 0x03FF
    flag = tcp_header[4] & 0x003F
    urgent_pointer = flag & 0x0020
    acknowledgment = flag & 0x0010
    push = flag & 0x0000
    reset = flag & 0x0004
    sync = flag & 0x0002
    fin = flag & 0x0001
    window = tcp_header[5]
    check_sum = tcp_header[6]
    urgent_pointer = tcp_header[7]
    dado = recv[data_offset * 4 : tam]
    print("\t\tTCP Header:")

    print(
        "\t\t\tSource Port: %hu, Destination Port: %hu"
        % (source_port, destination_port)
    )
    print(
        "\t\t\tSequence Number: %hu, Acknowlodgment Number: %hu, Data Offset: %hu"
        % (sequence_number, acknowledgment_number, data_offset)
    )
    print("\t\t\tReserved: %hu" % reserved)
    print("\t\t\tFlags:")
    print("\t\t\t\tUrgent Pointer: %hu, Acknowledgment: %hu") % (
        urgent_pointer,
        acknowledgment,
    )
    print("\t\t\t\tPush: %hu, Reset: %hu" % (push, reset))
    print("\t\t\t\tSync: %hu, Fin: %hu" % (sync, fin))
    print("\t\t\tWindow Size: %hu, Check Sum: %hu" % (window, check_sum))

    dado = " ".join("{:02x}".format(ord(i)) for i in dado)
    s = "\n".join("\t\t\t\t" + l for l in textwrap.wrap(dado, 90))

    print("\t\t\tData:\n%s" % s)

    # recv = recv[20:]
    recv = recv[data_offset:]
    return recv, source_port, destination_port


def met_udp_header(recv, tam):

    """
     0      7 8     15 16    23 24    31  
         +--------+--------+--------+--------+ 
         |     Source      |   Destination   | 
         |      Port       |      Port       | 
         +--------+--------+--------+--------+ 
         |                 |                 | 
         |     Length      |    Checksum     | 
         +--------+--------+--------+--------+ 
         |                                     
         |          data octets ...            
         +---------------- ...       
    """
    udp_header = struct.unpack("!4H", recv[:8])
    source_port = udp_header[0]
    destination_port = udp_header[1]
    length = udp_header[2]
    check_sum = udp_header[3]
    print("\t\tUDP Header:")

    print(
        "\t\t\tSource Port: %hu, Destination Port: %hu"
        % (source_port, destination_port)
    )
    print("\t\t\tLength: %hu, Check Sum: %hu" % (length, check_sum))

    recv = recv[8:]

    return recv


def met_ip_header(recv):

    """ 
    0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |Version|  IHL  |Type of Service|          Total Length         |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |         Identification        |Flags|      Fragment Offset    |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |  Time to Live |    Protocol   |         Header Checksum       |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |                       Source Address                          |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |                    Destination Address                        |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |                    Options                    |    Padding    |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    """
    ip_header = struct.unpack("!6H4s4s", recv[:20])
    type_of_service = ip_header[0] & 0x00FF
    version = ip_header[0] >> 12
    """ IHL : Internet header length (32 bits) """
    ihl = (ip_header[0] >> 8) & 0x0F
    total_len = ip_header[1]
    identification = ip_header[2]
    flags = ip_header[3] >> 13

    n = flags >> 1
    m = flags & 0x1

    offset = ip_header[3] & 0x1FFF
    time = ip_header[4] >> 8
    protocolo = ip_header[4] & 0x00FF
    checksum = ip_header[5]
    end_maquina_saida = socket.inet_ntoa(ip_header[6])
    end_maquina_destino = socket.inet_ntoa(ip_header[7])

    if protocolo == 17:
        prox = "UDP"

    elif protocolo == 6:
        prox = "TCP"

    else:
        prox = "nul"

    print("\tIP Header:")

    print("\t\tVersion: %hu, IHL: %hu" % (version, ihl))
    print(
        "\t\tType of Service: %hu, Total Length: %hu, Identification: %hu"
        % (type_of_service, total_len, identification)
    )
    print("\t\tNo Frag: %hu, More Frag: %hu" % (n, m))
    print("\t\tFragment Offset: %hu, Time to Live: %hu" % (offset, time))
    print("\t\tNext Protocol: %hu[%s]" % (protocolo, prox))
    print("\t\tCheck Sum: %hu" % checksum)
    print("\t\tIP Source: %s, IP Dest: %s" % (end_maquina_saida, end_maquina_destino))

    tam = total_len - (ihl * 32) / 8
    recv = recv[(ihl * 32) / 8 :]
    return recv, prox, tam


def met_ethernet_header(recv):

    ip = False
    # The firs parameter is the mac destination (6 octets)
    # When using '(number)s' we have the number of bytes wanted
    et_header = struct.unpack("!6s6sH", recv[:14])
    end_maquina_saida = binascii.hexlify(et_header[1])
    end_maquina_destino = binascii.hexlify(et_header[0])

    protocolo = et_header[2] >> 8
    print("Ethernet Header:")

    print(
        "\tMAC address dest:\t%s:%s:%s:%s:%s:%s"
        % (
            end_maquina_destino[0:2],
            end_maquina_destino[2:4],
            end_maquina_destino[4:6],
            end_maquina_destino[6:8],
            end_maquina_destino[8:10],
            end_maquina_destino[10:12],
        )
    )
    print(
        "\tMAC address de source:\t%s:%s:%s:%s:%s:%s"
        % (
            end_maquina_saida[0:2],
            end_maquina_saida[2:4],
            end_maquina_saida[4:6],
            end_maquina_saida[6:8],
            end_maquina_saida[8:10],
            end_maquina_saida[10:12],
        )
    )
    print("\tProtocolo:\t%s" % hex(protocolo))

    # IPv4 == 0X0800

    if protocolo == 8:
        ip = True

    recv = recv[14:]

    return recv, ip


def main():

    """Convert 16-bit positive integers from host to network byte order. On machines
    where the host byte order is the same as network byte order, this is a no-op; otherwise, 
    it performs a 2-b
    yte swap operation."""
    """socket.PF_PACKET to send and recieve messages, below the internet protocol layer
    The process must be run with root access"""
    """ When using socket.bind(()) we will redirect the access to an especific port
    I am using socket.RAW, so i dont want to bind my connection to a port"""
    sniffer = socket.socket(socket.PF_PACKET, socket.SOCK_RAW, socket.htons(0x3))
    wireshark_file = wireshark_open("aux.pcap")

    while True:
        recv = sniffer.recv(65535)
        wireshark_write(wireshark_file, recv)
        dados_novos, ip = met_ethernet_header(recv)

        if ip:
            dados_novos, prox, tam = met_ip_header(dados_novos)

            if prox == "TCP":
                dados_novos, src, dest = met_tcp_header(dados_novos, tam)

                if src == 80 or dest == 80:
                    dados_novos = met_http_header(dados_novos, tam)

            elif prox == "UDP":
                dados_novos = met_udp_header(dados_novos, tam)

    wireshark_close(wireshark_file)


main()
