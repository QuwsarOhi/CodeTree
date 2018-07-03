// LightOJ
// http://lightoj.com/volume_showproblem.php?problem=1141

#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

bitset<MAX>isPrime;
int divisor[MAX];

void sieve(long long lim = 1001) {             // Prime numbers for the limit should be sieved, otherwise WA
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(int i = 0; i <= lim; ++i) {
        if(isPrime[i]) {
            for(long long j = i; j <= lim; j += i) {
                isPrime[j] = 0;
                divisor[j] = i;
}}}}

vector<int> factorize(long long x) {    // This function only iterates over the prime numbers
    vector<int>factor;
    while(x > 1) {
        if(divisor[x] != 0) {
            factor.push_back(divisor[x]);
            x /= divisor[x];            // now x would be reduced by factor of divisor[x]
    }}
    return factor;
}

vector<int>PF[MAX];
void FactorINIT(int lim = 1000) {
    for(int i = 1; i <= lim; ++i) {
        PF[i] = factorize(i);
        if(!PF[i].empty() && PF[i].back() == i)
            PF[i].pop_back();
    }
}

bitset<MAX>vis;
int BFS(int u, int t) {
    vis.reset();
    vis[u] = 1;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, u));
    
    while(!pq.empty()) {
        int d = -pq.top().first;
        u = pq.top().second;
        pq.pop();
        
        if(u == t)
            return d;
        
        ++d;
        for(int i = 0; i < (int)PF[u].size(); ++i) {
            //cerr << "FROM " << u << " GOT " << PF[u][i] << endl;
            int v = u+PF[u][i];
            if(vis[v] || v > t)
                continue;
            vis[v] = 1;
            pq.push(make_pair(-d, v));
    }}
    return -1;
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int t, S, T;
    scanf("%d", &t);
    sieve();
    FactorINIT();
    
    //cerr << PF[2][0] << endl;
    
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &S, &T);
        printf("Case %d: %d\n", Case, BFS(S, T));
    }
    return 0;
}
        

