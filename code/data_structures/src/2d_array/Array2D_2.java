class Array2D_2{
     public static void main (String[] args) {
         int[][] a={{1,2,3,3},{4,5},{7,8,9}};
         System.out.println(a); //[[I..
         System.out.println(a[0]); // [I..
         System.out.println(a[0][0]); //1
         System.out.println(a.length); //3
         System.out.println(a[0].length); //4
         System.out.println(a[0][0].length); // Error
    }
}