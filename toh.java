import java.util.*;
class toh{
public static void toh1(int n,String s,String h,String d){
    if(n==0){
        return;
    }
    toh1(n-1,s,d,h);
    System.out.println("move "+n+"th disk from "+s+" to "+d);
    toh1(n-1,h,s,d);

}


public static void main(String[] args){
    Scanner scn=new Scanner(System.in);
    int n=scn.nextInt();
toh1(n,"source","helper","destination");
}
}