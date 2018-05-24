// UVa
// 122 - Trees on the level

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> >ans;
map<int, int>NODE;
char str[1000000];
int nodeCNT, dfsCNT;


int GenNum(string &ss) {
    int ret = 1;
    for(auto it : ss) {
        ret <<= 1;
        if(it == 'R')
            ++ret;
    }
    return ret;
}

bool Parser() {
    string ss;
    bool comma = 0;
    int digit = 0;
    for(int i = 0; str[i] != '\0'; ++i) {
        if(str[i] == '(')
            continue;
        else if(str[i] >= '0' and str[i] <= '9') {
            digit *= 10;
            digit += str[i]-'0';
        }
        else if(str[i] == ',')
            comma = 1;
        else if(str[i] == 'L' or str[i] == 'R')
            ss.push_back(str[i]);
        else {
            if(!comma)
                return 0;
            int nodeNo = GenNum(ss);
            ++nodeCNT;
            NODE[nodeNo] = digit;
            return 1;
        }
    }
    return 0;
}

void dfs(int u) {
    if(NODE.find(u) == NODE.end())
        return;
    
    ++dfsCNT;
    ans.push_back({u, NODE[u]});
    dfs(u<<1);
    dfs(u<<1|1);
}
        
int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    nodeCNT = dfsCNT = 0;
    while(scanf("%s", str) == 1) {
        if(!Parser()) {
            dfs(1);
            if(dfsCNT != nodeCNT)
                printf("not complete\n");
            else {
                sort(ans.begin(), ans.end());
                printf("%d", ans[0].second);
                for(int i = 1; i < dfsCNT; ++i)
                    printf(" %d", ans[i].second);
                printf("\n");
            }
            ans.clear();
            NODE.clear();
            nodeCNT = dfsCNT = 0;
        }
    }

    return 0;
}
