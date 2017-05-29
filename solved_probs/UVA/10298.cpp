//UVa
//10298 - Power Strings

//Basic KMP
//Double the input string
//Count matches, then minus one

#include<bits/stdc++.h>
using namespace std;

char P[2000010], T[1000010];
int P_Size, T_Size, Table[1000010];

void PrefixTable()
{
    register int i = 0, j = -1;
    Table[0] = -1;
    while(i < T_Size) {
        while(j >= 0 && T[i] != T[j])
            j = Table[j];
        i++, j++;
        Table[i] = j;
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
            //printf("cnt %d found at %d\n", cnt, i-j);
            j = Table[j];
        }
    }
    return cnt;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    while(1) {
        scanf(" %s", T);
        T_Size = strlen(T);
        P_Size = 2*T_Size;
        if(T_Size == 1 && T[0] == '.')
            break;
        for(int i = 0; i < T_Size; i++)
            P[i] = T[i];
        for(int i = T_Size, j = 0; j < T_Size; j++, i++)
            P[i] = T[j];
        PrefixTable();
        printf("%d\n", KmpSearch()-1);
    }
    return 0;
}
