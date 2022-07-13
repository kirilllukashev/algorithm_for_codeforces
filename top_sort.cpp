#include<bits/stdc++.h>

using namespace std;

const int MAXN = 50001;
vector<int> g[MAXN], used(MAXN), top_sort;
bool f = 1;

void dfs(int v){
    used[v] = 1;
    for(auto to: g[v]){
        if (used[to] == 0) dfs(to);
        else if (used[to] == 1){
            cout << -1;
            exit(0);
        }
    }
    used[v] = 2;
    top_sort.push_back(v);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, v, u;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> v >> u;
        g[v - 1].push_back(u - 1);
    }
    for(int i = 0; i < n; ++i){
        if (used[i] == 0) dfs(i);
    }
    for(int i = top_sort.size() - 1; i > -1; --i) cout << top_sort[i] + 1 << ' ';
}
