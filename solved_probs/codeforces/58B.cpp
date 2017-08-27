// CodeForces
// B. Coins
// http://codeforces.com/problemset/problem/58/B

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9;
#define INF 1e9
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define msi map<string, int>
#define mii map<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fSame(a, b) if(abs(a-b) < EPS) return 1
#define fBigEqual(a, b) if(a > b-EPS) return 1
#define fBig(a, b) if(a >= b+EPS) return 1


int main() {
	int n;
	scanf("%d", &n);
	
	while(n) {
		if(n == 1) {
			printf("1\n");
			break;
		}
		printf("%d ", n);
		for(int i = n-1; i >= 1; --i) {
			if(n%i == 0) {
				n = i;;
				break;
			}
		}
	}
	
	return 0;
}

