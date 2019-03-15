#include <iostream>
#include <vector>
#include "../../src/push_relabel/push_relabel.cpp"


int g_testCounter = 0;
std::vector<std::vector<int> > g_graph;
std::vector<std::vector<int> > g_flow;

void test(int res, int s, int t, bool empty)
{
	std::cout << "Test " << ++g_testCounter << ": ";
	int k = (empty ? max_flow_empty(g_graph,s,t) : max_flow(g_graph,g_flow,s,t));
	if(k == res)
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail. Expected: " << res << ", recieved: " << k << std::endl;
	

	g_graph.clear();
	g_flow.clear();
}

int main()
{


	std::cout << "Testing the push-relabel algorithm" << std::endl;

	g_graph.push_back(std::vector<int>{ 0, 1, 0 });
	g_graph.push_back(std::vector<int>{ 0, 0, 1 });
	g_graph.push_back(std::vector<int>{ 0, 0, 0 });

	test(1,0,2,true);

	g_graph.push_back(std::vector<int>{ 0, 1, 0, 0 });
	g_graph.push_back(std::vector<int>{ 0, 0, 1, 0 });
	g_graph.push_back(std::vector<int>{ 0, 0, 0, 1 });
	g_graph.push_back(std::vector<int>{ 0, 0, 0, 0 });
	
	test(1,0,3,true);

	g_graph.push_back(std::vector<int>{ 0, 10, 0 });
	g_graph.push_back(std::vector<int>{ 0, 0, 5 });
	g_graph.push_back(std::vector<int>{ 0, 0, 0 });

	test(5,0,2,true);

	g_graph.push_back(std::vector<int>{ 0, 10, 0 });
	g_graph.push_back(std::vector<int>{ 0, 0, 5 });
	g_graph.push_back(std::vector<int>{ 0, 0, 0 });

	g_flow.push_back(std::vector<int>{ 0, 3, 0 });
	g_flow.push_back(std::vector<int>{ 0, 0, 3 });
	g_flow.push_back(std::vector<int>{ 0, 0, 0 });

	test(5,0,2,false);

	g_graph.push_back(std::vector<int>{ 0, 10, 10, 0, 0, 0});
	g_graph.push_back(std::vector<int>{ 0, 0, 0, 10, 4, 0});
	g_graph.push_back(std::vector<int>{ 0, 0, 0, 4, 4, 0});
	g_graph.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 12});
	g_graph.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 8});
	g_graph.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 0});

	test(18,0,5,true);

	// wikipedia example
	g_graph.push_back(std::vector<int>{ 0, 15, 4, 0, 0, 0});
	g_graph.push_back(std::vector<int>{ 0, 0, 0, 12, 0, 0});
	g_graph.push_back(std::vector<int>{ 0, 0, 0, 0, 10, 0});
	g_graph.push_back(std::vector<int>{ 0, 0, 3, 0, 0, 7});
	g_graph.push_back(std::vector<int>{ 0, 5, 0, 0, 0, 10});
	g_graph.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 0});

	g_flow.push_back(std::vector<int>{ 0, 0, 4, 0, 0, 0});
	g_flow.push_back(std::vector<int>{ 0, 0, 0, 4, 0, 0});
	g_flow.push_back(std::vector<int>{ 0, 0, 0, 0, 4, 0});
	g_flow.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 4});
	g_flow.push_back(std::vector<int>{ 0, 4, 0, 0, 0, 0});
	g_flow.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 0});


	test(14,0,5,false);
	return 0;
}
