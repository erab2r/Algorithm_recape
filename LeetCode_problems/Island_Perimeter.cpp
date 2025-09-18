class Solution {
public:
int cnt;
bool visited[105][105];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
bool valid(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}
void dfs(int si,int sj,vector<vector<int>>& grid)
{
    visited[si][sj] = true;
    for(int i = 0;i<4;i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) == false)
            cnt++;
        else if(valid(ci,cj) == true && grid[ci][cj] ==0)
            cnt++;
        else if(!visited[ci][cj] && valid(ci,cj) && grid[ci][cj] == 1)
            dfs(ci,cj,grid);

    }
}
    int islandPerimeter(vector<vector<int>>& grid) { 
        cnt = 0;
        n = grid.size();
        m = grid[0].size();
         memset(visited,false,sizeof(visited));
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
                if(!visited[i][j] && grid[i][j] == 1)
                    dfs(i,j,grid);
        return cnt;
    }
};