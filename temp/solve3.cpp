#include <bits/stdc++.h>
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define INF 1e8
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int G[8], r, c;
int dp[8][(1<<8)+10][(1<<8)+10];

void TOGGLE(int x, int y) {
    for(int i = 0; i < 9; ++i) {
        int _x = x+dx[i], _y = y+dy[i];
        if(_x < 0 || _y < 0 || _x >= r || _y >= c)
            continue;
        toggleBit(G[_x], _y);
}}

void PRINT() {
    for(int i = 0; i < r; ++i, cout << endl)
        for(int j = c-1; j >= 0; --j)
            cout << (isOn(G[i], j)?1:0) << " ";
    cout << endl;
}

int recur(int x, int y) {
    if(y == c) ++x, y = 0;
    
    for(int i = 0; i < x-1; ++i)
        if(G[i] != 0)
            return INF;
    
    if(x == r) {
        if(G[x-1] == 0) PRINT();
        return (G[x-1]==0 ? 0:INF);
    }
    
    int &ret = dp[x][G[x]][G[x+1]];
    if(ret != -1) {
        cout << "HIT " << x << " " << y << " " << G[x-1] << " " << G[x] << endl;
        //PRINT();
        //getchar();
        return ret;
    }
    
    ret = recur(x, y+1);
    TOGGLE(x, y);
    ret = min(ret, recur(x, y+1)+1);
    TOGGLE(x, y);
    
    //cout << "Saved " << x << " " << y << " " << G[x-1] << " " << G[x] << endl;
    //PRINT();
    //getchar();
    
    return ret;
}


int main() {
    int t;
    char ch;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; ++Case) {
        scanf("%d%d", &r, &c);
        for(int i = 0; i < r; ++i) {
            G[i] = 0;
            for(int j = 0; j < c; ++j) {
                scanf(" %c", &ch);
                if(ch == '.')
                    setBit(G[i], j);
            }
        }
        
        memset(dp, -1, sizeof dp);
        cout << recur(0, 0) << endl;
    }
    return 0;
}
