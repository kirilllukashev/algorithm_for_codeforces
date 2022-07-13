#include<bits/stdc++.h>

//#pragma GCC optimize("O3")
//#pragma GCC target("sse4")

#define int long long
#define pb push_back
#define f first
#define s second
#define _ << ' ' <<
#define pairs pair<int, int>

const int mod = 1e9 + 7;

typedef long long ll;
typedef long double ld;

using namespace std;

int n;
const int maxn = 1e6;
vector<int> b(maxn, 0);

int prv(int i){
    return (i & (i + 1)) - 1;
}

int nxt(int i){
    return (i | (i + 1));
}

int query(int k){
    int ans = 0;
    for(int i = k; i >= 0; i = prv(i)) ans += b[i];
    return ans;
}

void upd(int s, int val){
    for(int i = s; i < n; i = nxt(i)){
        b[i] += val;
    }
}

bool sorting(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
void solve(){
    cin >> n;
    int x, y;
    vector<int> ans(n);
    vector<vector<int>> vals(n);

    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        vals[i] = {-x, y, i};
    }
    sort(vals.begin(), vals.end(), sorting);

    for(int i = 0; i < n; ++i){
        vals[i][1] = i;
    }
    sort(vals.begin(), vals.end());

    for(int i = 0; i < n; ++i){
        ans[vals[i][2]] = query(vals[i][1]);
        upd(vals[i][1], 1);
    }
    for(auto x: ans) cout << x << '\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
