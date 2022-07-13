#include<bits/stdc++.h>

using namespace std;

vector<int> a;

void bubble_sort () {
    bool f = 1;
    while (f) {
        f = 0;
        for (int i = 0; i < a.size() - 1; ++i) {
            if(a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                f = 1;
            }
        }
        if(!f) break;
    }
}
int main () {
    int n;
    cin >> n;
    int q;
    for (int i = 0; i < n; ++i) {
        cin >> q;
        a.push_back(q);
    }
    bubble_sort();
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ' ';
    }
}
