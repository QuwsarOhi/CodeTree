#include <bits/stdc++.h>
using namespace std;

// https://github.com/rlaguilar/Programming-Contests/blob/master/data-structures/treap%20with%20implicit%20key.cpp

template<typename T> struct treap {      // WARNING: NOT VERIFIED
/*  QUERY TYPES:
    1. ADD x y D: Add D to each number in sub-sequence {Ax ... Ay}. For example, performing "ADD 2 4 1" on {1, 2, 3, 4, 5} results in {1, 3, 4, 5, 5}
    2. REVERSE x y: reverse the sub-sequence {Ax ... Ay}. For example, performing "REVERSE 2 4" on {1, 2, 3, 4, 5} results in {1, 4, 3, 2, 5}
    3. REVOLVE x y T: rotate sub-sequence {Ax ... Ay} T times. For example, performing "REVOLVE 2 4 2" on {1, 2, 3, 4, 5} results in {1, 3, 4, 2, 5}
    4. INSERT x P: insert P after Ax. For example, performing "INSERT 2 4" on {1, 2, 3, 4, 5} results in {1, 2, 4, 3, 4, 5}
    5. DELETE x: delete Ax. For example, performing "DELETE 2" on {1, 2, 3, 4, 5} results in {1, 3, 4, 5}
    6. MIN x y: what is the minimum number in sub-sequence {Ax ... Ay}. For example, the correct answer to "MIN 2 4" on {1, 2, 3, 4, 5} is 2
    7. SUM x y: what is the sum of all numbers in sub-sequence {Ax...Ay}. For example, the answer to "SUM 3 5" on {1, 2, 3, 4, 5} is 12
*/
	typedef int node;
	typedef vector<T> vt;
    ull MAXN, MAXS, NIL, oo;
	vector<node> lch, rch;
    node root;
	vt val;     //val[i] = value of array at corresponding index to node i
	vi cnt; 	//cnt[i] = gets the number of nodes in the subtree rooted at node i
	vi rev;     //rev[i] = says if the node i is reversed
	vt acc;     //acc[i] = accumulated value for sum in all the subtree rooted at node i
	vt sum;     //sum[i] = gets the sum of values of all nodes in the subtree rooted at node i
	vt mim;	    //mim[i] = gets the minimum value of all nodes in the subreee rooted at node i
	vt arr;	    //arr[i] = value of initial array at index i
	ull	sz;
    treap() {
        MAXN = 2e5 + 5, MAXS = 8e6, NIL = 0, oo = 1e9 + 5;
        val.resize(MAXS), cnt.resize(MAXS), rev.resize(MAXS), acc.resize(MAXS);
        sum.resize(MAXS), mim.resize(MAXS), arr.resize(MAXN);
        lch.resize(MAXS), rch.resize(MAXS);
    }
	int random ()           { return (rand()<<15)+rand(); }
	void init ()            { sz = 1; /*important*/ }
	int get_cnt (node t)	{ return t != 0 ? cnt[t] : 0;	}
	int get_sum (node t)	{ return t != 0 ? sum[t] : 0;	}
	T get_min (node t)	{ return t != 0 ? mim[t] : oo; }

	void push (node t) {
		if (t != 0) {
			if (rev[t])	{           // handling reverse query
				rev[t] = false;
				if (lch[t] != NIL)
					rev[lch[t]] ^= 1;
				if (rch[t] != NIL)
					rev[rch[t]] ^= 1;
				swap(lch[t], rch[t]);
			}
			if (acc[t]) {           // handling interval sum query
				val[t] += acc[t];
				if (lch[t] != NIL)
					acc[lch[t]] += acc[t];
				if (rch[t] != NIL)
					acc[rch[t]] += acc[t];
				acc[t] = 0;
    }}}
	void update (node t) {
		if (t != 0) {
			cnt[t] = get_cnt(lch[t]) + get_cnt(rch[t]) + 1;
			sum[t] = get_sum(lch[t]) + get_sum(rch[t]) + val[t];
			T mc = min(get_min(lch[t]), get_min(rch[t]));
			mim[t] = min(mc, val[t]);
    }}
	node new_node (T v, node l, node r) {
		assert(sz < MAXS);
		val[sz] = v, mim[sz] = v, lch[sz] = l, rch[sz] = r;
		update(sz);
		return sz++;
	}
	node build (int b, int e) {     	// WARNING: Call root = build(0, n - 1)
		if (b > e) return NIL;
		int m = (b + e) >> 1;
		return new_node(arr[m], build(b, m - 1), build(m + 1, e));
	}
	void split (node t, node &l, node &r, int cnt) {
		if (t == NIL) l = r = NIL;
		else {
			push(t);
			int tmp = get_cnt(lch[t]);
			if (tmp >= cnt)
				split(lch[t], l, lch[t], cnt), r = t;
			else
				split(rch[t], rch[t], r, cnt - tmp - 1), l = t;
			update(t);
    }}
	node merge (node l, node r) {
		if (l == NIL || r == NIL)
			return l == NIL ? r : l;
		push(l);
		push(r);
		if (random() % (cnt[l] + cnt[r]) < cnt[l]) {
			rch[l] = merge(rch[l], r);
			update(l);
			return l;
		}
		lch[r] = merge(l, lch[r]);
		update(r);
		return r;
	}
	void insert (int idx, int val) {
		if (idx > get_cnt(root)) return;
		node n1, n2;
		split(root, n1, n2, idx);
		root = merge(n1, new_node(val, NIL, NIL));
		root = merge(root, n2);
	}
	void erase (int idx) {
		if (get_cnt(root) <= idx)
			return;
		node n1, n2, n3;
		split(root, n1, n2, idx);
		split(n2, n2, n3, 1);
		root = merge(n1, n3);
	}
	void reverse (int l, int r) {
		node n1, n2, n3;
		split(root, n1, n2, l);
		split(n2, n2, n3, r - l + 1);
		rev[n2] ^= 1;
		root = merge(n1, n2);
		root = merge(root, n3);
	}
	//Rotate arr[l...r] k times to the right (WARNING: TO THE RIGHT!!!)
	/*void rotate (int l, int r, int k) {
		if (l > r) return;
		node n1, n2, n3, n4;
		split(root, n1, n2, l);
		split(n2, n2, n3, r - l + 1);
		k %= get_cnt(n2);
		split(n2, n2, n4, get_cnt(n2) - k);
		root = merge(n1, n4);
		root = merge(root, n2);
		root = merge(root, n3);
	}*/
	//WARNING: Check overflow in sum
	int sum_query (int l, int r) {
		node n1, n2, n3;
		split(root, n1, n2, l);
		split(n2, n2, n3, r - l + 1);
		int ans = get_sum(n2);
		root = merge(n1, n2);
		root = merge(root, n3);
		return ans;
	}
	void sum_query (int l, int r, int v) {
		node n1, n2, n3;
		split(root, n1, n2, l);
		split(n2, n2, n3, r - l + 1);
		acc[n2] += v;
		root = merge(n1, n2);
		root = merge(root, n3);
	}
	int min_query (int l, int r) {
		node n1, n2, n3;
		split(root, n1, n2, l);
		split(n2, n2, n3, r - l + 1);
		int ans = get_min(n2);
		root = merge(n1, n2);
		root = merge(root, n3);
		return ans;
}};

//  ------------------------------------------------------------------------------------------------------

/*
template <typename T, typename U>
pair<T,U> operator+ (const pair<T,U> & a, pair<T,U> & b) {
	return make_pair (a.first+b.first, a.second+b.second);
}

template <typename T, typename U>
pair<T,U> operator- (const pair<T,U> & a, pair<T,U> & b) {
	return make_pair (a.first-b.first, a.second-b.second);
}

template <typename T, typename U>
pair<T,U> operator* (const int & a, pair<T,U> & b) {
	return make_pair (a*b.first, a*b.second);
}*/

template <typename T> 
class treapset {
private:
	struct item;
	typedef struct item * pitem;
	
	bool _is_sorted = true, stop;
	pitem root = NULL, _begin = NULL;

	long long next_priority () {
		long long prior = rand();
		return prior;
	}

	void regenerate_priorities_recursive (vector<int> & new_priors, pitem & t, int l, int r) {
		if (!t) return;
		t->prior = new_priors[r-1];
		regenerate_priorities_recursive (new_priors, t->l, l, l+cnt(t->l));
		regenerate_priorities_recursive (new_priors, t->r, l+cnt(t->l), r-1);
	}

	void regenerate_priorities () {
		int sz = size();
		vector<int> new_priors(sz);
		for (int i =0; i < sz; i++) new_priors[i] = next_priority();
		sort (new_priors.begin(), new_priors.end());
		for (int i =0; i < sz; i++) new_priors[i] += i;
		regenerate_priorities_recursive (new_priors, root, 0, sz);
	}

	struct item {
		long long prior;
		int cnt, rev;
		T key, add, fsum;
		pitem l, r;
		item(T x, long long p) {
			add = 0*x;
			key = fsum = x;
			cnt = 1;
			rev = 0;
			l = r = NULL; 
			prior = p;
    }};

	int cnt (pitem it) {
		return it ? it->cnt : 0;
	}

	void upd_cnt (pitem it) {
		if (it)
			it->cnt = cnt(it->l) + cnt(it->r) + 1;
	}

	void upd_sum (pitem it) {
		if (it) {
			it->fsum = it->key;
			if (it->l) it->fsum += it->l->fsum;
			if (it->r) it->fsum += it->r->fsum;
		}
	}

	void update (pitem t, T add, int rev) {
		if (!t) return;
		t->add = t->add + add;
		t->rev = t->rev ^ rev;
		t->key = t->key + add;
		t->fsum = t->fsum + cnt(t) * add;
	}

	void push (pitem t) {
	 	if (!t || (t->add == 0*T() && t->rev == 0)) return;
		update (t->l, t->add, t->rev);
		update (t->r, t->add, t->rev);
		if(t->rev) swap(t->l,t->r);
		t->add = 0*T();
		t->rev = 0;
	}

	void merge (pitem & t, pitem l, pitem r) {
		push (l);
		push (r);
		if (!l || !r) 
			t = l ? l : r;
		else if (l->prior > r->prior)
			merge (l->r, l->r, r),  t = l;
		else
			merge (r->l, l, r->l),  t = r;
		upd_cnt (t);
		upd_sum (t);
	}

	void split (pitem t, pitem & l, pitem & r, int index) { // split at position
		if (!t)
			return void( l = r = 0 );
		push (t);
		if (index <= cnt(t->l))
			split (t->l, l, t->l, index),  r = t;
		else
			split (t->r, t->r, r, index - 1 - cnt(t->l)),  l = t;
		upd_cnt (t);
		upd_sum (t);
	}

	void splitK (pitem t, pitem & l, pitem & r, T & key, bool & eq) { // split by key
		if (!t)
			return void( l = r = 0 );
		push (t);
		if (key == t->key) {
			eq =true;
			return;
		}
		if (key < t->key) {
			splitK (t->l, l, t->l, key, eq);
			if (!eq) r = t;
		}
		else {
			splitK (t->r, t->r, r, key, eq);
			if (!eq) l = t;
		}
		if(!eq) upd_cnt (t);
		upd_sum (t);
	}

	void insert(pitem & t, pitem it, int index) { // insert at position
		push (t);
		if (!t) 
			t = it;
		else if (it->prior == t->prior) {
			stop = true;
			regenerate_priorities();
		}
		else if (it->prior > t->prior)
			split (t, it->l, it->r, index),  t = it;
		else if (index <= cnt(t->l))
			insert (t->l, it, index);
		else
			insert (t->r, it, index - cnt(t->l) - 1 );
		if (stop) return;
		upd_cnt (t);
		upd_sum (t);
	}

	void insertK (pitem & t, pitem it, bool & eq) { // insert by key
		push (t);
		if (!t)
			t = it;
		else if (it->key == t->key) {
			eq =true; 
			return;
		}
		else if (it->prior == t->prior) {
			stop = true;
			regenerate_priorities();
		}
		else if (it->prior > t->prior) {
			splitK (t, it->l, it->r, it->key, eq);
			if (!eq) t = it;
		}
		else if (it->key < t->key)
			insertK (t->l, it, eq);
		else
			insertK (t->r, it, eq);
		if (stop) return;
		if (!eq) upd_cnt (t);
		upd_sum (t);
	}

	void erase (pitem & t, int index) {
		push (t);
		if (cnt(t->l) == index) 
			merge (t, t->l, t->r);
		else if (index < cnt(t->l))
			erase (t->l, index);
		else
			erase (t->r, index - cnt(t->l) - 1 );
		upd_cnt (t);
		upd_sum (t);
	}

	void eraseK (pitem & t, T key, bool & found) {
		push (t);
		if (key == t->key) {
			merge (t, t->l, t->r);
			found = true;
		}
		else if (key < t->key)
			eraseK (t->l, key, found);
		else
			eraseK (t->r, key, found);
		upd_cnt (t);
		upd_sum (t);
	}

	T get (pitem t, int index) {
		push (t);
		if (index < cnt(t->l))
			return get (t->l, index);
		else if (index > cnt(t->l))
			return get (t->r, index - cnt(t->l) - 1);
		return t->key;
	}

	int find (pitem t, T key) {
		push (t);
		if (!t || key == t->key)
			return cnt (t->l);
		if (key < t->key)
			return get (t->l, key);
		else 
			return get (t->r, key) + 1 + cnt (t->l);
	}

	pair <T, int> lower_bound (pitem t, T key, int index) {
		push (t);
		if (!t)
			return make_pair (T(), size());
		if (key == t->key) 
			return make_pair (key, index + cnt(t->l));
		if (key < t->key) {
			pair <T, int> ret = lower_bound (t->l, key, index);
			if (ret.second == size()) ret = make_pair (t->key, index + cnt(t->l));
			return ret;
		}
		return lower_bound (t->r, key, index + 1 + cnt(t->l));
	}

	pair <T, int> upper_bound (pitem t, T key, int index) {
		push (t);
		if (!t)
			return make_pair (T(), size());
		if (key < t->key) {
			pair <T, int> ret = upper_bound (t->l, key, index);
			if (ret.second == size()) ret = make_pair (t->key, index + cnt(t->l));
			return ret;
		}
		return upper_bound (t->r, key, index + 1 + cnt(t->l));
	}

	void shift (pitem &t, int l, int r, T add) {
		pitem l1, r1;
		split (t, l1, r1, r + 1);
		pitem l2, r2;
		split (l1, l2, r2, l);
		update (r2, add, 0);
		pitem t2;
		merge (t2, l2, r2);
		merge (t, t2, r1);
	}

	void reverse (pitem &t, int l, int r) {
		pitem l1, r1;
		split (t, l1, r1, r + 1);
		pitem l2, r2;
		split (l1, l2, r2, l);
		update (r2, 0*T(), 1);
		pitem t2;
		merge (t2, l2, r2);
		merge (t, t2, r1);
	}

	T query_sum (pitem &t, int l, int r) {
		pitem l1, r1;
		split (t, l1, r1, r + 1);
		pitem l2, r2;
		split (l1, l2, r2, l);
		T ret = r2->fsum;
		pitem t2;
		merge (t2, l2, r2);
		merge (t, t2, r1);
		return ret;
	}

public:

	int size () {return cnt(root);}
	bool empty () {return (cnt(root) == 0);}
	bool is_sorted () {return _is_sorted;}

	bool insert (T x) {
		if (!_is_sorted) return false;
		bool eq = false;
		pitem it = new item (x, next_priority());
		stop = false;
		insertK (root, it, eq);
		while (stop) {
			stop = false;
			eq = false;
			insertK (root, it, eq);
		}
		return !eq;
	}

	void insert_pos (int pos, T x) {
		if (pos > size()) return;
		pitem it = new item (x, next_priority());
		stop = false;
		insert (root, it, pos);
		while (stop) {
			stop = false;
			insert (root, it, pos);
		}
		if (pos > 0 && _is_sorted) {
			if (get (root, pos-1) >= get (root, pos)) _is_sorted = false;
		}
		if (pos < size()-1 && _is_sorted) {
			if (get (root, pos) >= get (root, pos+1)) _is_sorted = false;
		}
	}

	bool erase (T x) {
		if (!_is_sorted) return false;
		bool found = false;
		eraseK (root, x, found);
		return found;
	}

	void erase_pos (int pos) {
		if (pos >= size()) return;
		erase (root, pos);
	}

	int get_index (T key) {
		if(!_is_sorted) return size();
		pitem t = root;
		int index = 0;
		while (t && t->key != key) {
			if (t->key > key)
				t = t->l;
			else {
				index += cnt(t->l) + 1;
				t = t->r;
			}
		}
		if (!t) return size();
		index += cnt(t->l);
		return index;
	}

	T operator[] (int index) {
		return get (root, index);
	}

	pair <T, int> lower_bound (T x) {
		if(!_is_sorted) return make_pair (T(), size());
		return lower_bound (root, x, 0);
	}

	pair <T, int> upper_bound (T x) {
		if(!_is_sorted) return make_pair (T(), size());
		return upper_bound (root, x, 0);
	}

	void shift (int left, int right, T x) {
		left = max (left, 0);
		right = min (right, size()-1);
		shift (root,left,right,x);
		if (left > 0 && _is_sorted) {
			if (get (root, left-1) >= get (root, left)) _is_sorted = false;
		}
		if (right < size()-1 && _is_sorted) {
			if (get (root, right) >= get (root, right+1)) _is_sorted = false;
		}
	}

	void reverse (int left, int right) {
		left = max (left, 0);
		right = min (right, size()-1);
		reverse (root,left,right);
		if(left != right) _is_sorted = false;
	}

	T sum (int left, int right) {
		return query_sum (root, left, right);
	}
};

treapset<int>treap;

int main() {
    int n;
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i) {
        scanf("%d", &x);
        treap.insert(x);
    }
    
    scanf("%d", &q);
    
    while(q--) {
        
