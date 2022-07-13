#include<bits/stdc++.h>

using namespace std;


int main(){
    long double x1, y1, r1, x2, y2, r2;

    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

    long double len = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    long double pi = acos(-1);
    long double ans;
    if(len >= r1 + r2) ans = 0;
    else if(len + r1 <= r2 || len + r2 <= r1){
        long double mn = min(r1, r2);
        ans = mn * mn * pi;
    }
    else{
        long double angle1 = acos((r1 * r1 - r2 * r2 + len * len) / (2 * r1 * len)) * 2;
        long double angle2 = acos((r2 * r2 - r1 * r1 + len * len) / (2 * r2 * len)) * 2;
        ans = (r1 * r1 * angle1) / 2 + (r2 * r2 * angle2) / 2 - (r1 * r1 * sin(angle1)) / 2 - (r2 * r2 * sin(angle2)) / 2;
    }
    cout << fixed << setprecision(10);
    cout << ans;
}
