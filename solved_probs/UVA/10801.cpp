//UVa
//10801 - Lift Hopping
//Single Source Shortest Path (Dikjstra)

#include <bits/stdc++.h>
#define INF 1e6
using namespace std;

int Time[6], dp_time[6][101], n, k;
bool lift_floor[6][101], lift_changed[6][6][101];
vector<int> lift[6];

int dikjstra(int start_lift, int end_floor)
{
    for(int i = 0; i <= 5; i++)
        for(int j = 0; j <= 100; j++)
            dp_time[i][j] = INF;
    memset(lift_changed, 0, sizeof lift_changed);

    //time, floor, lift_no
    priority_queue<pair<int, pair<int, int> > > pq;
    pq.push(make_pair(0, make_pair(0, -start_lift)));
    dp_time[start_lift][0] = 0;

    while(!pq.empty()) {
        int u_floor = -pq.top().second.first;
        int u_time = -pq.top().first;
        int u_lift = -pq.top().second.second;
        pq.pop();

        if(u_floor == end_floor)
            return u_time;

        if(u_time > dp_time[u_lift][u_floor])
            continue;

        //get out and wait for the other lifts
        for(int i = 0; i < n; i++) {
            if(i == u_lift || !lift_floor[i][u_floor])
                continue;
            int new_time = u_time + 60;
            if(new_time < dp_time[i][u_floor]) {
                dp_time[i][u_floor] = new_time;
                pq.push(make_pair(-dp_time[i][u_floor], make_pair(-u_floor, -i)));
            }
        }

        for(int i = 0; i < lift[u_lift].size(); i++) {
            int floor = lift[u_lift][i];

            if(floor == u_floor)
                continue;

            int new_time = u_time + (int)abs(floor - u_floor) * Time[u_lift];

            if(new_time < dp_time[u_lift][floor]) {
                dp_time[u_lift][floor] = new_time;
                pq.push(make_pair(-dp_time[u_lift][floor], make_pair(-floor, -u_lift)));
            }
        }
    }
    return INF;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int x;
    char S[1000];
    while(scanf("%d %d", &n, &k) !=  EOF) {
        for(int i = 0; i < n; i++)
            scanf("%d", &Time[i]);
        memset(lift_floor, 0, sizeof lift_floor);
        for(int i = 0; i < n; i++) {
            scanf(" %[^\n] ", S);
            stringstream ss;
            ss << S;
            while(ss >> x) {
                lift[i].push_back(x);
                lift_floor[i][x] = 1;
            }
        }
        int ans = INF;
        for(int i = 0; i < n; i++) {
            if(lift_floor[i][0])
                ans = min(ans, dikjstra(i, k));
        }
        if(ans == INF)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
        for(int i = 0; i < n; i++)
            lift[i].clear();
    }
    return 0;
}
