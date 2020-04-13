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
	printf("\t1.初始化队列\n");
	printf("\t2.入队\n");
	printf("\t3.出队\n");
	printf("\t4.清空队列\n");
	printf("\t5.销毁队列\n");
	printf("\t6.检查队列是否为空\n");
	printf("\t7.判查看队头元素\n");
	printf("\t8.确定队列长度\n");
	printf("\t9.遍历 函数操作\n");
	printf("\t10.退出\n");
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
				printf("请先初始化\n");
				system("pause");
				break;
			}
			EnLQueue(Q);
			break;
		case 3:
			if(Q->front == NULL){
				printf("请先初始化\n");
				system("pause");
				break;
			}
			Delete(Q);
			break;
		case 4:
			if(Q->front == NULL){
				printf("请先初始化\n");
				system("pause");
				break;
			}
			ClearLQueue(Q);
			printf("success\n");
			system("pause");
			break;
		case 5:
			if(Q->front == NULL){
				printf("请先初始化\n");
				system("pause");
				break;
			}
			DestoryLQueue(Q);
			printf("success\n");
			system("pause");
			break;
		case 6:
			if(Q->front == NULL){
				printf("请先初始化\n");
				system("pause");
				break;
			}
			if(!IsEmptyLQueue(Q)){
				printf("队列不为空\n");
				system("pause");
			}
			break;
		case 7:
			if(Q->front == NULL){
				printf("请先初始化\n");
				system("pause");
				break;
			}
			GetHead(Q,datatype);
			break;
		case 8:
			if(Q->front == NULL){
				printf("请先初始化\n");
				system("pause");
				break;
			}
			Length(Q);
			break;
		case 9:
			if(Q->front == NULL){
				printf("请先初始化\n");
				system("pause");
				break;
			}
			TraverseLQueue(Q,LPrint);
			break;
		case 10:
			exit(1);
			break;
		default:
			printf("输入错误，请重新输入\n");
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
			printf("队首数据为%d\n",*(int*)e);
			system("pause");
			break;
		case 'f':
			printf("队首数据为%f\n",*(int*)e);
			system("pause");
			break;
		case 'c':
			printf("队首数据为%c\n",*(int*)e);
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
	printf("队列长度为%d\n",l);
	system("pause");
}
