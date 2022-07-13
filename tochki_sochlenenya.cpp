#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define pb push_back
#define fr first
#define sc second

using namespace std;
using namespace __gnu_pbds;

typedef pair<int, int> node;
typedef tree<node, null_type, less<node>,
        rb_tree_tag, tree_order_statistics_node_update> ordered_set;
//find_by_order(q) - q largest, order_of_key(num) - quantity of elements which are less

typedef long long ll;
typedef long double ld;

const int MOD = 1e9 + 9;
const int MAXN = 2e4 + 10;
const int INF = 1e9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#endif

vector<vector<int>> g(MAXN);
vector<int> used(MAXN), d(MAXN), h(MAXN);
set<int> ans;

void dfs(int v, int p = -1) {
    used[v] = 1;
    d[v] = h[v] = (p == -1 ? 0 : h[p] + 1);
    int cnt = 0;
    for (int u : g[v]) {
        if (u != p) {
            if (used[u])
                d[v] = min(d[v], h[u]);
            else {
                dfs(u, v);
                d[v] = min(d[v], d[u]);
                if (h[v] <= d[u] && p != -1) {
                    ans.insert(v);
                }
                cnt++;
            }
        }
    }
    if (p == -1 && cnt > 1) {
        ans.insert(v);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int s, f;
        cin >> s >> f;
        g[s].pb(f);
        g[f].pb(s);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(i, -1);
        }
    }
    cout << ans.size() << '\n';
    for (auto x: ans) {
        cout << x << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifdef RATEL
    freopen("input.txt", "r", stdin);
#endif
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
