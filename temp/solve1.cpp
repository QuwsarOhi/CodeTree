#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

/*vector<int> INSERT(vector<int> &v, int pstP, int newP, int len) {
    int T1 = v[pstP];
    vector<int>VV;
    
    for(int i = 0; i < len; ++i) {
        if(i == pstP) continue;
        if(i == newP) VV.push_back(T);
        else VV.push_back(v[i]);
    }
}*/

//                0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
bool isPrime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1};

void PRINTER(vi v, bool nl = 1) {
    for(auto it : v)
        cout << it << " ";
    if(nl) cout << endl;
}

// BUG
vi GETVEC(vi &u, int p1, int p2, bool kk) {
    int l = max(0, p1-1);
    int r = min((int)u.size()-1, p1+1);
    vi v = u;
    int t1 = v[p1], t2 = v[p2];
    
    if(kk) {
        v.erase(v.begin()+p2);
        cout << "AFTER ERASE\n";
        PRINTER(v);
        cout << "L " << l << endl;
        v.insert(v.begin()+l, t2);
        PRINTER(v);
    }
    else {
        v.erase(v.begin()+p1);
        v.insert(v.begin()+r, t1);
    }
    return v;
}

map<vi, int>vis;
vi v;

int BFS(vi u) {
    vis.clear();
    priority_queue<vi>pq;
    pq.push(u);
    vis[u] = 0;
    
    cout << "START" << endl;
    
    while(!pq.empty()) {
        u = pq.top();
        int w = vis[u];
        pq.pop();
        
        cout << "LLOOOP" << endl;
        
        bool ok = 1;
        for(int i = 1; i < (int)u.size(); ++i)
            if(abs(u[i-1]) > abs(u[i])) ok = 0;
        if(ok) return w;
        
        cout << "FROM" << endl;
        PRINTER(u, 0);
        cout << "TO" << endl;
        for(int i = 0; i < (int)u.size(); ++i)
            for(int j = 0; j < (int)u.size(); ++j)
                if(isPrime[abs(v[i]+v[j])] && ((v[i] < 0 && v[j] > 0) || (v[i] > 0 && v[j] < 0))) {
                    cout << "FOUND " << i << " " << j << endl;
                    v = GETVEC(u, i, j, 0);
                    if(vis.find(v) == vis.end()) {
                        cout << endl;
                        PRINTER(v);
                        vis[v] = w+1;
                        pq.push(v);
                    }
                    
                    v = GETVEC(u, i, j, 1);
                    if(vis.find(v) == vis.end()) {
                        cout << endl;
                        PRINTER(v);
                        vis[v] = w+1;
                        pq.push(v);
                    }
                }
        getchar();
    }
    
    return -1;
}


int main() {
    int t, x;
    scanf("%d", &t);
    
    
    for(int Case = 1; Case <= t; ++Case) {
        v.clear();
        for(int i = 0; i < 8; ++i) {
            scanf("%d", &x);
            v.push_back(x);
        }
        
        int ans = BFS(v);
        printf("Case %d: %d", Case, ans);
    }
    return 0;
}
