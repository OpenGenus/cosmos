### Building and running the executable

1) Run `make` to get the executable tsp
2) Run `./tsp < input >` output to get the results

### Algorithm

1) Used simulated annealing to first direct the path towards the random walk when temperature is high and then towards hill climbing when temperature is low.

2) Randomly picked up two edges and swapped to get a suggested path, if cost of suggested path is better than current path we move towards it. In case the suggested path is worse in comparison to current path we still move towards it with some probability when temperature is high.

3) Called the optimization function to get rid of long edges by using a series of swap operations.

4) Kept a tabu tenure counter to make the current path equal to best path in case we are not able to find better results.

5) Repeated the above process till the best_path became static for a large duration.
