#include<bits/stdc++.h>

using namespace std;

const int maxn = 10010;
vector<vector<int>> g(maxn), gb(maxn);
vector<int> used(maxn, 0), top, col(maxn, -1);
set<pair<int, int>> pairs;

void dfs(int v){
    used[v] = 1;
    for(auto to: g[v]){
        if(!used[to]){
            dfs(to);
        }
    }
    top.push_back(v);
}
void dfs2(int v, int val){
    col[v] = val;
    for(auto to: gb[v]){
        if(col[to] == -1)
            dfs2(to, val);
    }
}
int main(){
    freopen("condense2.in", "r", stdin);
    freopen("condense2.out", "w", stdout);
    int n, m;

    cin >> n >> m;

    int from, to;
    for(int i = 0; i < m; ++i){
        cin >> from >> to;
        g[from].push_back(to);
        gb[to].push_back(from);
    }

    for(int i = 1; i <= n; ++i){
        if(!used[i])
            dfs(i);
    }

    int c = 1;

    for(int i = n - 1; i > 0; --i){
        if(col[top[i]] == -1)
            dfs2(top[i], c++);
    }
    for(int i = 1; i <= n; ++i){
        for(auto to: g[i]){
            if(col[to] != col[i]){
                pairs.insert({col[to], col[i]});
            }
        }
    }
    cout << pairs.size();
}
