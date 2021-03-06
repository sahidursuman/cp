#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int par[N], ok[N];

int find(int u) {
  return par[u] = (par[u] == u? u : find(par[u]));
}

// true - digabung
bool merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) {
    if (ok[u]) {
      ok[u] = 0;
      return 1;
    } else {
      return 0;
    }
  } else {
    if (!ok[u] && !ok[v]) return 0;
    par[u] = v;
    ok[v] &= ok[u];
    return 1;
  }
}

int main() {
  for (int i = 0; i < N; i++) par[i] = i, ok[i] = 1;
  
  int n, m;
  scanf("%d %d", &n, &m);
  vector<tuple<int, int, int> > p;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    p.emplace_back(w, u, v);
  }
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  long long ans = 0;
  for (int i = 0; i < p.size(); i++) {
    int u, v, w;
    tie(w, u, v) = p[i];
    if (merge(u, v)) {
      ans += w;
    }
  }
  cout << ans << endl;
  return 0;
}
