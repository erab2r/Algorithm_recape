// You will be given an undirected graph which will be connected as input. Then you will be given a level L. You need to print the node values at level L in descending order. The source will be 0 always.
#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];
int level[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(int child : adj_list[par])
        {
            if(!visited[child])
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
            }
        }
    }
}
int main()
{   
    int n,e;
    cin >> n >> e;
    for(int i = 0;i<e;i++)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited,false,sizeof(visited));
    memset(level,-1,sizeof(level));
    int L;
    cin >> L;
    bfs(0);
    vector<int> nodeAtLevel;
    for(int i = 0;i<n;i++)
    {   
        if(level[i] == L){
            nodeAtLevel.push_back(i);
        }
    }
    reverse(nodeAtLevel.begin(),nodeAtLevel.end());
    for(int x : nodeAtLevel)
    {
        cout << x << " ";
    }

}                               


// Node:   0  1  2  3  4  5    level[i] == L
// Level:  0  1  1  1  2  2
