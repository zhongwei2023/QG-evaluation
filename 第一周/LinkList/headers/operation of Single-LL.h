#include <stdio.h>
#include <stdlib.h> 

struct SLL				//SLL即single link list 
	{
		int data;
		struct SLL * next;
	}; 

//创建单链表 
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
	
//遍历打印列表 
void print(struct SLL* head)				//遍历打印列表 
	{
		struct SLL* node=head;
		
		while(node!=NULL)
			{
				printf("%d",node->data);
				node=node->next;
			}
	}

//单链表奇偶调换	
void swap(struct SLL* head)
{
    struct SLL*currNode=head;
    struct SLL*prevNode=NULL;
    struct SLL*nextNode;
    
    while(currNode!=NULL && currNode->next!=NULL)		//头结点和尾节点不为空 
    {
    	nextNode=currNode->next;						//先让nextdode指向currnode下一个 
        currNode->next=nextNode->next;		
        nextNode->next=currNode;				//奇偶调换 
        
        if(prevNode==NULL)						//第一次遍历，奇偶调换之后，nextnode成为头结点,将其赋给head  
            head=nextNode;
            
        currNode=currNode->next;				//让currnode指向下一对奇偶调换的结点的第一个结点 
	}
}

//单链表中点查找  
struct SLL* searchMid(struct SLL* head) {
 
    struct SLL *fast=head,*slow=head;
 
    while(fast!=NULL&&fast->next!=NULL) {
        fast=fast->next->next;
        slow=slow->next;
    }
 
    return slow;
}

//判断列表是否成环 
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
    printf("%d",judge?"yes\n":"no\n");				//judge为1，说明成环，为0，说明不成环。 
}

//迭代法反转列表 
struct SLL* reverse_1(struct SLL* head)			//迭代法 
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
