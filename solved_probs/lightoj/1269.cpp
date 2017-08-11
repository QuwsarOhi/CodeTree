// LightOJ
// 1269 - Consecutive Sum
// Trie, Greedy

// If the problem is looked closely, this is a Range Minimum XOR and Range Maximum XOR problem
// Like cumulative frequency, xor has also the same principle
// Ex:
// num:			  			3(1),  8(2), 2(3), 6(4), 5(5)
// bit:						0011,  1000, 0010  0110, 0101
// Cumulative Xor : 		0011,  1011, 1001, 1111, 1010		(From left to right)
// Cumulative Xor : 		1010,  1001, 0001, 0011, 0101		(From right to left)
// the segment 3-5, can be calculated by(from left to right): [1-2] ^ [1-5] :  1011 ^ 1010 : 0111

// In this problem, for every cumulative Xor, we have to find the maximum and minimum cumulative xor in any segment
// we take a cumulative xor like left to right, check in trie if the cumulative xor can be maximized/minimized (greedy approach)
// then insert the new cumulative xor in the trie, this must be done after checking for maximum/ minimum xor


#include <bits/stdc++.h>
#define setBit(x, i) (x |= (1 << i))
#define isOn(x, i) (x & (1 << i))

using namespace std;

struct node {
	node *next[2];
	node() {
		next[0] = next[1] = NULL;
	}
};

/* Prints bits
void printer(int x) {
	for(int i = 31; i >= 0; --i) {
		if(isOn(x, i))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}*/

void trieInsert(int val, node *current) {
	int pos;
	for(int i = 31; i >= 0; --i) {
		if(isOn(val, i))
			pos = 1;
		else
			pos = 0;
		if(current->next[pos] == NULL)
			current->next[pos] = new node();
		
		current = current->next[pos];
	}
}

int trieMax(int val, node *current) {
	int tmp = 0, mn, mx;
	for(int i = 31; i >= 0; --i) {
		if(isOn(val, i) == 0)
			mn = 0, mx = 1;
		else
			mn = 1, mx = 0;
		if(current->next[mx] != NULL) {
			current = current->next[mx];
			setBit(tmp, i);
		}
		else if(current->next[mn] != NULL)
			current = current->next[mn];	
	}
	
	return tmp;
}

int trieMin(int val, node *current) {
	int tmp = 0, mn, mx;
	for(int i = 31; i >= 0; --i) {
		if(isOn(val, i) == 0)
			mn = 0, mx = 1;
		else
			mn = 1, mx = 0;
		
		if(current->next[mn] != NULL) {
			current = current->next[mn];
		}
		else if(current->next[mx] != NULL) {
			current = current->next[mx];
			setBit(tmp, i);
		}
	}
	return tmp;
}

void del(node * current) {
	for(int i = 0; i < 2; ++i)
		if(current->next[i] != NULL)
			del(current->next[i]);
	delete current;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "r", stdout);
	
	int t, n, Min, Max, x, CXor;
	
	scanf("%d", &t);
	
	for(int Case = 1; Case <= t; ++Case) {
		scanf("%d", &n);
		
		node *root = new node();
		CXor = 0;
		
		for(int i = 0; i < n; ++i) {
			scanf("%d", &x);
			CXor ^= x;
			if(i == 0) {
				Min = Max = x;
			}
			else {
				Min = min(Min, min(CXor, trieMin(CXor, root)));
				Max = max(Max, max(CXor, trieMax(CXor, root)));
			}
			trieInsert(CXor, root);
		}
		
		printf("Case %d: %d %d\n", Case, Max, Min);
		del(root);
	}
	
	return 0;
}
