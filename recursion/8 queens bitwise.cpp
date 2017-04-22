//UVa
//11195 - Another n-Queen Problem
//Tricky Bitwise Backtracking

#include <bits/stdc++.h>
using namespace std;

int ALL, col, cnt, blockR, blockC;

map<pair<int, int>, bool>mp;

void bitPrint(int n)
{
    for(int i = 10; i >= 0; i--) {
        if(n & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

//row, column, leftDiagonal, rightDiagonal
//placing queen in row major order
//we check if it is possible to place the queen in that row(of a fix column)
//if so, move forward
void backtrack(int r, int c, int ld, int rd)
{
    //ALL = n number of 1 in bitset (starting from least)
    if(r == ALL) {  //if all rows are taken
        cnt++;
        return;
    }

    //pos = (those bits which we want to work with(to avoid overflow)) & (~(row where queen placed | if left diagonal attacked || if right diagonal attacked))
    int pos = ALL & (~(r | ld | rd));       //negate the or, so the set bits are accessable
    //there are also set bits, whose position is greater than n, so to turn them off, we used ALL with it (&)

    while(pos) {                        //pos is the suitable places for placing queen, place queen in each position, and move forward
        int place = pos & -pos;         //get right most set bit
        pos -= place;                   //turn of the right most set bit from place
        if(mp[make_pair(place, 1 << c)])    //checking if the place can be used
            continue;
        //for each (left to right)column left diagonal moves left from the queens place(s), right diagonal moves right from the queens place(s)
        backtrack(r | place, c+1, (ld | place) << 1, (rd | place) >> 1);
    }
}

int main()
{
    int n, Case = 1;
    char c;
    while(scanf("%d", &n) && n) {
        blockR = blockC = col = cnt =  0;
        ALL = (1 << n) - 1;         //bit trick, set all n bits
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                scanf(" %c ", &c);
                if(c == '*')
                    mp[make_pair(1 << i, 1 << j)] = 1;
            }

        backtrack(0, 0, 0, 0);
        printf("Case %d: %d\n", Case++, cnt);
        mp.clear();
    }
    return 0;
}
