#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("in", "r", stdin);
    
    int N, K, M, v[20100];
    scanf("%d%d%d", &N, &K, &M);
    
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &v[i]);
        v[i] %= M;
    }
    
    
    int pst = 1, Ans = 0;
    for(int k = 1; k <= K; ++k) {
        int sum = 0, best = 0, pos = -1;
        
        cout << "PST " << pst << " LIM " << N-K+k << endl;
        
        for(int i = pst; i <= N-K+k; ++i) {
            sum = (sum + v[i]) % M;
            if(sum > best or k == K)
                pos = i, best = sum;
        }
        
        Ans += best;
        cout << pst << " to " << pos << endl;
        pst = pos+1;
    }
    
    printf("%d\n", Ans);
    return 0;
}
