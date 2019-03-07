#include <bits/stdc++.h>
#define MAX 100009
using namespace std;

int block, pos[MAX], v[MAX], jump[MAX];

// retuns block range of index
void getRange(int idx, int n, int &l, int &r) {
    l = (idx/block)*block;
    r = l+block-1;
    r = min(r, n-1);
}

void segmentCal(int idx, int n) {
    int l, r;
    getRange(idx, n, l, r);
    //cerr << "BLOCK " << idx/block << endl;

    for(int i = r; i >= l; --i) {
        if(i+v[i] <= r)
            pos[i] = pos[i+v[i]] + v[i];
        else
            pos[i] = v[i];
    }
    
    for(int i = r; i >= l; --i) {
        if(i+v[i] <= r)
            jump[i] = jump[i+v[i]]+1;
        else
            jump[i] = 1;
        //cerr << i << " --> " << pos[i] << " " << jump[i] << endl;
    }
}

void update(int idx, int val, int n) {
    v[idx] = val;
    segmentCal(idx, n);
}

pair<int, int> query(int idx, int n) {
    int jumps = 0;
    //cerr << "Query " << idx << endl;
    while(idx + pos[idx] < n) {
        jumps += jump[idx];
        idx = idx + pos[idx];
        //cerr << idx << " ** " << jumps << endl;
    }
    while(idx + v[idx] < n) {
        idx = idx + v[idx], ++jumps;
        //cerr << idx << " ** " << jumps << endl;
    }
    return make_pair(idx, jumps);
}

void build(int n) {
    block = sqrt(n + .0) + 1;
    //cerr << "BLOCK SIZE " << block << endl;
    for(int i = 0; i-1 < n; i += block)
        segmentCal(i, n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, typ, a, b;
    cin >> n >> m;

    for(int i = 0; i < n; ++i)
        cin >> v[i];

    build(n);

    while(m--) {
        cin >> typ >> a;
        
        if(typ == 1) {
            pair<int, int> p;
            p = query(--a, n);
            cout << p.first+1 << " " << p.second+1 << "\n";
        }
        else {
            cin >> b;
            update(--a, b, n);
        }
    }
    return 0;
}