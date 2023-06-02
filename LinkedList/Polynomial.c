#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>

typedef struct term{//struct for each term
    int exp;
    int coef;
    struct term* next;
}term;

void addTerm(int exp, int coef, term** s) {
    term* a = (term*)malloc(sizeof(term));
    a->exp = exp;
    a->coef = coef;
    if (*s == NULL) {
        *s = a;
        a->next = a;
    }
    else {
        term* tmp = *s;
        if (tmp->exp <= a->exp) {
            if (tmp->exp == a->exp) tmp->coef += a->coef;
            else {
                a->next = tmp;
                *s = a;
            }
        }
        else {
            while (tmp->next->exp > a->exp && tmp->next != *s)tmp = tmp->next;
            if (tmp->next == *s) {
                tmp->next = a;
                a->next = *s;
            }
            else if (tmp->next->exp == a->exp) tmp->next->coef += a->coef;
            else {
                term* tmp2 = tmp->next;
                tmp->next = a;
                a->next = tmp2;
            }
        }
    }
}

void printPoly(term* s) {
    term* tmp = s;
    if (tmp == NULL) return;
    else {
        printf("(%d)x^%d", tmp->coef, tmp->exp);
    }
    tmp = tmp->next;
    while (tmp!=s) {
        printf(" + (%d)x^%d", tmp->coef, tmp->exp);
        tmp = tmp->next;
    }
}

int main() {
    int ord = 0, exp, coef;
    term* s = 0; // 차수가 높은 것부터 s에 저장할 것임
    while (1) {
        printf("\n\n\n\nChoose menu\n1. Add Term\n2. Print Polynomial\n3. Exit\nAns : ");
        scanf("%d", &ord);
        if (ord == 1) {
            printf("Enter exp :");
            scanf("%d", &exp);
            printf("Enter coef: ");
            scanf("%d", &coef);
            addTerm(exp, coef, &s);
        }
        else if (ord == 2) {
            printPoly(s);
        }
        else {
            break;
        }
    }
    printf("End Process\n");

    return 0;
}
