#include"SqStack.h"

//��ʼ��ջ
Status initStack(SqStack **s,int sizes){
	*s=(SqStack*)malloc(sizeof(SqStack));
	if((*s)->elem=(ElemType*)malloc(sizes*sizeof(ElemType))){
		(*s)->size=sizes;
		(*s)->top=-1;
		return SUCCESS;
	}
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s){
	if(!s){
		printf("���ȳ�ʼ��\n");
		getch();
		return SUCCESS;
	}
	if(s->top==-1){
		printf("ջ�ǿյ�\n");
		getch();
		return SUCCESS;
	}
	return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e){
	if(isEmptyStack(s)){
		return ERROR;
	}
	*e=s->elem[s->top];
	return SUCCESS;
}

//���ջ
Status clearStack(SqStack *s){
	if(isEmptyStack(s)){
		return ERROR;
	}
	s->top=-1;
	printf("ջ�����\n");
	getch();
	return SUCCESS;
}

//����ջ
Status destroyStack(SqStack **s){
	if(!(*s)){
		printf("���ȳ�ʼ��\n");
		getch(); 
		return ERROR; 
	}
	free(*s);
	*s=NULL;
	printf("ջ������\n");
	getch();
	return SUCCESS;
}

//���ջ����
Status stackLength(SqStack *s,int *length){
	*length=s->top+1;
}

//��ջ
Status pushStack(SqStack *s,ElemType data){
	if(s->top==s->size-1){
		printf("ջ������\n");
		return ERROR;
	}
	s->top++;
	s->elem[s->top]=data;
	return SUCCESS;
}

//��ջ
Status popStack(SqStack *s,ElemType *data){
	if(isEmptyStack(s)){
		return ERROR;
	}
	*data=s->elem[s->top];
	s->top--;
	return SUCCESS;
}
