#include<bits/stdc++.h>

using namespace std;

vector<int> a;

void sort_insert () {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i; j > 0; --j) {
            if (a[j] > a[j - 1]) {
                break;
            }
            swap(a[j], a[j - 1]);
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
    sort_insert();
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}
