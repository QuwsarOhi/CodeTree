#include <bits/stdc++.h>
using namespace std;


bool cmp(pair<int, int> x, pair<int, int> y) {
	if(x.first+x.second != y.first+y.second)
		return x.first+x.second < y.first+y.second;
	else
		return x.first < y.first;
}

int main() {
	int t, x, y;
	vector<pair<int, int> >V;
	for(int i  = 0; i <= 100; i++)
		for(int j = 0; j <=100; j++)
			V.push_back(make_pair(i, j));
	sort(V.begin(), V.end(), cmp);
	
	map<pair<int,int>, int>mp;
	
	for(int i = 0; i < (int)V.size(); i++)
		mp[make_pair(V[i].first, V[i].second)] = i+1;
	
	scanf("%d", &t);
	
	while(t--) {
		scanf("%d %d", &x, &y);
		if(x <= 100 && y <= 100)
			printf("%d\n", mp[make_pair(x, y)]);
		else
			printf("1000000");
	}
	
	return 0;
}
