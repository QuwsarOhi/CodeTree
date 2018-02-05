#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
set<pair<int, int>> noedges;
set<int> unvis;
int comp[200005], siz;
void go(int x, int c) {
	comp[x] = c;
	++siz;
	unvis.erase(x);
    cout << x << " -- " << c << endl; 
	int las = 0;
	while (!unvis.empty()) {
		auto it = unvis.lower_bound(las + 1);
		if (it == unvis.end()) break;
		las = *it;
		int y = *it;
		if (noedges.count({x, y})) {
			continue;
		}
		go(y, c);
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) unvis.insert(i);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		noedges.insert({x, y});
		noedges.insert({y, x});
	}
	vector<int> sizes;
	for (int i = 1; i <= n; ++i) {
		if (comp[i]) continue;
		siz = 0;
		go(i, i);
		sizes.push_back(siz);
	}
	sort(sizes.begin(), sizes.end());
	printf("%d\n", sizes.size());
	for (int s : sizes) printf("%d ", s);
}
