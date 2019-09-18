#define CATCH_CONFIG_MAIN
#include "../../../../test/c++/catch.hpp"
#include "../../src/push_relabel/push_relabel.cpp"
#include <iostream>


int g_testCounter = 0;
std::vector<std::vector<int>> g_graph;
std::vector<std::vector<int>> g_flow;

int test(int s, int t, bool empty)
{
    int k = (empty ? maxFlowEmpty(g_graph,s,t) : maxFlow(g_graph,g_flow,s,t));
    
    g_graph.clear();
    g_flow.clear();

    return k;
}

TEST_CASE("push relabel max flow, zero initial flow")
{
    g_graph.push_back(std::vector<int>{ 0, 1, 0 });
    g_graph.push_back(std::vector<int>{ 0, 0, 1 });
    g_graph.push_back(std::vector<int>{ 0, 0, 0 });

    REQUIRE(test(0,2,true) == 1);

    g_graph.push_back(std::vector<int>{ 0, 1, 0, 0 });
    g_graph.push_back(std::vector<int>{ 0, 0, 1, 0 });
    g_graph.push_back(std::vector<int>{ 0, 0, 0, 1 });
    g_graph.push_back(std::vector<int>{ 0, 0, 0, 0 });
    
    REQUIRE(test(0,3,true) == 1);

    g_graph.push_back(std::vector<int>{ 0, 10, 0 });
    g_graph.push_back(std::vector<int>{ 0, 0, 5 });
    g_graph.push_back(std::vector<int>{ 0, 0, 0 });

    REQUIRE(test(0,2,true) == 5);

    g_graph.push_back(std::vector<int>{ 0, 10, 10, 0, 0, 0});
    g_graph.push_back(std::vector<int>{ 0, 0, 0, 10, 4, 0});
    g_graph.push_back(std::vector<int>{ 0, 0, 0, 4, 4, 0});
    g_graph.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 12});
    g_graph.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 8});
    g_graph.push_back(std::vector<int>{ 0, 0, 0, 0, 0, 0});

    REQUIRE(test(0,5,true) == 18);
}

TEST_CASE("push relabel max flow, with existing flow")
{
    g_graph.push_back(std::vector<int>{ 0, 10, 0 });
    g_graph.push_back(std::vector<int>{ 0, 0, 5 });
    g_graph.push_back(std::vector<int>{ 0, 0, 0 });

    g_flow.push_back(std::vector<int>{ 0, 3, 0 });
    g_flow.push_back(std::vector<int>{ 0, 0, 3 });
    g_flow.push_back(std::vector<int>{ 0, 0, 0 });

    REQUIRE(test(0,2,false) == 5);

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

    REQUIRE(test(0,5,false) == 14);
}
