// Toph
// https://toph.co/p/palindromist

// Prefix and Suffix Hash

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long>pll;

const ll p = 31;
const ll mod1 = 1e9+9;
const ll mod2 = 1e9+7;

vector<pll> Power;


// Genarates Powers
void PowerGen(int n) {
    Power.resize(n+1);
    Power[0] = {1, 1};
    
    for(int i = 1; i < n; ++i) {
        Power[i].first = (Power[i-1].first * p)%mod1;
        Power[i].second = (Power[i-1].second * p)%mod2;
    }
}

pll prefixHash(char *s, int len) {
    ll hashVal1 = 0, hashVal2 = 0;
    
    for(int i = 0; i < len; ++i) {
        hashVal1 = (hashVal1 + (s[i] - 'a' + 1)* Power[i].first)%mod1;
        hashVal2 = (hashVal2 + (s[i] - 'a' + 1)* Power[i].second)%mod2;
    }
    return {hashVal1, hashVal2};
}

pll suffixHash(char *s, int len) {
    ll hashVal1 = 0, hashVal2 = 0;
    
    for(int i = 0, j = len-1; i < len ; ++i, --j) {
        hashVal1 = (hashVal1 + (s[j] - 'a' + 1)* Power[i].first)%mod1;
        hashVal2 = (hashVal2 + (s[j] - 'a' + 1)* Power[i].second)%mod2;
    }
    return {hashVal1, hashVal2};
}

char s[10100];

int main() {
    int t, len, q, k;
    char typ, c;
    PowerGen(1100000);
    
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf(" %s", s);
        len = strlen(s);
        
        pll pHash = prefixHash(s, len);
        pll sHash = suffixHash(s, len);
        
        scanf("%d", &q);
        printf("Case %d:\n", Case);
        
        while(q--) {
            scanf(" %c %c %d", &typ, &c, &k);
            c = c - 'a' + 1;
            
            if(typ == 'L') {
                // Prefix Add
                
                pHash.first = ((ll)pHash.first * Power[k].first)%mod1;
                pHash.second = ((ll)pHash.second * Power[k].second)%mod2;
                
                for(int i = 0; i < k; ++i) {
                    pHash.first = (pHash.first + ((ll)c*Power[i].first)%mod1)%mod1;
                    pHash.second = (pHash.second + ((ll)c*Power[i].second)%mod2)%mod2;
                }
                
                // Suffix Add
                for(int i = len; i < k+len; ++i) {
                    sHash.first = (sHash.first + ((ll)c*Power[i].first)%mod1)%mod1;
                    sHash.second = (sHash.second + ((ll)c*Power[i].second)%mod2)%mod2;
                }
            }
            else {
                // Prefix Add
                for(int i = len; i < len+k; ++i) {
                    pHash.first = (pHash.first + ((ll)c*Power[i].first)%mod1)%mod1;
                    pHash.second = (pHash.second + ((ll)c*Power[i].second)%mod2)%mod2;
                }
                
                // Suffix Add
                sHash.first = ((ll)sHash.first * Power[k].first)%mod1;
                sHash.second = ((ll)sHash.second * Power[k].second)%mod2;
                
                for(int i = 0; i < k; ++i) {
                    sHash.first = (sHash.first + ((ll)c*Power[i].first)%mod1)%mod1;
                    sHash.second = (sHash.second + ((ll)c*Power[i].second)%mod2)%mod2;
                }
            }
            
            len += k;
            printf("%s\n", pHash == sHash ? "Yes":"No");
        }
    }
    
    return 0;
}


/*
1
aba
5
L b 2
R b 1
R b 1
L z 3
R z 3
*/
