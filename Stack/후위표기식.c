#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef double Element;

Element data[MAX_STACK_SIZE];
int top;

void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}

void init_stack() { top = -1; }
int is_empty() { return top == -1; }
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }

void push(Element e)
{
	if (is_full())
		error("스택 포화 에러");
	data[++top] = e;
}
Element pop()
{
	if (is_empty())
		error("스택이 비었습니다.");
	return data[top--];
}
Element peek()
{
	if (is_empty())
		error("스택 포화 에러");
	return data[top];
}
// 괄호 오류없는지 판단하는 함수
int check_matching(char expr[])
{
	int i = 0, prev;
	char ch;

	init_stack();
	while (expr[i] != '\0')
	{
		ch = expr[i++];
		if (ch == '[' || ch == '(' || ch == '{')
			push(ch);
		else if (ch == ']' || ch == ')' || ch == '}')
		{
			if (is_empty())
				return 2;		//조건 2 위반
			prev = pop();
			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{'))
			{
				return 3;		//조건 3 위반
			}
		}
	}
	if (is_empty() == 0) return 1;	//조건 1 위반
	return 0;					//괄호 정상
}
// 후위 표기식으로 변환하는 함수
int precedence(char op) // 우선순위 체크 
{
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void infix_to_postfix(char expr[])
{
	char arr[1000] = {0,}; // 후위표기식으로 변경하여 담을 char배열 생성
	int i = 0, j = 0; // j는 후위표기식으로 변경할 배열의 카운트 담당 
	char c, op;

	init_stack();
	while (expr[i] != '\0') {
		c = expr[i++];
		if ((c >= '0' && c <= '9')) {
			arr[j++] = c;
		}
		else if (c == '(')
			push(c);
		else if (c == ')') {
			while (is_empty() == 0) {
				op = pop();
				if (op == '(')
					break;
				else
					arr[j++] = op;
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (is_empty() == 0) {
				op = peek();
				if (precedence(c) <= precedence(op)) {
					arr[j++] = op;
					pop();
				}
				else break;
			}
			push(c);
		}
	}
	while (is_empty() == 0)
		arr[j++] = pop();
	strcpy(expr, arr);
}

//계산하는 함수
double calc_postfix(char expr[]) // 후위표기식 기반으로 계산 
{
	char c;
	int i = 0;
	double val, val1, val2;

	init_stack();
	while (expr[i] != '\0')
	{
		c = expr[i++];
		if (c >= '0' && c <= '9')
		{
			val = c - '0';
			push(val);
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			val2 = pop();
			val1 = pop();
			switch (c)
			{
			case '+': push(val1 + val2); break;
			case '-': push(val1 - val2); break;
			case '*': push(val1 * val2); break;
			case '/': push(val1 / val2); break;
			}
		}
	}
	return data[top];
}
//메인함수부분
int main() {
	char str[1000];
	int ecode;
	printf("수식을 입력하세요 : ");
	scanf("%s", str);
	ecode = check_matching(str);
	if (!ecode) {
		infix_to_postfix(str);
		printf("%lf",calc_postfix(str));
	}
	else {
		printf("조건%d번을 위반하는 오류가 발생하였습니다.\n", ecode);
	}

	return 0;
}
