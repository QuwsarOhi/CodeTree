//UVa
//750 - 8 Queens Chess Problem
#include<bits/stdc++.h>

using namespace std;

int row[8], a, b, line;

bool place(int r, int c)
{
    for(int prev_column = 0; prev_column < c; prev_column++)    //checking previously placed queens if they are in same row or in diagonal positions
        if(row[prev_column] == r || (abs(row[prev_column] - r) == abs(c-prev_column)))
            return false;
    return true;
}

void backtrack(int c)               //c = column value
{
    if(c == 8 && row[b] == a) {     //if 8 queens are placed and one queen is placed in (a, b) place, else try other solutions
        printf("%2d      %d", line++, row[0]+1);    //printing the solutions
        for(int j = 1; j < 8; j++) printf(" %d", row[j]+1);
        printf("\n");
    }
    for(int r = 0; r < 8; r++)      //check if queen can be placed all row
        if(place(r, c)) {           //check if queen can be placed in this row
            row[c] = r;             //if it can be placed, we save the row[column] = row
            backtrack(c+1);         //now move to the next column
        }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &a, &b);     //initial row and column where queen must be placed
        a--; b--;                   //converting to 0 based operation
        memset(row, 0, sizeof(row));
        line = 1;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0);               //generating solutions starting from column 1 (0 in this system)
        if(t) printf("\n");
    }
    return 0;
}
