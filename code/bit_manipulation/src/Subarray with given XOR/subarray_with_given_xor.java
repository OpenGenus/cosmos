  public class Solution {
    public int solve(ArrayList<Integer> A, int k) {
       int count=0;
       int xr=0; // current xor
       HashMap<Integer,Integer> map=new HashMap<>(); //stores y wrt count
       //y=xr^k
       for(int a:A) {
            xr^=a;
            if(map.containsKey(xr^k)) //y=xr ^ k
                count+=map.get(xr^k);
            if(xr==k) count++;

            map.put(xr,map.getOrDefault(xr,0)+1);

       }
       return count;
    }
}
