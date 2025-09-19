class Solution {
public:
    bool vis[2005];
    vector<int> adj_list[2005];
    bool pathvis[2005];
    bool cycle = false;

    void dfs(int src)
    {
        vis[src] = true;
        pathvis[src] = true;
        for(int child : adj_list[src])
        {
            if(vis[child] && pathvis[child])
                cycle = true;
            if(!vis[child])
                dfs(child);
        }
        pathvis[src] = false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        for(auto v : prerequisites)
        {
            int a = v[0];
            int b = v[1];
            adj_list[a].push_back(b);
        }
        for(int i=0;i<n;i++)
            if(!vis[i])
                dfs(i);

        return !cycle;
    }
};