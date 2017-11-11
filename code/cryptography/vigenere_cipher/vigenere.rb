#Created by AnkDos

def gen_key(text,key)
    text=text.upcase.delete(' ').split("")
    key=key.upcase.split("").compact
        gen_ki=[]
        i=0;j=0
        while i<text.length
            if j==key.length
                    j=0
                end
                gen_ki<<key[j]
                j+=1
              i+=1
            end    
     gen_ki
end

def cipher(text,key)
     gen_ki=gen_key(text,key)
     text=text.upcase.delete(' ').split("")
    
     alphabets=["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
      encrpted_key=[]
       i=0
       while i<text.length
          encrpted_key<<alphabets[(alphabets.index(text[i])+alphabets.index(gen_ki[i])).modulo(26)]
          i+=1 
        end
    encrpted_key.join
end


def decipher(enc_text,key)
    gen_ki=gen_key(enc_text,key)
    enc_text=enc_text.upcase.delete(' ').split("")
   
    alphabets=["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
     decrypted_key=[]
      i=0
      while i<enc_text.length
        decrypted_key<<alphabets[(alphabets.index(enc_text[i])-alphabets.index(gen_ki[i])+26).modulo(26)]
         i+=1 
       end
   decrypted_key.join
end

#test
puts  "#{cipher("HELLO wORLD","ANKUR")}"    #This will produce =>HRVFFWBBFU
puts "#{decipher("HRVFFWBBFU","ANKUR")}"    #This will produce =>HELLOWORLD
