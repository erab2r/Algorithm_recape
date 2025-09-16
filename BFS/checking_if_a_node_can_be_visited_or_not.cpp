#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool visited[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
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
            }
        }
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    while (e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    int src,dst;
    cin >> src >> dst;
    bfs(src);
    if(visited[dst])
    {
        cout << "Node can be visited\n";
    }
    else
    {
        cout << "Node can't be visited\n";
    }
    
}