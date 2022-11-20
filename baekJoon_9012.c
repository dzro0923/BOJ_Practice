#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char stack[50];
int top = 0;

int check_matching(char* str);

void push(char c);
char pop();
int is_empty();

int main() {
	char str[51];

	int t;
	scanf("%d", &t); // 받는 입력의 개수

	for (int i = 0; i < t; i++) {
		scanf("%s", str);

		if (check_matching(str))
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}

int check_matching(char* str) {
	int result = 1;

	for (int i = 0; str[i] != '\0'; i++) {
		//받는 입력은 '(', ')' 둘로 이루어진 문자열임
		if (str[i] == '(') {
			push(str[i]);
		}
		else {
			if (is_empty()) {
				result = 0;
				break;
			}
			else {
				pop();
			}
		}
	}

	if (!is_empty())
		result = 0;

	while (!is_empty()){
		pop();
	}

	return result;
}

void push(char c) {
	stack[top++] = c;
}

char pop() {
	return stack[--top];
}

int is_empty() {
	return (top == 0);
}