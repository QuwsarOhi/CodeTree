#include<bits/stdc++.h>
using namespace std;

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

void build(int str[], int len, node *current)
{
    for(int i = 0; i < len; i++) {
        int pos = mp[str[i]];
        if(current->next[])
    }
}

int main()
{

}
