//UVa
//10010 - Where's Waldorf?

#include<bits/stdc++.h>
using namespace std;

char S[60][60], P[60];
bool found;
int P_len, n, m, r[] = {-1, -1, -1, 0, 0, 1, 1, 1}, c[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void BackTrack(int i, int j, int check_pos, int p)
{
    if(i >= n || j >= m || i < 0 || j < 0 || check_pos >= P_len)
        return;
    else if(S[i][j] != P[check_pos])
        return;
    check_pos++;
    if(check_pos == P_len) {
        found = 1;
        return;
    }
    BackTrack(i+r[p], j+c[p], check_pos, p);
}


int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t, q;
    scanf("%d", &t);
    bool first = 1;
    while(t--) {
        scanf(" %d %d", &n, &m);
        if(!first)
            printf("\n");
        first = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                scanf(" %c", &S[i][j]);
                S[i][j] = tolower(S[i][j]);
            }
        scanf(" %d", &q);
        while(q--) {
            scanf(" %s", P);
            P_len = strlen(P);
            for(int i = 0; i < P_len; i++)
                P[i] = tolower(P[i]);
            found = 0;
            for(int i = 0; i < n && !found; i++)
                for(int j = 0; j < m && !found; j++) {
                    found = 0;
                    for(int p = 0; p < 8 && !found; p++)
                        BackTrack(i, j, 0, p);
                    if(found)
                        printf("%d %d\n", i+1, j+1);
                }
        }
    }
    return 0;
}
