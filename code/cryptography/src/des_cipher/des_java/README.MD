# Explanation

- KeyFile = _files:/key.txt_
- MsgFile = _files:/msg.txt_
- CphFile = _files:/cipher.txt_

**1. `desPlaintextBlock()` that takes the plaintext as input and splits it up into 64 bit blocks. If the last block is less than 64 bits, pad it with 0s.**

```
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

        return split(plain_text, block_size);
    }

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

    public String[] split(String src, int len) {
        String[] result = new String[(int) Math.ceil((double) src.length() / (double) len)];

        for (int i = 0; i < result.length; i++)
            result[i] = src.substring(i * len, Math.min(src.length(), (i + 1) * len));

        result[result.length - 1] = padLeftZeros(result[result.length - 1], len);
        return result;
    }

```

**2. `permutation()` that takes a 64-bit block, performs permutation according to the 8 x 8 IP table and returns the permuted block.**

CONSTANTS:

```
// CONSTANTS
// Initial Permutation Table

int[] IP = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30,
            22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35,
            27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
```

METHOD:

```
 /***
     * per-mutate input hexadecimal
     * according to specified sequence
     *
     * @param sequence permutation table
     * @param input
     * @return
    */
    String permutation(int[] sequence, String input) {
        String output = "";
        input = hextoBin(input);
        for (int i = 0; i < sequence.length; i++)
            output += input.charAt(sequence[i] - 1);
        output = binToHex(output);
        return output;
    }

```

USAGE:

```
// Initial permutation
        plainText = permutation(IP, plainText);

```

**3. FinalPermutation that takes a 64-bit block, performs permutation according to the 8 x 8 FP table and returns the permuted block.**

```
    // Inverse Initial Permutation Table
    int[] IP1 = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54,
            22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11,
            51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};



USAGE:

// Final permutation
        plainText = permutation(IP1, plainText);

```
