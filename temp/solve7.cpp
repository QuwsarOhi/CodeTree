// SPOJ
// http://www.spoj.com/problems/ADACLEAN/
// ADACLEAN - Ada and Spring Cleaning

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll p = 31;
const ll mod1 = 1e9+9;
const ll mod2 = 1e9+7;

vector<pll>Power, Hash;
map<pll, bool>PrevHash;
char s[101000];

// Genarates Powers
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
    }
}


int main() {
    int t, len, k;
    
    scanf("%d", &t);
    PowerGen(101000);
    
    const ll LIM = 100100;
    
    while(t--) {
        scanf("%d%d", &len, &k);
        scanf(" %s", s);
        
        int cnt = 0;
        ll hashVal1 = 0, hashVal2 = 0;
        for(int i = 0; i < len; ++i) {
            hashVal1 = (hashVal1 + (s[i] - 'a' + 1)*Power[i].first)%mod1;
            hashVal2 = (hashVal2 + (s[i] - 'a' + 1)*Power[i].second)%mod2;
            
            Hash.push_back({hashVal1, hashVal2});
            
            if(i >= k-1) {
                pll blockHash;
                
                blockHash.first = (hashVal1 - (i-k >= 0 ? Hash[i-k].first:0) + mod1)%mod1;
                blockHash.second = (hashVal2 - (i-k >= 0 ? Hash[i-k].second:0) + mod2)%mod2;
                
                blockHash.first = (blockHash.first * Power[LIM-i].first)%mod1;
                blockHash.second = (blockHash.second * Power[LIM-i].second)%mod2;
                
                if(PrevHash.find(blockHash) != PrevHash.end())
                    continue;
                
                PrevHash[blockHash] = 1;
                ++cnt;
            }
        }
        
        printf("%d\n", cnt);
        PrevHash.clear();
        Hash.clear();
    }
    
    return 0;
}
