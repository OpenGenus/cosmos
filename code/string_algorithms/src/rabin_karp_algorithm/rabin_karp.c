/*
 * Part of Cosmos by OpenGenus Foundation
 * Rabin-Karp is a linear time pattern finding
 * algorithm.
 */

#include <stdio.h>
#include <string.h>

#define d 256	/* Base (assuming characters are from ascii set) */

/*
 * Return 1, if strings match else 0
 */
int
is_str_equal(char str1[], char str2[], int txt_shift, int len)
{
	int i;
	for (i = 0; i < len; i++)
		if (str1[i] != str2[txt_shift+i])
			return (0);
	return (1);
}


/*
 * Main search algorithm function
 * Search algorithm taken from CLRS book
 */
void
rabin_karp_search(char pat[], char txt[], int q)
{
	int n = strlen(txt);
	int m = strlen(pat);
	int p = 0;	/* hash value for pattern */
	int t = 0;	/* hash value for text */
	int h = 1;
	int i,s;

	/* Precompute constant h = d^(m-1)(mod q)
	 * do not use ^ for power as without modulo,
	 * number can get really large. Use loop
	 * h is going to be used multiple times, so precompute it.
	 */
	for (i = 0; i < m-1; i++)
		h = (h*d) % q;

	/*
	 * Preprocessing:
	 * Calculate hash(p) of complete search pattern(pat[0...m-1])
	 * Calculate hash(t) of substring text[0...m-1]
	 */
	for (i = 0; i < m; i++) {
		p = (d*p + pat[i]) % q;
		t = (d*t + txt[i]) % q;
	}

	/* Matching */
	for (s = 0; s < n-m; s++) {
		if ((p == t) && (is_str_equal(pat, txt, s, m)))
			printf("String found at location: %d\n", s+1);
		if (s < n-m) {
			t = (d*(t-txt[s]*h) + txt[s+m]) % q;
			/* Take care of -ve mod values (add q) */
			if (t < 0)
				t += q;
		}
	}
}


/*
 * Test Code: Main function to test the algorithm
 */
int
main(void)
{
	char txt[1000], pat[100];
	int txt_len, pat_len;
	int q = 1001; //A big enough prime modulus

	/* Get user inputs */
	printf("Enter test string: ");
	fgets(txt, sizeof(txt), stdin);
	printf("Enter pattern to find: ");
	fgets(pat, sizeof(pat), stdin);

	/* Calculate string lengths */
	txt_len = strlen(txt);
	pat_len = strlen(pat);

	/* fgets also gives '\n', so remove it from input strings */
	if (txt[txt_len-1] == '\n')
		txt[txt_len-1] = '\0';
	if (pat[pat_len-1] == '\n')
		pat[pat_len-1] = '\0';

	rabin_karp_search(pat, txt, q);

	return (0);
}
