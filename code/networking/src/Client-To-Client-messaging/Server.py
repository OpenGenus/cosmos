import socket
import select
import sys
from _thread import *

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

if len(sys.argv) != 3:
	print ("Correct usage: script, IP address, port number")
	exit()
  
IP_address = str(sys.argv[1])

Port = int(sys.argv[2])

print("Server started ...")

server.bind((IP_address, Port))
server.listen(100)

list_of_clients = []
destination_address = 0 #default
msg_buffer = ""

def clientthread(conn, addr):

	pos = len(list_of_clients)
	if(pos-1) == 0:
		print(str(conn.getpeername()) + " connected as A")
		message_first = "You are connected as A"
	elif(pos -1) == 1:
		print(str(conn.getpeername()) + " connected as C")
		message_first = "You are connected as C"
	elif(pos -1) == 2:
		print(str(conn.getpeername()) + " connected as D")
		message_first = "You are connected as D"


	conn.send(message_first.encode())

	while True:
			try:
				message = conn.recv(1030).decode()

				if message:
					destination_addr = message[0]
					msg =message[1:]
					if (msg.lower() == "exit"):
						# shut down the thread in case of exit.
						last_msg = "Closing down"
						conn.send(last_msg.encode())
						conn.close()
						remove(conn)

					else:
						if(msg[:4] == "file:"):
							dest_file = message[0]
							msg_info = msg[5:]
							message_to_send = "<" + str(conn.getpeername()) + "> " + msg_info
							routing(message_to_send, conn,dest_file,addr)


						elif(len(message) != 1 ):
							print ("<" + str(conn.getpeername()) + "> " + msg)
							message_to_send = "<" + str(conn.getpeername()) + "> " + msg
							routing(message_to_send, conn,destination_addr,addr)
						else:
							pass


				else:
					remove(conn)

			except:
				continue
        
def routing(message, conn, destination_addr, addr):
	dest = int(destination_addr)
	connection = list_of_clients[dest]


	for clients in list_of_clients:
		if clients == connection:
			try:
				clients.send(message.encode())
				print("Sent to the client")
			except:
				clients.close()
				remove(clients)

def remove(connection):
	if connection in list_of_clients:
		list_of_clients.remove(connection)

while True:
	conn, addr = server.accept()
	list_of_clients.append(conn)
	start_new_thread(clientthread,(conn,addr))

conn.close()
server.close()
