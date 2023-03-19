#include <stdio.h>

struct SLL
{
	int data;
	struct SLL* next;
};
struct SLL* reverse_2(struct SLL* head)			//递归法 反转列表 
{
	if(head->next==NULL)
		return head;
	
	struct SLL* new_head=reverse_2(head->next);
	head->next->next=head;		//巧妙将两个结点的指向关系调转 
	head->next=NULL;		//将head赋为null，递归到最后一步时，原来的头结点变为null尾结点 
	
	return new_head;
}
