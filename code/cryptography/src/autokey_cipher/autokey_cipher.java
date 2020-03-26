import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class autokey
{
    public static String createkey(String plaintext, int keycount, HashMap<Character, Integer> hashmap1, HashMap<Integer, Character> hashmap2)
    {
        char keytextarray[] = plaintext.toLowerCase().toCharArray();
        int temp = keycount % 26;
        
        for(int i = 0; i < plaintext.length(); ++i)
        {
            int a = hashmap1.get(plaintext.charAt(i));
            if(i == 0)
            {
                a = (a + temp) % 26;
            }
            else
            {
                a = (a + hashmap1.get(plaintext.charAt(i - 1))) % 26;
            }
            keytextarray[i] = hashmap2.get(a);
        }
        return new String(keytextarray);
    }
    
    public static String encryption(String plaintext, String keytext, HashMap<Character, Integer> hashmap1, HashMap<Integer, Character> hashmap2)
    {
        char plaintextarray[] = plaintext.toLowerCase().toCharArray();
        for(int i = 0; i < plaintext.length(); ++i)
        {
            int a = hashmap1.get(plaintext.charAt(i));
            int b = hashmap1.get(keytext.charAt(i));
            a = (a + b) % 26;
            plaintextarray[i] = hashmap2.get(a);
        }
        return new String(plaintextarray);
    }
    
    public static String decryption(String encrypted, String keytext, HashMap<Character, Integer> hashmap1, HashMap<Integer, Character> hashmap2)
    {
        char encryptedarray[] = encrypted.toLowerCase().toCharArray();
        for(int i = 0; i < encrypted.length(); ++i)
        {
            int a = hashmap1.get(encrypted.charAt(i));
            int b = hashmap1.get(keytext.charAt(i));
            a -= b;
            if(a < 0)
            {
                int x;
                x = Math.abs(a) % 26;
                a = 26 - x;
            }
            else
            {
                a %= 26;
            }
            encryptedarray[i] = hashmap2.get(a);
        }
        return new String(encryptedarray);
    }
    
    public static void main(String[] args) throws IOException
    {
        int keycount = 0;
        String plaintext = null, keytext = null, encrypted = null, decrypted = null;
        HashMap<Character, Integer> hashmap1 = new HashMap<Character, Integer>();
        HashMap<Integer, Character> hashmap2 = new HashMap<Integer, Character>();
        BufferedReader bufferedreader = new BufferedReader(new InputStreamReader(System.in));
        
        for(int i = 0; i < 26; ++i)
        {
            hashmap1.put((char)(i + 97), i);
            hashmap2.put(i,(char)(i + 97));
        }
        
        System.out.print("Enter the Plain Text : ");
        plaintext = bufferedreader.readLine();
        
        System.out.print("Enter Key: ");
        keycount = Integer.parseInt(bufferedreader.readLine());
        
        System.out.println("Plain Text is: " + plaintext);
        keytext = createkey(plaintext, keycount, hashmap1, hashmap2);
        encrypted = encryption(plaintext, keytext, hashmap1, hashmap2);
        System.out.println("Encrypted Text: " + keytext);
        
        decrypted = decryption(encrypted, keytext, hashmap1, hashmap2);
        System.out.println("Decrypted Text: " + decrypted);
        
        bufferedreader.close();
    }
}

/*
Sample Input:
Enter the Plain Text : hello
Enter Key: 11(L)
Sample Output:
Plain Text is: hello
Encrypted Text : slpwz
Decrypted Text : hello
*/
