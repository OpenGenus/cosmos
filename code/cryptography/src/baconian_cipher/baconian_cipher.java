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
        StringBuilder results = new StringBuilder();
        word = word.toLowerCase();
        for (Character letter : word.toCharArray()) {
            results.append(this.cipherMap.get(letter.toString()));
        }
        return results.toString();
    }

    public String decode(String word) {
        StringBuilder results = new StringBuilder();
        word = word.toLowerCase();
        for (int start = 0; start < word.length() / 5; ++start) {
            StringBuilder code = new StringBuilder();
            int startIndex = start * 5;
            for (int index = startIndex; index < startIndex + 5; ++index) {
                code.append(word.charAt(index));
            }
            String letter = getKeyFromValue(this.cipherMap, code.toString());
            results.append(letter);
        }
        return results.toString();
    }

    public static String getKeyFromValue(Map hashmap, Object value) {
        for (Object key: hashmap.keySet()) {
            if (hashmap.get(key).equals(value)) {
                return key.toString();
            }
        }
        return null;
    }
}