import java.util.Scanner;
import java.awt.Point;

public class playfair_cipher{
  private int length = 0, dim = 5;
  private String [][] matrixx;
  
  private playfair_cipher()
  {
    System.out.print("Enter the Key: ");
    Scanner input = new Scanner(System.in);
    String key = arranging(input);
    while(key.equals(""))
      key = arranging(input);
    
    matrixx = this.matrix(key);
    
    System.out.print("Enter the Plaintext: ");
    String plaintext = arranging(input);
    while(plaintext.equals(""))
      plaintext = arranging(input);
    
    String encryptedtext = encrypt(plaintext); //Encryption
    String decryptedtext = decrypt(encryptedtext); //Decryption

    //Displaying Results
    System.out.println("\n\nThe Encrypted text(Cipher Text) is: " + encryptedtext);
    System.out.println("The Decrypted text is: " + decryptedtext);
  }
  
  private String arranging(Scanner s){
    String arrange = s.nextLine();
    arrange = arrange.toUpperCase();
    arrange = arrange.replaceAll("[^A-Z]", "");
    arrange = arrange.replace("J", "I");
    return arrange;
  }
  
  private String[][] matrix(String key){
    String matrix_array[][] = new String[dim][dim];
    String keyText = key + "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    
    for(int i = 0; i < dim; ++i)
      for(int j = 0; j < dim; ++j)
        matrix_array[i][j] = "";
    
    for(int k = 0; k < keyText.length(); ++k)
    {
      boolean repeat = false;
      boolean used = false;
      for(int i = 0; i < dim; ++i)
      {
        for(int j = 0; j < dim; ++j)
        {
          if(matrix_array[i][j].equals("" + keyText.charAt(k)))
          {
            repeat = true;
          }
          else if(matrix_array[i][j].equals("") && !repeat && !used)
          {
            matrix_array[i][j] = "" + keyText.charAt(k);
            used = true;
          }
        }
      }
    }
    return matrix_array;
  }
  
  private String encrypt(String text)
  {
    length = (int) text.length() / 2 + text.length() % 2;
    for(int i = 0; i < (length - 1); ++i)
    {
      if(text.charAt(2 * i) == text.charAt(2 * i + 1))
      {
        text = new StringBuffer(text).insert(2 * i + 1, 'X').toString();
        length = (int) text.length() / 2 + text.length() % 2;
      }
    }
    
    String[] encMatrix = new String[length];
    for(int j = 0; j < length ; ++j)
    {
      if(j == (length - 1) && text.length() / 2 == (length - 1))
        text = text + "X";
      encMatrix[j] = text.charAt(2 * j) +""+ text.charAt(2 * j + 1);
    }
    
    String temp = "";
    String[] matrixResult = new String[length];
    matrixResult = chooseChar(encMatrix);
    for(int k = 0; k < length; ++k)
      temp = temp + matrixResult[k];
    return temp;
  }
  
  private String[] chooseChar(String text[])
  {
    String[] encryptedText = new String[length];
    for(int i = 0; i < length; ++i){
      char a = text[i].charAt(0);
      char b = text[i].charAt(1);
      int r1 = (int) chooseIndex(a).getX();
      int r2 = (int) chooseIndex(b).getX();
      int c1 = (int) chooseIndex(a).getY();
      int c2 = (int) chooseIndex(b).getY();
      
      if(r1 == r2)
      {
        c1 = (c1 + 1) % dim;
        c2 = (c2 + 1) % dim; 
      }
      else if(c1 == c2)
      {
        r1 = (r1 + 1) % dim;
        r2 = (r2 + 1) % dim;
      }
      else
      {
        int temp = c1;
        c1 = c2;
        c2 = temp;
      }
      encryptedText[i] = matrixx[r1][c1] + "" + matrixx[r2][c2];
    }
    return encryptedText;
  }
  
  private String decrypt(String text)
  {
    String decryptedText = "";
    for(int i = 0; i < text.length() / 2; ++i)
    {
      char a = text.charAt(2*i);
      char b = text.charAt(2*i+1);
      int r1 = (int) chooseIndex(a).getX();
      int r2 = (int) chooseIndex(b).getX();
      int c1 = (int) chooseIndex(a).getY();
      int c2 = (int) chooseIndex(b).getY();
      if(r1 == r2)
      {
        c1 = (c1 + 4) % dim;
        c2 = (c2 + 4) % dim;
      }
      else if(c1 == c2)
      {
        r1 = (r1 + 4) % dim;
        r2 = (r2 + 4) % dim;
      }
      else
      {
        int temp = c1;
        c1 = c2;
        c2 = temp;
      }
      decryptedText = decryptedText + matrixx[r1][c1] + matrixx[r2][c2];
    }
    return decryptedText;
  }
  
  private Point chooseIndex(char c)
  {
    Point pt = new Point(0,0);
    for(int i = 0; i < dim; ++i)
      for(int j = 0; j < dim; ++j)
        if(c == matrixx[i][j].charAt(0))
          pt = new Point(i,j);
    return pt;
  }

  public static void main(String args[])
  {
    playfair_cipher pf = new playfair_cipher();
  }
}

/*
Sample Output:

Enter the Key: harry
Enter the Plaintext: my name is ravi


The Encrypted text(Cipher Text) is: SFKBLFMOYRUK
The Decrypted text is: MYNAMEISRAVI
*/
