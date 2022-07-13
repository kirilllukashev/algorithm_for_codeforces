#include<bits/stdc++.h>

using namespace std;

vector<long long> hashs(100010, 0), powp(100010, 1);
long long p = 31, mod = 1e9 + 7;

int get_hash(int l, int r){
    return (hashs[r] - hashs[l - 1] * powp[r - l + 1] % mod + mod) % mod;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;

    for(int i = 1; i < s.size() + 1; ++i){
        powp[i] = powp[i - 1] * p % mod;
    }

    for(int i = 0; i < s.size(); ++i){
        hashs[i + 1] = (hashs[i] * p % mod + (s[i] - 'a' + 1)) % mod;
    }

    int q;
    cin >> q;

    int l1, r1, l2, r2;

    for(int i = 0; i < q; ++i){
        cin >> l1 >> r1 >> l2 >> r2;
        if(get_hash(l1, r1) == get_hash(l2, r2) && r1 - l1 == r2 - l2){
            cout << '+';
        }
        else{
            cout << '-';
        }
    }
}
