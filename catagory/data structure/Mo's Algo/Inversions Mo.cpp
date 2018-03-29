// Hackerrank
// Sherlock and Inversions
// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/sherlock-and-inversions/description/

#include <bits/stdc++.h>
#define pc(x) putchar_unlocked(x);

using namespace std;
typedef long long ll;
const int MAX = 100100;


struct BIT {
    int tree[MAX];
    int MaxVal;
    
    void init(int sz=1e7) {
        MaxVal = sz+1;
    }

    void update(int idx, ll val) {
        for( ;idx <= MaxVal; idx += (idx & -idx))
            tree[idx] += val;
    }
    
    void update(int l, int r, ll val) {
        if(l > r) swap(l, r);
        update(l, val);
        update(r+1, -val);
    }

    ll read(int idx) {
        ll sum = 0;
        for( ;idx > 0; idx -= (idx & -idx))
            sum += tree[idx];
        return sum;
    }
};

struct query {
    int l, r, id;
} q[MAX];


const int block = 320;
BIT t1;
unordered_map<int, int>Map;
ll Ans = 0, ans[MAX];
int val[MAX], LIM = 1;
set<int>Set;


inline void fastIn(int &num) {          // Fast IO, with space and new line ignoring
    bool neg = false;
    register int c;
    num = 0;
    c = getchar_unlocked();
    for( ; c != '-' && (c < '0' || c > '9'); c = getchar_unlocked());
    if (c == '-') {
        neg = true;
        c = getchar_unlocked();
    }
    for(; (c>47 && c<58); c=getchar_unlocked())
        num = (num<<1) + (num<<3) + c - 48;
    if(neg)
        num *= -1;
}

inline void fastOut(long long n) {
    long long N = n, rev, count = 0;
    rev = N;
    if (N == 0) { pc('0'); return ;}
    while ((rev % 10) == 0) { count++; rev /= 10;}                  //obtain the count of the number of 0s
    rev = 0;
    while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
    while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
    while (count--) pc('0');
}


bool cmp(query a, query b) {
    int block_a = a.l/block, block_b = b.l/block;
    if(block_a == block_b)
        return a.r < b.r;
    return block_a < block_b;
}

// For adding left, found how many numbers are less than val[x]

// t1 : for finding smaller
// t2 : for finding greater

void addLeft(int x) {
    int idx = Map[val[x]];
    ll smaller = t1.read(idx-1);
    Ans += smaller;
    t1.update(idx, 1);
}


void removeLeft(int x) {
    int idx = Map[val[x]];
    ll smaller = t1.read(idx-1);
    Ans -= smaller;
    t1.update(idx, -1);
}


// For adding right, found how many numbers are greater than val[x]

void addRight(int x) {
    int idx = Map[val[x]];
    ll greater = t1.read(LIM) - t1.read(idx);
    Ans += greater;
    t1.update(idx, 1);
}

void removeRight(int x) {
    int idx = Map[val[x]];
    ll greater = t1.read(LIM) - t1.read(idx);
    Ans -= greater;
    t1.update(idx, -1);
}


int main() {
    int n, Q;
    
    fastIn(n), fastIn(Q);
    for(int i = 0; i < n; ++i) {
        fastIn(val[i]);
        Set.insert(val[i]);
    }
    
    for(auto it : Set)
        Map[it] = ++LIM;
    
    t1.init(LIM+2);
    
    for(int i = 0; i < Q; ++i) {
        fastIn(q[i].l), fastIn(q[i].r);
        q[i].l--, q[i].r--;
        q[i].id = i;
    }
    
    sort(q, q+Q, cmp);
    int l = 0, r = -1;
    
    for(int i = 0; i < Q; ++i) {
        
        while(l > q[i].l)   addLeft(--l);
        while(r < q[i].r)   addRight(++r);
        while(l < q[i].l)   removeLeft(l++);
        while(r > q[i].r)   removeRight(r--);
        
        ans[q[i].id] = Ans;
    }
    
    for(int i = 0; i < Q; ++i) {
        fastOut(ans[i]);
        puts("");
    }
}
