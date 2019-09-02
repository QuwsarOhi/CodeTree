#include <bits/stdc++.h>
#define SEED 420					// MODIFY SEED TO GENERATE DIFFERENT TEST CASE
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct DSU {
    vector<int>u_list, u_set;
    DSU() {}
    DSU(int SZ) { init(SZ); }
    int unionRoot(int n) {
        if(u_set[n] == n) return n;
        return u_set[n] = unionRoot(u_set[n]);
    }
    int makeUnion(int a, int b) { 
        int x = unionRoot(a), y = unionRoot(b);
        if(x == y) return x;           
        else if(u_list[x] > u_list[y]) {      
            u_set[y] = x;
            u_list[x] += u_list[y];   
            return x;
        }
        else {                               
            u_set[x] = y;
            u_list[y] += u_list[x];       
            return y;
    }}
    void init(int len) {                       
        u_list.resize(len+5);
        u_set.resize(len+5);
        for(int i = 0; i <= len+3; i++)
            u_set[i] = i, u_list[i] = 1;  
    }
    bool isRoot(int x) {                           
        return u_set[x] == x;
    }
    bool isRootContainsMany(int x) {             
        return (isRoot(x) && (u_list[x] > 1));
    }
    bool isSameSet(int a, int b) {               
        return (unionRoot(a) == unionRoot(b));
}};

ll range(ll l, ll r) {
	ll x = (rand() + 1)%r + l;
	return x;
}


void buildTree(ll nodes) {
	cout << nodes << endl;

	DSU edges;
	edges.init(nodes+1);
	//vector<vector<ll> > G(nodes+1);

	ll edge = 0, u, v;
	while(edge < nodes-1) {
		u = range(1, nodes);
		v = range(1, nodes);

		if(u != v and not edges.isSameSet(u, v)) {
			cout << u << " " << v << "\n";
			//G[u].push_back(v);
			edges.makeUnion(u, v);
			edge++;
		}
	}
}

void GEN(ll nodes) {
	buildTree(nodes);

	ll query = range(1, 2*nodes);
	cout << query << "\n";

	while(query > 0) {
		--query;
		ll u = range(1, nodes);
		ll v = range(1, 200000);
		cout << u << " " << v << endl;
	}
}


int main() {
	srand(SEED);
	GEN(4);
	return 0;
}