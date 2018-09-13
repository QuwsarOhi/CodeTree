// UVa
// 10288 - Coupons

#include <bits/stdc++.h>
using namespace std;
#define MAX                 200010
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;


//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

struct fraction {                   // Fraction Calculation Template
    ll a, b;
    fraction() {
        a = 1;
        b = 1;
    }
    fraction(int x, int y) : a(x), b(y) {}
    void flip() {swap(a, b);}
    fraction operator + (fraction other) {
        fraction temp;
        temp.b = ((b)*(other.b))/(__gcd((b), other.b));
        temp.a = (temp.b/b)*a + (temp.b/other.b)*other.a;
        int x = __gcd(temp.a, temp.b);
        if(x != 1) {temp.a/=x; temp.b/=x;}
        return temp;
    }
    fraction operator - (fraction other) {
        fraction temp;
        temp.b = (b*other.b)/__gcd(b, other.b);
        temp.a = (temp.b/b)*a - (temp.b/other.b)*other.a;
        int x = __gcd(temp.a, temp.b);
        if(x != 1) {temp.a/=x; temp.b/=x;}
        return temp;
    }
    fraction operator / (fraction other) {
        fraction temp;
        temp.a = a*other.b;
        temp.b = b*other.a;
        int x = __gcd(temp.a, temp.b);
        if(x != 1) {temp.a/=x; temp.b/=x;}
        return temp;
    }
    fraction operator * (fraction other) {
        fraction temp;
        temp.a = a*other.a;
        temp.b = b*other.b;
        int x = __gcd(temp.a, temp.b);
        if(x != 1) {temp.a/=x; temp.b/=x;}
        return temp;
}};



int main() {
	int n;
	while(sf("%d", &n) == 1) {
		fraction ans = fraction(1, 1);
		for(int i = 2; i <= n; ++i) {
			fraction x = fraction(n, n-i+1);
			//cerr << ans.a << "/" << ans.b << " * " << x.a << "/" << x.b << endl;
			ans = ans + x;
		}
		ll a = ans.a/ans.b;
		ll b = ans.a%ans.b;
		ll c = ans.b;
		
		
		int len = max(floor(log10(b))+1, floor(log10(c))+1);
		
		if(c == 1)
			pf("%ld\n", ans.a);
		else {
			int alen = floor(log10(a))+2;
			for(int i = 0; i < alen; ++i) pf(" ");
			pf("%lld\n", b);
			pf("%lld ", a);
			while(len--) pf("-");
			pf("\n");
			for(int i = 0; i < alen; ++i) pf(" ");
			pf("%lld\n", c);
		}
	}
	return 0;
}
			
