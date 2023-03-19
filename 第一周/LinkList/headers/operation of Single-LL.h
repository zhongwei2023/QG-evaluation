#include <stdio.h>
#include <stdlib.h> 

struct SLL				//SLL��single link list 
	{
		int data;
		struct SLL * next;
	}; 

//���������� 
struct SLL* creat(void)			
	{
		struct SLL * head;
		struct SLL *p1,*p2;
		int i=0,n=0;
		printf("PLease input the number of node:\n");
		scanf("%d",&i);
		
		p1=p2=(struct SLL*)malloc(sizeof(struct SLL));
		head=NULL;
		
		while(n<i)
			{
				n++;
				
				if(n==1)
					{
						head=p1;
						printf("PLease input no.%d data:\n",n);
						scanf("%d",&p1->data);	
					}
				else 
					{
						p2=(struct SLL*)malloc(sizeof(struct SLL));
						p1->next=p2;
						p1=p2;
						printf("PLease input no.%d data:\n",n);
						scanf("%d",&p1->data);
					}	
			}
		p1->next=NULL;
		return head;
	}
	
//������ӡ�б� 
void print(struct SLL* head)				//������ӡ�б� 
	{
		struct SLL* node=head;
		
		while(node!=NULL)
			{
				printf("%d",node->data);
				node=node->next;
			}
	}

//��������ż����	
void swap(struct SLL* head)
{
    struct SLL*currNode=head;
    struct SLL*prevNode=NULL;
    struct SLL*nextNode;
    
    while(currNode!=NULL && currNode->next!=NULL)		//ͷ����β�ڵ㲻Ϊ�� 
    {
    	nextNode=currNode->next;						//����nextdodeָ��currnode��һ�� 
        currNode->next=nextNode->next;		
        nextNode->next=currNode;				//��ż���� 
        
        if(prevNode==NULL)						//��һ�α�������ż����֮��nextnode��Ϊͷ���,���丳��head  
            head=nextNode;
            
        currNode=currNode->next;				//��currnodeָ����һ����ż�����Ľ��ĵ�һ����� 
	}
}

//�������е����  
struct SLL* searchMid(struct SLL* head) {
 
    struct SLL *fast=head,*slow=head;
 
    while(fast!=NULL&&fast->next!=NULL) {
        fast=fast->next->next;
        slow=slow->next;
    }
 
    return slow;
}

//�ж��б��Ƿ�ɻ� 
void judge_Cylization(struct SLL *head){
	int judge;
    if(head==NULL) judge=0;
    
    struct SLL *fast=head;
    struct SLL *slow=head;
    
    while(1){
        if(slow==NULL || slow->next==NULL || fast==NULL ||fast->next==NULL || fast->next->next==NULL)
        	{
        		judge=0;break;
			}
		else 
			{
				slow=slow->next;fast=fast->next->next;
			}
        if(slow == fast) judge=1;
    }
    printf("%d",judge?"yes\n":"no\n");				//judgeΪ1��˵���ɻ���Ϊ0��˵�����ɻ��� 
}

//��������ת�б� 
struct SLL* reverse_1(struct SLL* head)			//������ 
{
	struct SLL *p1,*p2;
	p1=head;
	head=NULL;
	while(p1!=NULL) 
	{
		p2=p1;
		p1=p1->next;
		p1->next=p2;
		head=p1;		
	}
	return head;
}
