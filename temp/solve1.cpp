#include <bits/stdc++.h>
using namespace std;


vector<int>A[1000];
int N, K, M, v[20100];

int recur(int pos, int k, int tSum, int sum) {
    if(pos == N and k == K-1) {
        
        cout << sum+tSum%M << " ------------- " << endl;
        for(int i = 0; i <= k; ++i) {
            cout << i << " :";
            for(auto it : A[i])
                cout << " " << it;
            cout << endl;
        }
        
        return (sum + tSum%M);
    }
    
    if(k > K or pos >= N)
        return -1e6;
    
    
    int ret1 = -1, ret2 = -1;
    
    A[k].push_back(v[pos]);
    ret1 = recur(pos+1, k, tSum+v[pos]%M, sum);
    A[k].pop_back();
    

        A[k+1].push_back(v[pos]);
        ret2 = recur(pos+1, k+1, v[pos]%M, sum+tSum%M);
        A[k+1].pop_back();
    
    return max(ret1, ret2);
}

int main() {
    //freopen("in", "r", stdin);
    
    cin >> N >> K >> M;
    
    for(int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
        //v[i] %= M;
    }
    cout << "START" << endl;
    cout << recur(0, 0, 0, 0) << endl;
    return 0;
}
