#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;

int t[MAXN * 4];
int a[MAXN];

const int inf = 1e9;

void build(int v, int l, int r) {
	if (l + 1 == r) {
		t[v] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(2 * v, l, m);
	build(2 * v + 1, m, r);
	//t[v] = t[2 * v] + t[2 * v + 1];
	t[v] = max(t[2 * v], t[2 * v + 1]);
}

void upd(int v, int l, int r, int pos, int x) {
	if (l + 1 == r) {
		t[v] = x;
		return;
	}
	int m = (l + r) / 2;
	if (pos < m) {
		upd(2 * v, l, m, pos, x);
	}
	else {
		upd(2 * v + 1, m, r, pos, x);
	}
	t[v] = t[2 * v] + t[2 * v + 1];
}

int get_sum(int v, int l, int r, int ql, int qr) {
	if (ql >= r || l >= qr) {
		return 0;
	}
	if (l >= ql && qr >= r) {
		return t[v];
	}
	int m = (l + r) / 2;
	return get_sum(2 * v, l, m, ql, qr) + get_sum(2 * v + 1, m, r, ql, qr);
}

int get_max(int v, int l, int r, int ql, int qr) {
    if (ql >= r || l >= qr) {
        return -inf;
    }
    if (l >= ql && qr >= r) {
        return t[v];
    }
    int m = (l + r) / 2;
    int a = get_max(2 * v, l, m, ql, qr);
    int b = get_max(2 * v + 1, m, r, ql, qr);
    return max(a, b);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int start = 1;
    while (start < n) start *= 2;

    build(1, 0, start);

    int m, l, r;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        l -= 1;
        cout << get_max(1, 0, start, l, r) << '\n';
    }

}
