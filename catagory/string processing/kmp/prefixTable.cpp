// Codeforces
// http://codeforces.com/problemset/problem/126/B
// Automaton, PrefixTable, KMP

#include <bits/stdc++.h>
using namespace std;

// Some Tricky Cases:
// aaaaaa : 0 1 2 3 4 5
// aaaabaa : 0 1 2 3 0 1 2
// abcdabcd : 0 0 0 0 1 2 3 4

void prefixTable(int n, char pat[], int table[]) {
    int len = 0, i = 1;                     // length of the previous longest prefix suffix
    table[0] = 0;                           // table[0] is always 0
 
    while (i < n) {
        if (pat[i] == pat[len]) {
            len++;
            table[i] = len;
            i++;
        }
        else {                              // pat[i] != pat[len]
            if (len != 0)                   // find previous match
                len = table[len-1];
            else                            // if (len == 0) and mismatch
                table[i] = 0, i++;          // set table[i] = 0, and go to next index
        }
    }
}


int main() {
    char s[1000100];
    scanf("%s", s);
    int table[1000100];
    int len = strlen(s);
    prefixTable(len, s, table);
    //for(int i = 0 ; i < len; ++i)
      //  printf("%d ", table[i]);
    //int p = -1;
    if(table[len-1] != 0) {
        for(int i = 0; i < len-2; ++i) {
            if(table[i] == table[len-1]) {
                p = table[i];
                break;
            }
        }
        if(p == -1 && table[table[len-1]-1] != 0)
            p = table[table[len-1]-1];
    }
    if(p > 0) {
        for(int i = 0; i < p; ++i)
            printf("%c", s[i]);
        printf("\n");
    }
    else {
        printf("Just a legend\n");
    }
    return 0;
}
