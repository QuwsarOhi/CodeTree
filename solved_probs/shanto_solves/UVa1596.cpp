// UVa
// 1596 - Bug Hunt

#include <bits/stdc++.h>
using namespace std;

string s;
map<string, pair<string, map<string, string> > > mp;

int isDefinition() {
	for(int i = 0; i < (int)s.size(); ++i)
		if(s[i] == '=')
			return i;
	return -1;
}

string valueOf(string var, string idx) {
	if(mp.find(var) == mp.end())	// Variable doesnt exist
		return string();
	
	pair<string, map<string, string> > &t = mp[var];
	
	if(t.first.size() < idx.size())				// Index out of range
		return string();
	else if(t.first.size() == idx.size() && t.first <= idx)
		return string();
	
	if(t.second.find(idx) == t.second.end())		// Uninitialized index
		return string();
	
	return t.second[idx];
}

string recur(int l) {
	string var, idx;
	if(isdigit(s[l])) {
		for(int i = l; s[i] != ']' && i < (int)s.size(); ++i)
			idx += s[i];
		return idx;
	}
	for(int i = l; s[i] != '['; ++i) {
		l = i;
		var += s[i];
	}
	
	idx = recur(l+2);
	return valueOf(var, idx);
}

void DeclareVal(string var, string idx) {
	if(mp.find(var) != mp.end())
		mp.erase(mp.find(var));
	
	mp[var].first = idx;
}

bool DefineValIdx(string var, string idx, string val) {		// Returns 0 if overflows
	if(mp.find(var) == mp.end())
		return 0;
	pair<string, map<string, string> > &t = mp[var];
	
	if(t.first.size() < idx.size())
		return 0;
	else if(t.first.size() == idx.size() && t.first <= idx)
		return 0;
	
	t.second[idx] = val;
	return 1;
}

int main() {
	//freopen("in", "r", stdin);
	
	bool cnt = 0;
	int ErrorLine = 1e7, Line = 0;
	
	while(cin >> s) {
		if(s[0] == '.' && !cnt) {
			if(ErrorLine == 1e7)
				printf("0\n");
			else
				printf("%d\n", ErrorLine);
			cnt = 1;
			continue;
		}
		else if(s[0] == '.' && cnt)
			break;
		else if(cnt && s[0] != '.') {
			ErrorLine = 1e7;
			Line = 0;
			cnt = 0;
			mp.clear();
		}
	
		++Line;
		int p = isDefinition(), l;
		
		string LeftVar, LeftIdx;
		for(int i = 0; s[i] != '['; ++i) {
			LeftVar += s[i];
			l = i;
		}
		LeftIdx = recur(l+2);
		if(LeftIdx.empty())
			ErrorLine = min(Line, ErrorLine);
		if(p == -1) 
			DeclareVal(LeftVar, LeftIdx);
		else {
			string RightVal = recur(p+1);
			if(RightVal.empty() || !DefineValIdx(LeftVar, LeftIdx, RightVal)) {
				ErrorLine = min(Line, ErrorLine);
			}
		}
	}
	return 0;
}
