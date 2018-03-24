// CodeChef
// The Gift Of Raksha Bandhan
// https://www.codechef.com/problems/INSQ15_A

// Longest Substring Matching
// Hashing With Binary search

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  pair<ll, ll>pll;

const ll p = 31;
const ll mod1 = 1e9+9, mod2 = 1e9+7;

vector<pll>Power(5010000);

// Genarates Powers
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
    }
}

// Returns Double Hash vector for a full string
vector<pair<ll, ll> > doubleHash(char *s, int len) {
    ll hashVal1 = 0, hashVal2 = 0;
    vector<pair<ll, ll> >v;
    
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[i].first)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[i].second)%mod2;
        v.push_back({hashVal1, hashVal2});
    }
    
    return v;
}


char s[5100000];
vector<pll>Hash;

int main() {
    scanf("%s", s);
    int len = strlen(s), q, l;
    
    PowerGen(len+10);
    Hash = doubleHash(s, len);
    
    scanf("%d", &q);
    
    while(q--) {
        scanf("%d", &l);
        
        int low = 1, hi = l, ans = -1;
        
        while(low <= hi) {
            int mid = ((low+hi)>>1);
            
            pll SubStrHash;
            SubStrHash.first = (Hash[l+mid-1].first - Hash[l-1].first + mod1)%mod1;
            SubStrHash.second = (Hash[l+mid-1].second - Hash[l-1].second + mod2)%mod2;
            
            pll prefHash;
            prefHash.first = (Hash[mid-1].first * Power[l].first)%mod1;
            prefHash.second = (Hash[mid-1].second * Power[l].second)%mod2;
            
            if(prefHash == SubStrHash) {
                ans = mid;
                low = mid+1;
            }
            else
                hi = mid-1;
        }
        
        if(ans == -1)
            printf("0\n");
        else
            printf("%d\n", ans);
    }
    
    return 0;
}
