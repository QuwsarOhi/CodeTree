//Codeforces
//http://codeforces.com/contest/798/problem/B
//problem - 789B
//Implementation, Backtrack

#include <bits/stdc++.h>
using namespace std;

int len;
unordered_map<string, int>mp;
unordered_map<string, int>cnt;

void make_log(string s) {
	len = s.length();
	for(int i = 0; i < len; i++) {
		string tmp;
		for(int j = i; j < len; j++)
			tmp += s[j];
		for(int k = 0; k < i; k++)
			tmp += s[k];
		if(mp[tmp] < 1) {
			mp[tmp]++;
			cnt[tmp] = i;
		}
	}
}

void checker(string s, int ind) {
	map<string, bool>t;
	//cout << "entered " << len << endl;
	for(int i = 0; i < len; i++) {
		string tmp;
		for(int j = i; j < len; j++)
			tmp += s[j];
		for(int k = 0; k < i; k++)
			tmp += s[k];
		if(!t[tmp]) {
			t[tmp] = 1;
			mp[tmp]++;
			cnt[tmp]+= i;
		}
	}
	return;
}
int main()
{
	int t;
	scanf("%d", &t);
	string s[t];
	for(int i = 0; i < t; i++)
		cin >> s[i];
	make_log(s[0]);
	for(int i = 1; i < t; i++)
		checker(s[i], i);
	int Min = 1e7;
	for(unordered_map<string, int>:: iterator it = mp.begin(); it != mp.end(); it++) {
		if(it->second == t)
			Min = min(Min, cnt[it->first]);
	}
	if(Min == 1e7)
		cout << "-1" << endl;
	else
		cout << Min << endl;
	return 0;
}
