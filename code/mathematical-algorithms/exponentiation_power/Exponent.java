class exponent{

    public static int exponentBySquare(int num, int power){
        if(power==0)
            return 1;

        if(power==1)
            return num;

        int temp=exponentBySquare(num,power/2);
        temp*=temp;

        if(power%2==1){
            temp*=num;
        }

        return temp;
    }
    public static void main(String[] args){
        System.out.println(exponentBySquare(2,9));
    }
}