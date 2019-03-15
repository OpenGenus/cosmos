#include <vector>
#include <queue>
#include <cmath>
#include <limits>



// push as much excess flow as possible from f to t
void push(std::vector<std::vector<int> > * graph, std::vector<std::vector<int> > * flow, std::vector<std::vector<int> > * residual, std::vector<int> * excess, int f, int t){

	if((*excess)[f] <= 0){
		std::cerr << "excess on node " << f << "is " << (*excess)[f] << std::endl;
		return;
	}
	
	// calculate the maximum amount of flow that can be pushed
	int tmp = std::min((*excess)[f], (*residual)[f][t]);

	(*excess)[f] -= tmp;
	(*excess)[t] += tmp;

	(*residual)[f][t] -= tmp;
	(*residual)[t][f] += tmp;

	// if this holdes, the edge is a backwards edge, so t->f will be reduced
	if((*graph)[f][t] == 0){

		(*flow)[t][f] -= tmp;
		return;
	}

	(*flow)[f][t] += tmp;
}

// reset the height of node "node", so excess flow can be pushed
void relabel(std::vector<std::vector<int> > * residual, std::vector<int> * height, int node){


	int min = std::numeric_limits<int>::max();

	for(int i = 0; i < residual->size(); i++){
		if((*residual)[node][i] > 0 && (*height)[i] < min){

			min = (*height)[i];
		}
	}

	height->at(node) = min + 1;
}



// expecting propper flow matrix, empty residual
// and no a ->b, b-> a capacities
int max_flow_residual(std::vector<std::vector<int> > graph, std::vector<std::vector<int> > flow, std::vector<std::vector<int> > * residual, int s, int t){

	int num_nodes = graph.size();

	// property check
	if(graph.size() != graph[0].size() || graph.size() != flow.size()){
		std::cerr << "Graph matrix/Flow Matrix has wrong format" << std::endl;
	}


	std::vector<int> excess(num_nodes,0);
	excess[s] = std::numeric_limits<int>::max();




	// initialize the residual graph
	for(int i = 0; i < num_nodes; i++){
		for(int j = 0; j < num_nodes; j++){
			int tmp = flow[i][j];
			if(tmp > 0){
					(*residual)[j][i] = tmp;
			}
			int g = graph[i][j] - tmp;
			if(g > 0){
				(*residual)[i][j] = g;
			}
		}
	}

	std::queue<int> active_nodes;

	// push initial flow from source
	for(int i = 0; i < num_nodes; i++){
		if(graph[s][i] > 0 && graph[s][i] > flow[s][i]){
			push(&graph, &flow, &(*residual), &excess, s, i);
			active_nodes.push(i);
		}
	}

	// create initial height values
	std::vector<int> height(num_nodes,0);
	height[s] = num_nodes;
	height[t] = 0;

	while(!active_nodes.empty()){


		int node = active_nodes.front();


		// store all nodes that excess flow can be pushed to from 'node'
		std::vector<int> nbr_lst;
		for(int i = 0; i < num_nodes; i++){

			if((*residual)[node][i] > 0){
				nbr_lst.push_back(i);
			}
		}

		int i = 0;


		// apply push / relabel to 'node' until all excess flow is taken care of
		while(excess[node] > 0){

			if(i == nbr_lst.size()){
				// all possible neighbors have been visited but there is still too much incoming flow
				// so the height of 'node' has to be increased
				i=0;
				relabel(residual,&height,node);
			}else{
				int j = nbr_lst[i];
				if((*residual)[node][j] > 0 && height[node] > height[j]){

					push(&graph,&flow,residual,&excess,node,j);
					if(excess[j] > 0 && j != s && j != t){
						active_nodes.push(j);
					}

				}
				i++;
			}
		}

		active_nodes.pop();
	}


	// extract the flow
	int res = 0;
	for(int i = 0; i < num_nodes; i++){
		res += std::max(0,flow[s][i]);
	}

	return res;
}

int max_flow(std::vector<std::vector<int> > graph, std::vector<std::vector<int> > flow, int s, int t){

	int l = graph.size();
	std::vector<std::vector<int> > empty_residual(l, std::vector<int>(l,0));

	return max_flow_residual(graph, flow,  &empty_residual, s, t);

}


int max_flow_empty(std::vector<std::vector<int> > graph, int s, int t){

	// create empty flow matrix
	int l = graph.size();
	std::vector<std::vector<int> > empty_flow(l, std::vector<int>(l,0));

	return max_flow(graph, empty_flow, s, t);
}
