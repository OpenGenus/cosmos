import java.security.MessageDigest;
import java.util.List;

import com.google.gson.GsonBuilder;

public class UtilityClass {

	public static String getDifficultyString(int difficulty) {
		
		return new String(new char[difficulty]).replace('\0','0');
	}

	public static String getSHA256Hash(String inputString) {
		try {
			MessageDigest message=MessageDigest.getInstance("SHA-256");
			byte[] hash=message.digest(inputString.getBytes("UTF-8"));
			StringBuffer hexString=new StringBuffer();
			for(int i=0;i<hash.length;i++) {
				String hex=Integer.toHexString(0xff&hash[i]);
				if(hex.length()==1) {
					
					hexString.append('0');
				}
				hexString.append(hex);
			}
			
		
		return hexString.toString();
		}
		catch(Exception e) {
			System.out.println("Exception occured");
		}
		return null;
	}
		public static  String getJSONData(List<Block> blockchain) {
			return new GsonBuilder().setPrettyPrinting().create().toJson(blockchain);
		}
		
	}