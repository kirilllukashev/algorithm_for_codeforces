#include<bits/stdc++.h>

using namespace std;

int dp[600][600];
int a[600];

int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            dp[j][i] = dp[j][i - 1] + 1;
            for(int q = j; q <= i; ++q){
                if(a[q] == a[i]){
                    dp[j][i] = min(dp[j][q - 1] + max(dp[q + 1][i - 1], 1), dp[j][i]);
                }
            }
        }
    }
    cout << dp[1][n];
}
