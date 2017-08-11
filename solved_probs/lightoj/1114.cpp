// LightOJ
// 1114 - Easily Readable
// Trie
// This problem is in 'Trie' section, but this can be easily solved with sorting
// The main problem statement is :: The first and last letters of each word remain unmodified and all the characters in the middle can be reordered freely.
// Sort all words without the first and last word, then do mapping and count

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, q, n, len, ans;
	char s[110], S[10100];
	string str;
	map<string, int>mp;
	
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		mp.clear();
		printf("Case %d:\n", Case);
		while(n--) {
			scanf(" %s", s);
			len = strlen(s);
			if(len != 1)
				sort(s+1, s+len-1);
			mp[string(s)]++;
		}
		scanf("%d ", &q);
		while(q--) {
			fgets(S, 10050, stdin);
			//scanf(" %[^\n]", S);
			stringstream ss(S);
			ans = 1;
			while(ss >> str) {
				if(str.size() != 1) 
					sort(str.begin()+1, str.end()-1);
				ans *= mp[str];
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
