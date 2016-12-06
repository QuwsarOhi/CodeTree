//UVa
//11235 - Frequent values
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
#define N 100000

/*the inputs are
 * 10 4
 * -1 -1 1 1 1 1 3 10 10 10
 * 2 3
 * 1 10
 * 5 10 //crital divided into 5, 6 and 7, 10
 * 5 6 //critical the answer would be 6-5+1
 * we must check the starting of a query, if the query is intact or broken
 * -> if it is broken then we generate the value manually, and find the next segment with RMQ
 * -> if it is intact then we can run a RMQ
 * -> if the start and end query are of a same number(range of numbers, ex: 5 to 6), then
 *    we only need to generate the result manually
*/

using namespace std;

int arr[N], tree[4*N], end_point[N];

void segment_build(ll pos, ll L, ll R) 
{
	tree[pos] = 0;
	if(L==R) {
		tree[pos] = arr[L];
		return;
	}
	segment_build(pos*2, L, (L+R)/2);
	segment_build((pos*2)+1, (((L+R)/2)+1), R);
	tree[pos] = max(tree[pos*2], tree[pos*2+1]);
}

ll segment_query(ll pos, ll L, ll R, ll l, ll r)
{
	if(r < L || l > R)
		return 0;
	if(l <=L  && R <= r)
		return tree[pos];
	ll mid = (L+R)/2;
	ll x = segment_query((pos*2), L, mid, l, r);
	ll y = segment_query((pos*2)+1, mid+1, R, l, r);
	return max(x, y);
}

int main()
{
	ll a, b, x, y, s, temp1, q1, q2, ans;
	wh(sf("%lld", &a) && a) {
		sf("%lld", &b);
		memset(arr, 0, sizeof(arr));
		memset(end_point, 0, sizeof(end_point));
		memset(tree, 0, sizeof(tree));
		y = s = 0;
		fr(i, 1, a+1) {
			sf(" %lld", &x);
			if(x == y)
				arr[i] += arr[i-1]+1;
			else {
				arr[i] = 1;
				if(y != 0)
					end_point[i-1] = i-1;
			}
			y = x;
		}
		end_point[a] = a;
		for(ll i = a; i > 0; i--) {
			if(end_point[i] != 0)
				temp1 = end_point[i];
			end_point[i] = temp1;
		}
		segment_build(1 , 1, a);
		wh(b--) {
			sf("%lld %lld", &x, &y);
			temp1 = end_point[x];
			if(temp1 < y) {
				q1 = temp1 - x + 1;
				q2 = segment_query(1, 1, a, temp1+1, y);
				ans = max(q1, q2);
			}
			else if(end_point[x] >= y) {
				ans = y-x+1;
			}
			else
				ans = segment_query(1, 1, a, x, y);
			pf("%lld\n", ans);
		}
	}
	return 0;
}
