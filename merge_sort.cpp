#include<bits/stdc++.h>
using namespace std;
long long answer = 0;
vector<int> mergesort(vector<int> a){
    if(a.size() == 1){
        return a;
    }
    int m = a.size() / 2;
    vector<int> l_1;
    for(int i = 0; i < m; ++i){
        l_1.push_back(a[i]);
    }
    vector <int> l = mergesort(l_1);
    vector<int> r_1;
    for(int i = m; i < a.size(); ++i){
        r_1.push_back(a[i]);
    }
    vector <int> r = mergesort(r_1);
    int i = 0, j = 0;
    vector<int> ans;
    while(i != l.size() && j != r.size()){
        if(l[i] > r[j]){
            ans.push_back(r[j]);
            j += 1;
            answer += l.size() - i;
        }
        else{
            ans.push_back(l[i]);
            i += 1;
        }
    }
    if(i == l.size()){
        while(j != r.size()){
                ans.push_back(r[j]);
                j += 1;
        }
    }
    else{
        while(i != l.size()){
            ans.push_back(l[i]);
            i += 1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> a;
    int val;
    for(int i = 0; i < n; ++i){
        cin >> val;
        a.push_back(val);
    }
    vector<int> ans;
    ans = mergesort(a);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}
