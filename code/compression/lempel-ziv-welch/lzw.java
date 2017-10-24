import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.List;
import java.lang.Character;

class LZW{
    public static ArrayList<Integer> compress(String text){
        Map<String, Integer> dict = new HashMap<String, Integer>();
        int dictSize = 256;
        for (int i=0; i < dictSize; i++){
            dict.put(Character.toString((char)i), i);
        }

        String buffer = "";
        ArrayList<Integer> result = new ArrayList<Integer>();
        for (int i=0; i < text.length(); i++){
            String ch = text.substring(i, i+1);
            String temp = buffer + ch;
            if (dict.containsKey(temp)) {
                buffer = temp;
            } else {
                result.add(dict.get(buffer));
                dict.put(temp, dictSize);
                dictSize++;
                buffer = ch;
            }
        }
        if(buffer != ""){
            result.add(dict.get(buffer));
        }
        return result;
    }

    public static String decompress(List<Integer> text){
        Map<Integer, String> dict = new HashMap<Integer, String>();
        Integer dictSize = 256;
        for (int i=0; i < dictSize; i++){
            dict.put(i, Character.toString((char)i));
        }

       /* int old = text.get(0);
        text.remove(0);
        String result = Character.toString((char)old);
        String S = "", C = "";
        for (Integer ch : text) {
            if(dict.containsKey(ch)){
                S = dict.get(ch);
            }else {
                S = Character.toString((char)old) + C;
            }
            result += S;
            C = S.substring(0,1);
            dict.put(old, C);
            old = ch;
        }*/
        String buffer = Character.toString((char)(int)text.get(0));
        String result = buffer;
        text.remove(0);
        String entry = "";
        for (Integer ch : text) {
            if(dict.containsKey(ch)){
                entry = dict.get(ch);
            }else if ( ch == dictSize){
                entry = buffer.substring(0,1);
            }
            result += entry;
            dict.put(dictSize, entry.substring(0,1));
            dictSize++;
            buffer = entry;
        }

        return result;
    }

    public static void main(String[] args){
        String text = "Hello World!!!";
        ArrayList<Integer> compressed_text = compress(text);
        System.out.println(compressed_text);
        String decompressed_text = decompress(compressed_text);
        System.out.println(decompressed_text);
    }
}