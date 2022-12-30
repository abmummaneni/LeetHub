class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        // Key -> node, Val -> paths to end
        unordered_map<int, vector<vector<int>>> mp;
        // Nodes to process
        stack<int> todo;
        // Push root node
        todo.push(0);
        // Variable to see if all children have been seen
        bool allSeen;
        // Last Node
        int last = graph.size() - 1;
        while (!todo.empty()) {
            int node = todo.top();
            // Node has been seen
            if (mp.find(node) != mp.end()){
                todo.pop();
                continue;
            }
            // Last Node
            if (node == last) {
                mp[node] = {{node}};
                todo.pop();
                continue;
            }
            allSeen = true;
            // Push children onto stack if they have not been seen
            for (auto child: graph[node]) {
                if (mp.find(child) == mp.end()) {
                    todo.push(child);
                    allSeen = false;
                }
            }
            // If all children have been seen, add current node to the start of the child's sub path
            if (allSeen) {
                vector<vector<int>> paths;
                for (auto child: graph[node]) {
                    for (auto subPath: mp[child]) {
                        subPath.insert(subPath.begin(), node);
                        paths.push_back(subPath);
                    }
                }
                mp[node] = paths;
                todo.pop();
            }
        }
        // Return all paths from root
        return mp[0];
    }
};