#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
	int Data;
} DataNode;

typedef struct ArrayStack {
	int Capacity;
	int Top;
	DataNode* NextNode;
} ArrayStack;

void createStack(ArrayStack** Stack, int Capacity) {
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->NextNode = (DataNode*)malloc(sizeof(DataNode) * Capacity);

	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}

void DestroyStack(ArrayStack* Stack) {
	free(Stack->NextNode);
	free(Stack);
}

void pushX(ArrayStack* Stack, int Data) {

	Stack->Top++;
	Stack->NextNode[Stack->Top].Data = Data;
}

int pop(ArrayStack* Stack) {
	int value = 0;
	
	if (Stack->Top == -1) {
		return -1;
	}
	value = Stack->NextNode[Stack->Top].Data;
	Stack->Top--;

	return value;
}

int size(ArrayStack* Stack) {
	return Stack->Top + 1;
}

int empty(ArrayStack* Stack) {
	return (Stack->Top == -1) ? 1 : 0;
}

int top(ArrayStack* Stack) {
	if (Stack->Top == -1) {
		return -1;
	}
	return Stack->NextNode[Stack->Top].Data;
}

int main() {
	ArrayStack* BOJStack = NULL;
	int N, X, i;
	char func[10];

	scanf("%d", &N);
	if (!(N >= 1 && N <= 10000)) {
		return 0;
	}
	createStack(&BOJStack, N);
	for (i = 0; i < N; i++) {
		scanf("%s", func);

		if (strcmp(func, "push") == 0) {
			scanf("%d", &X);
			if (!(X >= 1 && X <= 100000)) {
				return 0;
			}
			pushX(BOJStack, X);
		}
		else if (strcmp(func, "pop") == 0) {
			printf("%d\n", pop(BOJStack));
		}
		else if (strcmp(func,"size") == 0) {
			printf("%d\n", size(BOJStack));
		}
		else if (strcmp(func,"empty") == 0) {
			printf("%d\n", empty(BOJStack));
		}
		else if (strcmp(func,"top") == 0) {
			printf("%d\n", top(BOJStack));
		}
	}

	DestroyStack(BOJStack);

	return 0;
}