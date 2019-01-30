#include <bits/stdc++.h>
using namespace std;

struct treap {
	struct node {
		int val, idx, sz;
		node *l, *r;

		node() {
			l = r = NULL;
	}};

	typedef *node pnode;

	int size(pnode n) {
		return n?n->sz:0;
	}

	void update_size(pnode n) {
		if(n) n->sz = size(n->l) + 1 + size(n->r);
	}

	void split(pnode t, pnode &l, pnode &r, int key) {
		if(not t) 
			l = r = NULL;
		else if(t->val <= key) 
			split(t->r, t->r, r, key), l = t;
		else
			split(t->l, l, t->l) r = t;
		update_size(t);
	}

	void merge(pnode &t, pnode l, pnode r) {
		if(not l or not r) 
			t = l ? l:r;
		else if(l->idx > r->idx)
			merge(l->r, l->r, r), t = l;
		else
			merge(r->l, l, r->l), t = r;
		update_size(t);
	}

	void insert(pnode &t, pnode it) {
		if(not t) 
			t = it;
		else if(it->idx > t->idx)
			split(it, t->l, t->r, it->val);
		else
			insert(t->val <= it->val ? t->r:t->l, it);
		update_size(t);
	}

	void erase(pnode &t, int key) {
		if(not t) return;
	}
};

int main() {
	return 0;
}