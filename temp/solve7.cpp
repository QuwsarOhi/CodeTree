#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > u, v;

int main() {
	int t, l, r, m;
	scanf("%d", &t);
	bool ff = 1;

	while(t--) {
		scanf("%d", &m);

		while(1) {
			scanf("%d%d", &l, &r);
			if(l == 0 and r == 0)
				break;
			v.push_back({l, r});
		}

		sort(v.begin(), v.end());

		u.clear();
		for(int i = 0; i < v.size(); ++i) {
			if(u.empty()) {
				if(v[i].first <= 0)
					u.push_back(v[i]);
				else
					break;
			}

			if(v[i].first <= 0) {
				if(u.back().second < v[i].second) {
					u.pop_back();
					u.push_back(v[i]);
				}
			}

			if(u[i-2].second >= u[i].first and u[i].second >= u[i-1].second) {
				pair<int, int> t = u[i];
				u.pop_back(), u.pop_back();
				u.push_back(t);
			}
		}

		for(auto it : u)
			cout << it.first << ", " << it.second << endl;
		cout << endl;

		if(not ff)
			printf("\n");
		ff = 0;
		if(u.empty() or u.back().second < m)
			printf("0\n");
		else {
			printf("%d\n", (int)u.size());
			for(int i = 0; i < u.size(); ++i)
				printf("%d %d\n", u[i].first, u[i].second);
		}

		u.clear();
		v.clear();
	}

	return 0;
}