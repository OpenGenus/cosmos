import java.util.HashMap;
import java.util.Map;

public class Baconian {

    private Map<String ,String> cipherMap = new HashMap<>();

    public Baconian() {
        cipherMap.put("a", "aaaaa");
        cipherMap.put("b", "aaaab");
        cipherMap.put("c", "aaaba");
        cipherMap.put("d", "aaabb");
        cipherMap.put("e", "aabaa");
        cipherMap.put("f", "aabab");
        cipherMap.put("g", "aabba");
        cipherMap.put("h", "aabbb");
        cipherMap.put("i", "abaaa");
        cipherMap.put("j", "abaab");
        cipherMap.put("k", "ababa");
        cipherMap.put("l", "ababb");
        cipherMap.put("m", "abbaa");
        cipherMap.put("n", "abbab");
        cipherMap.put("o", "abbba");
        cipherMap.put("p", "abbbb");
        cipherMap.put("q", "baaaa");
        cipherMap.put("r", "baaab");
        cipherMap.put("s", "baaba");
        cipherMap.put("t", "baabb");
        cipherMap.put("u", "babaa");
        cipherMap.put("v", "babab");
        cipherMap.put("w", "babba");
        cipherMap.put("x", "babbb");
        cipherMap.put("y", "bbaaa");
        cipherMap.put("z", "bbaab");
    }

    public String encode(String word) {
        String results = "";
        word = word.toLowerCase();
        for (Character letter : word.toCharArray()) {
            results += (this.cipherMap.get(letter.toString()));
        }
        return results;
    }

    public String decode(String word) {
        String results = "";
        word = word.toLowerCase();
        for (int start = 0; start < word.length() / 5; ++start) {
            String code = "";
            int startIndex = start * 5;
            for (int index = startIndex; index < startIndex + 5; ++index) {
                code += word.charAt(index);
            }
            String letter = getKeyFromValue(code);
            results += letter;
        }
        return results;
    }

    public String getKeyFromValue(Object value) {
        for (Object key: this.cipherMap.keySet()) {
            if (this.cipherMap.get(key).equals(value)) {
                return key.toString();
            }
        }
        return null;
    }

    public static void main(String [] args) {
        Baconian bac = new Baconian();
        // => babbaabaaaababaabaaaabbbbaabaaaaabbabaaaaaaaa
        System.out.println(bac.encode("Wikipedia")); 
        // => wikipedia
        System.out.println(bac.decode("babbaabaaaababaabaaaabbbbaabaaaaabbabaaaaaaaa"));
    }
}