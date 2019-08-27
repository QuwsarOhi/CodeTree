#include <bits/stdc++.h>
#define MAX 200009
#define MOD 1073741824
using namespace std;
typedef long long ll;

ll range(ll l, ll r) {
	x %= r;
	if(x == 0)
		x++;
	return x;
}

set< pair<ll, ll> > edge;
void tree(ll V, ll E) {
	while(E > 0) {
		ll u = range(1, V);
		ll v = range(1, V);

		if(edge.count({v, u}))
			continue;

		
	}
}

int main() {

}