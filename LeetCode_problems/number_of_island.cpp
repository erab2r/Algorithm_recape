class Solution {
public:
    bool visited[305][305];
    vector<pair<int,int>> d =  {{0,-1},{0,1},{-1,0},{1,0}};
    int n,m;

    bool valid(int i, int j)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }

    void dfs(int si, int sj, vector<vector<char>>& grid)
    {
        visited[si][sj] = true;
        for(int i=0;i<4;i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;
            if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj]=='1')
                dfs(ci,cj,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt = 0;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!visited[i][j] && grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    cnt++;
                }
        return cnt;
    }
};