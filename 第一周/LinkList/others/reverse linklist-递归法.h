#include <stdio.h>

struct SLL
{
	int data;
	struct SLL* next;
};
struct SLL* reverse_2(struct SLL* head)			//�ݹ鷨 ��ת�б� 
{
	if(head->next==NULL)
		return head;
	
	struct SLL* new_head=reverse_2(head->next);
	head->next->next=head;		//�����������ָ���ϵ��ת 
	head->next=NULL;		//��head��Ϊnull���ݹ鵽���һ��ʱ��ԭ����ͷ����Ϊnullβ��� 
	
	return new_head;
}
