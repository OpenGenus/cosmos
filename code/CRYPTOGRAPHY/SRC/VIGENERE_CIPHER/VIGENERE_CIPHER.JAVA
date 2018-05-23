/**
 * Modified code from: https://rosettacode.org/wiki/Vigen%C3%A8re_cipher#Java
 * Part of Cosmos by Open Genus Foundation
 */

import java.util.Scanner;

public class vigenere_cipher{
    public static void main(String[] args) {
        System.out.println("Enter key: ");
        Scanner scanner = new Scanner(System.in);
        String key = scanner.nextLine();
        
        System.out.println("Enter text to encrypt: ");
        String text = scanner.nextLine();

        String enc = encrypt(text, key);
        System.out.println(enc);
        System.out.println(decrypt(enc, key));
    }
 
    static String encrypt(String text, final String key) {
        String res = "";
        for (int i = 0, j = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (Character.isUpperCase(c)){
              res += (char)((c + key.charAt(j) - 2 * 'A') % 26 + 'A');
              j = ++j % key.length();
            }
            if (Character.isLowerCase(c)){
              res += (char)((c + Character.toLowerCase(key.charAt(j)) - 2 * 'a') % 26 + 'a');
              j = ++j % key.length();
            }
        }
        return res;
    }
 
      static String decrypt(String text, final String key) {
          String res = "";
          for (int i = 0, j = 0; i < text.length(); i++) {
              char c = text.charAt(i);
              if (Character.isUpperCase(c)) {
                res += (char)((c - key.charAt(j) + 26) % 26 + 'A');
                j = ++j % key.length();
              }
              if (Character.isLowerCase(c)) {
                res += (char)((c - Character.toLowerCase(key.charAt(j)) + 26) % 26 + 'a');
                j = ++j % key.length();
              }
          }
          return res;
      }
}