//UVa
//760 - DNA Sequencing
//Trie
//Find the longest edge where two separate strings visited once or more

#include<bits/stdc++.h>
using namespace std;

map<char, int>mp;
map<int, char>rev;
vector<string>vec;
int mx_len;

struct node {
    node *next[5];
    bitset<2>visited;
    node() {
        visited.reset();
        for(int i = 0; i < 5; i++)
            next[i] = NULL;
    }
};

void del(node *current)
{
    for(int i = 0; i < 5; i++)
        if(current->next[i] != NULL)
            del(current->next[i]);
    delete current;
}

void build(char str[], int len, int on, node *current)
{
    for(int i = 0; i < len; i++) {
        int pos = mp[str[i]];
        if(current->next[pos] == NULL)
            current->next[pos] = new node();
        current = current->next[pos];
        current->visited[on] = 1;
    }
}

void LCS(string past, node *current, int totalStr)
{
    for(int i = 0; i < 4; i++) {
        if(current->next[i] != NULL) {
            if(current->next[i]->visited.count() == totalStr) {
                string x;
                x+= past;
                x+= rev[i];
                mx_len = max(mx_len, (int)x.size());
                LCS(x, current->next[i], totalStr);
                if(x.size() == mx_len)
                    vec.push_back(x);
            }
        }
    }
}

int main()
{
    mp['a'] = 0;
    mp['c'] = 1;
    mp['g'] = 2;
    mp['t'] = 3;
    rev[0] = 'a';
    rev[1] = 'c';
    rev[2] = 'g';
    rev[3] = 't';
    bool first = 1;
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    char S[400];
    while(scanf(" %s", S) != EOF) {
        int len = strlen(S);
        node *root = new node();
        if(!first)
            printf("\n");
        first = 0;
        for(int i = 0; i < len; i++)
            build(S+i, len-i, 0, root);
        scanf(" %s", S);
        len = strlen(S);
        for(int i = 0; i < len; i++)
            build(S+i, len-i, 1, root);
        mx_len = -1;
        LCS("", root, 2);
        del(root);
        if(vec.size() == 0)
            printf("No common sequence.\n");
        else
            for(int i = 0; i < vec.size(); i++)
                if(vec[i].size() == mx_len)
                    printf("%s\n", vec[i].c_str());
        vec.clear();
    }
    return 0;
}
