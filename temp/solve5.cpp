// Toph
// https://toph.co/p/chikongunia

// HashValue Manipulation

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pll;

const ll p = 31;
const ll mod1 = 1e9+9;
const ll mod2 = 1e9+7;

map<pll, int>PrevHash;
vector<pll>Hash, Power;

// Genarates Powers
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
    }
}

pll HashCal(char *s, int len) {
    ll hashVal1 = 0, hashVal2 = 0;
    
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[i].first)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[i].second)%mod2;
    }
    return {hashVal1, hashVal2};
}


pll ChangeHash(pll hash, int pos, char newChar, char oldChar) {
    hash.first -= ((oldChar - 'a' + 1) * Power[pos].first)%mod1;
    hash.second -= ((oldChar - 'a' + 1) * Power[pos].second)%mod2;
    
    hash.first = (hash.first + (newChar - 'a' + 1) * Power[pos].first + mod1)%mod1;
    hash.second = (hash.second + (newChar - 'a' + 1) * Power[pos].second + mod2)%mod2;
    
    return hash;
}

char s[1000100];

int main() {
    ll n, Ans = 0, len;
    
    scanf("%lld%lld", &n, &len);
    PowerGen(len+5);
    
    for(int i = 0; i < n; ++i) {
        scanf(" %s", s);
        
        pll HashVal = HashCal(s, len);
        
        for(int i = 0; i < len; ++i)
            for(int c = 'a'; c <= 'z'; ++c) {
                if(c == s[i])
                    continue;
                pll ModifiedHash = ChangeHash(HashVal, i, c, s[i]);
                if(PrevHash.find(ModifiedHash) != PrevHash.end())
                    Ans += PrevHash[ModifiedHash];
            }
            
        PrevHash[HashVal]++;
    }
    
    printf("%lld\n", Ans);
    
    return 0;
}
