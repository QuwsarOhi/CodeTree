//UVa
//498 - Polly the Polynomial
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define fr(i, a, b) for(register int i = a; i < b; i++)
#define f1(i, b) for(register int i = 1; i <= b; i++)
#define mimx(a, b) if(a > b)swap(a, b)
#define msi map<string, int>
#define mii map<int, int>
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define sf scanf
#define pf printf
#define wh while
#define inf std::numeric_limits<int>::max()
#define ll long long
#define ui unsigned int
#define vi vector<int>
#define ii pair<int, int>
#define iii pair<ii, int>
#define vii vector<pair<int, int> >
#define ull unsigned long long
#define N 50000
#define ri register int
#define arrsize(x) sizeof(x)/(sizeof(x[0]))
#define ull unsigned long long
#define frein freopen("in", "r", stdin);
#define freout freopen("out", "w", stdout);

using namespace std;

int co_efficient[1000];

long long horner(int x, int n)
{
    long long ans = co_efficient[0];
    for(int i = 1; i < n; i++) {
        ans = ans*x + co_efficient[i];
    }
    return ans;
}

int main()
{
    char a[10000];
    int n, x, c;
    vector<long long>v;
    while(scanf(" %[^\n]", a) != EOF) {
        stringstream ss;
        ss << a;
        n = 0;
        memset(co_efficient, 0, sizeof(co_efficient));
        while(ss >> c){
            co_efficient[n] = c;
            n++;
        }
        scanf(" %[^\n]", a);
        stringstream s1;
        s1 << a;
        while(s1 >> x) {
            v.push_back(horner(x, n));  //running horner method to n times, as we have n co-efficients
        }                               //so the rest result will produce only zeros, which we are avoiding here to optimize
        for(size_t i = 0; i < v.size(); i++) {
            if(i == v.size()-1) printf("%lld\n", v[i]);
            else printf("%lld ", v[i]);
        }
        v.clear();
    }
    return 0;
}
