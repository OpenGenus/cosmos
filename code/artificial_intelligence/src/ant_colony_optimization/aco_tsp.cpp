/* Part of Cosmos by OpenGenus Foundation
 * Application of Ant Optimization Algorithm in Travelling Salesman Problem.
 * Input: N - Number of vertices, followed by adjacency matrix which stores weights of edges
 *   of complete undirected weighted graph with no loops.
 * Output: tour thought all unrepeated vertices via the cheapest path and the cost of this tour.
 */
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const double g_rho = 0.6;    // Evaporation constant
const double g_q = 0.2;      // Constant in equation delta_T_kth_from_i_to_j = q / L_kth

double doubleRand()
{   
    // Generate random double within the interval [0.0, 1.0)
    return double(rand()) / (double(RAND_MAX) + 1.0);
}

// Return true if all vertices have been visited
bool goToStart (int startOfTour, int N, vector<vector<int>> &parents)
{   
    for (int j = 0; j < N; j++)
        if (parents[startOfTour][j] == -1 && j != startOfTour) 
            return false;
    return true;
}

int chooseNextNode (int ant, int startOfTour, int N, vector<vector<double>> &distance,
                    vector<vector<double>> &pheromone, vector<vector<int>> &parents)
{   // Choose the next vertex for "ant" to go
    double denominator = 0, prob, interval = 0;
    double rand = doubleRand(); // Random number in [0, 1).
    if (!goToStart(startOfTour, N, parents)) {     // There are unvisited vertices
        // Calculate denominator based on unvisited vertices
        for (int j = 0; j < N; j++) {
            if (j != startOfTour && parents[startOfTour][j] == -1){
                denominator += pheromone[ant][j] / distance[ant][j];    // Calculate denominator in probability function
            }
        }
        // Chooses an edge using a percentage interval
        for (int j = 0; j < N; j++) {
            if (j != startOfTour && parents[startOfTour][j] == -1){  // Unvisited vertices
                // Calculate the probability of edge being chosen
                prob = (pheromone[ant][j] / distance[ant][j]) / denominator;
                if ( (interval <= rand) && (rand <= interval + prob) ) //random double falls into percentage interval
                    return j;
                else 
                    interval += prob; //Update lowerbound of interval
            }
        }
    } 
    else
        return startOfTour;   // All vertices have been visited
}

double lkAfterCompleteTour (int k, int N, vector<vector<double>> &distance,
                            vector<vector<double>> &pheromone, vector<vector<int>> &parents)
{   // Build the tour for k-th ant and returns the length of this tour
    int next;
    int ant = k;    // k - start of tour, "ant" is a k-th ant who is going through the tour
    double l = 0;    // l is the length of k-th ant's tour
    for (int j = 0; j < N; j++){
        next = chooseNextNode(ant, k, N, distance, pheromone, parents);  // Choose the next vertex for "ant" to go
        l += distance[ant][next];    // Update distance
        parents[k][next]= ant;       // Makes the current vertex parent of the next vertex
        ant = next;    // Move to next vertex
    }
    return l;    // Total length of the tour
}

double calculateDeltaPheromone (int i, int j, int N,  vector<vector<int>> &parents, vector<double> &len)
{
    double t = 0;
    for (int k = 0; k < N; k++)
        if ((parents[k][i]==j) || (parents[k][j]==i) )    // kth ant uses edge (i,j)
            t += g_q / len[k];
    return t;
}

void updatePheromone (int N, vector<vector<double>> &pheromone, vector<vector<int>> &parents, vector<double> &len)
{
    for (int i = 0; i < N; i++)    // Update only lower half of square
        for (int j = 0; j < i; j++)
            pheromone[i][j] = g_rho*pheromone[i][j] + calculateDeltaPheromone(i, j, N, parents, len);
    // Update the rest of square
    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            pheromone[i][j] = pheromone[j][i];
}

void updateParentsAndLength  (int N, vector<vector<int>>& parents, vector<double>& len, vector<double>& previousLen)
{    // Empty "parents" and makes previousLen equal to current len
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            parents[i][j] = -1;
        previousLen[i]=len[i];
    }
}

bool reachStagnation (int N, vector<double>& len, vector<double>& previousLen)
{   // Return true if we have reached stagnation
    // We have reached stagnation if "len" matrix is equal to "previousLen"
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (len[i] != previousLen[j]) 
                return false;
    return true;
}

int main()
{
    int N;    // Number of vertices
    vector<vector<double>> distance, pheromone;    // Adjacency matrices of weighted edges and pheromone values on them
    vector<vector<int>> parents;     // Parents of vertices in every tour => stores the path for every ant.
    vector<double> len;              // Lengths of each ant's tour
    vector<double> previousLen;      // Stores the length of each ant's tour in a previous iteration
    vector<double> v0;               // Empty vector of double
    vector<int> i0;                  // Empty vector of int
    double lowestLen = double (RAND_MAX); // Stores current lowest cost
    vector<int> cheapestPath; // Stores the cheapest path
    double x;
    cin >> N;
    int maxIter = 30000;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        distance.push_back(v0);
        pheromone.push_back(v0);
        parents.push_back(i0);
        len.push_back(0);
        previousLen.push_back(0);
        for (int j = 0; j < N; j++)
        {
            cin >> x;
            distance[i].push_back(x);     // Stores adjacency matrices of weighted edges
            if (i != j) pheromone[i].push_back(0.1);     // Initialize the level of pheromones
            else pheromone[i].push_back(0);        // Since there is no loop => there is no pheromone
            parents[i].push_back(-1);       // Each node has no parents yet => notate the absence of parent as -1
        }
    }
    bool stagnation = false;      // We don't have a stagnation yet
    while (!stagnation && maxIter--)
    {
        for (int k = 0; k < N; k++)     // For each  of N ants we need to find their tours
            len[k] = lkAfterCompleteTour(k,N,distance,pheromone,parents);     // Build the tour for k-th ant and returns the length of this tour
        updatePheromone(N, pheromone, parents, len);     // Update pheromone table
        stagnation = reachStagnation(N, len, previousLen);     // Return true if we have reached stagnation
        for(int k = 0; k < N;k++)
            if(len[k] < lowestLen) // Stores the best path seen so far
            {
                lowestLen = len[k];
                cheapestPath = parents[k];
            }
        if (!stagnation && maxIter) updateParentsAndLength(N, parents, len, previousLen);     // Empty "parents" and update previousLen
    }
    int k = 0;
    // Prints out the shortest tour
    cout<< "\nTour is: ";
    for (int i = 0; i<N; i++)
    {
        cout << k << "->";
        k = cheapestPath[k];
    }
    cout << 0 <<"\nCost is: " << lowestLen<<endl;
    return 0;
}