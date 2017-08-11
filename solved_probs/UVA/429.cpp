//UVa
//429 - Word Transformation
//BFS

#include<bits/stdc++.h>
using namespace std;

string S1, S2;
vector<string>st;
map<string, int>steps;

void bfs(string U)
{
    queue<string>q;
    q.push(U);
    steps[U] = 0;

    while(!q.empty() && steps[S2] == 0) {
        string u = q.front();
        q.pop();

        for(int i = 0; i < st.size(); i++) {
            string v = st[i];

            if(steps[v] == 0 && v.size() == u.size()) {
                int difference = 0;
                for(int j = 0; j < v.size(); j++)
                    if(v[j] != u[j])
                        difference++;
                if(difference == 1) {
                    steps[v] = steps[u] + 1;
                    q.push(v);
                }
            }
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    char S[40];
    scanf("%d ", &t);
    bool first = 1;
    while(t--) {
        if(!first)
            printf("\n");
        first = 0;

        while(1) {
            scanf(" %s ", S);
            if(S[0] == '*')
                break;
            st.push_back(S);
        }

        while(1) {
            if(fgets(S, 30, stdin) == NULL)
                break;
            if(S[0] == '\n')
                break;

            stringstream ss;
            ss << S;
            ss >> S1 >> S2;

            bfs(S1);
            printf("%s %s %d\n", S1.c_str(), S2.c_str(), steps[S2]);
            steps.clear();
        }
        st.clear();
    }
    return 0;
}
