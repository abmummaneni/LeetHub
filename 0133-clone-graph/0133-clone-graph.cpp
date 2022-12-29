/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *cloneGraph(Node *root) {
        if (!root){return root;}
        // Key -> old, Val -> new
        unordered_map<Node *, Node *> seen;
        stack<Node *> todo;
        bool allSeen;
        todo.push(root);
        while (!todo.empty()) {
            Node *node = todo.top();
            allSeen = true;
            for (auto &neighbor: node->neighbors) {
                if (!seen[neighbor]) {
                    todo.push(neighbor);
                    allSeen = false;
                }
            }
            if(!seen[node]){seen[node] = new Node(node->val);}

            if(allSeen){
                vector<Node*> newNeighbors;
                for (auto &neighbor: node->neighbors){
                    newNeighbors.push_back(seen[neighbor]);
                }
                seen[node]->neighbors = newNeighbors;
                todo.pop();
            }
        }
        return seen[root];
    }

};