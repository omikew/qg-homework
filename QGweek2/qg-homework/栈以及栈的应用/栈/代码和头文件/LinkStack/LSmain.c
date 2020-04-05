#include"LinkStack.h"

void main(){
	void menu(LinkStack**s);
	LinkStack *s;
	s=NULL;
	while(1){
		menu(&s);
	}
}

void menu(LinkStack**s){
	int i;
	
	system("cls");
	printf("***********\n");
	printf("\t1.初始化栈\n");
	printf("\t2.入栈\n"); 
	printf("\t3.出栈\n"); 
	printf("\t4.判断栈是否为空\n"); 
	printf("\t5.得到栈顶元素\n"); 
	printf("\t6.清空栈\n"); 
	printf("\t7.销毁栈\n"); 
	printf("\t8.检测栈长度\n"); 
	printf("\t9.退出\n");  
	printf("***********\n");
	
	scanf("%d",&i);
	switch(i){
		case 1:
			initLStack(s);
			break;
		case 2:
			Push(*s);
			break;
		case 3:
			Pop(*s);
			break;
		case 4:
			if(!isEmptyLStack(*s)){
				printf("栈不是空的\n");
				getch();
			}
			break;
		case 5:
			getTop(*s); 
			break;
		case 6:
			clearLStack(*s); 
			break;
		case 7:
			destroyLStack(s); 
			break;
		case 8:
			getLength(*s);
			break;
		case 9:
			exit(1);
			break;
		default:
			printf("输入出错\n");
			getch();
			menu(s);
	} 
}

Status Push(LinkStack*s){
	ElemType data;
	if(!s){
		printf("请先初始化栈\n");
		getch();
		return ERROR;
	}
	printf("请输入入栈数据：");
	scanf("%d",&data); 
	if(pushLStack(s,data)){
		printf("push success\n");
		Print(s);
		return SUCCESS;
	}
	printf("push error\n");
	return ERROR;
}

Status Pop(LinkStack*s){
	ElemType data;
	if(!s){
		printf("请先初始化栈\n");
		getch();
		return ERROR;
	}
	if(popLStack(s,&data)){
		printf("出栈的数据是%d\n",data);
		Print(s);
		return SUCCESS;
	}
	printf("pop error!");
	return ERROR;
}
void Print(LinkStack*s){
	LinkStackPtr p;
	printf("栈："); 
	if(isEmptyLStack(s)){
		printf("(空)");
	}
	for(p=s->top;p;p=p->next){
		printf("%d\t",p->data);
	}
	printf("\n");
	getch();
}
Status getLength(LinkStack*s){
	int length;
	if(!s){
		printf("请先初始化栈\n");
		getch();
		return ERROR;
	}
	if(isEmptyLStack(s)){
		return ERROR;
	}
	if(LStackLength(s,&length)){
		printf("栈的长度为：%d\n",length);
		getch();
		return SUCCESS;
	}
	printf("获取失败\n");
	return ERROR;
}
Status getTop(LinkStack*s){
	ElemType e;
	if(!s){
		printf("请先初始化栈\n");
		getch();
		return ERROR;
	}
	if(getTopLStack(s,&e)){
		printf("栈顶数据为：%d\n",e);
		getch();
		return SUCCESS;
	}
	printf("获取失败\n");
	return ERROR;
}
