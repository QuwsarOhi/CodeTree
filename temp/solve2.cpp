// LightOJ
// 1207 - Posters for Election

#include <bits/stdc++.h>
using namespace std;

set<pair<pair<int, int>, int> >Set;
bitset<101000>found;

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, n, l, r, poster = 0;
    
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d", &n);
        poster = 0;
        
        while(n--) {
            scanf("%d%d", &l, &r);
            
            poster++;
            pair<pair<int, int>, int> pi = make_pair(make_pair(l, -1), -1);
            set<pair<pair<int, int>, int> > :: iterator it = Set.lower_bound(pi);
            
            while(it != Set.end() && it->first.second <= r) {
                int segL = it->first.second;
                int segR = it->first.first;
                int pastPoster = it->second;
                
                Set.erase(it++);
                
                if(segL < l)
                    Set.insert(make_pair(make_pair(l-1, segL), pastPoster));
                if(segR > r)
                    Set.insert(make_pair(make_pair(segR, r+1), pastPoster));
            }
            
            Set.insert(make_pair(make_pair(r, l), poster));
        }
        
        set<pair<pair<int, int>, int> > :: iterator it = Set.begin();
        found.reset();
        
        while(it != Set.end()) {
            found[it->second] = 1;
            ++it;
        }
        
        Set.clear();
        printf("Case %d: %d\n", Case, int(found.count()));
    }
    
    return 0;
}
