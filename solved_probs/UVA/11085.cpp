//UVa
//11085 - Back to the 8-Queens
#include<bits/stdc++.h>

using namespace std;

int row[8], t_row[8], min_step, step, c = 1;

bool place(int r, int c)
{
    for(int prev_col = 0; prev_col < c; prev_col++)
        if(t_row[prev_col] == r || abs(t_row[prev_col] - r) == abs(c - prev_col))
            return false;
    return true;
}

void backtrack(int c)
{
    if(c == 8) {
        step = 0;
        for(int i = 0; i < 8; i++) {
            if(t_row[i] != row[i]) step++;
        }
        min_step = min(min_step, step);
        return;
    }
    for(int r = 0; r < 8; r++) {
        if(place(r, c)) {
            t_row[c] = r;
            backtrack(c+1);
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    while(scanf("%d %d %d %d %d %d %d %d", &row[0], &row[1], &row[2], &row[3], &row[4], &row[5], &row[6], &row[7])!= EOF) {
        for(int i = 0; i < 8; i++) --row[i];    //converting to 0 based index
        min_step = 12;
        backtrack(0);
        printf("Case %d: %d\n", c++, min_step);
    }
    return 0;
}
