#include <bits/stdc++.h>
using namespace std;
#define MAX                 200100
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS)) 
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define dbug(vari)          cerr << #vari << " = " << (vari) <<endl
#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;



struct node {
    int key;            // Contains the value                   notation : key
    int degree;         // Degree of this node                  notation : degree(x)
    //node *parent;        // Parent of this node
    node *left;          // left pointer of this node
    node *right;         // right pointer of this node
    node *child;         // child of this node (every node is connected to ONLY ONE child node)
    
    node(int val) {
        this->key = val;
        this->degree = 0;
    }
    
    void INIT() {
        this->left = this->right = this;
        this->child = NULL;
    }
};


struct FibHeap {
    int nH;             // Number of nodes in Heap              notation : n[H]
    node *H;            // Heap pointer (Points to the minimum key-Node)
    int Size;           // Added Extra
    
    
    // Tested, OK
    FibHeap() {           // Heap initializer
        nH = 0;                 // heapSize set to 0
        H = NULL;               // By default the heap is empty, So keep a NULL pointer
        Size = 0;
    }
    
    
    // Checked, OK
    void addLeft(node** pstNode, node** newNode) {
        pf("asd\n");
        if(*pstNode == NULL) {
            *pstNode = *newNode;
            return;
        }
        
        ((*pstNode)->left)->right = *newNode;         // add to left
        (*newNode)->right = *pstNode;
        (*newNode)->left = (*pstNode)->left;
        (*pstNode)->left = *newNode;
    }    

    
    
    // Tested, OK
    void push(int value) {
        node* newNode = new node(value);
        newNode->INIT();
        
        addLeft(&H, &newNode);
        if(newNode != H && newNode->key < H->key) {          // Update to new node if it is small
            H = newNode;
        }
        
        ++nH;                                // Number of nodes in heap increased by one
        //pf("DONE\n");
    }
    
    // OK
    void FibHeapLink(node** y, node** x) {
        // remove y from x
        ((*y)->left)->right = (*y)->right;
        ((*y)->right)->left = (*y)->left;
        (*y)->left = (*y)->right = (*y);
        //make y child of x, incrementing x.degree
        if((*x)->child == NULL) {
            (*x)->child = *y;
            //(*y)->parent = *x;              // DOES PARENT HAS ANYTHING TO DO????
        }
        else {
            addLeft(&((*x)->child), &(*y));
            (*x)->degree += 1;
        }
    }
            
    
    void Consolidate() {
        pf("CAME\n");
        node* A[nH+2];
        
        for(int i = 0; i <= nH; ++i)
            A[i] = NULL;
        
        bool firstIter = 1;
        node* rightNode;
        for(node* w = H; (w != H->left) || firstIter; w = rightNode, firstIter = 0) {
            node* x = w;
            rightNode = x->right;
            int d = x->degree;
            pf("rootlist elem %d : deg : %d\n", x->key, d);
            while(A[d] != NULL) {
                node* y = A[d];         // another node same degree as x
                if(x->key > y->key)     // if x is bigger than y, swap x, y so that x is the smaller one
                    swap(x, y);
                FibHeapLink(&y, &x);
                A[d] = NULL;
                d += 1;
            }
            A[d] = x;
            pf("in consolidate   ");
            rootList();
        }
        
        H = NULL;
        for(int i = 0; i <= nH; ++i) {
            if(A[i] != NULL) {
                if(H == NULL) {
                    //pf("done1\n");
                    H = A[i];
                }
                else {
                    //pf("done2\n");
                    addLeft(&H, &A[i]);
                    if(A[i]->key < H->key)
                        H = A[i];
                }
            }
        }
    }
                    
    int pop() {
        node* z = H;
        if(z == NULL)
            return 1e9;             // Just returning an INFINITE value
        
        bool firstIter = 1;
        node* pstRight = NULL;
        rootList();
        for(node* x = z->child; z->child != NULL && ((x != (z->child)->left) || firstIter); x = pstRight, firstIter = 0) {
            pf("LOLA1\n");
            pstRight = x->right;
            if(x->right != NULL)
                pf("ok\n");
            if(x != NULL)
                addLeft(&H, &x);
            //x->parent = NULL;
            pf("LOLA2\n");
        }
        pf("LOLA3\n");
        //rootList();
        if(z != NULL && z == z->right) {         // if there is only one node in root list
            pf("here1\n");
            H = NULL;
        }
        else {
            pf("or here\n");
            H = z->right; //commented line
            // remove H.min from rootlist
            //z = H;
            (z->right)->left = z->left;
            (z->left)->right = z->right;
            //H = H->left;
            Consolidate();
        }
        nH -= 1;
        return z->key;
    }
    
    // Extra function starts------------------------------------
    
    int size() {
        return nH;
    }
    
    bool empty() {
        return (!(nH));
    }
    
    int top() {
        if(H != NULL)
            return H->key;
        return INF;
    }
    
    // BUGGY -------------------------------------
    void deleteNode(node* n) {
        delete n->child;
        //delete n->right;
        delete n->left;
        //delete n->parent;
        delete n;
    }
    
    void goDown(node* n) {
        if(n != NULL && n->child != NULL)
            goDown(n);
        else if(n != H)
            deleteNode(n);
        else
            H = NULL;
    }
    
    void clear() {
        goDown(H);
        Size = 0;
    }
    // NEED to add Clear function!!
    
    void rootList() {
        for(node* x = H; ;x = x->right) {
            pf("-----%d", x->key);
            if(x == H->left)
                break;
        }
        pf("\n");
    }
};



int main() {
    //fileWrite("out");
    FibHeap hp;
    
    for(int i = 10; i >= 0; --i) {
        pf("pushing %d\n", i);
        hp.push(i);
        pf("%d pushed size : %d isEmpty : %d\n", i, hp.size(), hp.empty());
        hp.rootList();
    }
    
    pf("Extracted Min : %d", hp.pop());
    hp.rootList();
    pf("pushing %d\n", 50);
    hp.push(50);
    pf("%d pushed size : %d isEmpty : %d\n", 50, hp.size(), hp.empty());
    hp.rootList();
    
    for(int i = 0; i <= 10; ++i) {
        pf("Extracting %d'th\n", i);
        pf("Extracted Min : %d, \n", hp.pop());
        pf("Size : %d\n", hp.size());
        hp.rootList();
    }
    
    pf("Clearing\n");
    hp.clear();
    pf("Clearing ok\n");
    
    return 0;
}



/*
int main()
{
    fileRead("in");
    fileWrite("out");
    
    FibHeap pq;
	while(1)
	{
		register int t;
		register int x;
		scanf("%d", &t);
		
		if(t == 0)
			break;
		while(t--)
		{
			scanf("%d", &x);
			pq.push(x);
		}
		register int sum = 0;
		int cost = 0;
		while(!pq.empty())
		{
			if(pq.size() == 1)
			{
				//cout << pq.size() << endl;
				//cost += pq.top();
				pq.pop();
				break;
			}
			//cout << pq.top() << " ";
			sum += pq.top();
			pq.pop();
			sum += pq.top();
			//cout << pq.top() << "\n";
			pq.pop();
			pq.push(sum);
			cost += sum;
			sum = 0;
		}
		printf("%d\n", cost);
        pq.clear();
	}
	return 0;
}
*/
