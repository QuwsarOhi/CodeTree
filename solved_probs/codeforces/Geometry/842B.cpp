// Codeforces
// B. Gleb And Pizza
// http://codeforces.com/contest/842/problem/B
// Geometry

#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define INF 1e9+10
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define sf scanf
#define pf printf
#define ull unsigned long long
#define ll long long
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define msi map<string, int>
#define mii map<int, int>
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vii vector<pair<int, int> >
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);


struct point { 
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
};


double dist(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x)
                 + (p1.y - p2.y) * (p1.y - p2.y));
}


int main() {
	int r, d, n;
	double x, y, r1;
	sf("%d%d%d", &r, &d, &n);
	point p0;
	int cnt = 0;
	double mn = r-d;
	fr(i, 0, n) {
		sf("%lf%lf%lf", &x, &y, &r1);
		point p1(x, y);
		double dis = dist(p0, p1);
		double start = dis-r1;
		double End = dis+r1;
		if(End-EPS < (double)r) {
			if(mn - EPS < start) {
				++cnt;
			}
		}
	}
	pf("%d\n", cnt);
	return 0;
}
