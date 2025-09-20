class Solution {
public:
    int n,m;
    bool visited[15][15];
    int sum;
    vector<pair<int,int>> d = {{1,0},{-1,0},{0,1},{0,-1}};

    bool valid(int i,int j)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }

    void dfs(int si, int sj, vector<vector<int>>& grid)
    {
        visited[si][sj] = true;
        sum += grid[si][sj];
        for(int i=0;i<4;i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj])
                dfs(ci,cj,grid);
        }
    }

    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int mx=0;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] && grid[i][j])
                {
                    sum = 0;
                    dfs(i,j,grid);
                    mx = max(sum,mx);
                }
            }
        return mx;
    }
};