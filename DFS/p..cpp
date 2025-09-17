#include<bits/stdc++.h>
using namespace std;

char grid[1000][1000];
int n,m;
bool visited[1000][1000];
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};

bool valid(int i,int j)
{
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == '#')
        return false;
    return true;
}

void bfs(int si,int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    visited[si][sj] = true;

    while (!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for(int i=0;i<4;i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if(valid(ci,cj) && !visited[ci][cj])
            {
                q.push({ci,cj});
                visited[ci][cj] = true;
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

    memset(visited,false,sizeof(visited));

    int rooms = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j] == '.' && !visited[i][j])
            {
                bfs(i,j);
                rooms++;
            }
        }
    }

    cout << rooms << endl;
    return 0;
}
// input : 
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########
// output : 3