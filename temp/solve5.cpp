#include <bits/stdc++.h>
#define MAX 301000
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;

struct BIT {
    ll tree[2*MAX][3];
    int MaxVal;
    BIT() {
    	memset(tree, 0, sizeof tree);
    }
    void update(int idx, int pos, ll val = 1) {
        for( ;idx <= MaxVal; idx += (idx & -idx))
            tree[idx][pos] += val;
    }
    ll read(int idx, int pos) {
        ll sum = 0;
        for( ;idx > 0; idx -= (idx & -idx))
            sum += tree[idx][pos];
        return sum;
    }
	// Modified BIT, this section can be used to add/remove/read 1 to all elements from 1 to pos
    // all of the inverse functions must be used, for any manipulation
    ll invRead(int idx, int pos) {           // gives summation from 1 to idx
        return read(MaxVal-idx, pos);
    }
    void invUpdate(int idx, int pos, ll val = 1) {
        update(MaxVal-idx, pos, val);
}};


BIT ft, ftr;
string s;

int main() {
	int n;
	cin >> n;
	cin >> s;

	ft.MaxVal = s.size()+20;
	ftr.MaxVal = (s.size()+20)*2;

	for(int i = 0; i < n; ++i)
		ft.update(i+1, s[i]-'0');

	int tot = n/3;

	// 2 -> 0, 1
	for(int i = 0; i < n; ++i) {
		if(s[i] == '2' and ft.read(ft.MaxVal, 2) > tot) {
			//cerr << i << " 2* " << s[i] << " " << ft.read(ft.MaxVal, 2) << endl;

			if(ft.read(ft.MaxVal, 0) < tot) {
				s[i] = '0';
				ft.update(i+1, 0);
				
			}
			else {
				s[i] = '1';
				ft.update(i+1, 1);
			}
			ft.update(i+1, 2, -1);
		}
	}

	// 1 -> 0
	for(int i = 0; i < n; ++i) {
		if(s[i] == '1' and ft.read(ft.MaxVal, 1) > tot) {
			//cerr << i << " 1* " << s[i] << " " << ft.read(ft.MaxVal, 1) << endl;

			if(ft.read(ft.MaxVal, 0) < tot) {
				s[i] = '0';
				ft.update(i+1, 0);
				ft.update(i+1, 1, -1);
			}
		}
	}

	for(int i = 0; i < n; ++i) {
		ftr.invUpdate(i+1, s[i]-'0');
	}

	// 0-> 1, 2
	/*cerr << ftr.invRead(1, 0) << endl;
	cerr << ftr.invRead(1, 1) << endl;
	cerr << ftr.invRead(1, 2) << endl;*/

	for(int i = n-1; i >= 0; --i) {
		if(s[i] == '0' and ftr.invRead(1, 0) > tot) {
			//cerr << i << " 0* " << s[i] << ftr.invRead(1, 0) << endl;

			if(ftr.invRead(1, 2) < tot) {
				s[i] = '2';
				ftr.invUpdate(i+1, 2);
			}
			else {
				s[i] = '1';
				ftr.invUpdate(i+1, 1);
			}
			ftr.invUpdate(i+1, 0, -1);
		}
	}


	// 1 -> 24
	for(int i = n-1; i >= 0; --i) {
		if(s[i] == '1' and ftr.invRead(1, 1) > tot) {
			if(ftr.invRead(1, 2) < tot) {
				s[i] = '2';
				ftr.invUpdate(i+1, 2);
				ftr.invUpdate(i+1, 1, -1);
			}
		}
	}


	cout << s << endl;
	return 0;
}