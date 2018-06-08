
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define ss stringstream
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define vec vector<int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long
#define ld long double
#define ui unsigned int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pair<int, int> >
#define vvi vector<vector<int> >
#define N 2147483648
#define EPS 1e-9
#define ri register int
#define arrsize(x) sizeof(x)/(sizeof(x[0]))
#define ull unsigned long long
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

struct fraction {
    int a, b;
    fraction() {
        a = 1;
        b = 1;
    }
    fraction(int x, int y) : a(x), b(y) {}
    flip() {swap(a, b);}
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
    }
};

int main()
{

}
