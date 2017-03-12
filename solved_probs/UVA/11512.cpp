//UVa
//11512 - GATTACA
//Longest Repeated Substring
//Trie, Find the deepest node which is visited more than once

#include<bits/stdc++.h>
using namespace std;

map<char, int>mp;
map<int, char>rev;

struct node {
    int visited;
    bool isEnd;
    node *next[4];
    node() {
        visited = 0;
        isEnd = false;
        for(int i = 0; i < 4; i++)
            next[i] = NULL;
    }
};

void build(char str[], int len, node *current)
{
    for(int i = 0; i < len; i++) {
        int pos = mp[str[i]];
        if(current->next[pos] == NULL)
            current->next[pos] = new node();
        current = current->next[pos];
        current->visited++;
    }
    current->isEnd = true;
}

string LRS(node *current, string past, int *cnt)
{
    int pos;
    string y;
    y += past;
    for(int i = 0; i < 4; i++) {
        if(current->next[i] != NULL) {
            if(current->next[i]->visited > 1) {
                string tmp;
                tmp += rev[i];
                //*cnt =  min(current->next[i]->visited, *cnt);
                int cnt_next = 1e4;
                tmp += LRS(current->next[i], "", &cnt_next);
                if(tmp.size() > y.size()) {
                    y = tmp;
                    //*cnt = min(*cnt, cnt_next);
                }
                else if(tmp.size() == y.size())
                    if(tmp < y) {
                        y = tmp;
                        //*cnt = min(*cnt, cnt_next);
                    }
            }
        }
    }
    return y;
}

void del(node *current)
{
    for(int i = 0; i < 4; i++)
        if(current->next[i]!=NULL)
            del(current->next[i]);
    delete current;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    mp['A'] = 0;
    mp['C'] = 1;
    mp['G'] = 2;
    mp['T'] = 3;
    rev[0] = 'A';
    rev[1] = 'C';
    rev[2] = 'G';
    rev[3] = 'T';
    int t;
    scanf("%d", &t);
    char S[1100];
    while(t--) {
        node *root = new node();
        scanf(" %s", S);
        int S_len = strlen(S);
        for(int i = 0; i < S_len; i++) {
            build(S+i, S_len-i, root);
        }
        int cnt = 1e4;
        string y = LRS(root, "", &cnt);
        if(y.size() == 0)
            printf("No repetitions found!\n");
        else {
            printf("%s ", y.c_str());
            node *current = root;
            for(int i = 0; i < y.size(); i++) {
                if(current->next[mp[y[i]]] != NULL)
                    current = current->next[mp[y[i]]];
            }
            printf("%d\n", current->visited);
        }
        del(root);
    }
    return 0;
}
