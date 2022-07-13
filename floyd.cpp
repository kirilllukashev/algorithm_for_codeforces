#include<bits/stdc++.h>

using namespace std;

const int inf = 1e9, maxn = 201;
vector<vector<int>> dist(maxn, vector<int>(maxn, inf));

int main() {
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    int v, u, w;
    for(int i = 0; i < m; ++i){
        cin >> v >> u >> w;
        dist[v - 1][u - 1] = w;
    }
    for(int i = 0; i < n; ++i){
        dist[i][i] = 0;
    }
    for(int k = 0; k <= n; ++k){
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << dist[i][j] << ' ';
        }
        cout << "\n";
    }
}
