#include <stdio.h>
#include <stdlib.h>
#include "Calculator.h" 

int main(){
	 
    char infix[100];
    char postfix[100];
    printf("example:(3+2)*3-7\n");
	printf("remind:请勿输入等号，仅支持结果和运算因子为正数的运算\n");
	printf("Please input the infix expression: \n");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix)-1] = '\0'; // 去掉末尾的换行符
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    int result = calculate(postfix);
    if(result != -1){
        printf("Expression result: %d\n", result);
    }
    return 0;
}


 
