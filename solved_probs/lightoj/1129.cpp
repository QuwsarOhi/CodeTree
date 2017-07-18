// LightOJ
// 1129 - Consistency Checker
// Trie

// Key topic: no number is the prefix another number in that data set

// sort the input data first
// Keep a trie with endpoint mark, insert data in trie, and check wheather there exists an endpoint of previous data

#include <bits/stdc++.h>
using namespace std;

struct node {
	bool isEnd;
	node *next[10];
	node() {
		isEnd = 0;
		for(int i = 0; i < 10; ++i)
			next[i] = NULL;
	}
};

bool buildTrie(string str, node *current) {
	int len = str.size();
	
	for(int i = 0; i < len; ++i) {
		int pos = str[i] - '0';
		
		if(current->next[pos] == NULL)
			current->next[pos] = new node();
		if(current->isEnd) {
			//printf("at pos %d\n", i);
			return 0;
		}
		current = current->next[pos];
	}
	if(current->isEnd) {
		//printf("at last\n");
		return 0;
	}
	current->isEnd = 1;
	return 1;
}

void del(node *current) {
	for(int i = 0; i < 10; ++i) 
		if(current->next[i] != NULL)
			del(current->next[i]);
	delete current;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, n;
	char s[20];
	vector<string>v;
	
	scanf("%d", &t);
	for(int Case = 1; Case <=t; ++Case) {
		scanf("%d", &n);
		while(n--) {
			scanf(" %s", s);
			v.push_back(string(s));
		}
		sort(v.begin(), v.end());
		
		node *root = new node();
		bool consistant = 1;
		
		for(int i = 0; i < (int)v.size() && consistant; ++i) {
			if(!buildTrie(v[i], root)) {
				//printf("%s\n", v[i].c_str());
				consistant = 0;
			}
		}
		
		printf("Case %d: ", Case);
		
		if(consistant)
			printf("YES\n");
		else
			printf("NO\n");
		v.clear();
		del(root);
	}
	return 0;
}
