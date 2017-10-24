// 1018 - Brush (IV) 
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	int t, n, x, y;
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		vector<pair<int, int> >v;
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &x, &y);
			v.push_back(make_pair(x, y));
		}
		int cnt = 0;
		while(!v.empty()) {
			//cout << "Start" << endl;
			int mx = 0, p = -1, val;
			vector<pair<int, int> > :: iterator it1;
			map<int, set<pair<int, int> > >mp[4];
			//map<int, pair<int, set<pair<int, int> > > >:: iterator itmp;
			for(it1 = v.begin(); it1 != v.end(); ++it1) {
				//cout << "Pb" << endl;
				mp[0][it1->first].insert(make_pair(it1->first, it1->second));
				
				mp[1][it1->second].insert(make_pair(it1->first, it1->second));
				
				mp[2][it1->second + it1->first].insert(make_pair(it1->first, it1->second));
				
				mp[3][abs(it1->first)-abs(it1->second)].insert(make_pair(it1->first, it1->second));
				
				if((int)mp[0][it1->first].size() > mx) {
					val = it1->first;
					p = 0;
					mx = (int)mp[0][it1->first].size();
				}
				else if((int)mp[1][it1->second].size() > mx) {
					val = it1->second;
					p = 1;
					mx = (int)mp[1][it1->second].size();
				}
				else if((int)mp[2][it1->second + it1->first].size() > mx) {
					val = it1->second + it1->first;
					p = 2;
					mx = (int)mp[2][it1->second + it1->first].size();
				}
				else if((int)mp[3][abs(it1->first)-abs(it1->second)].size() > mx) {
					val = abs(it1->first)-abs(it1->second);
					p = 3;
					mx = (int)mp[3][abs(it1->first)-abs(it1->second)].size();
				}
			}
			//cout << "Done\n";
			set<pair<int, int> > st(mp[p][val]);
			for(set<pair<int, int> >::iterator it = st.begin(); it != st.end(); ++it) {
				v.erase(find(v.begin(), v.end(), make_pair(it->first, it->second)));
			}
			++cnt;
		}
		
		printf("Case %d: %d\n", Case, cnt);
	}
	
	return 0;
}
