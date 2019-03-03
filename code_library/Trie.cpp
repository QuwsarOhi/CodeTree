//Trie
//Complexity : making a trie : O(S), searching : O(S)

bool found;
struct node {
    bool isEnd;
    node *next[11];
    node() {
        isEnd = false;
        for(int i = 0; i < 10; i++)
            next[i] = NULL;
    }};

//trie of a string abc, ax
// [start] --> [a] --> [b] --> [c] --> endMark
//				|
//			   [x] --> endMark
//creates trie, returns true if the trie we are creating is a segment of a string
//to only create a trie remove lines which are comment marked

bool create(char str[], int len, node *current) {
    for(int i = 0; i < len; i++) {
        int pos = str[i] - '0';
        if(current->next[pos] == NULL)
            current->next[pos] = new node();
        current = current->next[pos];
        if(current->isEnd)	//
            return true; 	//
    }
    current->isEnd = true;	//
    return false;			//
}

void del(node *current) {
    for(int i = 0; i < 10; i++)
        if(current->next[i] != NULL)
            del(current->next[i]);
    delete current;
}

void check(node *current) {
    for(int i = 0; i < 10; i++) {
        if(current->next[i] != NULL)
            check(current->next[i]);
    }
    if(found) return;
    if(current->isEnd && !found) {
        for(int i = 0; i < 10 && !found; i++)
            if(current->next[i] != NULL) {
                found = 1;
}}}

// NON-Dynamic implementation
// root node is at 0 index of tree
// root node counter contains total number of string insertion
// each inserted char counter is on the child node of the edges

struct Trie {
	struct node {
		int cnt;
		int nxt[60];
	};
	int nodes;
	node tree[MAX];
    void newNode() {
        tree[nodes].cnt = 0;
        memset(tree[nodes].nxt, -1, sizeof tree[nodes].nxt);
        ++nodes;
    }
    void init() {
        nodes = 0;
        newNode();
    }
	int getId(char x) {
        if(x >= 'A' and  x <= 'Z')
            return (x - 'A' + 27);
        return (x - 'a' + 1);
	}
	void insert(string &str, int len = 0, int idx = 0) {
		tree[idx].cnt++;
		if(len == str.size()) return;
		int id = getId(str[len]);
		if(tree[idx].nxt[id] == -1) {
			tree[idx].nxt[id] = nodes;
			newNode();
		}
		insert(str, len+1, tree[idx].nxt[id]);
	}
	int search(string &str, int len = 0, int idx = 0) {
		if(len == str.size())
			return -2;
		int id = getId(str[len]);
		if(tree[idx].nxt[id] == -1)
			return -1;
		if(tree[idx].cnt == 1)
			return len;
		return search(str, len+1, tree[idx].nxt[id]);
}};
