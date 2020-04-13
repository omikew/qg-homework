#include"AQueue.h" 
//初始化队列 
void InitAQueue(AQueue *Q){
	int i;
	if(Q->flag == 1){
		printf("队列已经初始化,请先销毁\n"); 
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

//入队操作 
Status EnAQueue(AQueue *Q, void *data){
	if((Q->rear+1)%MAXQUEUE == Q->front){	//判断队列是否为满 
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

//出队操作 
Status DeAQueue(AQueue *Q){
	if(Q->front == Q->rear){	//判断队列是否为空 
		return FALSE;
	}
	Q->front = (Q->front+1)%MAXQUEUE;
	Q->length--;
	return TRUE;
} 

//清空队列
void ClearAQueue(AQueue *Q){
	Q->front = Q->rear = 0;
	Q->length = 0;
} 

//销毁队列
void DestoryAQueue(AQueue *Q){
	ClearAQueue(Q);
	Q = NULL;
} 

//检查队列是否已满 
Status IsFullAQueue(const AQueue *Q){
	if((Q->rear+1)%MAXQUEUE == Q->front){ 
		printf("队列已满\n");
		getch(); 
		return TRUE;
	}
	printf("队列未满\n");
	getch();
	return FALSE;
}

//检查队列是否为空
Status IsEmptyAQueue(const AQueue *Q){
	if(Q->front == Q->rear){	
		printf("队列为空\n");
		getch();
		return TRUE;
	}
	printf("队列不是空的\n");
	getch();
	return FALSE;
} 

//查看队头元素
Status GetHeadAQueue(AQueue *Q, void **e){
	*e = Q->data[Q->front];
	return TRUE;
} 

//确定队列长度 
int LengthAQueue(AQueue *Q){
	return (Q->rear-Q->front+MAXQUEUE)%MAXQUEUE; 
}

//操作函数 
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

//遍历 函数操作
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q)){
	
	int i;
	for(i = Q->front; i%MAXQUEUE != Q->rear; i=(i+1)%MAXQUEUE){
		type = datatype[i];
		(*foo)(Q->data[i]);
	}
	system("pause");
} 

//输入
Status Scan (AQueue *Q,void **data) {
	char t[20];
	int a;
	float b;
	char c;
	printf("请输入数据类型：");
	scanf("%s",t);
	//判断输入类型 
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
			printf("请输入数据：");
			if(scanf("%d",&a) == 0){
				fflush(stdin);
				return FALSE;
			}
			*data = &a;
			break;
		case 'f':
			printf("请输入数据：");
			if(scanf("%f",&b) == 0){
				fflush(stdin);
				return FALSE;
			}
			*data = &b;
			break;
		case 'c':
			printf("请输入数据：");
			if(scanf("%c",&c) == 0){
				fflush(stdin);
				return FALSE;
			}
			*data = &c;
			break;
		default:
			printf("输入类型不在允许范围内（为简化代码只允许int、float、char）\n");
			getch();
			return FALSE;		
	}
	datatype[Q->rear] = type;
	return TRUE;	
}

