//UVa
//10931 - Parity
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

using namespace std;

int main()
{
	ll x;
	unsigned int c, i;
	wh(sf("%lld", &x) && x)
	{
        bitset<50>t(x);
        c = t.count();
        string s = t.to_string(), y;
        bool f= false;
        for(i = 0; i < s.size(); i++)
        {
            if(!f && s[i] == '1')
            {
                f = true;
                y += s[i];
            }
            else if(f)
                y += s[i];
        }
        cout << "The parity of " << y <<  " is " << c << " (mod 2).\n";
	}
	return 0;
}
