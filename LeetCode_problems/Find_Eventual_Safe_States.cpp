class Solution {
public:
    bool vis[10005];
    bool pathvis[10005];
    vector<int> safe;
    
    bool dfs(int src, vector<vector<int>>& graph)
    {
        vis[src] = true;
        pathvis[src] = true;
        for(int child : graph[src])
        {
            if(vis[child] && pathvis[child])
                return true;
            if(!vis[child])
                if(dfs(child, graph))
                    return true;
        }
        safe.push_back(src);
        pathvis[src] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs(i,graph);
        
        sort(safe.begin(),safe.end());
        return safe;
    }
};




























































// This problem is about finding eventual safe states in a directed graph.

// If a node leads to a cycle → it’s unsafe.

// If every path from a node eventually ends at a terminal node (no outgoing edges) → it’s safe.

// So, the problem reduces to cycle detection: nodes that are not part of or connected to a cycle are safe.

// Approach
// Perform DFS with recursion stack tracking (pathvis[]):

// If during DFS we revisit a node in the current path → cycle detected → mark unsafe.

// If we finish exploring a node without detecting a cycle, it’s safe.

// Maintain a vis[] array to avoid reprocessing nodes.

// Store safe nodes in a list as DFS completes.

// Finally, sort the list of safe nodes and return it.

// Complexity
// Time complexity:
// O(V+E)

// Space complexity:
// O(V+E)