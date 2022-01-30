// Part of Cosmos by OpenGenus Foundation
import java.util.HashMap;
import java.util.Map;

public class MorseCode {
    
    private Map<String, String> engToMorse;
    private Map<String, String> morseToEng;
    private static final String rawMorseCodes = "A:.-|B:-...|C:-.-.|D:-..|E:.|F:..-.|G:--.|H:....|I:..|J:.---|K:-.-|L:.-..|M:--|N:-.|O:---|P:.--.|Q:--.-|R:.-.|S:...|T:-|U:..-|V:...-|W:.--|X:-..-|Y:-.--|Z:--..|1:.----|2:..---|3:...--|4:....-|5:.....|6:-....|7:--...|8:---..|9:----.|0:-----|,:--..--|.:.-.-.-|?:..--..|/:-..-.|-:-....-|(:-.--.|):-.--.-";
    
    public MorseCode() {
        engToMorse = new HashMap<String, String>();
        morseToEng = new HashMap<String, String>();
        String[] morseCodes = rawMorseCodes.split("\\|");
        for (String morseCode: morseCodes) {
            String[] keyValue = morseCode.split(":");
            String english = keyValue[0];
            String morse = keyValue[1];
            engToMorse.put(english, morse);
            morseToEng.put(morse, english);
        }
    }

    public String encrypt(String english) {
        String cipherText = "";
        english = english.toUpperCase();
        for (int i = 0; i < english.length(); i++) {
            if (english.charAt(i) != ' ') {
                cipherText += engToMorse.get(String.valueOf(english.charAt(i)));
                cipherText += ' ';
            }
            else {
                cipherText += ' ';
            }
        }
        return cipherText;
    }

    public String decrypt(String morse) {
        String plainText = "";
        String[] words = morse.split("\\s{2}");
        for (String word : words) {
            String[] letters = word.split("\\s");
            for (String letter : letters) {
                plainText += morseToEng.get(letter);
            }
            plainText += " ";
        }
        return plainText;
    }

    public static void main(String[] args) {
        String msg = "alice killed bob";
        String morseMsg = ".- .-.. .. -.-. .  -.- .. .-.. .-.. . -..  -... --- -...";
        MorseCode mCode = new MorseCode();
        System.out.println(mCode.encrypt(msg));
        System.out.println(mCode.decrypt(morseMsg));
    }
}
