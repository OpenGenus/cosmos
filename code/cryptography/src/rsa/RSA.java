import java.math.BigInteger;
import java.util.Random;
import java.util.Scanner;
/**
 *
 * @author thompson naidu
 */
 
 
public class RSA {
    private BigInteger p,q,N,phi,e,d;
    private int bitlength=1024;
    private Random rand;
    
   
    public RSA(){
        rand=new Random();
        p=BigInteger.probablePrime(bitlength, rand);
        q=BigInteger.probablePrime(bitlength, rand);
        N=p.multiply(q);
        phi= p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        e=BigInteger.probablePrime(bitlength/2, rand);
        while(phi.gcd(e).compareTo(BigInteger.ONE)>0 && e.compareTo(phi)< 0){
            e.add(BigInteger.ONE);
        }
        d=e.modInverse(phi);
    }
    
    public static String bytesToString(byte[] bytes){
        String text="";
        for(byte b:bytes){
            text+=Byte.toString(b);
        }
        return text;
    }
    
    //encrypt the message
    public  byte[] encrypt(byte[] message){
        return (new BigInteger(message)).modPow(e,N).toByteArray();
    }
    
    //decrypt the message
    public byte[] decrypt(byte[] message){
        return (new BigInteger(message)).modPow(d,N).toByteArray();
    }
    
    public static void main(String[] args) {
        RSA rsa=new RSA();
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the plain text: ");
        String plaintext=sc.nextLine();
        System.out.println("Encryption in progress..");
        System.out.println("String in bytes : "+bytesToString(plaintext.getBytes()));
        
        // encrypt
        byte[] encrypted = rsa.encrypt(plaintext.getBytes());
        // decrypt
        byte[] decrypted = rsa.decrypt(encrypted);
        System.out.println("Decrypting Bytes: " + bytesToString(decrypted));
        System.out.println("Decrypted String: " + new String(decrypted));
    }
}
