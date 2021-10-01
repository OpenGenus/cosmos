import base64
s = input("dec or enc?:")

if s == "dec":
    enc = input("input encode strings:")
    print("[+]{}".format(enc))
    print("[+]Decoded! {}".format(base64.b64decode(enc)))

elif s == "enc":
    string = input("input strings:")
    print("[+]{}".format(string))
    print("[+]Encoded! {}".format(base64.b64encode(string.encode('utf-8'))))
else:
    print("What's?")