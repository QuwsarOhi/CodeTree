#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 19;

ll dp[1 << N][N];
bool edg[N][N];

int popcount(int x){
    return __builtin_popcount(x);
}

string bit(int x) {
    bitset<5>b(x);
    return b.to_string();
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int a, b;
    for(int i = 0; i < m ; i ++ ){
        cin >> a >> b;
        a -- ;
        b -- ;
        edg[a][b] = true;
        edg[b][a] = true;
    }
    for(int i = 0; i < n; i ++ ){
        dp[1 << i][i] = 1;
    }
    int pos;
    int ones;
    ll ret = 0ll;
    for(int i = 1 ; i < (1 << n); i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            if(i & (1 << j)){
                pos = j;
                break;
            }
        }
        ones = popcount(i);

        for(int k = 0; k < n; ++k)
            cout << bit(i) << " " << k << " : " << dp[i][k] << endl;

        for(int cp = pos; cp < n; cp ++ ){
            if(!(i & (1 << cp))){
                continue;
            }

            for(int np = pos; np < n; np ++ ){
                if(!edg[cp][np])
                    continue;
                if(!(i & (1 << np))){
                    dp[i | (1 << np)][np] += dp[i][cp];
                }
                else{
                    if(np == pos and ones >= 3){
                        cout << "Added " << dp[i][cp] << " " << bit(i) << " " << cp << " " << np << " " << pos << endl;
                        ret += dp[i][cp];
                    }
                }
            } 
        }
        cout << endl;
    }
    cout << ret/2 << "\n";
    return 0;
}