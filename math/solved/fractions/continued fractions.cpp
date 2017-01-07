//UVa
//834 - Continued Fractions
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

//to know how this code works
//check https://en.wikipedia.org/wiki/Continued_fraction

struct fraction {
    int a, b;
    fraction() {
        a = 1;
        b = 1;
    }
    fraction(int x, int y) : a(x), b(y) {}
    fraction operator - (fraction other) {
        fraction temp;
        temp.b = (b*other.b)/__gcd(b, other.b);
        temp.a = (temp.b/b)*a - (temp.b/other.b)*other.a;
        int x = __gcd(temp.a, temp.b);
        if(x != 1) {temp.a/=x; temp.b/=x;}
        return temp;
    }
};

int main()
{
    int a, b;
    float z;
    vector<int>vc;
    while(scanf(" %d %d", &a, &b)!= EOF) {
        if(a != 0 && b != 0) {              //as __gcd(0, 0) produces errors, check it manually
            int p = __gcd(a, b);
            if(p != 1) {a/=p; b/=p;}        //reducing the values if possible
        }
        fraction x(a, b);
        while(1) {
            if(x.b == 0) z = 0;
            else z = (float)x.a/(float)x.b + EPS;
            vc.push_back((int)z);
            if(x.b == 1 || x.b == 0 || x.a == x.b || x.a == 0) break;   //we check these types x/x or x/0 or 0/x or x (x/1)
            fraction y((int)z, 1);                                      //cause these are not rational number
            x = x - y;
            if(x.a < x.b) swap(x.a, x.b);
        }
        printf("[%d", vc[0]);
        if(vc.size() >= 2) {
            printf(";");
            for(size_t i = 1; i < vc.size(); i++) {
                if(i == vc.size()-1) printf("%d", vc[i]);
                else printf("%d,", vc[i]);
            }
        }
        printf("]\n");
        vc.clear();
    }
    return 0;
}
