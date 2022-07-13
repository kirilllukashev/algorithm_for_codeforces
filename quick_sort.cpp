#include<bits/stdc++.h>

using namespace std;

vector<int> a;

vector<int> quick_sort (vector<int> arr) {
    if (arr.size() < 2) {
        return arr;
    }
    int randm = rand() % arr.size();
    vector<int> l, r, m;
    for(int i = 0; i < arr.size(); ++i) {
        if (arr[i] < arr[randm]) {
            l.push_back(arr[i]);
        } else if (arr[i] > arr[randm]) {
            r.push_back(arr[i]);
        } else {
            m.push_back(arr[i]);
        }
    }
    l = quick_sort(l);
    r = quick_sort(r);
    vector<int> ans;
    for (int i = 0; i < l.size(); ++i) {
        ans.push_back(l[i]);
    }
    for (int i = 0; i < m.size(); ++i) {
        ans.push_back(m[i]);
    }
    for (int i = 0; i < r.size(); ++i) {
        ans.push_back(r[i]);
    }
    return ans;
}

int main(){
    int n, q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> q;
        a.push_back(q);
    }
    vector<int> ans;
    ans = quick_sort(a);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}


