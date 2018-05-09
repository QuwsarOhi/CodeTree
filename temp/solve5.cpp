#include <bits/stdc++.h>
using namespace std;

int N, K, P, v[20100];

int V(int l, int r) {
    if(l)
        return v[r] - v[l-1];
    return v[r];
}

int recur(int k, int i) {
    if(k == 0)
        return V(0, i);
    
    int ret = -1;
    for(int j = 0; j < i; ++j)
        ret = max(recur(k-1, j) + V(j+1, i), ret);
    
    return ret;
}

int main() {
    cin >> N >> K >> P;
    
    for(int i = 0; i < N; ++i) {
        cin >> v[i];
        v[i] %= P;
        if(i) v[i] = (v[i] + v[i-1])%P;
        cout << v[i] << endl;
    }
    
    cout << recur(K, N-1) << endl;
    return 0;
}
