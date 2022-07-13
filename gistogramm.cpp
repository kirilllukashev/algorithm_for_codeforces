#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;

    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> left(n);
    vector<int> right(n);

    stack<pair<int, int>> st_l;

    st_l.push({-(1e9 + 10), -1});

    for(int i = 0; i < n; ++i){
        while(st_l.top().first >= a[i]){
            st_l.pop();
        }
        left[i] = st_l.top().second;
        st_l.push({a[i], i});
    }

    stack<pair<int, int>> st_r;

    st_r.push({-(1e9 + 10), n});

    for(int i = n - 1; i > -1; --i){
        while(st_r.top().first >= a[i]){
            st_r.pop();
        }
        right[i] = st_r.top().second;
        st_r.push({a[i], i});
    }
    long long ans = 0;
    for(int i = 0; i < n; ++i){
        ans = max(ans, (long long)a[i] * (right[i] - left[i] - 1));
    }
    cout << ans;
}
