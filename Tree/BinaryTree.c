#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int tree[10001];//binary search tree with array

void insert(int n, int i) { // insert recursively
    if (!tree[i]){
        tree[i] = n;
        return;
    }
    if (tree[i] < n)insert(n, i * 2 + 1);
    else insert(n, i * 2);
}

void pre(int i) { //Preorder traversal
    printf("%d\n", tree[i]);
    if (tree[i * 2])pre(i * 2);
    if (tree[i * 2 + 1])pre(i * 2 + 1);
}

void post(int i) {
    if (tree[i * 2])pre(i * 2);
    if (tree[i * 2 + 1])pre(i * 2 + 1);
    printf("%d\n", tree[i]);
}

void inord(int i) {
    if (tree[i * 2])pre(i * 2);
    printf("%d\n", tree[i]);
    if (tree[i * 2 + 1])pre(i * 2 + 1);
}

int main(void) {
    int n;
    while (1) {
        printf("Select Menu\n1. insert node\n2. Preoder traversal\n3. Inorder traversal\n4. Postorder traversal\nSelect :");
        scanf("%d",&n);
        if (n == 1) {
            scanf("%d", &n);
            insert(n,1);
            printf("\n");
        }
        else if (n == 2) {
            pre(1);
            printf("\n");
        }
        else if (n == 3) {
            inord(1);
            printf("\n");
        }
        else if (n == 4) {
            post(1);
            printf("\n");
        }
        else {
            break;
        }
    }
    return 0;
}
