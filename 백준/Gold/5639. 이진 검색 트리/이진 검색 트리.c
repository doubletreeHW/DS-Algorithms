#include <stdio.h>
#include <stdlib.h>

typedef struct tagBSTNode {
	struct tagBSTNode* Left;
	struct tagBSTNode* Right;

	int Data;
} BSTNode;

BSTNode* CreateNode(int NewData) {
	BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	return NewNode;
}

void DestroyNode(BSTNode* Node) {
	free(Node);
}

void DestroyTree(BSTNode* Tree) {
	if (Tree == NULL) { // 1. 기저 조건: NULL이면 즉시 리턴
        return;
    }
	
    // 2. 후위 순회 방식으로 재귀 호출
	DestroyTree(Tree->Left);
	DestroyTree(Tree->Right);

    // 3. 노드 해제
	DestroyNode(Tree);
    // Tree->Right = NULL; 등 포인터를 NULL로 만드는 코드는 메모리를 해제했기 때문에 굳이 필요하지 않습니다.
}

void InsertNode(BSTNode* Tree, BSTNode* Child) {
	if(Tree->Data < Child->Data) {
		if(Tree->Right == NULL) {
			Tree->Right = Child;
		}
		else {
			InsertNode(Tree->Right, Child);
		}
	}
	else if(Tree->Data > Child->Data) {
		if(Tree->Left == NULL) {
			Tree->Left = Child;
		}
		else {
			InsertNode(Tree->Left, Child);
		}
	}
}

void PrintNode(BSTNode* Node) {
	if(Node == NULL) {
		return;
	}

	PrintNode(Node->Left);
	PrintNode(Node->Right);
	printf("%d\n", Node->Data);
}

int main() {
	BSTNode* boj = NULL;
	int data;
	while (scanf("%d", &data) != EOF) {
        if (boj == NULL) {
            // 트리가 비어있으면 첫 번째 데이터를 루트 노드로 설정
            boj = CreateNode(data);
        } else {
            // 트리가 있으면 노드 삽입
            InsertNode(boj, CreateNode(data));
        }
    }

	PrintNode(boj);

	DestroyTree(boj);

	return 0;
}