#include"SqStack.h"

void main(){
	Status meun(SqStack**s);
	SqStack *s=NULL;
	while(1){
		meun(&s);
	}
}

Status meun(SqStack**s){ 
	int i;
	system("cls");
	printf("*********************\n");
	printf("\t1.初始化栈\n");
	printf("\t2.入栈\n");
	printf("\t3.出栈\n");
	printf("\t4.判断栈是否为空\n");
	printf("\t5.得到栈顶元素\n");
	printf("\t6.清空栈\n");
	printf("\t7.销毁栈\n");
	printf("\t8.检测栈的长度\n");
	printf("\t9.退出\n");
	printf("*********************\n");
	
	Scan(&i);	
	switch(i){
		case 1:
			Init(s);
			break;
		case 2:
			Push(*s);
			break;
		case 3:
			Pop(*s);
			break;
		case 4:
			if(!isEmptyStack(*s)){
				printf("栈不是空的\n");
				getch();
			}
			break;
		case 5:
			getTop(*s); 
			break;
		case 6:
			clearStack(*s); 
			break;
		case 7:
			destroyStack(s); 
			break;
		case 8:
			getLength(*s);
			break;
		case 9:
			exit(1);
			break;
		default:
			printf("输入错误\n");
			getch();
			return ERROR; 
	}
}

//防脸滚键盘装置 
Status Scan(ElemType*data){
	char s[20];
	int i;
	fflush(stdin);
	scanf("%s",s);
	for(i=0,*data=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			*data=*data*10+(ElemType)(s[i]-'0');
		}else{
			printf("输入出错\n");
			getch();
			return ERROR;
		}
	}
	return SUCCESS;
}

void Print(SqStack *const s){
	int i;
	printf("栈："); 
	if(isEmptyStack(s)){
		printf("(空)");
	}
	for(i=0;i<=s->top;i++){
		printf("%d\t",s->elem[i]);
	}
	printf("\n");
	getch();
}

Status Init(SqStack**s){
	int sizes;
	if(*s){
		printf("顺序栈已经初始化,若想创建新栈，请先销毁原先的栈\n");
		getch();
		return ERROR;		
	}
	printf("请输入栈的大小\n");
	Scan(&sizes);
	if(initStack(s,sizes)){
		printf("初始化成功\n");
		getch();
	}
}

Status Push(SqStack*s){
	ElemType data;
	if(!s){
		printf("请先初始化栈\n");
		getch();
		return ERROR;
	}
	printf("请输入入栈数据：");
	if(!Scan(&data)){
		return ERROR;
	}
	if(pushStack(s,data)){
		printf("push success\n");
		Print(s);
		return SUCCESS;
	}
	printf("push error\n");
	return ERROR;
}

Status Pop(SqStack*s){
	ElemType data;
	if(!s){
		printf("请先初始化栈\n");
		getch();
		return ERROR;
	}
	if(popStack(s,&data)){
		printf("出栈的数据是%d\n",data);
		Print(s);
		return SUCCESS;
	}
	printf("pop error!");
	getch();
	return ERROR;
}

Status getLength(SqStack*s){
	int length;
	if(!s){
		printf("请先初始化栈\n");
		getch();
		return ERROR;
	}
	if(isEmptyStack(s)){
		return ERROR;
	}
	if(stackLength(s,&length)){
		printf("栈的长度为：%d\n",length);
		getch();
		return SUCCESS;
	}
	printf("获取失败\n");
	return ERROR;
}

Status getTop(SqStack*s){
	ElemType e;
	if(!s){
		printf("请先初始化栈\n");
		getch();
		return ERROR;
	}
	if(getTopStack(s,&e)){
		printf("栈顶数据为：%d\n",e);
		getch();
		return SUCCESS;
	}
	printf("获取失败\n");
	return ERROR;
}
