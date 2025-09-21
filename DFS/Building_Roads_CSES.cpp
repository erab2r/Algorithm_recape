#include<bits/stdc++.h>
using namespace std;

vector<int> adj_list[100005];
bool vis[100005];

void dfs(int src) {
    vis[src] = true;
    for (int child : adj_list[src]) {
        if (!vis[child]) dfs(child);
    }
}

int main() {   
    int n,e;
    cin >> n >> e;
    while (e--) {
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    vector<int> res;  
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            res.push_back(i); 
            dfs(i);
    
        }
    }

    int sz = res.size();

    cout<<sz-1<<endl;

    if (sz > 1) {
        for(int i=0; i<sz-1; i++) {
            cout<<res[i]<<" "<<res[i+1]<<endl;
        }
    }
    cout<<endl;

    return 0;
}



