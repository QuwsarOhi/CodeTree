//String Matching
//Knuth Morris Pratt
//Complexity : O(String + Token)

#include<bits/stdc++.h>
using namespace std;

char P[2000010], T[1000010];
int P_Size, T_Size, Table[1000010];

//T is the string that we need to find
//S is the string in which we have to find
//Table contains the prefix table

//builds the prefix table
void PrefixTable()
{
    register int i = 0, j = -1;
    Table[0] = -1;
    while(i < T_Size) {
        while(j >= 0 && T[i] != T[j]) {
			printf("jump to %d = Table[%d] (%d)\n", j, j, Table[j]);
            j = Table[j];
		}
        i++, j++;
        Table[i] = j;
        printf("Table[%d] = %d\n", i, j);
    }
}

int KmpSearch()
{
    register int i = 0, j = 0, cnt = 0;
    while(i < P_Size) {
        while(j >= 0 && P[i] != T[j])
            j = Table[j];
        i++, j++;
        if(j == T_Size) {
            cnt++;
			//the match found in i-j, if i-j = 0, then the string is fully matched
			//this happens when the string is equal in length of the token
			 
            //printf("%d'th Match found at %d\n", cnt, i-j); 	//the leftmost index
            j = Table[j];
        }
    }
    //j contains the first segment index that is matched in token
    return cnt;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    strcpy(T, "SEVENTY SEVEN\0");
    T_Size = strlen(T);
    PrefixTable();
    for(int i = 0; i < T_Size; i++)
		printf("%d ", Table[i]);
    return 0;
}


//------------------------Genuine PrefixTable (Prefix-Suffix Length)------------

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
