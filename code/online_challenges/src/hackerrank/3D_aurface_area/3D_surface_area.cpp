#include <iostream>

int main()
{
    int h, w;
    int a[110][110];
    std::cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j)
            std::cin >> a[i][j];
    }
    int sum = 0;
    for (int i = 0; i < h; ++i) {
        if (i == 0) {
            for (int j = 0; j < w; ++j) {
                int temp = 0;
                if (j == 0) {
                    temp = (a[i][j] - 1) * 4 + 6;
                    sum += temp;
                }
                else {
                    temp = (a[i][j] - 1) * 4 + 6;
                    int d = std::min(a[i][j - 1], a[i][j]);
                    temp -= (d * 2);
                    sum  += temp;
                }
            }
        }
        else {
            for (int j = 0; j < w; ++j) {
                int temp = 0;
                if (j == 0) {
                    temp = (a[i][j] - 1) * 4 + 6;
                    int d = std::min(a[i][j], a[i - 1][j]);
                    temp -= (d * 2);
                    sum += temp;
                }
                else {
                    temp = (a[i][j] - 1) * 4 + 6;
                    int d = std::min(a[i][j - 1], a[i][j]);
                    temp -= (d * 2);
                    d = std::min(a[i][j], a[i - 1][j]);
                    temp -= (d * 2);
                    sum += temp;
                }
            }
        }
    }
    std::cout << sum << "\n";

    return 0;
}
