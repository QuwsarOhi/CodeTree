#include<bits/stdc++.h>
using namespace std;

vector<int>V, IN;

void printer()
{
    for(int i = 0; i < V.size(); i++)
        printf("%d ", V[i]);
    printf("\n");
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int x;
    while(scanf("%d", &x) != EOF) {
        IN.push_back(x);
    }
    for(int i = IN.size()-1; i >= 0; i--) {
        x = IN[i];
        vector<int> :: iterator it = lower_bound(V.begin(), V.end(), x);
        if(it == V.end())
            V.push_back(x);
        else
            V[it - V.begin()] = x;
        printer();
    }
    /*while(scanf("%d", &x) != EOF) {
        vector<int> :: iterator it = lower_bound(V.begin(), V.end(), x);
        if(it == V.end())
            V.push_back(x);
        else
            V[it - V.begin()] = x;
        printer();
    }*/
    printf("%d\n", V.size());
    printf("-\n");
    for(int i = 0; i < V.size(); i++)
        printf("%d\n", V[i]);
    return 0;
}
