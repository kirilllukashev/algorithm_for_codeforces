#include<bits/stdc++.h>

using namespace std;

vector<int> a;

void selection_sort () {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

int main(){
    int n, q;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> q;
        a.push_back(q);
    }
    selection_sort();
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}

