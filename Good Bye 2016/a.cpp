#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int t = 240 - k;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (t >= i * 5) {
      t -= i * 5;
      ans = i;
    } else {
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
