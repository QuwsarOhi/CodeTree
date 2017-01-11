//UVa
//11878 - Homework Checker

#include<bits/stdc++.h>
using namespace std;

int main()
{
    /*string x = "12+24=?";
    regex r1("(\\d+)([+-])(\\d+)[=]((\\d+)|\\?)");
    smatch m;
    regex_search(x, m, r1);
    for(auto y:m) cout << "test: " <<y <<"\n";
    return 0;*/
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int a, b, c, cnt = 0;
    char x, y[5];
    while(scanf(" %d", &a) != EOF) {
        scanf(" %c", &x);
        scanf(" %d", &b);
        getchar();
        scanf(" %s", y);
        //printf("%d%c%d%s\n", a, x, b, y);
        if(ispunct(y[0])) continue;
        int len = strlen(y);
        c = 0;
        for(int i = 0; i < len; i++) { c*=10; c += y[i] - '0';}
        if(x == '+')
            if(a+b == c) cnt++;
        if(x == '-') {
            //printf("%d", c);
            if(a-b == c) cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
