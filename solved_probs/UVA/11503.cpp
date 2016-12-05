//UVa
//11503 - Virtual Friends
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
#define N 200000

using namespace std;

ll u_set[N+100], u_list[N+100];
//u_set is used to determine set
//u_list is used to keep track of the nodes that each node connects (as a root)

inline ll root(ll n) //finding the root of a set
{
	if(u_set[n] == n)
		return n;
	else
		return u_set[n] = root(u_set[n]); //path compression is also done
}

inline ll make_union(ll a, ll b) //make union of set, returns the value of
{								 //the new root
	ll x = root(a);
	ll y = root(b);
	if(x == y)                   //returns the same value if the input two
		return x;				 //value is same
	else if(u_list[x] > u_list[y]) {
		u_set[y] = x;
		u_list[x] += u_list[y];
		return x;
	}
	else {
		u_set[x] = y;
		u_list[y] += u_list[x];
		return y;
	}
}

void union_init(ll l)  //initialising of set and list
{
	for(ll i = 0; i <= l; i++) {
		u_list[i] = 1;
		u_set[i] = i;
	}
}

int main()
{
	ll x, p, t, k;
	char n1[30], n2[30];
	sf("%lld", &t);
	wh(t--) {
		union_init(N);
		x = 0;
		map<string, ll>m;
		sf(" %lld", &p);
		wh(p--) {
			sf(" %s %s", n1, n2);
			string n3 = string(n1), n4 = string(n2);
			if(m.find(n3) == m.end())
				m[n3] = x++;
			if(m.find(n4) == m.end())
				m[n4] = x++;
			k = make_union(m[n3], m[n4]);
			pf("%lld\n", u_list[k]);
		}
	}
	return 0;
}
