//LightOJ
//1113 - Discover the Web
#include<bits/stdc++.h>
using namespace std;

stack<string>for_ward, back_ward;
string current;
char a[60];

void Visit()
{
    scanf(" %s", a);
    string x;
    x = a;
    back_ward.push(current);
    current = x;
    while(!for_ward.empty())
        for_ward.pop();
    printf("%s\n", a);
}

void Forward()
{
    if(for_ward.empty())
        printf("Ignored\n");
    else {
        back_ward.push(current);
        current = for_ward.top();
        for_ward.pop();
        printf("%s\n", current.c_str());
    }
}

void Backward()
{
    if(back_ward.empty())
        printf("Ignored\n");
    else {
        for_ward.push(current);
        current = back_ward.top();
        back_ward.pop();
        printf("%s\n", current.c_str());
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int Case = 1; Case <= t; Case++) {
        current = "http://www.lightoj.com/";
        printf("Case %d:\n", Case);
        while(!for_ward.empty())
            for_ward.pop();
        while(!back_ward.empty())
            back_ward.pop();
        while(1) {
            scanf(" %s", a);
            if(!strcmp(a, "VISIT"))
                Visit();
            else if(!strcmp(a, "BACK"))
                Backward();
            else if(!strcmp(a, "FORWARD"))
                Forward();
            else
                break;
        }
    }
    return 0;
}
