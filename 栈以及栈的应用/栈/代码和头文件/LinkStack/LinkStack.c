#include"LinkStack.h"
//��ʼ��ջ
Status initLStack(LinkStack **s){
	if(*s){
		printf("ջ�Ѿ���ʼ�������봴����ջ����������ԭ�ȵ�ջ��\n");
		getch();
		return ERROR;
	}
	*s=(LinkStack*)malloc(sizeof(LinkStack));
	(*s)->top=NULL;
	(*s)->count=0;	
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	
	if(!s){
		printf("���ȳ�ʼ��ջ\n");
		getch();
		return SUCCESS;
	}
	if(s->count==0){
		printf("ջ�ǿյ�\n");
		getch();
		return SUCCESS;
	}
	return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(isEmptyLStack(s)){
		return ERROR; 
	}
	*e=s->top->data;
	return SUCCESS; 
}

//���ջ
Status clearLStack(LinkStack *s){
	LinkStackPtr p;
	if(!s){
		printf("���ȳ�ʼ��ջ\n");
		getch();
		return ERROR;
	}
	if(isEmptyLStack(s)){
		return ERROR; 
	}
	while(s->top){
		p=s->top;
		s->top=p->next;
		free(p);
		s->count--;
	}
	p=NULL;
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack **s){
	LinkStackPtr p;
	if(!*s){
		printf("���ȳ�ʼ��ջ\n");
		getch();
		return ERROR;
	}
	while((*s)->top){
		p=(*s)->top;
		(*s)->top=p->next;
		free(p);
		(*s)->count--;
	}
	p=NULL;
	*s=NULL;
	return SUCCESS;	
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	*length=s->count;
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p;
	p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top;
	s->top=p;
	s->count++;
	return SUCCESS; 
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	LinkStackPtr p;
	if(isEmptyLStack(s)){
		return ERROR;
	}
	*data=s->top->data;
	p=s->top;
	s->top=s->top->next;
	s->count--;
	free(p);
	p=NULL;
	return SUCCESS;
}

