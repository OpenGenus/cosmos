import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class autokey
{
	public static String createKey(String plainText, int keyCount, HashMap<Character, Integer> hashMap1, HashMap<Integer, Character> hashMap2)
	{
		char keyTextArray[] = plainText.toLowerCase().toCharArray();
		int temp = keyCount % 26;
		
		for(int i = 0; i < plainText.length(); i++)
		{
			int a = hashMap1.get(plainText.charAt(i));
			
			if(i == 0)
			{
				a = (a + temp) % 26;
			}
			else
			{
				a = (a + hashMap1.get(plainText.charAt(i - 1))) % 26;
			}
			keyTextArray[i] = hashMap2.get(a);
		}
		return new String(keyTextArray);
	}
	
	public static String Encryption(String plainText, String keyText, HashMap<Character, Integer> hashMap1, HashMap<Integer, Character> hashMap2)
	{
		char plainTextArray[] = plainText.toLowerCase().toCharArray();
		for(int i = 0; i < plainText.length(); i++)
		{
			int a = hashMap1.get(plainText.charAt(i));
			int b = hashMap1.get(keyText.charAt(i));
			a = (a + b) % 26;
			plainTextArray[i] = hashMap2.get(a);
		}
		return new String(plainTextArray);
	}
	
	public static String Decryption(String encrypted, String keyText, HashMap<Character, Integer> hashMap1, HashMap<Integer, Character> hashMap2)
	{
		char encryptedArray[] = encrypted.toLowerCase().toCharArray();
		for(int i = 0; i < encrypted.length(); i++)
		{
			int a = hashMap1.get(encrypted.charAt(i));
			int b = hashMap1.get(keyText.charAt(i));
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
			encryptedArray[i] = hashMap2.get(a);
		}
		return new String(encryptedArray);
	}
	
	public static void main(String[] args) throws IOException
	{
		int keyCount = 0;
		String plainText = null, keyText = null, encrypted = null, decrypted = null;
		HashMap<Character, Integer> hashMap1 = new HashMap<Character, Integer>();
		HashMap<Integer, Character> hashMap2 = new HashMap<Integer, Character>();
		BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		
		for(int i = 0; i < 26; i++)
		{
			hashMap1.put((char)(i + 97), i);
			hashMap2.put(i,(char)(i + 97));
		}
		
		System.out.print("Enter the Plain Text : ");
		plainText = bufferedReader.readLine();
		
		System.out.println("Enter Key: ");
		keyCount = Integer.parseInt(bufferedReader.readLine());
		
		System.out.println("Plain Text is: " + plainText);
		
		keyText = createKey(plainText, keyCount, hashMap1, hashMap2);
		encrypted = Encryption(plainText, keyText, hashMap1, hashMap2);
		System.out.println("Encrypted Text: " + keyText);
		
		decrypted = Decryption(encrypted, keyText, hashMap1, hashMap2);
		System.out.println("Decrypted Text: " + decrypted);
		
		bufferedReader.close();
	}
}

/*
Sample Input:
Enter the Plain Text : hello
Enter Key: 11(j)

Sample Output:
Plain Text is: hello
Encrypted Text : slpwz
Decrypted Text : hello
*/
