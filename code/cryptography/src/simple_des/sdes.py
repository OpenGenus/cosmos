def p_10(k):
    p_list=[2,4,1,6,3,9,0,8,7,5]
    for i in range(len(k)):
        p_list[i]=k[p_list[i]]
    return p_list
def p_8(k):
    p_list=[5,2,6,3,7,4,9,8]
    for i in range(len(p_list)):
        p_list[i]=k[p_list[i]]
    return p_list
def p_4(k):
    permutation_list=[1,3,2,0]
    for i in range(len(permutation_list)):
        permutation_list[i]=k[permutation_list[i]]
    return permutation_list
def left_shift_by_1(k):
    k.append(k[0])
    k.pop(0)
    return k
def left_shift_by_2(k):
    k.append(k[0])
    k.append(k[1])
    k.pop(0)
    k.pop(0)
    return k
def generate_keys(key):
    p_10_list=p_10(key)
    l=p_10_list[:5]
    r=p_10_list[5:]
    l1=left_shift_by_1(l)
    r1=left_shift_by_1(r)
    key1=l1+r1
    key1=p_8(key1)
    l2=left_shift_by_2(l)
    r2=left_shift_by_2(r)
    key2=l2+r2
    key2=p_8(key2)
    print("Key1 Generated : ","".join(key1))
    print("Key2 Generated : ","".join(key2))
    keys=[]
    keys.append(key1)
    keys.append(key2)
    return keys
def i_p(pt):
    p_list=[1,5,2,0,3,7,4,6]
    for i in range(len(p_list)):
        p_list[i]=pt[p_list[i]]
    return p_list
def inverse_i_p(k):
    i_p_list=[3,0,2,4,6,1,7,5]
    for i in range(len(i_p_list)):
        i_p_list[i]=k[i_p_list[i]]
    return i_p_list
def e_p(k):
    e_list=[3,0,1,2,1,2,3,0]
    for i in range(len(e_list)):
        e_list[i]=k[e_list[i]]
    return e_list
def xor(l1,l2):
    xor_list=[]
    for i in range(len(l1)):
        xor_list.append(str(int(l1[i])^int(l2[i])))
    return xor_list
def Part_1(pt):
    return i_p(pt)
def Part_2(pt,key,sbox1,sbox2):
    l=pt[:4]
    r=pt[4:]
    expanded_right_half=e_p(r)
    xor_out=xor(expanded_right_half,key)
    xor_left_half=xor_out[:4]
    xor_right_half=xor_out[4:]
    left_row_value=2*(int(xor_left_half[0]))+int(xor_left_half[3])
    left_column_value=2*(int(xor_left_half[1]))+int(xor_left_half[2])
    right_row_value=2*(int(xor_right_half[0]))+int(xor_right_half[3])
    right_column_value=2*(int(xor_right_half[1]))+int(xor_right_half[2])
    s0b=sbox1[left_row_value][left_column_value]
    s1b=sbox2[right_row_value][right_column_value]
    s0b=bin(s0b).replace("0b","") 
    s1b=bin(s1b).replace("0b","") 
    if(len(s0b)<2):
        s0b="0"+s0b
    if(len(s1b)<2):
        s1b="0"+s1b
    combined_s_value=s0b+s1b
    combined_s_value = p_4(combined_s_value)
    xcs=xor(l,combined_s_value)
    xcs = xcs+r
    return xcs
def encrypt(pt,keys,sbox1,sbox2):
    initial_permutation_list=Part_1(pt)
    xcs_r1 = Part_2(initial_permutation_list ,keys[0],sbox1,sbox2)
    xcs_r2 = Part_2(xcs_r1,keys[1],sbox1,sbox2)
    xcs_r2=xcs_r2[4:]+xcs_r2[:4]    
    inverse_initial_permutation_value=inverse_i_p(xcs_r2)
    encrypted_text=""
    for i in range(len(inverse_initial_permutation_value)):
        encrypted_text=encrypted_text+inverse_initial_permutation_value[i]
    return encrypted_text
def decrypt(dt,keys,sbox1,sbox2):
    initial_permutation_list=Part_1(dt)
    initial_permutation_list = initial_permutation_list[4:]+initial_permutation_list[:4]
    xcs_r1 = Part_2(initial_permutation_list,keys[1],sbox1,sbox2)
    xcs_r2 = Part_2(xcs_r1,keys[0],sbox1,sbox2)
    inverse_initial_permutation_value=inverse_i_p(xcs_r2)
    decrypted_text=""
    for i in range(len(inverse_initial_permutation_value)):
        decrypted_text=decrypted_text+inverse_initial_permutation_value[i]
    return decrypted_text
# key = list(input("Enter the 10-bit Key Value : "))
# pt = list(input("Enter the 8-bit Plain Text : "))
key = list("1010000010")
pt = list("10010101")
sbox1=[[1,0,3,2],
    [3,2,1,0],
    [0,2,1,3],
    [3,1,3,2]]
sbox2=[[0,1,2,3],
    [2,0,1,3],
    [3,0,1,0],
    [2,1,0,3]]
print("Entered Plain text : ","".join(pt))
keys=generate_keys(key)
encrypted_text=encrypt(pt,keys,sbox1,sbox2)
print("After Encryption, Cipher Text : ",encrypted_text)
decrypted_text = decrypt(encrypted_text,keys,sbox1,sbox2)
print("After Decryption, Original Plain Text : ",decrypted_text)
