###!/* Part of Cosmos by OpenGenus Foundation */
###Vigenere cipher implementation in Julia

function encrypt(msg::AbstractString, key::AbstractString)
    msg    = uppercase(join(filter(isalpha, collect(msg))))
    key    = uppercase(join(filter(isalpha, collect(key))))
    msglen = length(msg)
    keylen = length(key)
 
    if keylen < msglen
        key = repeat(key, div(msglen - keylen, keylen) + 2)[1:msglen]
    end
 
    enc = Vector{Char}(msglen)
 
    @inbounds for i in 1:length(msg)
        enc[i] = Char((Int(msg[i]) + Int(key[i]) - 130) % 26 + 65)
    end
 
    return join(enc)
end
 
function decrypt(enc::AbstractString, key::AbstractString)
    enc    = uppercase(join(filter(isalpha, collect(enc))))
    key    = uppercase(join(filter(isalpha, collect(key))))
    msglen = length(enc)
    keylen = length(key)
 
    if keylen < msglen
        key = repeat(key, div(msglen - keylen, keylen) + 2)[1:msglen]
    end
 
    msg = Vector{Char}(msglen)
 
    @inbounds for i in 1:length(enc)
        msg[i] = Char((Int(enc[i]) - Int(key[i]) + 26) % 26 + 65)
    end
 
    return join(msg)
end
 
const messages = ("Attack at dawn.", "Don't attack.", "The war is over.", "Happy new year!")
const key = "LEMON"
 
for msg in messages
    enc = encrypt(msg, key)
    dec = decrypt(enc, key)
    println("Original: $msg\n -> encrypted: $enc\n -> decrypted: $dec")
end
