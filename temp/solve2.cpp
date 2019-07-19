#include <bits/stdc++.h>
#define MAX 100009
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector<long long> vl;

ll v[3][100009];
ll dp[3][100009];
ll n;

ll recur(int pos, int lstIdx) {
	if(pos == n)
		return 0;

	ll &ret = dp[lstIdx][pos];

	//cout << pos << " " << lstIdx << " : " << ret << endl;
	if(ret != -1)
		return ret;

	ret = 0;
	if(lstIdx != 1)
		ret = max(ret, recur(pos+1, 1)+v[1][pos]);
	if(lstIdx != 2)
		ret = max(ret, recur(pos+1, 2)+v[2][pos]);

	ret = max(ret, recur(pos+1, 0));

	//cout << pos << " " << lstIdx << " : " << ret << endl;
	return ret;
}


int main() {
	cin >> n;

	for(int i = 1; i <= 2; ++i)
		for(int j = 0; j < n; ++j)
			cin >> v[i][j];

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 100000; ++j)
			dp[i][j] = -1;

	cout << recur(0, 0) << endl;
    return 0;
}