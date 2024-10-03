/* Part of Cosmos by OpenGenus Foundation */
void
xor_swap(int * restrict a, int * restrict b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
