class CoprimeNumbers{
	public static long gcd(long c,long d){
		if(d==0){
			return c;
		}else{
			return gcd(d,c%d);
		}
	}
	public static boolean isCoprime(long a,long b){
		return gcd(a,b)==1;
	}
	public static void main(String[] args){
		System.out.println(isCoprime(6,3));
	}
}