#include<bits/stdc++.h>
#include <typeinfo>

#define int long long
#define pb push_back
#define fr first
#define sc second

typedef long long ll;
typedef long double ld;

const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 1;
const int INF = 1e9;

using namespace std;

long long p = 101;

int hash_val(vector<int>& a, int MOD, int p) {
    int val = 0;
    for (auto x: a) {
        val = (val * p % MOD + x) % MOD;
    }
    return val;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifdef RATEL
    freopen("input.txt", "r", stdin);
#endif
    vector<int> MOD = {(int)(1e9 + 7), (int)(1e9 + 9), (int)(1e9 + 31), (int)(1e9 + 37), (int)(1e9 + 123)};
    vector<int> P = {101, 103, 107, 109, 113};
    int k, n, m;
    cin >> k >> n >> m;
    vector<vector<vector<int>>> now(n, vector<vector<int>>(m));
    for (int x = 1; x <= k; ++x) {
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j) {
                if (s[j] == '*') {
                    now[i][j].pb(x);
                }
            }
        }
    }
    vector<set<pair<int, int>>> comp(5);
    for (int x = 0; x < 5; ++x) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = hash_val(now[i][j], MOD[x], P[x]);
                int quan = now[i][j].size();
                comp[x].insert({val, quan});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 5; ++i) {
        ans = max(ans, (int)comp[i].size());
    }
    cout << ans;
}
