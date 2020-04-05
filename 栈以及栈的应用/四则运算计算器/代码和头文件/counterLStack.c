#include"LinkStack.h"
//初始化栈
Status initLStack(LinkStack **s){
	if(*s){
		printf("栈已经初始化，若想创建新栈，请先销毁原先的栈。\n");
		getch();
		return ERROR;
	}
	*s=(LinkStack*)malloc(sizeof(LinkStack));
	(*s)->top=NULL;
	(*s)->count=0;	
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	
	if(!s){
		printf("请先初始化栈\n");
		getch();
		return SUCCESS;
	}
	if(s->count==0){
		printf("栈是空的\n");
		getch();
		return SUCCESS;
	}
	return ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(isEmptyLStack(s)){
		return ERROR; 
	}
	*e=s->top->data;
	return SUCCESS; 
}

//清空栈
Status clearLStack(LinkStack *s){
	LinkStackPtr p;
	if(!s){
		printf("请先初始化栈\n");
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

//销毁栈
Status destroyLStack(LinkStack **s){
	LinkStackPtr p;
	if(!*s){
		printf("请先初始化栈\n");
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

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	*length=s->count;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p;
	p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top;
	s->top=p;
	s->count++;
	return SUCCESS; 
}

//出栈
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

