// SOPJ
// ARRAYSUB

#include <bits/stdc++.h>
#define MOD 998244353
#define MAX 1000100
#define dd(XX)       cerr << #XX << " :: " << XX << endl;
using namespace std;
typedef long long ll;

int v[MAX];
multiset<int>s;

int main() {
    int n, k, r;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    scanf("%d", &k);
    for(r = 0; r < k; ++r)
        s.insert(-v[r]);

    printf("%d", -(*s.begin()));


    while(r < n) {
        auto it = s.find(-v[r-k]);
        s.erase(it);
        s.insert(-v[r++]);

        printf(" %d", -(*s.begin()));
    }

    printf("\n");
    return 0;
}
