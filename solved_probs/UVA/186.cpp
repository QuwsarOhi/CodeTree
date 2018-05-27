// UVa
// 186 - Trip Routing
// All pair shortest path / Single source shortest path

#include <bits/stdc++.h>
#define MAX 150
using namespace std;

map<string, int>NameMap, RouteMap;
vector<int>G[MAX], W[MAX];
vector<string>NameReMap, RouteReMap;

map<pair<int, int>, int>Route;
map<pair<int, int>, pair<int, int> >RR;

int NameCnt, RouteCnt, par[MAX];

bitset<MAX>vis;

int ConvName(string &s) {
    if(NameMap.find(s) == NameMap.end()) {
        NameMap[s] = NameCnt++;     // NameCnt starts from 0
        NameReMap.push_back(s);
        return NameCnt-1;
    }
    return NameMap[s];
}
        
int ConvRoute(string &s) {
    if(RouteMap.find(s) == RouteMap.end()) {
        RouteMap[s] = RouteCnt++;  // RouteCnt starts from 0
        RouteReMap.push_back(s);
        return RouteCnt-1;
    }
    return RouteMap[s];
}


void Parse(string &s) {
    string ss;
    int w = 0, PP = 0, u = -1, v = -1, r = -1;
    for(auto it : s) {
        if(it == ',') {
            if(PP == 0)
                u = ConvName(ss);
            else if(PP == 1)
                v = ConvName(ss);
            else
                r = ConvRoute(ss);
            ss.clear();
            ++PP;
        }
        else if(PP <= 2)
            ss.push_back(it);
        else
            w = w*10 + (it-'0');
    }
    
    if(u > v) swap(u, v);
    pair<int, int> p = make_pair(u, v);
    if(Route.find(p) == Route.end()) {
        G[u].push_back(v);
        G[v].push_back(u);
        
        //cout << "NEW EDGE\n";
        RR[p];
        Route[p] = r;
        W[u].push_back(w);
        W[v].push_back(w);
        RR[p].first = W[u].size();
        RR[p].second = W[v].size();
    }
    else if(W[u][RR[p].first-1] > w){
        //cout << "OLD EDGE\n";
        Route[p] = r;
        W[u][RR[p].first-1] = w;
        W[v][RR[p].second-1] = w;
    }
}

int bfs(int from, int to) {
    int u, v, w;
    vis.reset();
    memset(par, -1, sizeof par);
    vis[from] = 1;
    priority_queue<pair<int, int> >pq;
    pq.push({0, from});
    
    while(!pq.empty()) {
        u = pq.top().second;
        w = -pq.top().first;
        pq.pop();
        
        if(u == to)
            return w;
        
        for(int i = 0; i < (int)G[u].size(); ++i) {
            int _w = w + W[u][i];
            v = G[u][i];
            
            if(vis[v])
                continue;
            
            vis[v] = 1;
            par[v] = u;
            pq.push({-_w, v});
        }
    }
    return -1;
}

void pathPrint(int u, int child) {
    if(par[u] == -1) {
        pair<int, int> p = {min(u, child), max(u, child)};
        printf("%-21s%-21s%-11s%5d\n", NameReMap[u].c_str(), NameReMap[child].c_str(), RouteReMap[Route[p]].c_str(), W[min(u, child)][RR[p].first-1]);
        return;
    }
    
    pathPrint(par[u], u);
    if(child == -1)
        return;
    
    pair<int, int> p = {min(u, child), max(u, child)};
    printf("%-21s%-21s%-11s%5d\n", NameReMap[u].c_str(), NameReMap[child].c_str(), RouteReMap[Route[p]].c_str(), W[min(u, child)][RR[p].first-1]);
}

int main() {
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    string str, ss;
    bool done = 0;
    while(getline(cin, str)) {
        if(str.empty()) {
            //cout << "PROCESS CHANGED\n";
            done = 1;
            
            //for(auto it : NameMap)
            //    cout << it.first << " " << it.second << endl;
            
            continue;
        }
        
        if(!done)
            Parse(str);
        else {
            int u, v;
            for(auto it : str) {
                if(it == ',') {
                    u = ConvName(ss);
                    ss.clear();
                }
                else
                    ss.push_back(it);
            }
            v = ConvName(ss);
            ss.clear();
            
            //cout << u << " to " << v << endl; 
            
            int ans = bfs(u, v);
            
            printf("\n\n");
            printf("From                 To                   Route      Miles\n");
            printf("-------------------- -------------------- ---------- -----\n");
            pathPrint(v, -1);
            printf("                                                     -----\n");
            printf("                                          Total      %5d\n", ans);
        }
    }
    
    return 0;
}
