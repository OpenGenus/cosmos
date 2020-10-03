#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
#define fio                     std::ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll                      long long
#define vi                      vector<int>
#define all(a)          a.begin(), a.end()
#define pb                      push_back
const ll mod = 1e9 + 7;
const ll N = 1e5;
const ll MAX = 1e18;
#define epsilon 1e-6
vector<vector<long double>> adjacency_matrix;
// Initial Temperature
long double temperature = 10000000000000;
long long num_cities;
long double answer = INT_MAX;
void initialize_vectors(vector<long long> &best_path, vector<long long> &current_path,
                        vector<long long> &suggested_path)
{
    for (long long i = 0; i < num_cities; i++)
    {
        current_path[i] = i;
        suggested_path[i] = i;
        best_path[i] = i;
    }
    random_shuffle(current_path.begin(), current_path.end());
}
long double evaluation(vector<long long> vec)
{
    long double cost = 0;
    for (long long i = 0; i < num_cities - 1; i++)
        cost += adjacency_matrix[vec[i]][vec[i + 1]];
    cost += adjacency_matrix[vec[vec.size() - 1]][vec[0]];
    return cost;
}
// swaps random edges
pair<long, long> random_edge()
{
    long long start_ind = rand() % num_cities;
    long long end_ind = (rand() % num_cities) + 1;
    if (start_ind > end_ind)
        swap(start_ind, end_ind);
    return make_pair(start_ind, end_ind);
}
// Uses triangle law to swap longer edges
void Optimization(vector<long long> &auxiliary_best)
{
    for (size_t i = 0; i < auxiliary_best.size() - 3; i++)
    {
        long double AB = adjacency_matrix[auxiliary_best[i]][auxiliary_best[i + 1]];
        long double CD = adjacency_matrix[auxiliary_best[i + 2]][auxiliary_best[i + 3]];
        long double AC = adjacency_matrix[auxiliary_best[i]][auxiliary_best[i + 2]];
        long double BD = adjacency_matrix[auxiliary_best[i + 1]][auxiliary_best[i + 3]];
        if (AB + CD > AC + BD)
        {
            swap(auxiliary_best[i + 1], auxiliary_best[i + 2]);
            i += 3;
        }
        else
            i++;
    }
}
void simulated_annealing()
{
    vector<long long> best_path(num_cities, 0), current_path(num_cities, 0), suggested_path(
        num_cities, 0);
    initialize_vectors(best_path, current_path, suggested_path);
    int limit = 10000000;
    long double best_path_cost = 0;
    long long tabu_tenure = 0, break_counter = 0;
    while (limit-- && break_counter <= 200000)
    {
        suggested_path = current_path;
        pair<long long, long long> edges = random_edge();
        long long start = edges.first, end = edges.second;
        reverse(suggested_path.begin() + start, suggested_path.begin() + end);
        Optimization(suggested_path);
        long double current_path_cost = evaluation(current_path);
        long double suggested_path_cost = evaluation(suggested_path);
        long double net_gain = suggested_path_cost - current_path_cost;
        long double rand_num = (double) (rand() / (double) RAND_MAX);
        long double probability = 1 / (1 + std::pow(M_E, (net_gain / temperature)));
        best_path_cost = evaluation(best_path);
        if (probability > rand_num)
            current_path = suggested_path;
        if (suggested_path_cost < best_path_cost)
        {
            best_path = suggested_path;
            answer = min(answer, suggested_path_cost);
            tabu_tenure = 0;
            current_path = suggested_path;
            break_counter = 0;
            for (size_t i = 0; i < best_path.size(); i++)
                cout << best_path[i] + 1 << " ";
            cout << best_path[0] + 1 << endl;
        }
        else
            tabu_tenure++;
        if (tabu_tenure >= 500)
        {
            Optimization(best_path);
            if (best_path_cost > evaluation(best_path))
            {
                best_path_cost = evaluation(best_path);
                answer = best_path_cost;
                current_path = best_path;
                break_counter = 0;
                for (size_t i = 0; i < best_path.size(); i++)
                    cout << best_path[i] + 1 << " ";
                cout << best_path[0] + 1 << endl;
            }

            tabu_tenure = 0;
        }
        cout << "Best_Path_till now " << best_path_cost << endl;
        // Cooling Rate
        temperature *= 0.999;
        break_counter++;
    }
    cout << "Final Path:\n";
    for (size_t i = 0; i < best_path.size(); i++)
        cout << best_path[i] + 1 << " ";
    cout << best_path[0] + 1 << endl;
    cout << endl;

}
void processing_data()
{
    vector<pair<long double, long double>> location;
    string type;
    cin >> type;
    long double x, y;
    cin >> num_cities;
    srand (time(NULL));
    for (long long i = 0; i < num_cities; i++)
    {
        cin >> x >> y;
        location.push_back(make_pair(x, y));
    }
    for (long long i = 0; i < num_cities; i++)
    {
        vector<long double> temp;
        for (long long j = 0; j < num_cities; j++)
        {
            cin >> x;
            temp.push_back(x);
        }
        adjacency_matrix.push_back(temp);
    }
}
int main()
{
    processing_data();
    simulated_annealing();
    cout << "Minimum Path found so far " << answer << endl;
    return 0;
}
