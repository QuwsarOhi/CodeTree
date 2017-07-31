// LightOJ
// 1148 - Mad Counting

// n people are asked how many people are there (except the man whom is aksed) who supports the same team
// they reply the answer (one person is asked only one time)
// you have to find the minimum number of total people from this info


// it is sure that there are minimum n person, but there could be more!

// If one people gives ans 3, then there are 3 people who support the same team
// so after that person, if another person replys 3, then he also supports the same team like the previous person

// EXample:
// 4
// 1 1 3 3
// ans : 4+2 = 6
// 1 - 1 : supports same team, and said about one another
// 3 - 3 : supports same team, said about one another, but there are more 2 person (if a person says 3, then there is 3 person would reply
// the same)

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n, ans, x;
	map<int, int>mp;
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		ans = n;
		mp.clear();
		for(int i = 0; i < n; ++i) {
			scanf("%d", &x);
			if(mp[x] <= 0 && x != 0)
				mp[x] = x;
			else
				--mp[x];
		}
		map<int, int>::iterator it;
		for(it = mp.begin(); it != mp.end(); ++it)
			if(it->second > 0)
				ans += it->second;
		printf("Case %d: %d\n", Case, ans);
	}
	return 0;
}
