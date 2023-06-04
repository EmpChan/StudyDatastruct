#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct node{ // Tree with Linked List
    int val;
    struct node* left;
    struct node* right;
}node;

void insert(node** p, int i) { // insert recursively
    if (*p==NULL){
        node* tmp= (node*)calloc(sizeof(node),1);
        tmp->val = i;
        *p = tmp;
        return;
    }
    else {
        if ((*p)->val > i) {
            insert(&((*p)->left), i);
        }
        else {
            insert(&((*p)->right), i);
        }
    }
}

void pre(node* p) { //Preorder traversal
    printf("%d\n", p->val);
    if (p->left)pre(p->left);
    if (p->right)pre(p->right);
}

void post(node* p) {
    if (p->left)pre(p->left);
    if (p->right)pre(p->right);
    printf("%d\n", p->val);
}

void inord(node* p) {
    if (p->left)pre(p->left);
    printf("%d\n", p->val);
    if (p->right)pre(p->right);
}

int main(void) {
    int n;
    node* root = 0;
    while (1) {
        printf("Select Menu\n1. insert node\n2. Preoder traversal\n3. Inorder traversal\n4. Postorder traversal\nSelect :");
        scanf("%d",&n);
        if (n == 1) {
            scanf("%d", &n);
            insert(&root,n);
            printf("\n");
        }
        else if (n == 2) {
            if (!root)continue;
            pre(root);
            printf("\n");
        }
        else if (n == 3) {
            if (!root)continue;
            inord(root);
            printf("\n");
        }
        else if (n == 4) {
            if (!root)continue;
            post(root);
            printf("\n");
        }
        else {
            break;
        }
    }
    return 0;
}
