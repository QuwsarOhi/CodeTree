#include <bits/stdc++.h>
#define ALPHA 54
using namespace std;

int alphaToInt(char x) {
	if(x >= 'a' && x <= 'z')
		return x-'a';
	else
		return x-'A'+26;
}

struct node {
    int endPoint;
    bitset<ALPHA>word;
    node *next[ALPHA];
    node() {
        endPoint = 0;
        word.reset();
        for(int i = 0; i < ALPHA; i++) {
            next[i] = NULL;
		}
    }
};


void placeInTRIE(char *str, int len, node *current) {
	int pos;
	for(int i = 0; i < len; ++i) {
		if(i != 0 && i != (len-1))
			pos = 53;
		else
			pos = alphaToInt(str[i]);
		current->word[alphaToInt(str[i])] = 1;
		if(current->next[pos] == NULL)
			current->next[pos] = new node();
		current = current->next[pos];	
	}
	current->endPoint++;
	//printf("%s %d\n", str, current->endPoint);
}

void del(node *current) {
	for(int i = 0; i < ALPHA; ++i)
		if(current->next[i] != NULL)
			del(current->next[i]);
	delete current;
}


/*
int findPossibleMatch(string str, int len, node *current) {
	int pos;
	for(int i = 0; i < len; ++i) {
		if(i != 0 && i != (len-1))
			pos = 53;
		else
			pos = alphaToInt(str[i]);
		if(!current->word[alphaToInt(str[i])])
			return 0;
		if(current->next[pos] == NULL)
			return 0;
		current = current->next[pos];
	}
	return current->endPoint;
}*/

int findPossibleMatch(int len, node *current, string str) {
	if(len == 1) {
		if(current->next[alphaToInt(str[len-1])] != NULL) 
			if(current->next[alphaToInt(str[len-1])]->endPoint != 0)
				return 1;
		return 0;
	}
	int ans = -1;
	for(int i = 1; i < len-1; ++i) {
		if(current->next[alphaToInt(str[i])] != NULL)
			ans = findPossibleMatch(len-1, current->next[i], str);
	}
	return ans; 
}

int main() {
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	
	int t, n, ans, tmp, q;
	char s[110], S[100100];
	scanf("%d", &t);
	map<string, bool>mp;
	for(int Case = 1; Case <= t; ++Case) {
		printf("Case %d:\n", Case);
		scanf("%d", &n);
		node *root = new node();
		
		for(int i = 0; i < n; ++i) {
			scanf(" %s", s);
			placeInTRIE(s, strlen(s), root);
		}
		mp.clear();
		scanf("%d", &q);
		
		//printf("-----------------------------------------------------\n");
		//getchar();
		while(q--) {
			//fgets(S, 100050, stdin);
			scanf(" %[^\n]", S);
			stringstream ss(S);
			string str;
			ans = 1;
			while(ss >> str) {
				if(root->next[alphaToInt(str[0])] != NULL) {
					int len = str.size();
					ans *= findPossibleMatch(len-1, root->next[alphaToInt(str[0])], str);
				}
				else {
					printf("at %s\n", str.c_str());
					ans = 0;
				}
				printf("%d %s\n", ans, str.c_str());
			}
			printf("****************************************%d\n", ans);
		}
		
		del(root);
	}
	return 0;
}
