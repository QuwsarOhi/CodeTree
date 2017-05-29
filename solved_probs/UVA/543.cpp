//UVa
// 543 - Goldbach's Conjecture
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

bitset<1000010> bit;
void sieve()
{
    bit.set();
    bit[0] = bit[1] = 0;
    for(ll i = 2; i <= 1001; i++)
    {
        if(bit[i])
        {
            for(ll j = i*i; j <= 1000001; j += i)
            {
               // pf("%lld not prime\n", j);
                bit[j] = 0;
            }
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    ll n, a, b;
    sieve();
    //pf("6 is prime = %d\n", (int)bit[6]);
    //pf("7 is not prime = %d\n", (int)bit[7]);
    //pf("done\n");
    wh(sf("%lld", &n) && n)
    {
        a = b = 0;
        /*for(map<ll, int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            if(mp[n-it->first])
            {
                a = it->first;
                b = n-it->first;
                //pf("found %lld %lld\n", a, b);
                break;
            }
        }*/
        for(ll i = 0; i <= 1000000; i++)
        {
            if(bit[i])
                if(bit[n-i])
                {
                    a = i;
                    b = n - i;
                    break;
                }
        }
        if(a == 0 && b == 0)
            pf("Goldbach's conjecture is wrong.\n");
        else
            pf("%lld = %lld + %lld\n", n, min(a, b), max(a, b));
    }
    return 0;
}
