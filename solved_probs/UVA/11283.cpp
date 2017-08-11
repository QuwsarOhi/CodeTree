//UVa
//11283 - Playing Boggle

#include<bits/stdc++.h>
using namespace std;

int score, P_len, r[] = {-1, -1, -1, 0, 0, 1, 1, 1}, c[] = {-1, 0, 1, -1, 1, -1, 0, 1}, A[30];
char S[5][5], P[30];
bool found, visited[5][5];

void Backtrack(int i, int j, int word_count)
{
    if(i < 0 || i >= 4 || j < 0 || j >= 4 || word_count >= P_len)
        return;
    if(S[i][j] != P[word_count])
        return;
    word_count++;
    visited[i][j] = 1;
    if(word_count == P_len) {
        found = 1;
        visited[i][j] = 0;
        return;
    }
    for(int p = 0; p < 8 && !found; p++) {
        int x = i+r[p];
        int y = j+c[p];
        if(!visited[x][y])
            Backtrack(x, y, word_count);
    }
    visited[i][j] = 0;
}

void score_counter(int n)
{
    if(n == 3 || n == 4)
        score++;
    else if(n == 5)
        score+= 2;
    else if(n == 6)
        score+= 3;
    else if(n == 7)
        score+= 5;
    else if(n >= 8)
        score+= 11;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t, q;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                scanf(" %c", &S[i][j]);
        scanf(" %d", &q);
        score = 0;
            for(int i = 0; i < 5; i++)
                for(int j = 0; j < 5; j++)
                    visited[i][j] = 0;
        while(q--) {
            scanf(" %s", P);
            P_len = strlen(P);
            found = 0;
            for(int i = 0; i < 4 && !found; i++)
                for(int j = 0; j < 4 &&!found; j++)
                    if(!visited[i][j]) {
                        found = 0;
                        Backtrack(i, j, 0);
                        if(found)
                            score_counter(P_len);
                    }
        }
        printf("Score for Boggle game #%d: %d\n", Case, score);
    }
    return 0;
}
