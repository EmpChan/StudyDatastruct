#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <limits.h>
//Thread Binary Search Tree
typedef struct node {
    int val;
    struct node* left;
    struct node* right;
    bool lc;//leftchild
    bool rc;//rightchild
}node;

void insert(int a,node** p) {
    if ((*p)->val >= a) {
        if ((*p)->lc) {
            node* tmp = (node*)calloc(sizeof(node), 1);
            tmp->val = a;
            tmp->left = (*p)->left;
            tmp->right = (*p);
            tmp->lc = 1;
            tmp->rc = 1;
            (*p)->lc = 0;
            (*p)->left = tmp;
        }
        else insert(a, &((*p)->left));
    }
    else {
        if ((*p)->rc) {
            node* tmp = (node*)calloc(sizeof(node), 1);
            tmp->val = a;
            tmp->right = (*p)->right;
            tmp->left = (*p);
            tmp->lc = 1;
            tmp->rc = 1;
            (*p)->rc = 0;
            (*p)->right = tmp;
        }
        else insert(a, &((*p)->right));
    }
}

node* insucc(node* r) {
    node* tmp;
    tmp = r->right;
    if (!tmp->rc) {
        while (!tmp->lc) tmp = tmp->left;
    }
    return tmp;
}

void inord(node* r) {
    node* tmp = r;
    while (1) {
        tmp = insucc(tmp);
        if (tmp == r)break;
        printf("%d\n", tmp->val);
    }
}

int main(void) {
    int n, m;
    node* r = (node*)calloc(sizeof(node),1);
    r->val = INT_MAX;
    r->left = r;
    r->right = r;
    r->lc = 1, r->rc = 0;
    while (1) {
        printf("1. Insert\n2. Preorder\n3.Postorder\n4.Inorder\nAns: ");
        scanf("%d" ,& n);
        if (n == 1) {
            scanf("%d", &m);
            insert(m, &r);
        }
        else if (n == 2) {
            continue;//Pre(r);
        }
        else if (n == 3) {
            continue;// Post(r);
        }
        else if (n == 4) {
            inord(r);
        }
        else {
            break;
        }
    }
    return 0;
}
