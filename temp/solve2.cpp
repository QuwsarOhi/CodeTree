#include <bits/stdc++.h>
#define MAX 300011
#define INF 0x3f3f3f3f
#define MOD 1000000007
using namespace std;
typedef long long int ll;

string s1, s2;
ll cnt[2][2];
set<int> pos[2][2];

int main() {
	ll n, miss = 0;
	cin >> n >> s1 >> s2;


	for(int i = 0; i < n; ++i) {
		int p = s1[i] - 'a';
		int q = s2[i] - 'a';

		cnt[0][p]++;
		cnt[1][q]++;

		if(p != q) {
			pos[0][p].insert(i+1);
			pos[1][q].insert(i+1);
			++miss;
		}
	}

	if(((cnt[0][0]+cnt[1][0]) % 2 != 0) or ((cnt[0][1] + cnt[1][1]) % 2 != 0) or (miss%2 != 0)) {
		cout << -1 << endl;
		return 0;
	}

	ll tot = miss/2;

		for(int p = 0; p < 2; ++p) {
			for(int q = 0; q < 2; ++ q) {
				cerr << p << q << ": ";
				for(auto it : pos[p][q])
					cerr << it << " ";
				cerr << endl;
			}
		}

	cout << tot << endl;
	for(int i = 0; ; ++i) {
		//cerr << i << endl;
		if(pos[0][0].size() > 0) {
			//cerr << "HERE1\n";
			auto it1 = pos[0][0].begin();
			ll a = *it1;
			ll b = -1;

			if(pos[1][1].size() > 1) {
				pos[0][0].erase(a);
				pos[1][1].erase(a);
				
				auto it2 = pos[1][1].begin();
				b = *it2;
				pos[1][1].erase(b);
				pos[0][0].erase(b);
			}
			else {
				pos[0][1].insert(a);
				pos[0][0].erase(a);
				pos[1][1].erase(a);
				pos[1][0].insert(a);
				b = a;
			}
			//cerr << s1[a-1] << " " << s2[b-1] << endl;
			cout << a << " " << b << "\n";
		}
		else if(pos[0][1].size() > 0) {
			//cerr << "HERE\n";
			auto it1 = pos[0][1].begin();
			ll a = *it1;
			ll b = -1;

			if(pos[1][0].size() > 1) {
				pos[0][1].erase(a);
				pos[1][0].erase(a);

				auto it2 = pos[1][0].begin();
				b = *it2;

				pos[1][0].erase(b);
				pos[0][1].erase(b);
			} else {
				pos[0][1].erase(a);
				pos[0][0].insert(a);
				pos[1][1].insert(a);
				pos[1][0].erase(a);
				b = a;
			}
			cout << a << " " << b << "\n";
		}
		else
			break;

		/*for(int p = 0; p < 2; ++p) {
			for(int q = 0; q < 2; ++ q) {
				cerr << p << q << ": ";
				for(auto it : pos[p][q])
					cerr << it << " ";
				cerr << endl;
			}
		}*/
	}

	return 0;
}