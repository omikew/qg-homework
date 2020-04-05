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
	printf("\t1.��ʼ��ջ\n");
	printf("\t2.��ջ\n"); 
	printf("\t3.��ջ\n"); 
	printf("\t4.�ж�ջ�Ƿ�Ϊ��\n"); 
	printf("\t5.�õ�ջ��Ԫ��\n"); 
	printf("\t6.���ջ\n"); 
	printf("\t7.����ջ\n"); 
	printf("\t8.���ջ����\n"); 
	printf("\t9.�˳�\n");  
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
				printf("ջ���ǿյ�\n");
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
			printf("�������\n");
			getch();
			menu(s);
	} 
}

Status Push(LinkStack*s){
	ElemType data;
	if(!s){
		printf("���ȳ�ʼ��ջ\n");
		getch();
		return ERROR;
	}
	printf("��������ջ���ݣ�");
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
		printf("���ȳ�ʼ��ջ\n");
		getch();
		return ERROR;
	}
	if(popLStack(s,&data)){
		printf("��ջ��������%d\n",data);
		Print(s);
		return SUCCESS;
	}
	printf("pop error!");
	return ERROR;
}
void Print(LinkStack*s){
	LinkStackPtr p;
	printf("ջ��"); 
	if(isEmptyLStack(s)){
		printf("(��)");
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
		printf("���ȳ�ʼ��ջ\n");
		getch();
		return ERROR;
	}
	if(isEmptyLStack(s)){
		return ERROR;
	}
	if(LStackLength(s,&length)){
		printf("ջ�ĳ���Ϊ��%d\n",length);
		getch();
		return SUCCESS;
	}
	printf("��ȡʧ��\n");
	return ERROR;
}
Status getTop(LinkStack*s){
	ElemType e;
	if(!s){
		printf("���ȳ�ʼ��ջ\n");
		getch();
		return ERROR;
	}
	if(getTopLStack(s,&e)){
		printf("ջ������Ϊ��%d\n",e);
		getch();
		return SUCCESS;
	}
	printf("��ȡʧ��\n");
	return ERROR;
}
