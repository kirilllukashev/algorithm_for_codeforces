#include<bits/stdc++.h>

using namespace std;

int n, m;
const int maxn = 1e5;
vector<vector<pair<int, int>>> g(maxn);
vector<int> d(maxn, 1e9);

void dijkstra(int x){

    d[x] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, x});

    while(!q.empty()){
        pair<int, int> a = q.top();

        q.pop();

        int dst = a.first, v = a.second;

        if(d[v] < dst){
            continue;
        }

        for(auto to: g[v]){
            int u = to.first, len = to.second;

            if(dst + len < d[u]){
                d[u] = dst + len;
                q.push({dst + len, u});
            }
        }
    }
}
int main(){
    cin >> n >> m;

    int v, u, w;

    for(int i = 0; i < m; ++i){
        cin >> v >> u >> w;

        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }

    dijkstra(1);

    for(int i = 1; i <= n; ++i){
        cout << d[i] << ' ';
    }
}
