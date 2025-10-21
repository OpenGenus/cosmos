#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Basit bir linear SVM örneği (öğrenme yok, sadece mantık gösterimi)
class SVM
{
public:
    vector<double> weights;
    double bias;

    SVM()
    {
        weights = {0.5, -0.3};
        bias = 0.1;
    }

    int predict(vector<double> x)
    {
        double sum = bias;
        for (int i = 0; i < x.size(); i++)
            sum += x[i] * weights[i];
        return sum >= 0 ? 1 : -1;
    }
};

int main()
{
    SVM model;
    vector<vector<double>> data = {{1, 2}, {-1, -2}, {2, 3}, {-2, -3}};
    for (auto &x : data)
    {
        cout << "Prediction for (" << x[0] << ", " << x[1] << "): "
             << model.predict(x) << endl;
    }
    return 0;
}
