#include<bits/stdc++.h>

using namespace std;

int main () {
    int n, q;
    cin >> n;
    vector<int> cnt_pol(1e4 + 1, 0), cnt_otr(1e4 + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> q;
        if (q <= 0) {
            cnt_otr[abs(q)]++;
        } else {
            cnt_pol[abs(q)]++;
        }
    }
    vector<int> ans;
    for (int i = 1e4; i > -1; --i){
        while (cnt_otr[i] != 0) {
            ans.push_back(-i);
            cnt_otr[i]--;
        }
    }
    for (int i = 1; i < 1e4 + 1; ++i) {
        while (cnt_pol[i] != 0) {
            ans.push_back(i);
            cnt_pol[i]--;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}
