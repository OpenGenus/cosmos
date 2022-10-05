/*
 ------------------------Anonymous Array-----------------------------------

-> An array in java without any name is Anonymous Array.
-> It is an Array just for creating and using it instantly. (Used single time, created in single line)
-> It can be One Dimensional or Multi Dimensional


*/
class Anonymous {
    public static void main (String args[]) 
    {
        
        Anonymous.Sum(new int[]{10,20}); // 1-D
    }

    static void Sum(int[] no){
         
        int total=0;
        for(int i:no){
            total=total+i;
        }
        System.out.println("Sum is: "+total);

    }
}