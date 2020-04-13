#include"LQueue.h" 

void main(){
	void menu (LQueue *Q);

	LQueue *Q;
	Q = (LQueue*)malloc(sizeof(LQueue));
	Q->front = Q->rear = NULL;
	while(1){
		menu(Q);
	}
}

void menu (LQueue *Q){
	
	int i;
	
	system("cls");
	printf("********************\n");
	printf("\t1.��ʼ������\n");
	printf("\t2.���\n");
	printf("\t3.����\n");
	printf("\t4.��ն���\n");
	printf("\t5.���ٶ���\n");
	printf("\t6.�������Ƿ�Ϊ��\n");
	printf("\t7.�в鿴��ͷԪ��\n");
	printf("\t8.ȷ�����г���\n");
	printf("\t9.���� ��������\n");
	printf("\t10.�˳�\n");
	printf("********************\n");
	if(scanf("%d",&i) == 0){
		fflush(stdin);
	}
	switch(i){
		case 1:
			InitLQueue(Q);
			break; 
		case 2:
			if(Q->front == NULL){
				printf("���ȳ�ʼ��\n");
				system("pause");
				break;
			}
			EnLQueue(Q);
			break;
		case 3:
			if(Q->front == NULL){
				printf("���ȳ�ʼ��\n");
				system("pause");
				break;
			}
			Delete(Q);
			break;
		case 4:
			if(Q->front == NULL){
				printf("���ȳ�ʼ��\n");
				system("pause");
				break;
			}
			ClearLQueue(Q);
			printf("success\n");
			system("pause");
			break;
		case 5:
			if(Q->front == NULL){
				printf("���ȳ�ʼ��\n");
				system("pause");
				break;
			}
			DestoryLQueue(Q);
			printf("success\n");
			system("pause");
			break;
		case 6:
			if(Q->front == NULL){
				printf("���ȳ�ʼ��\n");
				system("pause");
				break;
			}
			if(!IsEmptyLQueue(Q)){
				printf("���в�Ϊ��\n");
				system("pause");
			}
			break;
		case 7:
			if(Q->front == NULL){
				printf("���ȳ�ʼ��\n");
				system("pause");
				break;
			}
			GetHead(Q,datatype);
			break;
		case 8:
			if(Q->front == NULL){
				printf("���ȳ�ʼ��\n");
				system("pause");
				break;
			}
			Length(Q);
			break;
		case 9:
			if(Q->front == NULL){
				printf("���ȳ�ʼ��\n");
				system("pause");
				break;
			}
			TraverseLQueue(Q,LPrint);
			break;
		case 10:
			exit(1);
			break;
		default:
			printf("�����������������\n");
			system("pause");
			menu(Q);	
	}
}


Status Delete (LQueue *Q){
	if(DeLQueue(Q)){
		printf("succuss\n");
		system("pause");
		return TRUE;
	}
	printf("error\n");
	system("pause");
	return FALSE;
}

Status GetHead (LQueue*Q,char datatype[30]){
	void *e;
	char t;
	GetHeadLQueue(Q,&e);
	t = datatype[0];
	switch(t){
		case 'i':
			printf("��������Ϊ%d\n",*(int*)e);
			system("pause");
			break;
		case 'f':
			printf("��������Ϊ%f\n",*(int*)e);
			system("pause");
			break;
		case 'c':
			printf("��������Ϊ%c\n",*(int*)e);
			system("pause");
			break;
		default:
			printf("error\n");
			system("pause");
			return FALSE;		
	}
	return TRUE;
} 

Status Length(LQueue*Q){
	int l;
	l = LengthLQueue(Q);
	printf("���г���Ϊ%d\n",l);
	system("pause");
}
