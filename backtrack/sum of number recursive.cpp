//UVa
//574 - Sum It Up
#include<bits/stdc++.h>
using namespace std;

int a[1010], n, cnt = 0;
vector<int>v;
map<vector<int>, bool>mark;
bool found;

void backtrack(int t, int sum, int i)
{
    if(sum == t){
        if(mark[v] == 0) {                  //if this combination isn't used before
        for(int j = 0; j < v.size(); j++) {
            if(j < (v.size() - 1)) printf("%d+", v[j]);
            else printf("%d\n", v[j]); } }
        found = 1;
        mark[v] = 1;                        //marking this combination
        return;
    }
    else if(i >= n || sum >= t) return;
    for(int j = i+1 ;j < n; j++)            //check every possible combination
        if(sum+a[j] <= t) {
            v.push_back(a[j]);              //getting new combination
            backtrack(t, sum+a[j], j);
            v.pop_back();                   //as the work is done with the last value, pop it
        }
}


int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    int t;
    while(scanf("%d %d", &t, &n) && t) {
        for(int i = 0; i < n; i++) scanf("%d", &a[i]);
        printf("Sums of %d:\n", t);
        found = 0;
        backtrack(t, 0, -1);
        if(!found) printf("NONE\n");
        mark.clear();
        v.clear();
    }
    return 0;
}
