#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

map<ull, vector<ull> >S;
vector<ull>T;
map<ull, ull>Count;
map<ull, bool>seg;
set<ull>SET;

ull ans[200010];

int main() {
    int n;
    ull l, r;
    
    scanf("%d", &n);
    
    
    for(int i = 0; i < n; ++i) {
        scanf("%llu%llu", &l, &r);
        S[l].push_back(i);
        S[r].push_back(i);
    }
    
    for(auto p1 = S.begin(); p1 != S.end(); ++p1) {
        //cout << vec.first << endl;
        for(auto it : p1->second) {
            if(SET.count(it))       // ERASE LATER
                T.push_back(it);
            else
                SET.insert(it);
        }
        
        cout << "POINT " << SET.size() << " : " << p1->first << endl;
        ans[SET.size()]++;
        
        while(!T.empty()) {
            SET.erase(T.back());
            T.pop_back();
        }
        
        auto p2 = p1;
        p2++;
        
        if(p2 != S.end()) {
            cout << "SEGMENT " << SET.size() << " : " << p2->first-1 << " -- " << p1->first+1 << endl;
            ans[SET.size()] += max(0LL, (long long)p2->first - (long long)p1->first - 1LL);
        }
    }
    
    for(int i = 1; i < n; ++i)
        printf("%llu ", ans[i]);
    printf("%llu\n", ans[n]);
    
    return 0;
}

/*

4
1 10
5 20
50 100
25 200
 
8
1 10
3 7
7 8
2 7
4 3
9 20
15 18
17 30 

*/
