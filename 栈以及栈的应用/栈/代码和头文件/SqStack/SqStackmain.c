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
	printf("\t1.��ʼ��ջ\n");
	printf("\t2.��ջ\n");
	printf("\t3.��ջ\n");
	printf("\t4.�ж�ջ�Ƿ�Ϊ��\n");
	printf("\t5.�õ�ջ��Ԫ��\n");
	printf("\t6.���ջ\n");
	printf("\t7.����ջ\n");
	printf("\t8.���ջ�ĳ���\n");
	printf("\t9.�˳�\n");
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
				printf("ջ���ǿյ�\n");
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
			printf("�������\n");
			getch();
			return ERROR; 
	}
}

//����������װ�� 
Status Scan(ElemType*data){
	char s[20];
	int i;
	fflush(stdin);
	scanf("%s",s);
	for(i=0,*data=0;s[i];i++){
		if(s[i]>='0'&&s[i]<='9'){
			*data=*data*10+(ElemType)(s[i]-'0');
		}else{
			printf("�������\n");
			getch();
			return ERROR;
		}
	}
	return SUCCESS;
}

void Print(SqStack *const s){
	int i;
	printf("ջ��"); 
	if(isEmptyStack(s)){
		printf("(��)");
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
		printf("˳��ջ�Ѿ���ʼ��,���봴����ջ����������ԭ�ȵ�ջ\n");
		getch();
		return ERROR;		
	}
	printf("������ջ�Ĵ�С\n");
	Scan(&sizes);
	if(initStack(s,sizes)){
		printf("��ʼ���ɹ�\n");
		getch();
	}
}

Status Push(SqStack*s){
	ElemType data;
	if(!s){
		printf("���ȳ�ʼ��ջ\n");
		getch();
		return ERROR;
	}
	printf("��������ջ���ݣ�");
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
		printf("���ȳ�ʼ��ջ\n");
		getch();
		return ERROR;
	}
	if(popStack(s,&data)){
		printf("��ջ��������%d\n",data);
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
		printf("���ȳ�ʼ��ջ\n");
		getch();
		return ERROR;
	}
	if(isEmptyStack(s)){
		return ERROR;
	}
	if(stackLength(s,&length)){
		printf("ջ�ĳ���Ϊ��%d\n",length);
		getch();
		return SUCCESS;
	}
	printf("��ȡʧ��\n");
	return ERROR;
}

Status getTop(SqStack*s){
	ElemType e;
	if(!s){
		printf("���ȳ�ʼ��ջ\n");
		getch();
		return ERROR;
	}
	if(getTopStack(s,&e)){
		printf("ջ������Ϊ��%d\n",e);
		getch();
		return SUCCESS;
	}
	printf("��ȡʧ��\n");
	return ERROR;
}
