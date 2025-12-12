#include <stdio.h> // 링크드 큐
#include <stdlib.h>

typedef struct tagNode {
	int Data;
	struct tagNode* NextNode;
} Node;

typedef struct tagQueue {
	Node* Front;
	Node* Rear;
	int Count;
} LQueue;

void CreateQueue(LQueue** Queue) {
	(*Queue) = (LQueue*)malloc(sizeof(LQueue));
	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}
void DestroyQueue(LQueue* Queue) {
	while (!empty(Queue)) {
		pop(Queue);
	}

	free(Queue);
}

Node* CreateNode(int NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	// NewNode->Data = (char*)malloc(sizeof(NewData));

	NewNode->Data = NewData;

	NewNode->NextNode = NULL;

	return NewNode;
}

void DestroyNode(Node* _Node) {
	// free(_Node->Data);
	free(_Node);
}

void pushX(LQueue* Queue, Node* NewNode) {
	if (Queue->Front == NULL) {
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
	else {
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
}

int pop(LQueue* Queue) {
	int value = 0;
	if (Queue->Front == NULL) {
		return -1;
	}

	Node* Popped = Queue->Front;

	value = Popped->Data;
	if (Queue->Front->NextNode != NULL) {
		Queue->Front = Queue->Front->NextNode;
	}
	else {
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	Queue->Count--;
	DestroyNode(Popped);

	return value;
}

int size(LQueue* Queue) {
	return Queue->Count;
}

int empty(LQueue* Queue) {
	return (Queue->Count == 0) ? 1 : 0;
}

int front(LQueue* Queue) {
	if (Queue->Front == NULL) {
		return -1;
	}
	return Queue->Front->Data;
}

int back(LQueue* Queue) {
	if (Queue->Front == NULL) {
		return -1;
	}
	return Queue->Rear->Data;
}

int main() {
	LQueue* BOJQueue = NULL;
	int N, X, i;
	char func[10];

	scanf("%d", &N);
	if (!(N >= 1 && N <= 10000)) {
		return 0;
	}
	CreateQueue(&BOJQueue);
	for (i = 0; i < N; i++) {
		scanf("%s", func);

		if (strcmp(func, "push") == 0) {
			scanf("%d", &X);
			if (!(X >= 1 && X <= 100000)) {
				return 0;
			}
			pushX(BOJQueue, CreateNode(X));
		}
		else if (strcmp(func, "pop") == 0) {
			printf("%d\n", pop(BOJQueue));
		}
		else if (strcmp(func, "size") == 0) {
			printf("%d\n", size(BOJQueue));
		}
		else if (strcmp(func, "empty") == 0) {
			printf("%d\n", empty(BOJQueue));
		}
		else if (strcmp(func, "front") == 0) {
			printf("%d\n", front(BOJQueue));
		}
		else if (strcmp(func, "back") == 0) {
			printf("%d\n", back(BOJQueue));
		}
	}
	DestroyQueue(BOJQueue);
	return 0;
}