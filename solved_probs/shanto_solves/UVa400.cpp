// UVa
// 400 - Unix ls

#include <bits/stdc++.h>
using namespace std;

vector<string>v, ans[70];

int Columns(int mx_len) {
	int cnt = 0, t = 60;
	if(mx_len <= t) {
		t-=mx_len;
		++cnt;
	}
	mx_len += 2;
	while(t >= mx_len) {
		t -= mx_len;
		++cnt;
	}
	return cnt;
}

bool CanBuildTable(int rows, int columns, int max_len) {
	int row_no = 0;
	
	for(auto it : v) {
		string x(it);
		int len = max_len - (int)x.size();
		while(len--) x += ' ';
		if(row_no == rows)
			row_no = 0;
		if(ans[row_no].size() != 0) ans[row_no][(int)ans[row_no].size()-1] += string("  ");
		ans[row_no].push_back(x);
		++row_no;
	}
	
	for(int i = 0; i < rows; ++i) {
		int len = 0;
		for(auto it : ans[i])
			len += it.size();
		if(len > 60)
			return 0;
	}
	return 1;
}
	

int main() {
	string x;
	int n;
	
	while(cin >> n) {
		int mx_len = 0;
		for(int i = 0; i < n; ++i) {
			cin >> x;
			v.push_back(x);
			mx_len = max(mx_len, (int)x.size());
		}
		
		sort(v.begin(), v.end());
		
		int column = Columns(mx_len);
		int row = ceil(n/(double)column);
		if(!CanBuildTable(row, column, mx_len)) {
			cout << "Failed\n" << endl;
			column = 60/mx_len;
			row = ceil(n/(double)column);		// Upper bound taken, so there may exist some empty row in rightmost column
			for(int i = 0; i <= row; ++i)
				ans[i].clear();
			CanBuildTable(row, column, mx_len);
		}
		
		for(int i = 0; i < 60; ++i)
			cout << "-";
		cout << "\n";
		
		for(int i = 0; i < row; ++i) {
			for(auto it : ans[i])
				cout << it;
			cout << "\n";
		}
		
		for(int i = 0; i <= row; ++i)
			ans[i].clear();
		v.clear();
	}
		
	return 0;
}
