#include"SqStack.h"

//初始化栈
Status initStack(SqStack **s,int sizes){
	*s=(SqStack*)malloc(sizeof(SqStack));
	if((*s)->elem=(ElemType*)malloc(sizes*sizeof(ElemType))){
		(*s)->size=sizes;
		(*s)->top=-1;
		return SUCCESS;
	}
}

//判断栈是否为空
Status isEmptyStack(SqStack *s){
	if(!s){
		printf("请先初始化\n");
		getch();
		return SUCCESS;
	}
	if(s->top==-1){
		printf("栈是空的\n");
		getch();
		return SUCCESS;
	}
	return ERROR;
}

//得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e){
	if(isEmptyStack(s)){
		return ERROR;
	}
	*e=s->elem[s->top];
	return SUCCESS;
}

//清空栈
Status clearStack(SqStack *s){
	if(isEmptyStack(s)){
		return ERROR;
	}
	s->top=-1;
	printf("栈已清空\n");
	getch();
	return SUCCESS;
}

//销毁栈
Status destroyStack(SqStack **s){
	if(!(*s)){
		printf("请先初始化\n");
		getch(); 
		return ERROR; 
	}
	free(*s);
	*s=NULL;
	printf("栈已销毁\n");
	getch();
	return SUCCESS;
}

//检测栈长度
Status stackLength(SqStack *s,int *length){
	*length=s->top+1;
}

//入栈
Status pushStack(SqStack *s,ElemType data){
	if(s->top==s->size-1){
		printf("栈是满的\n");
		return ERROR;
	}
	s->top++;
	s->elem[s->top]=data;
	return SUCCESS;
}

//出栈
Status popStack(SqStack *s,ElemType *data){
	if(isEmptyStack(s)){
		return ERROR;
	}
	*data=s->elem[s->top];
	s->top--;
	return SUCCESS;
}
