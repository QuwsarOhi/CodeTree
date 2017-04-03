//UVa
//12160 - Unlock the Lock
//BFS

#include<bits/stdc++.h>
using namespace std;

vector<int>buttons;

int BFS(int start_point, int end_point)
{
    vector<bool>visited(10000, false);

    //q -> lock display, number of clicks
    queue<pair<int, int> >q;

    q.push(make_pair(start_point, 0));
    visited[start_point] = 1;

    while(!q.empty()) {
        int display = q.front().first;
        int clicks = q.front().second + 1;

        q.pop();

        if(display == end_point)
            return clicks-1;

        for(int i = 0; i < buttons.size(); i++) {
            int new_display = display + buttons[i];

            //if the value gets bigger than 9999 start it again from 0
            if(new_display > 9999)
                new_display %= 10000;

            if(!visited[new_display]) {
                visited[new_display] = 1;
                q.push(make_pair(new_display, clicks));
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int L, U, R, x, Case = 1;
    while(scanf("%d %d %d", &L, &U, &R) && (L || U || R)) {
        while(R--) {
            scanf("%d", &x);
            buttons.push_back(x);
        }
        int ans = BFS(L, U);

        if(ans == -1)
            printf("Case %d: Permanently Locked\n", Case++);
        else
            printf("Case %d: %d\n", Case++, ans);
        buttons.clear();
    }
    return 0;
}
