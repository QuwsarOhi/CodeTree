https://toph.co/s/105765
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
#define endl         '\n'
#define clr(V)       V.clear()
#define sz(V)        V.size()
#define SORT(V)      sort( V.begin(), V.end() )
#define MEM(a,x)     memset( a, x, sizeof(a) )
#define FOR(i,a,b)   for( int i = a; i <= b; i++ )

int ara[ 10*N ];
int NOD[ 10*N ];
int n , q , l = 1 , r = 0;
int cnt[ 10*N ] , Ans[ 10*N ] , res[ 10*N ];

const int block = 320;

struct query {
    int l , r , id , val;
    bool operator <( const query &q ) const {
        int block_a = l/block;
        int block_b = q.l/block;
        if( block_a == block_b ) return ( r < q.r );
        else return ( block_a < block_b );
    }
} Q[ N ];

void calc( ) {
    for( int i = 1; i <= 10*N; i++ ) {
        for( int j = i; j <= 10*N; j += i ) {
            NOD[j]++;
        }
    }
}
void Remove( int idx ) {
    int x = ara[idx];
    cnt[x]--;
    if( cnt[x] == 0 ) res[ NOD[x] ]--;
}
void Add( int idx ) {
    int x = ara[idx];
    cnt[x]++;
    if( cnt[x] == 1 ) res[ NOD[x] ]++;
}
void MO( ) {
    sort( Q+1 , Q+q+1 );
    l = 1 , r = 0;
    FOR( i , 1 , q ) {
        while( l < Q[i].l ) Remove( l++ );
        while( l > Q[i].l ) Add( --l );
        while( r < Q[i].r ) Add( ++r );
        while( r > Q[i].r ) Remove( r-- );
        Ans[ Q[i].id ] = res[ Q[i].val ];
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    calc( );
    FOR( tc , 1 , t ) {
        int n;
        scanf("%d",&n);
        FOR( i , 1 , n ) scanf("%d",&ara[i]);
        scanf("%d",&q);
        FOR( i , 1 , q ) {
            scanf("%d %d %d",&Q[i].l,&Q[i].r,&Q[i].val);
            Q[i].id = i;
        }
        MO( );
        printf("Case %d:\n",tc);
        FOR( i , 1 , q ) printf("%d\n",Ans[i]);
        MEM( cnt , 0 );
        MEM( res , 0 );
    }
    return 0;
}
