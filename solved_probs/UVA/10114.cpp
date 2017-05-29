//UVa
//10114 - Loansome Car Buyer
#include <bits/stdc++.h>
#define pb push_back
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

using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    double dp, p, x, tmp, worth;
    ll a, m, r, i, past;
    wh(sf("%lld %lf %lf %lld", &m, &dp, &p, &r) && m > 0) {
        queue<pair<ll, double> >v;
        bool found = 0;
        wh(r--) {
            sf("%lld %lf", &a, &x);
            v.push(make_pair(a, x));
        }
        worth = dp + p;
        dp = p / m;
        //cout << "initial worth : " << worth << endl;
        //cout << "installment " << dp << endl;
        for(i = 0; i <= m; i++) {
            //cout << "month " << i << endl;
            if(!v.empty())
                if(v.front().first == i) {
                    past = i;
                    tmp = v.front().second;
                    //cout << tmp << endl;
                    v.pop();
                }
            //cout << "front " <<v.front().first << endl;
            //cout << "temp is : " << tmp << endl;
            //if(past != 0 || i == 0)
            worth -= worth*tmp;
            if(i != 0) p -= dp;
            //pf("%lf  %lf\n", worth, p);
            if(worth > p) {
                if(i == 1) pf("%lld month\n", i);
                else pf("%lld months\n", i);
                found = 1;
                //cout << worth << " " << p << endl;
                break;
            }
        }
        if(!found) pf("%lld months\n", --i);
    }
    return 0;
}
