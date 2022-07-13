#include<bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,sse4")
//#pragma GCC optimize("unroll-loops")

#define int long long
#define pb push_back
#define fr first
#define sc second
#define _ << ' ' <<
#define pairs pair<int, int>

const int mod = 1e9 + 7;
const int MAXN = 1e6 + 2;
typedef long long ll;
typedef long double ld;

using namespace std;

struct Point{
    double x, y;
    Point (double a = 0, double b = 0)
    {
        x = a;
        y = b;
    }
    void Input(){
        cin >> x >> y;
    }
};

struct Vector{
    double x, y;
    Vector (const Point &a, const Point &b)
    {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    Vector operator + (const Vector &b)
    {
        return Vector(Point(0, 0), Point(x + b.x, y + b.y));
    }
    double operator ^ (const Vector &b)
    {
        return x * b.x + y * b.y;
    }
    double operator * (const Vector &b)
    {
        return x * b.y - y * b.x;
    }
    double length()
    {
        return sqrt((double)(x * x + y * y));
    }
};

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Point a, b, c, d;
    a.Input();
    b.Input();
    c.Input();
    Vector vec_1_a{a, b}, vec_2_a{a, c}, vec_3_a{a, d};
    Vector vec_1_b{b, a}, vec_2_b{b, c}, vec_3_b{b, d};
    Vector vec_1_c{c, a}, vec_2_c{c, b}, vec_3_c{c, d};
    if (vec_1_a * vec_2_a < 0) {
        swap(vec_1_a, vec_2_a);
    }
    if (vec_1_b * vec_2_b < 0) {
        swap(vec_1_b, vec_2_b);
    }
    if (vec_1_c * vec_2_c < 0) {
        swap(vec_1_c, vec_2_c);
    }
    if(vec_1_a * vec_3_a >= 0 && vec_2_a * vec_3_a <= 0 && vec_1_b * vec_3_b >= 0 && vec_2_b * vec_3_b <= 0 && vec_1_c * vec_3_c >= 0 && vec_2_c * vec_3_c <= 0) {
        cout << "987654321";
    } else {
        cout << (-1) * (int)a.x << ' ' << (-1) * (int)a.y << ' ' << (-1) * (int)b.x << ' ' << (-1) * (int)b.y << ' ' << (-1) * (int)c.x << ' ' << (-1) * (int)c.y << ' ';
    }
}

