//UVa
// 11475 - Extend to Palindrome
//Also solvable with hashing

#include<bits/stdc++.h>
using namespace std;

char S[1000010], P[1000010];
int T[1000010], len;

void BuildTable()
{
    int i = 0, j = -1;
    T[0] = -1;
    while(i < len) {
        while(j >= 0 && P[i] != P[j])
            j = T[j];
        i++, j++;
        T[i] = j;
    }
}

int KmpSegment()
{
    int i = 0, j = 0;
    while(i < len) {
        while(j >= 0 && S[i] != P[j])
            j = T[j];
        //printf("j  %d\n", j);
        i++, j++;
        if(j == len) {
            if(i-j == 0)            //Found match in i-j'th index
                return -1;          //if it is zero then the string is fully matched
            j = T[j];
        }
    }
    return j;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    while(scanf(" %s", S) != EOF) {
        len = strlen(S);
        for(int i = 0, j = len-1; i < len; i++, j--)
            P[i] = S[j];
        P[len] = '\0';
        BuildTable();
        int segment_match = KmpSegment();
        printf("%s", S);
        if(segment_match != -1)
        for(int i = segment_match; i < len; i++)
            printf("%c", P[i]);
        printf("\n");
    }
    return 0;
}
