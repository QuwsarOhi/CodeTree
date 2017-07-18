// LightOJ
// 1224 - DNA Prefix
// Trie

// find a subset of samples in the set, where the length of the longest common prefix multiplied by the number of samples in that subset is maximum

// In trie node, we need two integer patameters extra, level & counter
// level indicates the depth/level (length) of a word
// counter indicates the total same prefix
// in each insertion in trie, we will find the maximum level*counter

#include <bits/stdc++.h>
using namespace std;

int maxVal;

struct node {
	int level, counter;
	node *next[4];
	
	node() {
		level = counter = 0;
		for(int i = 0; i < 4; ++i)
			next[i] = NULL;
	}
};

int chrToInt(char x) {
	if(x == 'A')
		return 0;
	else if(x == 'C')
		return 1;
	else if(x == 'G')
		return 2;
	return 3;
}


void buildTRIE(char *str, int len, node *current) {
	int level = 1, pos;
	for(int i = 0; i < len; ++i) {
		pos = chrToInt(str[i]);
		if(current->next[pos] == NULL)
			current->next[pos] = new node();
		current = current->next[pos];
		current->level = level++;
		current->counter++;
		maxVal = max(current->level * current->counter, maxVal);
		/*if(current->level * current->counter > maxVal) {
			printf("max found at %s %d : %d (%d * %d)\n", str, i, current->level * current->counter, current->level, current->counter);
			maxVal = current->level * current->counter;
		}*/
	}
}

void del(node *current) {
	for(int i = 0; i < 4; ++i)
		if(current->next[i] != NULL)
			del(current->next[i]);
	delete current;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	
	int t, n;
	char s[60];
	
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		maxVal = 0;
		node *root = new node();
		//printf("new node created\n");
		for(int i = 0; i < n; ++i) {
			scanf(" %s", s);
			buildTRIE(s, strlen(s), root);
			//printf("%s inserted\n", s);
		}
		
		del(root);
		
		printf("Case %d: %d\n", Case, maxVal);
	}
	return 0;
}
