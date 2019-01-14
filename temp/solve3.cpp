#include <bits/stdc++.h>
using namespace std;
#define MAX                 510000
#define EPS                 1e-9
#define INF                 0x3f3f3f3f
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define xx                  first
#define yy                  second
#define PI                  acos(-1)
#define pf                  printf
#define sf(XX)              scanf("%lld", &XX)
#define SIZE(a)             ((ll)a.size())
#define ALL(S)              S.begin(), S.end()              
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define FastIO              ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FileRead(S)         freopen(S, "r", stdin);
#define FileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define STOLL(X)            stoll(X, 0, 0)

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
typedef vector<ll>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------

double n, r;

double getAngle(double AB, double BC, double CA) {      // Returns the angle(IN RADIAN) opposide of side CA
    return acos((AB*AB + BC*BC - CA*CA)/(2.0*AB*BC));
}

double RAD_to_DEG(double rad) {
    return (180.0/PI)*rad;
}

double Check(double R) {
    double a = r+R;
    double b = R;
    double c = sqrt(a*a + b*b);
    double theta = RAD_to_DEG(getAngle(a, c, b));

    return theta*n*2.0;
}


int main() {
    scanf("%lf%lf", &n, &r);
    cerr << Check(6.4641016) << endl;

    double lo = 0, hi = 100, mid, ans;

    for(int i = 0; i < 100; ++i) {
        mid = (lo+hi)/2.0;
        printf("%.2lf : %.6lf\n", mid, Check(mid));

        if(Check(mid) > 360.0)
            hi = mid;
        else
            lo = mid;
    }

    printf("%.6lf\n", mid);
    return 0;
}