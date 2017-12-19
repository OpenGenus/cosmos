#include <stdio.h>

int 
main()
{
	printf("Enter Number of Denominations \n");
	int n, i;
	scanf("%d", &n);
	int denominations[n], frequency[n];
	for(i = 0; i < n; i++)
		frequency[i] = 0;
	printf("Enter Denominations in descending order \n");	
	for(i = 0; i < n; i++)
		scanf("%d", &denominations[i]);
	printf("Enter Bill \n");
	int bill;
	scanf("%d", &bill);
	i = 0;
	while (bill > 0 && i < n) {
		frequency[i] = bill / denominations[i];
		bill = bill - (frequency[i] * denominations[i]);
		i++;
	}
	if (bill == 0 )
		for(i = 0; i < n; i++)
			printf("%d * %d \n", denominations[i], frequency[i]);
	else
		printf("Bill cannot be paid \n");
	
	return (0);
}