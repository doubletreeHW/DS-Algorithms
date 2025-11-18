#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	int Data;
	struct tagNode* NextNode;
} Node;

typedef struct tagLinkedQueue {
	Node* Front;
	Node* Rear;
	int Count;
} LinkedQueue;

void CreateQueue(LinkedQueue** Queue) {
	(*Queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));

	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Count = 0;
}

void DestroyQueue(LinkedQueue* Queue) {
	while (!empty(Queue)) {
		pop(Queue);
	}
	free(Queue);
}

Node* CreateNode(int NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

void DestroyNode(Node* _Node) {
	free(_Node);
}

void pushX(LinkedQueue* Queue, Node* NewNode) {
	if (Queue->Front == NULL) {
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
	}
	else {
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
	}
	Queue->Count++;
}

int pop(LinkedQueue* Queue) {
	Node* OldFront = NULL;
	int value = 0;

	if (Queue->Front == NULL) {
		return -1;
	}

	value = Queue->Front->Data;
	OldFront = Queue->Front;

	Queue->Front = Queue->Front->NextNode;

	free(OldFront);

	Queue->Count--;

	if (Queue->Front == NULL) {
		Queue->Rear = NULL;
	}
	
	return value;
}	

int size(LinkedQueue* Queue) {
	return Queue->Count;
}

int empty(LinkedQueue* Queue) {
	return (Queue->Front == NULL) ? 1 : 0;
}

int front(LinkedQueue* Queue) {
	if (Queue->Front == NULL) {
		return -1;
	}
	return Queue->Front->Data;
}

int back(LinkedQueue* Queue) {
	if (Queue->Front == NULL) {
		return -1;
	}
	return Queue->Rear->Data;
}

 int main() {
	LinkedQueue* BOJQueue = NULL;
	long N, X, i;
	char func[10];
	
	scanf("%ld", &N);
	if (!(N >= 1 && N <= 2000000)) {
		return 0;
	}
	CreateQueue(&BOJQueue);
		for (i = 0; i < N; i++) {
			scanf("%s", func);

			if (strcmp(func, "push") == 0) {
				scanf("%ld", &X);
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