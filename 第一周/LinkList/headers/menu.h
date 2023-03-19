#include <stdio.h>
#include "operation of Single-LL.h" 
#include "operation of bidirection-LL.h" 

void menu_2()//单链表的menu 
{
	struct SLL* pt;
	pt=creat();
    puts("");
    printf("\t\t***********单链表界面 ***************\n");
    printf("\t\t*                                   *\n");
    printf("\t\t*          1.奇偶调换               *\n");
    printf("\t\t*          2.查找中点               *\n");
    printf("\t\t*          3.判断是否成环           *\n");
    printf("\t\t*          4.反转链表               *\n");
    printf("\t\t*          5.退出操作               *\n");
	printf("\t\t*                                   *\n");
    printf("\t\t*************************************\n");
    puts("");
    printf("请选择您要进行的操作：");
    int choose;
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        swap(pt);
  
        break;
    case 2:
        printf("%d",searchMid(pt));
        
        break;
    case 3:
    	judge_Cylization(pt);
    	
        break;
    case 4:
        reverse_1(pt);

        break;
    case 5:
        break;
    default:
        printf("操作异常！");
		menu_2();
        break;
    }
}

void menu_3()//双向链表的menu 
{
	struct SLL* pt;
	pt=(struct SLL*)creatBLL();			//转换指针类型，使单链表几个函数也能用于双向链表 
    puts("");
    printf("\t\t***********双向链表界面 ***************\n");
    printf("\t\t*                                   *\n");
    printf("\t\t*          1.奇偶调换               *\n");
    printf("\t\t*          2.查找中点               *\n");
    printf("\t\t*          3.判断是否成环           *\n");
    printf("\t\t*          4.反转链表               *\n");
    printf("\t\t*          5.退出操作               *\n");
	printf("\t\t*                                   *\n");
    printf("\t\t*************************************\n");
    puts("");
    printf("请选择您要进行的操作：");
    int choose;
    scanf("%d",&choose);
    switch(choose)
    {
    case 1:
        swap(pt);
  
        break;
    case 2:
        printf("%d",searchMid(pt));
        
        break;
    case 3:
    	judge_Cylization(pt);
    	
        break;
    case 4:
        reverse_1(pt);

        break;
    case 5:
        break;
    default:
        printf("操作异常！");
		menu_2();
        break;
    }
}


void menu_1()
{
    puts("");
    printf("\t\t**********  链表 操作  **************\n");
    printf("\t\t*                                   *\n");
    printf("\t\t*          1.创建单链表             *\n");
    printf("\t\t*          2.双向列表               *\n");
    printf("\t\t*          3.退出                   *\n");
    printf("\t\t*                                   *\n");
    printf("\t\t*************************************\n");
    puts("");
    printf("请选择您要进行的操作：");
    int choose;
    scanf("%d",&choose);
    
    switch(choose)
    {
    case 1:
        menu_2();
        break;
    case 2:
		menu_3();
        break;
    case 3:
        break;
    default:
        printf("操作异常！");
        menu_1();
        break;
    }
}


