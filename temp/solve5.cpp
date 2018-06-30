// F. One Occurrence

#include <bits/stdc++.h>
#define MAX 500010
using namespace std;

struct query {
    int l, r, id;
};

const int block = 800;          // For 500000
query q[MAX];
int ans[MAX];
int v[MAX];
int cnt[MAX];
set<int>Set;

int T;

bool cmp(query &a, query &b) {
    int block_a = a.l/block, block_b = b.l/block;
    if(block_a == block_b)
        return a.r < b.r;
    return block_a < block_b;
}

bool cmp2(query &a,query &b){
	if(a.l/block !=b.l/block)   return a.l < b.l;
	if((a.l/block)&1)           return a.r < b.r;
	return a.r > b.r;
}

void add(int x) {       // Add x'th value in range
    T = v[x];
    ++cnt[T];
    if(cnt[T] == 1)
        Set.insert(T);
    else if(Set.count(T))
        Set.erase(T);
}


void remove(int x) {    // Remove x'th value from range
    int T = v[x];
    --cnt[T];
    if(cnt[T] == 1)
        Set.insert(T);
    else if(Set.count(T))
        Set.erase(T);
}


int main() {
    int n, Q;

    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    scanf("%d", &Q);
    for(int i = 0; i < Q; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r);
        --q[i].l, --q[i].r;
        q[i].id = i;
    }

    sort(q, q+Q, cmp2);
    int l = 0, r = -1;
    
    //cerr << "DONE\n";
    
    for(int i = 0; i < Q; ++i) {
        while(l > q[i].l)   add(--l);
        while(r < q[i].r)   add(++r);
        while(l < q[i].l)   remove(l++);
        while(r > q[i].r)   remove(r--);
        
        /*for(int i = 0; i < 10; ++i)
            cerr << i << " : " << cnt[i] << endl;
        cerr << "--------------\n";
        for(auto it : Set)
            cerr << it << " ";
        cerr << endl;*/
        
        ans[q[i].id] = (Set.empty() ? 0:*Set.begin());                     // Add Constraints
    }

    for(int i = 0; i < Q; ++i)
        printf("%d\n", ans[i]);

    return 0;
}
