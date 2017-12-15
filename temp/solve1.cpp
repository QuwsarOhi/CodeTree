#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mem (a, b) memset (a, b, sizeof (a))

const  int N = 1e5 + 5 ;
const  int MOD = 1e9 + 7 ;
int a[N];
int cnt[75];
int dp[75] [(1<<19)+5];
int s[75];
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int _2p [N];

int main () {
    ios :: sync_with_stdio (false);
    cin.tie (0);
    
    for (int i = 1; i<=70; i++) {
        int t = i;
        for(int j = 0; j<19; j++) {
            while(t % prime[j] == 0) {
                t /= prime[j];
                s[i] ^ = (1 << j);
            }
        }
    }
    
    _2p[0] = 1 ;
    
    for(int I=1; I < N; I++) 
        _2p[I] = (_2p[I-1]*2 )%MOD;
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++ ;
    }
    dp[0][0] = 1;
    
    for (int i = 1; i <= 70; i++) {
        if (!cnt[i]) {
            for(int j = 0; j < (1<<19); j++)
            dp[i][j] = dp[i-1][j];
        }
        else {
            for ( int j = 0 ; j <( 1 << 19 ); j ++) {
                dp [i] [j ^ s [i]] = ((ll) dp [i] [j ^ s [i]] + (ll) _2p [cnt [i] -1 ] * dp [i- 1 ] J]) the MOD%; // from cnt [i] a number selected from an odd number, C (n-,. 1) + C (n-,. 3) ^ 2 + ... = (. 1-n-) 
                DP [I] [ j] = ((11) dp [i] [j] + (ll) _2p [cnt [i] -1 ] * dp [i- 1 ] [j])% MOD; // from cnt [i] C (n, 0) + C (n, 2) * C (n, 4) + ... = 2 ^ (n-1) 
            }
        }
    }
    cout << (dp [ 70 ] [ 0 ] - 1 )% MOD << endl; // Subtract 0 from case
return  0 ;}