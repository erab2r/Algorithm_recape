#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int cnt;
void dfs(int src)
{
    vis[src] = true;
    cnt++;
    for(int child : adj_list[src])
        if(!vis[child])
            dfs(child);
}

int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    vector<int> components;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==false)
        {   
            cnt = 0;
            dfs(i);
            components.push_back(cnt);
        }
    }
    sort(components.begin(),components.end());
    for( int x : components)
        cout << x << " ";
    return 0;
}