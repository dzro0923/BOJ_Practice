#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STACK_SIZE 100000	//������ �ִ� ũ��

// + - ���ڸ� ��� result
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

	int n; // �Է¹޴� ���� ���� (1~n)
	int input;	// 1~n ���� ������ �Է¹޴� ��
	int num = 1; // 1���� �ϳ��� �þ�� ��
	int index = 0;
	int check;

	scanf("%d", &n);

	// 2 1 2 �Է� �ÿ��� +-+- 4���� ���ڰ� �� MAX*2
	// ��Ÿ�� ������ �����ϱ� ���� �������� �޸𸮸� �Ҵ�����
	result = (char*)malloc(sizeof(char) * (n * 2 + 1));
	for (int i = 0; i < n; i++) {
		scanf("%d", &input);

		// ��������� num�� 1���� ��� �����ϴ� ����� ����
		// ���� 4 3 �� ���� ū ������ push�� ���� �̷�������� ���޾� pop �Ǵ� ����� �� �� ����
		while (num <= input) {
			push(&s, num++);
			result[index++] = '+';
		}
		check = pop(&s);
		if (check == input) {
			result[index++] = '-';
		}
		// �Ұ����ϴٸ�,
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