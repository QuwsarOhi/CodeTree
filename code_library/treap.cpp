#include <bits/stdc++.h>
using namespace std;


struct node {
    int key, prior;
    node *lft, *rht;
};

struct Treap {
    node *root;

    node *rhtRotate(node *y) {
        node *x = y->lft,  *T2 = x->rht;
        x->rht = y;
        y->lft = T2;
        return x;
    }

    node *lftRotate(node *x) {
        node *y = x->rht, *T2 = y->lft;
        y->lft = x;
        x->rht = T2;
        return y;
    }

    node* newNode(int key) {
        node* temp = new node;
        temp->key = key;
        temp->prior = rand()%100;
        temp->lft = temp->rht = NULL;
        return temp;
    }

    node* search(node* root, int key) {
        if(root == NULL || root->key == key)
            return root;
        if(root->key < key)
            return search(root->rht, key);
        return search(root->lft, key);
    }

    node* insert(node* root, int key) {
        if(!root)
            return newNode(key);

        if(key <= root->key) {
            root->lft = insert(root->lft, key);
            if(root->lft->prior > root->prior)
                root = rhtRotate(root);
        }
        else {
            root->rht = insert(root->rht, key);
            if(root->rht->prior > root->prior)
                root = lftRotate(root);
        }
        return root;
    }

    node* deleteNode(node* root, int key) {
        if(root == NULL)
            return root;

        if(key < root->key)
            root->lft = deleteNode(root->lft, key);
        else if(key > root->key)
            root->rht = deleteNode(root->rht, key);
        else if (root->lft == NULL) {
            node *temp = root->rht;
            delete(root);
            root = temp;
        }
        else if (root->rht == NULL) {
            node *temp = root->lft;
            delete(root);
            root = temp;
        }
        else if(root->lft->prior < root->rht->prior) {
            root = lftRotate(root);
            root->lft = deleteNode(root->lft, key);
        }
        else {
            root = rhtRotate(root);
            root->rht = deleteNode(root->rht, key);
        }
        return root;
    }

    void inorder(node* root) {
        if (root) {
            inorder(root->lft);
            cout << "key: "<< root->key << " | prior: %d " << root->prior;
            if (root->lft)
                cout << " | lft child: " << root->lft->key;
            if (root->rht)
                cout << " | rht child: " << root->rht->key;
            cout << endl;
            inorder(root->rht);
        }
    }
};

int main() {
    return 0;
}
