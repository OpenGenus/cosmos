import java.util.Date;

public class Block {


	private String previousHash;
	private String currentHash;
	private String data;
	private Long  timestamp;
	private int nonce=0;
	public Block(String previousHash,String data) {
		this.previousHash=previousHash;
		this.data=data;
		this.timestamp=new Date().getTime();
		this.currentHash=calculateHash();
	}
	public String currentHashValue()
	{
		return currentHash;
	}
	public String prevHashValue()
	{
		return previousHash;
	}
	public String calculateHash() {
		String calculateHash=UtilityClass.getSHA256Hash(
				previousHash+data+Long.toString(timestamp)+
				Integer.toString(nonce)
				);
				return calculateHash;
	}
	public void mineBlock(int difficulty) {
		String target=UtilityClass.getDifficultyString(difficulty);
		while(!currentHash.substring(0,difficulty).equals(target)) {
			nonce=nonce+1;
			currentHash=calculateHash();
		}
		System.out.println("Block is mined "+currentHash);
		
	}


}