#include <bits/stdc++.h>
#define INF 1e17
using namespace std;
typedef long long ll;

ll a[500], ans = INF, n;

set<int> s;
pair<int, int> getLR(int v) {
	auto it = s.find(v);
	auto it2 = it;
	pair<int, int> ret;

	if(it == s.begin())
		ret.first = *(--s.end());
	else
		ret.first = *(--it2);
	it++;

	if(it == s.end())
		ret.second = *s.begin();
	else
		ret.second = *it;

	return ret;
}


void recur(int vals, ll tot) {
	//cout << vals << " " << tot << endl;
	if(tot > ans)
		return;

	if(vals == 1) {
		ans = min(ans, tot);
		return;
	}

	for(int p = 0; p < n; ++p) {
		if(s.count(p)) {
			pair<int, int> x = getLR(p);
			ll v0 = a[x.first], v1 = a[p], v2 = a[x.second];
			s.erase(x.first);
			a[p] = v0 + v1;
			recur(vals-1, tot + v0 + v1);
			s.insert(x.first);
			s.erase(x.second);
			a[p] = v1 + v2;
			recur(vals-1, tot + v1 + v2);
			a[p] = v1;
			s.insert(x.second);
		}
	}
}


int main() {
	int t;
	cin >> t;

	while(t--) {
		cin >> n;

		for(int i = 0; i < n; ++i)
			cin >> a[i];

		s.clear();
		for(int i = 0; i < n; ++i)
			s.insert(i);

		ans = INF;
		recur(n, 0);
		cout << ans << endl;
	}

	return 0;
}