public static void sieve(boolean a[],int n){
		a[0]=true;
		a[1]=true;
		for(int i=0;i*i<=n;i++){
			if(!a[i]){
				for(int j=2;i*j<=n;j++){
					a[i*j]=true;
				}
			}
		}
	}
