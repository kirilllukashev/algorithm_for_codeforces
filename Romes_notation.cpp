
#include<bits/stdc++.h>

using namespace std;

vector<int> val{ 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
vector<string> sym{ "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
char my_char = 'M';
int ans = 0;

void diff(int n) {
    string num = "";
    int q = sym.size() - 1;
    while(q > -1){
        while(n >= val[q]){
            n -= val[q];
            num += sym[q];
        }
        q--;
    }
    for(int x = 0; x < num.size(); ++x){
        if (num[x] == my_char) ans++;
    }
}

int main() {
    int l = 301, r = 400;
    for(int i = l; i <= r; ++i){
        diff(((i + i * i) / 2) % 2048);
    }
    cout << my_char << endl;
    cout << ans << endl;
}
