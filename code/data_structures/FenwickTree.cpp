#include <iostream>
#include <time.h>
#define N 9
#define range 5
#define infinity 100100100

using namespace std;

void add(int fenwick[], int a, int delta);
int query(int fenwick[], int a, int b);

int main()
{
	//int input[N];
	int fenwick[N+1];			// This will contain cumulative frequency (At index i we have frequency [0..i])
	fenwick[0] = 0;
	fill(fenwick, fenwick + 1+ N, 0);
	int input[] = {1, 3, 4, 8, 6, 1, 4, 2};

	//for(int i = 0; i < N; i++)
		//input[i] = (rand()%range)+1;	

	for(int i = 0; i < N; i++)
		cout << input[i] << " ";
	cout << endl;

	for(int i = 1; i < N; i++)
		add(fenwick, i, input[i-1]);

	for(int i = 1; i < N; i++)
		cout << fenwick[i] << " ";
	cout << endl;

	cout << query(fenwick, 0,5); // Sum[0,5]


}

void add(int fenwick[], int a, int delta)
{
	for(; a < N; a += a & (-a))
		fenwick[a] += delta;
}

int query(int fenwick[], int a, int b)
{
	if(a > 0)
		return query(fenwick, 0,b) - query(fenwick, 0, a-1);

	int sum = 0;
	for(; b > 0; b -= b & (-b))
		sum += fenwick[b];

	return sum;
}