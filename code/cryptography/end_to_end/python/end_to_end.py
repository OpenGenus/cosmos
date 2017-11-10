import time
a = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
def encrypt(msg):
    off = 3
    enc = ""
    for i in msg:
        enc = enc + (a[(a.index(i)+off)%26])
    return enc
def decrypt(msg):
    off = 3
    dec = ""
    for i in msg:
        dec = dec + (a[(a.index(i)-off)%26])
    return dec

#Client Side(Sender)
msg = input("Enter Message To Send: ")
f = open('server.txt','w+')
print("Encrypting..........")
time.sleep(2)
enc = encrypt(msg)
print("Message Sent Is: ",enc)

#Server Side
f.write(enc)
f.close()

print()
#Client Side(Reciever)
print("Reciever Is Recieving.........")
time.sleep(2)
f = open('server.txt','r+')
msg = f.read()
print("Message Recieved Is: ",msg)
print("Decrypting........")
time.sleep(2)
dec = decrypt(msg)
print("Message Displayed Is: ",dec)

