#include"LQueue.h"
//初始化 
void InitLQueue(LQueue *Q){
	
	Node *p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	Q->front = Q->rear = p;
	Q->length = 0;
	datatype[0] = '\0';
}

//入队
Status EnLQueue(LQueue *Q){
	void *data;
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = malloc(sizeof(void));
	data = Scan(Q);
	switch(datatype[strlen(datatype)-1]){
		case 'i':
			//memcpy(p->data, data, sizeof(int));
			*(int*)p->data = *(int*)data;
			break;
		case 'f':
			memcpy(p->data, data, sizeof(float));
			break;
		case 'c':
			memcpy(p->data, data, sizeof(char));
			break;
	}
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	Q->length++;
	return TRUE;
}

//出队
Status DeLQueue(LQueue *Q){
	Node *p;
	int i;
	if(Q->front == Q->rear){
		return FALSE;
	}
	p = Q->front->next;
	Q->front->next = p->next;
	if(Q->rear == p){
		Q->rear = Q->front;
	} 
	Q->length--;
	free(p);
	for(i=0;i<strlen(datatype);i++){
		datatype[i] = datatype[i+1];
	}
	return TRUE;
} 

//清空队列
void ClearLQueue(LQueue *Q){
	
	while(Q->front != Q->rear){
		DeLQueue(Q);
	}
} 

//销毁
 void DestoryLQueue(LQueue *Q){
 	ClearLQueue(Q);
 	free(Q->front);
 	Q->front = Q->rear = NULL;
}
 
//检查是否为空
Status IsEmptyLQueue(const LQueue *Q){
	
	if(Q->length == 0){
		printf("队列为空\n");
		system("pause");
		return TRUE;
	}
	return FALSE;
}

//查看队头元素
Status GetHeadLQueue(LQueue *Q, void **e){
	if(IsEmptyLQueue(Q)){
		return FALSE;
	}
	*e = Q->front->next->data;
	return TRUE; 	
}

//确定队列长度
int LengthLQueue(LQueue *Q){
	return Q->length;
}

//遍历函数操作
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q)){
	Node *q;
	int i;
	if(IsEmptyLQueue(Q)){
		return FALSE;
	}
	for(q = Q->front->next,i=0; q; q = q->next,i++){
		type = datatype[i];
		(foo)(q->data);
	}
	system("pause");
}

//操作函数
void LPrint(void *q){
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

//输入
void* Scan (LQueue *Q){
	char t[20];
	int a;
	float b;
	char c;
	void *data = (void*)malloc(sizeof(void));
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
			scanf("%d",&a);
			data = &a;
			break;
		case 'f':
			printf("请输入数据：");
			scanf("%f",&b);
			data = &b;
			break;
		case 'c':
			type = 'c';
			printf("请输入数据：");
			scanf("%c",&c);
			data = &c;
			break;
		default:
			printf("输入类型不在允许范围内（为简化代码只允许int、float、char）\n");
			system("pause");
			return FALSE;		
	}
	datatype[strlen(datatype)+1] = datatype[strlen(datatype)];
	datatype[strlen(datatype)] = type;
	return data;
} 
