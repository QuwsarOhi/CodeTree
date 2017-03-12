#include<bits/stdc++.h>
using namespace std;

map<char, int>mp;
map<int, char>rev;

struct node {
    int visited;
    node *next[4];
    node() {
        visited = 0;
        for(int i = 0; i < 4; i++)
            next[i] = NULL;
    }
};

void del(node * current)
{
    for(int i = 0; i < 4; i++)
        if(current->next[i] != NULL)
            del(current->next[i]);
    delete current;
}

string LCS(node *current)
{
    string y;
    //y += past;
    for(int i = 0; i < 4; i++) {
        if(current->next[i] != NULL)
            if(current->next[i]->visited > 1) {
                string temp;
                temp += rev[i];
                temp += LCS(current->next[i]);
                if(y.size() < temp.size())
                    y = temp;
                else if(y.size() == temp.size())
                    if(y < temp)
                        y = temp;
                else
                    printf("didnt work\n");
            }
    }
    return y;
}


void build(char str[], int len, node *current)
{
    for(int i = 0; i < len; i++) {
        int pos = mp[str[i]];
        if(current->next[pos] == NULL)
            current->next[pos] = new node();
        current = current->next[pos];
        current->visited++;
    }
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int n;
    mp['a'] = 0;
    mp['c'] = 1;
    mp['g'] = 2;
    mp['t'] = 3;
    rev[0] = 'a';
    rev[1] = 'c';
    rev[2] = 'g';
    rev[3] = 't';
    char S[1100];
    while(scanf("%d", &n) && n) {
        node *root = new node();
        while(n--) {
            scanf(" %s", S);
            int S_len = strlen(S);
            for(int i = 0; i < S_len; i++)
                build(S+i, S_len-i, root);
        }
        string x = LCS(root);
        printf("%s\n", x.c_str());
        del(root);
    }
    return 0;
}
