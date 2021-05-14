#define _CRT_SECURE_NO_WARNINGS
#include"ListNode.h"

int main()
{
	PtrToNode head = malloc(sizeof(struct Node));
	head->next = NULL;
	//MakeEmpty(head);
	Insert(5, head, head);
	Insert(4, head, head);
	Insert(3, head, head);
	Insert(2, head, head);
	Insert(1, head,head);
	Position p1 = Find(3, head);
	printf("%d\n", p1->data);
	Position p = FindPrevious(3,head);	
	printf("%d\n", p->data);
	PrintNode(head);
	Delete(4, head);
	PrintNode(head);

	return 0;
}
