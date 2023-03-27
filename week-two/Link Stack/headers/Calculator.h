#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  //引用ctype库来判断输入的字符
#include "Operation of linkstack.h"

// 判断操作符优先级，返回1表示比栈顶元素优先级高
int isPriorityHigher(char op, char opTop){
    int priority[3][3] = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
    int index1, index2;
    if(op == '+') index1 = 0;
    else if(op == '-') index1 = 1;
    else index1 = 2;
    if(opTop == '+') index2 = 0;
    else if(opTop == '-') index2 = 1;
    else index2 = 2;
    return priority[index2][index1];
}

// 中缀表达式转后缀表达式
void infixToPostfix(char *infix, char *postfix){
    int i, j = 0;
    struct Node *top = createStack();
    for(i = 0; infix[i] != '\0'; i++){
        if(isdigit(infix[i])){
            postfix[j++] = infix[i];
            while(isdigit(infix[i+1])){
                i++;
                postfix[j++] = infix[i];
            }
            postfix[j++] = ' ';
        }
        else if(infix[i] == '('){
            top = push(top, infix[i]);
        }
        else if(infix[i] == ')'){
            while(getTop(top) != '('){
                postfix[j++] = getTop(top);
                postfix[j++] = ' ';
                top = pop(top);
            }
            top = pop(top);
        }
        else{
            while(!isEmpty(top) && getTop(top) != '(' && isPriorityHigher(infix[i], getTop(top))){
                postfix[j++] = getTop(top);
                postfix[j++] = ' ';
                top = pop(top);
            }
            top = push(top, infix[i]);
        }
    }
    while(!isEmpty(top)){
        postfix[j++] = getTop(top);
        postfix[j++] = ' ';
        top = pop(top);
    }
    postfix[j] = '\0';
}

// 计算表达式
int calculate(char* postfix){
    int i;
    struct Node *top = createStack();
    char num[100];
    for(i = 0; postfix[i] != '\0'; i++){
        if(postfix[i] == ' ') continue;
        if(isdigit(postfix[i])){
            int j = 0;
            while(isdigit(postfix[i])){
                num[j++] = postfix[i++];
            }
            num[j] = '\0';
            i--;
            top = push(top, atoi(num));
        }
        else{
            int a = getTop(top), b;
            top = pop(top);
            b = getTop(top);
            top = pop(top);
            switch(postfix[i]){
                case '+':
                    top = push(top, b + a);
                    break;
                case '-':
                    top = push(top, b - a);
                    break;
                case '*':
                    top = push(top, b * a);
                    break;
                case '/':
                    top = push(top, b / a);
                    break;
                default:
                    printf("Expression is invalid!");
                    return -1;
            }
        }
    }
    return getTop(top);
}

