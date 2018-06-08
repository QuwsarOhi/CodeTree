// Toph
// Game of Tic-Tac-Toe
// https://toph.co/p/game-of-tic-tac-toe

#include <bits/stdc++.h>
#define MAX 3
#define isOn(XX, II)        (XX & (1 << II))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
using namespace std;

bool Check(const int m[]) {
    bool ok;
    for(int i = 0; i < MAX; ++i)
        if(m[i] == (1 << MAX) - 1)
            return 1;
    
    for(int j = 0; j < MAX; ++j) {
        ok = 1;
        for(int i = 0; i < MAX; ++i)
            if(not isOn(m[i], j))
                ok = 0;
        if(ok) return 1;
    }
    
    ok = 1;
    for(int i = 0, j = 0; i < MAX; ++i, ++j)
        if(not isOn(m[i], j))
            ok = 0;
    if(ok) return 1;
    
    ok = 1;
    for(int i = MAX-1, j = 0; i >= 0; --i, ++j)
        if(not isOn(m[i], j))
            ok = 0;
    if(ok) return 1;
    
    return 0;
}

void Board(const int m[]) {
    bitset<3>b(m[0]), c(m[1]), d(m[2]);
    
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
}

int dp[2][1<<4][1<<4][1<<4];
int recur(bool player, int m[], int lvl = 0) {
    if(Check(m))
        return player;
    
    if(dp[player][m[0]][m[1]][m[2]] != -1)
        return dp[player][m[0]][m[1]][m[2]];
    
    for(int i = 0; i < MAX; ++i)
        for(int j = 0; j < MAX; ++j)
            if(not isOn(m[i], j)) {
                setBit(m[i], j);
                bool ret = recur(not player, m, lvl+1);
                clearBit(m[i], j);
                if(ret == player)
                    return player;
            }

    return (dp[player][m[0]][m[1]][m[2]] = not player);
}


int main() {
    int t, m[3];
    char c;
    scanf("%d", &t);
    
    for(int Case = 1; Case <= t; ++Case) {
        for(int i = 0; i < MAX; ++i) {
            m[i] = 0;
            for(int j = 0; j < MAX; ++j) {
                scanf(" %c", &c);
                if(c == 'X')
                    setBit(m[i], j);
            }
        }
        
        memset(dp, -1, sizeof dp);
        int ans = recur(0, m);
        printf("Game #%d: %s\n", Case, ans==0? "Alice":"Bob");
    }
    
    return 0;
}
