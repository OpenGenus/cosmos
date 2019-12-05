public class Ascii{
    Ascii()
    {
    }
    //encode method takes a string and returns its ascii for in an array
    public int[] encode(String s)
    {
      int[] temp = new int[s.length()];
      for(int i = 0; i < s.length(); i++) {
    	  temp[i] = (int)s.charAt(i);
      }
      return temp;
    }
    
    //decode method takes an array, decodes it in ascii and returns a string
    public String decode(int[] arr)
    {
      String s = "";
      for(int i : arr) {
    	  s += Character.toString((char)i);
      }
      return s;
    }
    
    public static void main(String[] args)
    {
    	Ascii coder = new Ascii();
    	
    	//encoding simulation
    	String decodedString = "Hello World!";
    	int[] encodedString = coder.encode(decodedString);
    	System.out.print(decodedString + " to Ascii -> ");
        for(int i : encodedString)
        	System.out.print(i+" ");
        System.out.print("\n\n");
        
        //decoding simulation
        int[] encodedArray = {73, 32, 108, 111, 118, 101, 32, 112, 114, 111, 103, 114, 97, 109, 109, 105, 110, 103, 33};
        String decodedString2 = coder.decode(encodedArray);
        System.out.print("Encoded array decoded to string -> ");
        for(int i : encodedArray)
        	 System.out.print(i + " ");
        System.out.print(": " + decodedString2);
    }
}
