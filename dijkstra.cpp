#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2001;
long long inf = 1e18;
vector<int> used(MAXN, 0), pr(MAXN, -1);
vector<long long> dist(MAXN, inf);
vector<vector<pair<int, int>>> g(MAXN);
long long n, s, f, q;

void dijkstra (long long v){
    dist[v] = 0;
    for (int i = 0; i < n; ++i){
        int h = -1;
        for (int j = 0; j < n; ++j){
            if(!used[j] && (h == -1 || dist[j] < dist[h])) h = j;
        }
        used[h] = true;
        int to;
        long long w;
        for (auto x: g[h]){
            to = x.first;
            w = x.second;
            if (dist[to] > dist[h] + w){
                dist[to] = dist[h] + w;
                pr[to] = h;
            }
        }
    }
}
int main() {
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> s >> f;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> q;
            if (q != -1 && q != 0) g[i].push_back({j, q});
        }
    }
    dijkstra(s - 1);
    if (dist[f - 1] == inf) cout << -1;
    else cout << dist[f - 1];
}
