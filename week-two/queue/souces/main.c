#include <stdio.h>
#include "queue.h"
int main() {
    Queue *queue = create_queue();
    printf("请输入你要存储的数据个数：\n");
    int n;
    scanf("%d",&n);
    if(n<=1e-6){
		printf("输入错误！\n"); 
    	return 0;
	}
	else{
	for(int i=1;i<=n;i++){
	    printf("请输入你要存储的数据类型：\n");
	    printf("1、int型；	2、char型；	3、float型;	 4、结束；\n");
		int choose;
		int x=0;
		char y=0;
		float z=0;
		
		scanf("%d",&choose);
		switch(choose)
		{
			case(1):
				scanf("%d",&x);
				enqueue(queue,&x);break;
			case(2):
				scanf("%c",&y);
				enqueue(queue,&y);break;
			case(3):
				scanf("%f",&z);
				enqueue(queue,&z);break;
			default:printf("enter data over!\n");
		}
	}
	}
    return 0;
}

