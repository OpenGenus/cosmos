//
//Given a reference of a node in a connected undirected graph.
//Return a deep copy (clone) of the graph.
//

//To create this deep copy of the graph, we recursively visit each node in the original graph, and make a copy of it,
// as well as all of it's neighbors. We used an unordered map, also known as a hashmap that maps the original node to it's copy,
// which helps us determine which Node's have already been copied, meaning we don't need to copy it again.
class Solution {
public:
    //This global unordered map helps us keep track of which Node's have been copied, and allows us to access these copies with
    //O(1) runtime.
    unordered_map<Node*, Node*> um;
    Node* cloneGraph(Node* node) {
        //Base case
        if (!node)
            return node;
        //We check to see if the original node exists in our map. If it does NOT, we need to add it point it to it's copy.
        if (!um.count(node)) {
            um[node] = new Node(node->val);
            //After creating the copy, we must recursively assign it's neighbors based on it's corresponding node's neighbors.
            for (auto it: node->neighbors) {
                um[node]->neighbors.push_back(cloneGraph(it));
            }
        }
        //After setting all of it's neighbors, we return a reference to the copy of that Node, which is accessed
        //using the original Node as a key.
        return um[node];
    }
};

//Time Complexity: The time complexity of this algorithm is O(N+M), where N is the number of Nodes in the graph, and M is the
//number of edges. This is because we must visit every Node once, and account for each one of it's neighbors once.