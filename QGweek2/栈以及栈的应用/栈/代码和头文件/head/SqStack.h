#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status 
{
	ERROR = 0, SUCCESS = 1
} Status;

typedef int ElemType;

typedef struct SqStack 
{
	ElemType *elem;
	int top;
	int size;
} SqStack;


//���������˳��ջ
Status initStack(SqStack **s,int sizes);//��ʼ��ջ
Status isEmptyStack(SqStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopStack(SqStack *s,ElemType *e); //�õ�ջ��Ԫ��
Status clearStack(SqStack *s);//���ջ
Status destroyStack(SqStack **s);//����ջ
Status stackLength(SqStack *s,int *length);//���ջ����
Status pushStack(SqStack *s,ElemType data);//��ջ
Status popStack(SqStack *s,ElemType *data);//��ջ

Status getTop(SqStack*s);
Status getLength(SqStack*s);
Status Pop(SqStack*s);
Status Push(SqStack*s);
void Print(SqStack*s);
Status Scan(ElemType*data);
Status Init(SqStack**s);
#endif 
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
