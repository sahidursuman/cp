#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int c[105], lo, hi;
char s[105];

int main(void)
{
	int i, n;
	sf("%s", s);
	n = strlen(s);
	FORS(i, n) {
		int low = s[i] - 'a';
		int high = s[i] - 'A';
		if(0 <= low && low <= 25)
			lo++, c[i] = low;
		else
			hi++, c[i] = high;
	}
	if(lo >= hi)
		FORS(i, n) pf("%c", c[i] + 'a');
	else
		FORS(i, n) pf("%c", c[i] + 'A');
	nl;
	return 0;
}
