//implementing quickSort
int partition(int ar[], int p, int r){
	int i = p-1;
	int temp;
	for(int j=p; j<r; j++){
		cmp++;
		if(ar[j] <= ar[r]) { i++; temp = ar[i]; ar[i] = ar[j]; ar[j] = temp; }
	}
	temp = ar[i+1];
	ar[i+1] = ar[r];
	ar[r] = temp;
	return (i+1);
}

void rqSort(int ar[], int p, int r){
	if(p<r)
	{
		int q = rpartition(ar, p, r);
		rqSort(ar, p, q-1);
		rqSort(ar, q+1, r);
	}
}

int rpartition(int ar[], int p, int r){
	srand(time(0));
	int m=p + rand()%(r-p);
	int temp=ar[m];
	ar[m]=ar[r];
	ar[r]=temp;
	return partition(ar, p, r);
}
