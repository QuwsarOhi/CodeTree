// UVa
// 344 - Roman Digititis

#include <bits/stdc++.h>
using namespace std;

int cnt[101][5], v[] = {1, 5, 10, 50, 100};

void Seg1() {
    cnt[1][0] = 1;
    cnt[2][0] = 2;
    cnt[3][0] = 3;
    cnt[4][0] = 1;
    cnt[4][1] = 1;
    cnt[5][1] = 1;
    cnt[6][0] = 1;
    cnt[6][1] = 1;
    cnt[7][0] = 2;
    cnt[7][1] = 1;
    cnt[8][0] = 3;
    cnt[8][1] = 1;
    cnt[9][2] = 1;
    cnt[9][0] = 1;
}

void Seg2() {
    cnt[10][2] = 1;
    cnt[20][2] = 2;
    cnt[30][2] = 3;
    cnt[40][2] = 1;
    cnt[40][3] = 1;
    cnt[50][3] = 1;
    cnt[60][2] = 1;
    cnt[60][3] = 1;
    cnt[70][3] = 1;
    cnt[70][2] = 2;
    cnt[80][3] = 1;
    cnt[80][2] = 3;
    cnt[90][2] = 1;
    cnt[90][4] = 1;
    cnt[100][4] = 1;
}

void Merge(int a, int b) {
    for(int i = 0; i < 5; ++i)
        if(cnt[a][i])
            cnt[b][i] += cnt[a][i];
}

void SegJoin() {
    for(int i = 10; i <= 90; i+=10)
        for(int j = 1; j <= 9; ++j)
            Merge(i, i+j);
    for(int i = 11; i <= 100; ++i)
        if(i%10 != 0)
            Merge(i%10, i);
}


int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    Seg1();
    Seg2();
    SegJoin();
    
    for(int i = 1; i <= 100; ++i)
        for(int j = 0; j < 5; ++j)
            cnt[i][j] += cnt[i-1][j];
    
    int n;
    while(scanf("%d", &n) and n)
        printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, cnt[n][0], cnt[n][1], cnt[n][2], cnt[n][3], cnt[n][4]);

    return 0;
}
