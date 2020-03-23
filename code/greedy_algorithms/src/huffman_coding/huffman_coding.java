import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

public class HuffmanEncoder {
	private class Node implements Comparable<Node> {
		char data;
		int freq;
		Node left;
		Node right;
		
		@Override
		public int compareTo(Node o) {
			// TODO Auto-generated method stub
			return this.freq - o.freq;
		}
	}
	
	private HashMap<Character, String> encMap = new HashMap<>(); // a -> 10
	private HashMap<String, Character> decMap = new HashMap<>(); // 10 -> a

	public HuffmanEncoder(String feeder) {
		// Step 1
		HashMap<Character, Integer> fmap = new HashMap<>();
		for (int i = 0; i < feeder.length(); i++) {
			char ch = feeder.charAt(i);
			fmap.put(ch, fmap.containsKey(ch) ? fmap.get(ch) + 1 : 1);
		}

		// Step 2
		ArrayList<Character> keys = new ArrayList<>(fmap.keySet());
		PriorityQueue<Node> pq = new PriorityQueue<>();
		
		for(Character key: keys){
			Node node = new Node();
			node.data = key;
			node.freq = fmap.get(key);
			pq.add(node);
		}
		
		// Step 3
		while(pq.size() > 1){
			Node one = pq.remove();
			Node two = pq.remove();
			
			Node merged = new Node();
			merged.freq = one.freq + two.freq;
			merged.left = one;
			merged.right = two;
			
			pq.add(merged);
		}
		
		// Step 4
		Node root = pq.remove();
		traverse(root, "");
	}

	private void traverse(Node node, String asf) {
		if(node.left == null && node.right == null){
			encMap.put(node.data, asf);
			decMap.put(asf, node.data);
			return;
		}
		
		traverse(node.left, asf + "0");
		traverse(node.right, asf + "1");
	}

	// abcd - 1111
	public String encode(String str) {
		String codedString = "";
		
		for(int i = 0; i < str.length(); i++){
			char ch = str.charAt(i);
			codedString += encMap.get(ch);
		}
		
		return codedString;
	}

	// 1111 - abcd
	public String decode(String str) {
		String decodedString = "";
		
		String prefix = "";
		for(int i = 0; i < str.length(); i++){
			char ch = str.charAt(i);
			prefix += ch;
			
			if(decMap.containsKey(prefix)){
				decodedString += decMap.get(prefix);
				prefix = "";
			}
		}
		
		return decodedString;
	}
}
