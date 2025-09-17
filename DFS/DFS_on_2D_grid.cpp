#include<bits/stdc++.h>
using namespace std;
char grid[1000][1000];
int n,m;
bool visited[1000][1000];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=m )
        return false;
    return true;
}
void dfs(int si,int sj)
{
    cout << si << " " << sj << "\n";
    visited[si][sj] = true;
    for(int i =0;i<4;i++)
    {
        int ci =si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj)==true && !visited[ci][cj])
            dfs(ci,cj);
    }

}
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];
    int si,sj;
    cin >> si >> sj;
    memset(visited,false,sizeof(visited));
    dfs(si,sj);
}

// complexity : 0(V+E);