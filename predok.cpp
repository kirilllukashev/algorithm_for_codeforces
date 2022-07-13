#include<bits/stdc++.h>
/*
6
0 1 1 2 3 3
5
4 1
1 4
3 6
2 6
6 5
*/
using namespace std;

const int MAXN = 1000001;
vector<vector<int>> g(MAXN);
vector<int> used(MAXN, 0), tin(MAXN), tout(MAXN);
int n;
int time_s = 1;
void dfs(int v){
    used[v] = 1;
    tin[v] = time_s;
    time_s++;
    for(auto to: g[v]){
        if(used[to] == 0){
            dfs(to);
        }
    }
    tout[v] = time_s;
    time_s++;
}
int main(){
    //freopen("ancestor.in", "r", stdin);
    //freopen("ancestor.out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    int q;
    int root;
    for(int i = 0; i < n; ++i){
        cin >> q;
        if(q == 0){
            root = i;
        }
        else{
            g[q - 1].push_back(i);
        }
    }
    dfs(root);
    int m;
    cin >> m;
    int a, b;
    for(int i = 0; i < m; ++i){
            cin >> a >> b;
            a--;
            b--;
            if(tin[a] < tin[b] && tout[a] > tout[b]){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
    }
}

