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
const int MAXN = 50;
const int INF = 1e9;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#endif

void solve() {
    int n, p;
    cin >> n >> p;
    p += 1;
    vector<vector<int>> dp(2 * n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i - 1 >= 0) {
                if (j - 1 >= 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                if (j + 1 <= n) {
                    dp[i][j] += dp[i - 1][j + 1];
                }
            }
        }
    }
    /*for (int i = 0; i <= 2 * n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }*/
    if (p - dp[2 * n][0] > 0) {
        cout << "N/A";
        return;
    }
    int depth = 0;
    string ans = "";
    for (int i = 2 * n - 1; i >= 0; --i) {
        if (depth + 1 <= n && dp[i][depth + 1] >= p) {
            ans += '(';
            depth++;
        } else {
            ans += ')';
            if (depth + 1 <= n) {
                p -= dp[i][depth + 1];
            }
            --depth;
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("parens.in", "r", stdin);
    //freopen("parens.out", "w", stdout);
#ifdef RATEL
    freopen("input.txt", "r", stdin);
#endif
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
