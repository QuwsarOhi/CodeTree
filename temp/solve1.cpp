#include <bits/stdc++.h>
using namespace std;


bool CanBuildTable(int rows, int columns, int max_len) {
	int row_no = 0;
	
	for(auto it : v) {
		string x(it);
		int len = max_len - (int)x.size();
		while(len--) x += ' ';
		if(row_no == rows)
			row_no = 0;
		if(ans[row_no].size() != 0) x += string("  ");
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
		
		
		int column = 60/mx_len;
		int row = ceil(n/(double)column);		// Upper bound taken, so there may exist some empty row in rightmost column
		
		
		
	}
		
		
