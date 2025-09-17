#include<bits/stdc++.h>
using namespace std;
char grid[1000][1000];
int n,m;
bool visited[1000][1000];
int level[1000][1000];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=m )
        return false;
    return true;
}
void bfs(int si,int sj)
{
  queue<pair<int,int>> q;
  q.push({si,sj});
  visited[si][sj] = true;
  level[si][sj] = 0;
  while (!q.empty())
  {
    pair<int,int> par = q.front();
    q.pop();
    int par_i = par.first;  //1 
    int par_j = par.second; // 2
    //cout << par_i << " " << par_j << endl;
    for(int i=0;i<4;i++)
    {
        int ci = par_i + d[i].first;
        int cj = par_j + d[i].second;
        if(valid(ci,cj) == true && !visited[ci][cj])
        {
            
            q.push({ci,cj});
            visited[ci][cj] = true;
            level[ci][cj] = level[par_i][par_j] + 1;
        }

    }
  }
  

}      
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];
    int si,sj,di,dj;
    cin >> si >> sj >> di >> dj;
    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    bfs(si,sj);
    cout << level[di][dj] << endl;
}

// complexity : 0(V+E);