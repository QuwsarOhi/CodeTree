// UVa
// 11219 - How old are you?
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

ll age(ll y1, ll m1, ll d1, ll y2, ll m2, ll d2) {		// Today, Birthday
	ll t1 = y1*10000+m1*100+d1;
	ll t2 = y2*10000+m2*100+d2;
	ll age = t1 - t2;
	pf("%lld\n", age);
	if(age < 0) return -1;
	return age/10000;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int d1, d2, m1, m2, y1, y2, t;
    ll t1;
    sf(" %d", &t);
    for(int c = 1; c<=t; c++){
        scanf(" %d/%d/%d", &d1, &m1, &y1);
        scanf(" %d/%d/%d", &d2, &m2, &y2);
        t1 = age(y1, m1, d1, y2, m2, d2);
        if(t1 < 0)
            pf("Case #%d: Invalid birth date\n", c);
        else if(t1 > 130)
            pf("Case #%d: Check birth date\n", c);
        else
            pf("Case #%d: %lld\n", c, t1);
    }
    return 0;
}
