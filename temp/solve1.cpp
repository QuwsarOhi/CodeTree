#include <bits/stdc++.h>
#define MAX 1000009
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<long long> vl;

set<ll>posSet;
ll a[MAX];

vl TRY(int p, int n) {
	posSet.clear();
	for(int i = 0; i < n; ++i)
		posSet.insert(i);

	auto it = posSet.begin();
	if(*it == p)
		++it;	
	ll lst = *it;
	vl ret;
	int itr = 0;

	while(posSet.size() > 2) {
		++it;
		if(it == posSet.end())
			it = posSet.begin();

		//cout << lst << " -> " << *it << " " << posSet.size() << endl;
		if(*it == p) {
			if(lst < p)
				ret.push_back(a[lst]);
			else
				ret.push_back(a[lst-1]);
			++it;
		}
		else {
			int tmp = *it;
			++it;
			posSet.erase(tmp);
		}

		// finding last
		while(it == posSet.end() or *it == p) {
			if(it == posSet.end())
				it = posSet.begin();
			else
				++it;
		}
		++itr;
		lst = *it;
	}

	//cerr << itr << endl;
	return ret;
}


int main() {
	ll t, n, f;
	cin >> t;

	while(t--) {
		cin >> n;

		for(int i = 0; i < n-1; ++i)
			cin >> a[i];
		cin >> f;

		ll mnHit = 1000000000000;
		int idx;
		bool found = 0;
		for(int i = 0; i < n; ++i) {
			int alive = i;
			if(i == n-1)
				alive = 0;

			if(a[alive] <= f) {
				vl hit = TRY(i, n);
				cout << i << " -> ";
				for(auto it : hit)
					cout << char(it+'a') << " ";
				cout << endl;
				/*if(hit < mnHit) {
					mnHit = hit;
					idx = i;
				}*/
				found = 1;
			}			
		}

		if(found) {
			cout << "possible\n";
			cout << idx+1 << " " << mnHit+f << "\n";
		}
		else
			cout << "impossible\n";
	}
   
    return 0;
}