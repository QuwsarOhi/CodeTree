// Palindromic Tree

struct node {
	int start, end, length, edge[26], suffixEdg;
};

struct PalinTree {
    int currNode;
    string s;                           // Contains the string
    int ptr, mxLen;
    node root1, root2, tree[MAX];
    PalinTree() {
        s.clear();
        root1.length = -1;
        root1.suffixEdg = 1;
        root2.length = 0;
        root2.suffixEdg = 1;
        tree[1] = root1;
        tree[2] = root2;
        ptr = 2;
        currNode = 1;
        mxLen = 0;
    }    
    void insert(int idx) {
        int tmp = currNode;
        while(1) {
            int curLength = tree[tmp].length;
            if(idx - curLength >= 1 && s[idx] == s[idx-curLength-1]) break;
            tmp = tree[tmp].suffixEdg;
        }
        if(tree[tmp].edge[s[idx]-'a'] != 0) {
            currNode = tree[tmp].edge[s[idx]-'a'];
            return;
        }
        ptr++;
        tree[tmp].edge[s[idx]-'a'] = ptr;
        tree[ptr].length = tree[tmp].length + 2;
        tree[ptr].end = idx;
        tree[ptr].start = idx - tree[ptr].length + 1;
        tmp = tree[tmp].suffixEdg;
        currNode = ptr;
        if(tree[currNode].length == 1) {
            tree[currNode].suffixEdg = 2;
            return;
        }
        while(1) {
            int curLength = tree[tmp].length;
            if(idx-curLength >= 1 && s[idx] == s[idx-curLength-1])
                break;
            tmp = tree[tmp].suffixEdg;
        }
        tree[currNode].suffixEdg = tree[tmp].edge[s[idx]-'a'];
    }    
    void buildTree() {          // Builds Palindrome Tree of string s
        for(int i = 0; i < (int)s.length(); ++i)
            insert(i);
    }  
    void CalMaxLen() {
        for(int i = 3; i <= ptr; ++i)
            mxLen = max(mxLen, tree[i].end - tree[i].start);
}};

int main() {
    PalinTree pt;
    cin >> pt.s;
    pt.buildTree();
    cout << "All distinct palindromic substring for " << pt.s << " : \n";
    for(int i=3; i<=pt.ptr; i++) {
    cout << i-2 << ") ";
    for(int j=pt.tree[i].start; j<=pt.tree[i].end; j++)
        cout << pt.s[j];
	    cout << endl;
}}
