#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a, b;
  scanf("%d %d %d", &n, &a, &b);
  if ((b - a) % 2) {
    puts("Borys");
  } else {
    puts("Alice");
  }
  return 0;
}