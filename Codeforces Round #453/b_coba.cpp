/*

I will leave my heart at the door
I won't say a word
They've all been said before, you know
So why don't we just play pretend
Like we're not scared of what is coming next
Or scared of having nothing left

Look, don't get me wrong
I know there is no tomorrow

All I ask is if this is my last night with you
Hold me like I'm more than just a friend
Give me a memory I can use
Take me by the hand while we do what lovers do
It matters how this ends
'Cause what if I never love again?

I don't need your honesty
It's already in your eyes
And I'm sure my eyes, they speak for me
No one knows me like you do
And since you're the only one that matters
Tell me who do I run to?

Let this be our lesson in love
Let this be the way we remember us
I don't wanna be cruel or vicious
And I ain't asking for forgiveness

All I ask is if this is my last night with you
Hold me like I'm more than just a friend
Give me a memory I can use
Take me by the hand while we do what lovers do
It matters how this ends
'Cause what if I never love again? 

*/

#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;

int n;

int power(int a, int b) {
  if (b == 0) return 1;
  return a * power(a, b - 1);
}

bool bad;

vector<double> mod(vector<double> a, vector<double> b) {
  /*
  puts("A");
  for (auto it : a) printf("%.2f ", it); printf("\n");
  for (auto it : b) printf("%.2f ", it); printf("\n\n");
  */
  double tb = a.back() / b.back();
  for (int i = 0; i < b.size(); i++) a[i+1] -= tb * b[i];
  /*
  puts("B");
  for (auto it : a) printf("%.2f ", it); printf("\n");
  for (auto it : b) printf("%.2f ", it); printf("\n\n");
  */
  tb = a[a.size() - 2] / b.back();
  for (int i = 0; i < b.size(); i++) a[i] -= tb * b[i];
  assert(fabs(a.back()) < eps && fabs(a[a.size() - 2]) < eps);
  vector<double> ret;
  for (int i = 0; i < (int) a.size() - 2; i++) ret.push_back(a[i]);
  if (ret.size() && fabs(ret.back()) < eps) bad = 1;
  return ret;
}

int main() {
  for (n = 1; n <= 150; n++) {
    int til_a = power(3, n + 1);
    int til_b = power(3, n);
    for (int i = 0; i < til_b; i++) {
      vector<int> ob;
      int now = i;
      for (int k = 0; k < n; k++) {
        ob.push_back(now % 3 - 1);
        now /= 3;
      }
      if (ob.back() != 1) continue;
      for (int j = 0; j < til_a; j++) {
        vector<int> oa;
        now = j;
        for (int k = 0; k <= n; k++) {
          oa.push_back(now % 3 - 1);
          now /= 3;
        }
        if (oa.back() != 1) continue;
        
        //printf("iter %d %d %d\n", n, i,  j);
        
        bool ok = 1;
        vector<double> a;
        for (auto it : oa) a.push_back(it);
        vector<double> b;
        for (auto it : ob) b.push_back(it);
        for (int k = 0; k < n; k++) {
          bad = 0;
          vector<double> be = mod(a, b);
          a = b;
          b = be;
          //puts("bagi kelar");
          if (bad) {
            ok = 0;
            break;
          }
        }
        if (ok) {
          printf("digit %d\n", n);
          for (auto it : oa) printf("%d ", it); printf("\n");
          for (auto it : ob) printf("%d ", it); printf("\n");
          printf("\n");
          goto NEXT;
        }
      }
    }
    NEXT:;
  }

  return 0;
}
