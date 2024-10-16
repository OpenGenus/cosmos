#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;
unordered_map<string, int> count(pair<vector<string>, vector<string>> &feature, vector<string> &position)
{
    unordered_map<string, int> d;

    for (int i = 0; i < 2; i++) // because pairs only have 2 values
    {
        for (int j = 0; j < feature.first.size(); j++)
        {
            if (i == 0)
            {
                d.emplace(feature.first[j], 0);
            }
            else
            {
                d.emplace(feature.second[j], 0);
            }
        }
    }

    for (int i = 0; i < position.size(); i++)
    {
        d.emplace(position[i], 0);
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < feature.first.size(); j++)
        {
            if (i == 0)
            {
                d[feature.first[j]] = d[feature.first[j]] + 1;
            }
            else
            {
                d[feature.second[j]] = d[feature.second[j]] + 1;
            }
        }
    }

    for (int i = 0; i < position.size(); i++)
    {
        d[position[i]] = d[position[i]] + 1;
    }

    for (int i = 0; i < 2; i++) // because pairs only have 2 values
    {
        for (int j = 0; j < feature.first.size(); j++)
        {
            for (int k = 0; k < position.size(); k++)
            {
                if (i == 0)
                {
                    d.emplace(feature.first[j] + "/" + position[k], 0);
                }
                else
                {
                    d.emplace(feature.second[j] + "/" + position[k], 0);
                }
            }
        }
    }

    for (int i = 0; i < position.size(); i++)
    {
        d[feature.first[i] + "/" + position[i]] = d[feature.first[i] + "/" + position[i]] + 1;
        d[feature.second[i] + "/" + position[i]] = d[feature.second[i] + "/" + position[i]] + 1;
    }

    return d;
}
unordered_map<string, double> calcProb(unordered_map<string, int> &d, pair<vector<string>, vector<string>> &feature, vector<string> &position)
{
    int sum = 0;
    unordered_map<string, double> x;
    sum = position.size();

    for (int i = 0; i < position.size(); i++)
    {
        x.emplace(position[i], (double)d[position[i]] / (double)sum);
    }

    for (int i = 0; i < sum; i++)
    {
        x.emplace(feature.first[i] + "/" + position[i], (double)d[feature.first[i] + "/" + position[i]] / (double)d[position[i]]);
        x.emplace(feature.second[i] + "/" + position[i], (double)d[feature.second[i] + "/" + position[i]] / (double)d[position[i]]);
    }

    return x;
}

vector<string> finalPredictions(unordered_map<string, double> &x, pair<vector<string>, vector<string>> &feature, vector<string> &position)
{
    vector<string> predict_array;
    vector<double> predict_array_prob;
    double temp;
    int size = position.size();

    for (int i = 0; i < size; i++)
    {
        predict_array.push_back("");
        predict_array_prob.push_back(0.0);
    }

    for (int k = 0; k < size; k++)
    {
        for (int i = 0; i < size; i++)
        {
            temp = 1.0;
            for (int j = 0; j < 2; j++)
            {
                if (j == 0)
                {
                    temp = temp * x[feature.first[i] + "/" + position[k]];
                }
                else
                {
                    temp = temp * x[feature.second[i] + "/" + position[k]];
                }
            }
            if (predict_array_prob[i] < temp * x[position[k]])
            {
                predict_array[i] = position[k];
                predict_array_prob[i] = temp * x[position[k]];
            }
        }
    }

    return predict_array;
}

int main()
{

    vector<string> weather = {
        "sunny",
        "rainy",
        "sunny",
        "sunny",
        "sunny",
        "rainy",
        "rainy",
        "sunny",
        "sunny",
        "rainy",
    };

    vector<string> car = {
        "working",
        "broken",
        "working",
        "working",
        "working",
        "broken",
        "broken",
        "working",
        "broken",
        "broken",

    };

    vector<string> position = {
        "go-out",
        "go-out",
        "go-out",
        "go-out",
        "go-out",
        "stay-home",
        "stay-home",
        "stay-home",
        "stay-home",
        "stay-home",

    };

    pair<vector<string>, vector<string>> feature;
    feature.first = weather;
    feature.second = car;
    unordered_map<string, int> d = count(feature, position);
    unordered_map<string, double> x = calcProb(d, feature, position);

    vector<string> predictions = finalPredictions(x, feature, position);

    for (int i = 0; i < weather.size(); i++)
    {
        cout << weather[i] << " " << car[i] << " prediction is -> " << predictions[i] << endl;
    }

    // test cases from naive_bayes.py file

    return 0;
}
