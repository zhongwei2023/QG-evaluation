#include <stdio.h>
#include "operation of Single-LL.h" 
#include "operation of bidirection-LL.h" 

void menu_2()//�������menu 
{
	struct SLL* pt;
	pt=creat();
    puts("");
    printf("\t\t***********��������� ***************\n");
    printf("\t\t*                                   *\n");
    printf("\t\t*          1.��ż����               *\n");
    printf("\t\t*          2.�����е�               *\n");
    printf("\t\t*          3.�ж��Ƿ�ɻ�           *\n");
    printf("\t\t*          4.��ת����               *\n");
    printf("\t\t*          5.�˳�����               *\n");
	printf("\t\t*                                   *\n");
    printf("\t\t*************************************\n");
    puts("");
    printf("��ѡ����Ҫ���еĲ�����");
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
        printf("�����쳣��");
		menu_2();
        break;
    }
}

void menu_3()//˫�������menu 
{
	struct SLL* pt;
	pt=(struct SLL*)creatBLL();			//ת��ָ�����ͣ�ʹ������������Ҳ������˫������ 
    puts("");
    printf("\t\t***********˫��������� ***************\n");
    printf("\t\t*                                   *\n");
    printf("\t\t*          1.��ż����               *\n");
    printf("\t\t*          2.�����е�               *\n");
    printf("\t\t*          3.�ж��Ƿ�ɻ�           *\n");
    printf("\t\t*          4.��ת����               *\n");
    printf("\t\t*          5.�˳�����               *\n");
	printf("\t\t*                                   *\n");
    printf("\t\t*************************************\n");
    puts("");
    printf("��ѡ����Ҫ���еĲ�����");
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
        printf("�����쳣��");
		menu_2();
        break;
    }
}


void menu_1()
{
    puts("");
    printf("\t\t**********  ���� ����  **************\n");
    printf("\t\t*                                   *\n");
    printf("\t\t*          1.����������             *\n");
    printf("\t\t*          2.˫���б�               *\n");
    printf("\t\t*          3.�˳�                   *\n");
    printf("\t\t*                                   *\n");
    printf("\t\t*************************************\n");
    puts("");
    printf("��ѡ����Ҫ���еĲ�����");
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
        printf("�����쳣��");
        menu_1();
        break;
    }
}


