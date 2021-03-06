#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const long long mod = 1e9 + 7;

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) tmp = tmp * a % mod;
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

int p[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", p + i);
  sort(p, p + n);
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    int a = i;
    int b = n - a;
    long long val = p[i] - p[i - 1];
    long long cur = (power(2, a) - 1 + mod) % mod;
    cur = cur * (power(2, b) - 1) % mod;
    ans += cur * val;
    ans %= mod;
  }
  if (ans < 0) ans += mod;
  cout << ans << endl;
  return 0;
}
