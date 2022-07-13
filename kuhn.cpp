#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> gr;
vector<int> mt;
vector<char> used;

bool try_kuhn (int v) {
  if (used[v]) {
    return false;
  }
  used[v] = true;
  for (size_t i = 0; i < gr[v].size(); ++i) {
    int to = gr[v][i];
    if (mt[to] == -1 || try_kuhn (mt[to])) {
      mt[to] = v;
      mt[v] = to;
      return true;
    }
  }
  return false;
}

void find_matching(int first_part) {
  mt.assign(gr.size(), -1);
  for (int v = 0; v < first_part; ++v) {
    used.assign(gr.size(), false);
    try_kuhn(v);
  }
}

void find_matching_fast(int first_part) {
  mt.assign(gr.size(), -1);
  for (int run = 1; run;) {
    run = 0;
    used.assign(gr.size(), false);
    for (int v = 0; v < first_part; ++v) if (mt[v] == -1 && try_kuhn(v)) {
      run = 1;
    }
  }
}
