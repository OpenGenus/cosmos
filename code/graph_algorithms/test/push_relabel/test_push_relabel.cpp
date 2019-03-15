#include <iostream>
#include <vector>
#include "../../src/push_relabel/push_relabel.cpp"


int t_n = 0;
std::vector<std::vector<int> > graph;
std::vector<std::vector<int> > flow;

void test(int res, int s, int t, bool empty){
	std::cout << "Test " << ++t_n << ": ";
	int k = (empty ? max_flow_empty(graph,s,t) : max_flow(graph,flow,s,t));
	if(k == res){
		std::cout << "Success" << std::endl;
	}else{
		std::cout << "Fail. Expected: " << res << ", recieved: " << k << std::endl;
	}

	graph.clear();
	flow.clear();
}

int main(){


	std::cout << "Testing the push-relabel algorithm" << std::endl;

	graph.push_back(std::vector<int>{ 0, 1, 0 });
	graph.push_back(std::vector<int>{ 0, 0, 1 });
	graph.push_back(std::vector<int>{ 0, 0, 0 });

	test(1,0,2,true);

	graph.push_back(std::vector<int>{ 0, 1, 0, 0 });
	graph.push_back(std::vector<int>{ 0, 0, 1, 0 });
	graph.push_back(std::vector<int>{ 0, 0, 0, 1 });
	graph.push_back(std::vector<int>{ 0, 0, 0, 0 });
	
	test(1,0,3,true);

	graph.push_back(std::vector<int>{ 0, 10, 0 });
	graph.push_back(std::vector<int>{ 0, 0, 5 });
	graph.push_back(std::vector<int>{ 0, 0, 0 });

	test(5,0,2,true);

	graph.push_back(std::vector<int>{ 0, 10, 0 });
	graph.push_back(std::vector<int>{ 0, 0, 5 });
	graph.push_back(std::vector<int>{ 0, 0, 0 });

	flow.push_back(std::vector<int>{ 0, 3, 0 });
	flow.push_back(std::vector<int>{ 0, 0, 3 });
	flow.push_back(std::vector<int>{ 0, 0, 0 });

	test(5,0,2,false);

	graph.push_back(std::vector<int>{ 0, 10, 10, 0, 0, 0});
	graph.push_back(std::vector<int>{ 0, 0, 0, 10, 4, 0});
	graph.push_back(std::vector<int>{ 0, 0, 0, 4, 4, 0});
	graph.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 12});
	graph.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 8});
	graph.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 0});

	test(18,0,5,true);

	// wikipedia example
	graph.push_back(std::vector<int>{ 0, 15, 4, 0, 0, 0});
	graph.push_back(std::vector<int>{ 0, 0, 0, 12, 0, 0});
	graph.push_back(std::vector<int>{ 0, 0, 0, 0, 10, 0});
	graph.push_back(std::vector<int>{ 0, 0, 3, 0, 0, 7});
	graph.push_back(std::vector<int>{ 0, 5, 0, 0, 0, 10});
	graph.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 0});

	flow.push_back(std::vector<int>{ 0, 0, 4, 0, 0, 0});
	flow.push_back(std::vector<int>{ 0, 0, 0, 4, 0, 0});
	flow.push_back(std::vector<int>{ 0, 0, 0, 0, 4, 0});
	flow.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 4});
	flow.push_back(std::vector<int>{ 0, 4, 0, 0, 0, 0});
	flow.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 0});


	test(14,0,5,false);
	return 0;
}
