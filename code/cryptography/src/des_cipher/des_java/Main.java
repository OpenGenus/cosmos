import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void writeToCipherFile(String file_path, String cipher_text) {
        try {
            FileWriter myWriter = new FileWriter(file_path);
            myWriter.write(cipher_text);
            myWriter.close();
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    /***
     * Parsing the text from the file Converting it to byte arrays Converting it ot 64-bit blocks
     * 
     * @param file_path
     * @param block_size
     * @return
     */
    public String[] desPlaintextBlock(String file_path, int block_size) {

        String plain_text = "";
        try {
            File myObj = new File(file_path);
            Scanner myReader = new Scanner(myObj);

            while (myReader.hasNextLine()) {
                plain_text += myReader.nextLine().toUpperCase();
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }


        byte[] byte_array = plain_text.getBytes();
        plain_text = "";

        for (byte value : byte_array) {
            plain_text += value;
        }

        // System.out.println(plain_text);

        return split(plain_text, block_size);
    }

    /***
     * Converting blocks of decrypted text back into byte array then into String
     * 
     * @param blocks
     * @return String
     */
    public static String blocksToPlainText(String[] blocks) {

        String decrypted_blocks = String.join("", blocks);
        writeToCipherFile("files/cipher.txt", decrypted_blocks);

        String[] decrypted_blocks_array = decrypted_blocks.split("(?<=\\G.{2})");

        byte[] byte_array = new byte[decrypted_blocks_array.length];

        for (int i = 0; i < byte_array.length; i++) {
            byte_array[i] = (byte) Integer.parseInt(decrypted_blocks_array[i]);
        }

        return new String(byte_array);
    }

    /***
     * If a block size is less than 64-bit padding it with zeros
     * 
     * @param inputString
     * @param length
     * @return
     */
    public String padLeftZeros(String inputString, int length) {
        if (inputString.length() >= length) {
            return inputString;
        }
        StringBuilder sb = new StringBuilder();
        while (sb.length() < length - inputString.length()) {
            sb.append('0');
        }
        sb.append(inputString);

        return sb.toString();
    }

    /**
     * Splitting the string into desired blocks
     */
    public String[] split(String src, int len) {
        String[] result = new String[(int) Math.ceil((double) src.length() / (double) len)];

        for (int i = 0; i < result.length; i++)
            result[i] = src.substring(i * len, Math.min(src.length(), (i + 1) * len));

        result[result.length - 1] = padLeftZeros(result[result.length - 1], len);
        return result;
    }

    // Driver code
    public static void main(String args[]) {

        // READING KEY
        String key = "";
        try {
            File myObj = new File("files/key.txt");
            Scanner myReader = new Scanner(myObj);

            while (myReader.hasNextLine()) {
                key += myReader.nextLine().toUpperCase();
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }

        Main driver = new Main();

        // PARSING TEXT
        String[] blocks = driver.desPlaintextBlock("files/msg.txt", 16);
        String[] cipher_blocks = blocks;


        System.out.println("\n== ENCRYPTION ==");
        System.out.println("\n== 64-bit blocks of file ==\n");
        System.out.println(Arrays.toString(blocks));
        System.out.println();

        // ENCRYPTING
        DES cipher = new DES();

        for (int i = 0; i < blocks.length; i++) {
            cipher_blocks[i] = cipher.encrypt(blocks[i], key);
        }

        System.out.println("\n== CIPHERED BLOCKS ==\n");
        System.out.println(Arrays.toString(cipher_blocks));
        System.out.println("\n== DECRYPTION ==");


        // DECRYPTING
        for (int i = 0; i < cipher_blocks.length; i++) {
            blocks[i] = cipher.decrypt(blocks[i], key);
        }

        System.out.println("\n== DECRYPTED BLOCKS ==\n");
        System.out.println(Arrays.toString(blocks));
        System.out.println();

        // BYTE ARR TO STRING
        System.out.println("\n== PLAIN TEXT ==\n");
        System.out.println(blocksToPlainText(blocks));
    }
}
