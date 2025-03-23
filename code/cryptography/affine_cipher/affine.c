//affine.c
/* affine_cipher in c
  * How it works: It uses modular arithmetic to transform the integer that 
  each plain text letter corresponds to into another integer that correspond to a cipher text letter.*/
  
  #include<stdio.h>
  #include<string.h>
  
  const int a=15;
  const int b=17;
  
  
  //Encryption algo
  string encrypt(string msg)
  {
    string cipher='';
    
    for(int i=0;i<strlen(msg);i++)
    {
      if(msg!= NULL)
      {
      cipher= cipher+ (char)((((a*(msg[i]-'A')+b))%26+'A');
      }
      else
        cipher+=msg[i];
        
      }
      return cipher;
   }
   //Decryption algo
   string decrypt (string cipher)
   {
        string msg='';
        int a_inv=0;
        int flag =0;
        
        
        for(int i=0; i<26;i++)
        {
            flag = (a*i)%26;
            
            if(flag==1)
            {
                a_inv=i;
             }
         }
         
         for (int i=0; i<strlen(cipher);i++)
         {
            if(cipher!=NULL)
            {
                msg= msg+ (char) (((a_inv*(cipher[i]+'A')-b)%26)+'A');
             }
             else
                msg+=cipher[i];
          }
            
          return msg;
    }
    
    //main program
    int main (void)
    {
        string msg="Hello world";
        string ciphertext=encrypt(msg);
        //prints out cipher 
        printf("encrypted message is %s", ciphertext);
        //Decrypts cipher to plain text
        printf("Decrypted message is %s", decrypt(ciphertext));
     }
        
   
            
         
         
         
   
  
  
  
