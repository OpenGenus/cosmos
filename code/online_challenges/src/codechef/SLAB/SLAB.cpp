// Part of Cosmos by OpenGenus
#include <iostream>

using namespace std;

int main ()
{
    int t;
    cin >> t;
    while (t --)
    {
    	
        long long int total, net, tax;
        cin >> total;
        
	if (total <= 250000)
        {
            net = total;
        }
        
	else if ((250000 < total) && (total <= 500000))
        {
            tax = 0.05 * (total - 250000);
            net = total - tax;
        }
        
	else if ((500000 < total) && (total <= 750000))
        {
            tax = 0.05 * ( 500000- 250000) + 0.10 * (total - 500000);
            net = total - tax;
        }
        
	else if ((750000 < total) && (total <= 1000000))
        {
            tax = 0.05 * (500000 - 250000) + 0.10 * (750000 - 500000) + 0.15 * (total - 750000);
            net = total - tax;
        }
        
        else if ((1000000 < total) && (total <= 1250000))
        {
            tax = 0.05 * (500000 - 250000) + 0.10 * (750000 - 500000) + 0.15 * (1000000 - 750000) + 0.20 * (total - 1000000);
            net = total - tax;
        }
        
        else if ((1250000 < total) && (total <= 1500000))
        {
            tax = 0.05 *(500000 - 250000) + 0.10 * (750000 - 500000) + 0.15 * (1000000 - 750000) + 0.20 * (1250000 - 1000000) + 0.25 * (total - 1250000);
            net = total - tax;
        }
        
        else if (total > 1500000)
        {
            tax = 0.05 * (500000 - 250000) + 0.10 * (750000 - 500000) + 0.15 * (1000000 - 750000) + 0.20 * (1250000 - 1000000) + 0.25 * (1500000 - 1250000) + 0.30 * (total - 1500000);
            net = total - tax;
        }
        
        cout << net << endl;
    }
    return 0;
}
