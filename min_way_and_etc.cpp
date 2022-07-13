#include<bits/stdc++.h>

using namespace std;

const int maxn = 5010;
long long INF = 1e18 * 9;

int used[maxn];
vector<long long> d(maxn, INF);
vector<vector<pair<int, long long>>> g(maxn);

void dfs(int v){
    used[v] = 1;
    for(auto x: g[v]){
        if(!used[x.first]) dfs(x.first);
    }
}

int main(){
    int n, m, s;
    cin >> n >> m >> s;
    int u, v;
    long long w;

    for(int i = 0; i < m; ++i){
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    d[s] = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 1; j <= n; ++j){
            for(auto x: g[j]){
                int to = x.first;
                long long w = x.second;
                if(d[j] < INF && d[to] > d[j] + w) d[to] = d[j] + w;
            }
        }
    }

    for(int j = 1; j <= n; ++j){
        for(auto x: g[j]){
            int to = x.first;
            long long w = x.second;
            if(d[j] < INF && d[to] > d[j] + w && !used[to]) dfs(to);
        }
    }
    for(int i = 1; i <= n; ++i){
        if(d[i] == INF) cout << "*\n";
        else if(used[i]) cout << "-\n";
        else cout << d[i] << "\n";
    }
}
