#include"AQueue.h" 
//��ʼ������ 
void InitAQueue(AQueue *Q){
	int i;
	if(Q->flag == 1){
		printf("�����Ѿ���ʼ��,��������\n"); 
	}else{
		for(i=0;i<MAXQUEUE;i++){
			Q->data[i] = malloc(sizeof(void));
		}
		Q->front = 0;
		Q->rear = 0;
		Q->length = 0;
		Q->flag = 1;
	}
	
}

//��Ӳ��� 
Status EnAQueue(AQueue *Q, void *data){
	if((Q->rear+1)%MAXQUEUE == Q->front){	//�ж϶����Ƿ�Ϊ�� 
		return FALSE;
	}
	switch(datatype[Q->rear]){
		case 'i':
			*(int*)Q->data[Q->rear] = *(int*)data;
			break;
		case 'f':
			*(float*)Q->data[Q->rear] = *(float*)data;
			break;
		case 'c':
			*(char*)Q->data[Q->rear] = *(char*)data;
			break;
	}
	Q->rear = (Q->rear+1)%MAXQUEUE;
	Q->length++;
	return TRUE;
} 

//���Ӳ��� 
Status DeAQueue(AQueue *Q){
	if(Q->front == Q->rear){	//�ж϶����Ƿ�Ϊ�� 
		return FALSE;
	}
	Q->front = (Q->front+1)%MAXQUEUE;
	Q->length--;
	return TRUE;
} 

//��ն���
void ClearAQueue(AQueue *Q){
	Q->front = Q->rear = 0;
	Q->length = 0;
} 

//���ٶ���
void DestoryAQueue(AQueue *Q){
	ClearAQueue(Q);
	Q = NULL;
} 

//�������Ƿ����� 
Status IsFullAQueue(const AQueue *Q){
	if((Q->rear+1)%MAXQUEUE == Q->front){ 
		printf("��������\n");
		getch(); 
		return TRUE;
	}
	printf("����δ��\n");
	getch();
	return FALSE;
}

//�������Ƿ�Ϊ��
Status IsEmptyAQueue(const AQueue *Q){
	if(Q->front == Q->rear){	
		printf("����Ϊ��\n");
		getch();
		return TRUE;
	}
	printf("���в��ǿյ�\n");
	getch();
	return FALSE;
} 

//�鿴��ͷԪ��
Status GetHeadAQueue(AQueue *Q, void **e){
	*e = Q->data[Q->front];
	return TRUE;
} 

//ȷ�����г��� 
int LengthAQueue(AQueue *Q){
	return (Q->rear-Q->front+MAXQUEUE)%MAXQUEUE; 
}

//�������� 
void APrint(void *q){
	switch(type){
		case 'i':
			printf("%d\t",*(int*)q);
			break;
		case 'f':
			printf("%f\t",*(float*)q);
			break;
		case 'c':
			printf("%c\t",*(char*)q);
			break;
	}
	
}

//���� ��������
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	
	int i;
	for(i = Q->front; i%MAXQUEUE != Q->rear; i=(i+1)%MAXQUEUE){
		type = datatype[i];
		(*foo)(Q->data[i]);
	}
	system("pause");
} 

//����
Status Scan (AQueue *Q,void **data) {
	char t[20];
	int a;
	float b;
	char c;
	printf("�������������ͣ�");
	scanf("%s",t);
	//�ж��������� 
	if(strcmp(t,"int") == 0){
		type = 'i';
	}else if(strcmp(t,"float") == 0){
		type = 'f';
	}else if(strcmp(t,"char") == 0){
		type = 'c';
	}
	fflush(stdin);
	switch(type){
		case 'i':
			printf("���������ݣ�");
			if(scanf("%d",&a) == 0){
				fflush(stdin);
				return FALSE;
			}
			*data = &a;
			break;
		case 'f':
			printf("���������ݣ�");
			if(scanf("%f",&b) == 0){
				fflush(stdin);
				return FALSE;
			}
			*data = &b;
			break;
		case 'c':
			printf("���������ݣ�");
			if(scanf("%c",&c) == 0){
				fflush(stdin);
				return FALSE;
			}
			*data = &c;
			break;
		default:
			printf("�������Ͳ�������Χ�ڣ�Ϊ�򻯴���ֻ����int��float��char��\n");
			getch();
			return FALSE;		
	}
	datatype[Q->rear] = type;
	return TRUE;	
}

