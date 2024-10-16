import java.util.*;
import java.util.List;
public class Application {
	static List<Block> blockchain=new ArrayList<Block>();
	final static int difficulty=4;
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Create Genesis Block");
		addBlock(new Block("0","this is first transaction"));
		addBlock(new Block(blockchain.get(blockchain.size()-1).currentHashValue(),"Second Transaction"));

		System.out.println(blockchain.toString());
		System.out.println(UtilityClass.getJSONData(blockchain));
		System.out.println(isChainValid(blockchain));
		
		
	}
	public static void addBlock(Block newBlock) {
		newBlock.mineBlock(difficulty);
		blockchain.add(newBlock);
		System.out.println("Block added to blockchain");
	}
	public static Boolean isChainValid(List<Block> blockchain) {
		Block currentBlock; 
		Block previousBlock;
		
		//loop through blockchain to check hashes:
		for(int i=1; i < blockchain.size(); i++) {
			currentBlock = blockchain.get(i);
			previousBlock = blockchain.get(i-1);
			//compare registered hash and calculated hash:
			if(!currentBlock.currentHashValue().equals(currentBlock.calculateHash()) ){
				System.out.println("Current Hashes not equal");			
				return false;
			}
			//compare previous hash and registered previous hash
			if(!previousBlock.currentHashValue().equals(currentBlock.prevHashValue()) ) {
				System.out.println("Previous Hashes not equal");
				return false;
			}
		}
		return true;


}
}