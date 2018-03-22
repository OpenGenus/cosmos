import socket

def validateIPv6(ip):
    try:
        socket.inet_pton(socket.AF_INET6, ip)
    except socket.error:
        return False
    return True
    
print(validateIPv6("2001:cdba:0000:0000:0000:0000:3257:9652"))   # True
print(validateIPv6("2001:cdbx:0000:0000:0000:0000:3257:9652"))   # False

