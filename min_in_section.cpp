#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> st1;
    vector<pair<int, int>> st2;

    int q;

    cin >> q;

    st1.push_back({q, q});

    for (int i = 1; i < k; ++i) {
        cin >> q;
        st1.push_back({q, min(st1[st1.size() - 1].second, q)});
    }
    cout << st1[st1.size() - 1].second << endl;
    for (int i = k; i < n; ++i) {
        cin >> q;
        if (st2.size() == 0) {
            st2.push_back({st1[st1.size() - 1].first, st1[st1.size() - 1].first});
            st1.pop_back();
            while (st1.size() != 0) {
                st2.push_back({st1[st1.size() - 1].first, min(st2[st2.size() - 1].second, st1[st1.size() - 1].first)});
                st1.pop_back();
            }
        }
        st2.pop_back();
        if (st1.size() == 0) {
             st1.push_back({q, q});
        } else {
            st1.push_back({q, min(st1[st1.size() - 1].second, q)});
        }
        if (st1.size() == 0) {
            cout << st2[st1.size() - 1].second << endl;
        } else if (st2.size() == 0) {
            cout << st1[st1.size() - 1].second << endl;
        } else {
            cout << min(st2[st2.size() - 1].second, st1[st1.size() - 1].second) << endl;
        }
    }
}
