#include <stdio.h>
#include <stdlib.h>
#include "Calculator.h" 

int main(){
	 
    char infix[100];
    char postfix[100];
    printf("example:(3+2)*3-7\n");
	printf("remind:��������Ⱥţ���֧�ֽ������������Ϊ����������\n");
	printf("Please input the infix expression: \n");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix)-1] = '\0'; // ȥ��ĩβ�Ļ��з�
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    int result = calculate(postfix);
    if(result != -1){
        printf("Expression result: %d\n", result);
    }
    return 0;
}


 
