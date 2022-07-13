#include<bits/stdc++.h>

using namespace std;

struct edge{
    int from, to, cost;
};

const int INF = 1e9;

signed main(){
    int n, w;

    cin >> n;

    vector <edge> e;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> w;

            if(w != 1e9){
                e.push_back({i, j, w});
            }
        }
    }

    vector<int> d(n + 1, 0), p(n + 1, -1);

    int x = -1;

    for(int i = 0; i < n; i++){
        x = -1;
        for(int j = 0; j < e.size(); j++){
            int from = e[j].from;
            int to = e[j].to;
            int cost = e[j].cost;
            if(d[to] > d[from] + cost){
                d[to] = max(d[from] + cost, -INF);
                p[to] = from;
                x = to;
            }
        }
    }
    if(x == -1){
        cout << "NO\n";
        return 0;
    }

    int y = x;

    for(int i = 0; i < n; i++){
        y = p[y];
    }

    cout << "YES\n";

    vector <int> path;

    path.push_back(y);

    int cur = p[y];

    while(cur != y)
    {
        path.push_back(cur);
        cur = p[cur];
    }

    path.push_back(y);

    reverse(path.begin(), path.end());
    cout << path.size() << endl;

    for (int tmp : path)
        cout << tmp + 1 << " ";
}
