#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t;     //t is the number of test case
    std::cin >> t;
    while (t--) {
        int n;     //n is the size of input array
        int sum, ans, ans1;
        sum = ans = ans1 = 0;
        int flag = 0;
        std::cin >> n;
        std::vector<int> arr(n);

        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
            if (arr[i] >= 0)
                ++flag;
        }

        if (flag == 0) {
            std::sort(arr.begin(), arr.end());
            std::cout << arr[n - 1] << " " << arr[n - 1] << "\n";
            continue;
        }

        sum = ans = ans1 = 0;

        for (int i = 0; i < n; ++i) {
            if ((sum + arr[i]) > 0)
                sum += arr[i];
            else
                sum = 0;
            if (arr[i] >= 0)
                ans1 += arr[i];

            ans = std::max(ans, sum);
        }

        std::cout << ans << " " << ans1 << "\n";
    }

    return 0;
}
