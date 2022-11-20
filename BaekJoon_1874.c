#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STACK_SIZE 100000	//스택의 최대 크기

// + - 문자를 담는 result
char* result;


typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
}StackType;


void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, int item) {
	if (is_full(s)) {
		return;
	}
	else
		s->data[++(s->top)] = item;
}

int pop(StackType* s) {
	if (is_empty(s)) {
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

int peek(StackType* s) {
	if (is_empty(s)) {
		exit(1);
	}
	else {
		return s->data[s->top];
	}
}

int main() {
	StackType s;
	init_stack(&s);

	int n; // 입력받는 수의 범위 (1~n)
	int input;	// 1~n 사이 범위의 입력받는 수
	int num = 1; // 1부터 하나씩 늘어나는 수
	int index = 0;
	int check;

	scanf("%d", &n);

	// 2 1 2 입력 시에도 +-+- 4개의 문자가 들어감 MAX*2
	// 런타임 에러를 방지하기 위해 동적으로 메모리를 할당해줌
	result = (char*)malloc(sizeof(char) * (n * 2 + 1));
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);

		// 결과적으로 num은 1부터 계속 증가하는 모습을 보임
		// 또한 4 3 과 같이 큰 숫자의 push가 먼저 이루어지더라도 연달아 pop 되는 모습을 볼 수 있음
		while (num <= input) {
			push(&s, num++);
			result[index++] = '+';
		}
		check = pop(&s);
		if (check == input) {
			result[index++] = '-';
		}
		// 불가능하다면,
		else {
			printf("NO\n");
			free(result);
			return 0;
		}
	}
	for (int i = 0; i < n * 2; i++) {
		printf("%c\n", result[i]);
	}
}