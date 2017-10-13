from Crypto.Cipher import AES

#make key a global variable which both funcs share

def encode(key,data):#encode with key and data, key is 16 length
	obj = AES.new(key, AES.MODE_CFB, 'This is an IV456')
	ciphertext=obj.encrypt(data)
	return ciphertext#encoded text
	
def decode(key,data):#decode with key and data, key is 16 length
	obj = AES.new(key, AES.MODE_CFB, 'This is an IV456')
	plaintext=obj.decrypt(data)
	return plaintext#with the same key this returns the decoded text
