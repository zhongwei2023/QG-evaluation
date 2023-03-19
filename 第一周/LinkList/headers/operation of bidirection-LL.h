#include <stdio.h>
#include <stdlib.h>

struct BLL 							//bidirectiinal link list 
{
	struct BLL * prev;
	int data;
	struct BLL * next;
};

struct BLL* creatBLL(void)				//´´½¨bidirectiinal link list 
	{
		struct BLL * head;
		struct BLL *p1,*p2;
		int i=0,n=0;
		printf("PLease input the number of node:\n");
		scanf("%d",&i);
		
		p1=p2=(struct BLL*)malloc(sizeof(struct BLL));
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
						p2=(struct BLL*)malloc(sizeof(struct BLL));
						p1->next=p2;
						p2->prev=p1;
						p1=p2;
						printf("PLease input no.%d data:\n",n);
						scanf("%d",&p1->data);
					}	
			}
		p1->next=NULL;
		return head;
	}
	
