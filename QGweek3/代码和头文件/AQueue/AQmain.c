#include"AQueue.h" 

void main(){
	void menu (AQueue *Q);

	AQueue Q;
	Q.flag = 0;
	while(1){
		menu(&Q);
	}
}

void menu (AQueue *Q){
	
	int i;
	
	system("cls");
	printf("********************\n");
	printf("\t1.初始化队列\n");
	printf("\t2.入队\n");
	printf("\t3.出队\n");
	printf("\t4.清空队列\n");
	printf("\t5.销毁队列\n");
	printf("\t6.检查队列是否已满\n");
	printf("\t7.检查队列是否为空\n");
	printf("\t8.判查看队头元素\n");
	printf("\t9.确定队列长度\n");
	printf("\t10.遍历 函数操作\n");
	printf("\t11.退出\n");
	printf("********************\n");
	if(scanf("%d",&i) == 0){
		fflush(stdin);
	}
	switch(i){
		case 1:
			InitAQueue(Q);
			break; 
		case 2:
			if(Q->flag == 0){
				printf("请先初始化队列\n");
				system("pause");
				break;
			}
			Enter(Q);
			break;
		case 3:
			if(Q->flag == 0){
				printf("请先初始化队列\n");
				system("pause");
				break;
			}
			Delete(Q);
			break;
		case 4:
			if(Q->flag == 0){
				printf("请先初始化队列\n");
				system("pause");
				break;
			}
			ClearAQueue(Q);
			printf("success\n");
			getch();
			break;
		case 5:
			if(Q->flag == 0){
				printf("请先初始化队列\n");
				system("pause");
				break;
			}
			DestoryAQueue(Q);
			printf("success\n");
			getch();
			break;
		case 6:
			if(Q->flag == 0){
				printf("请先初始化队列\n");
				system("pause");
				break;
			}
			IsFullAQueue(Q);
			break;
		case 7:
			if(Q->flag == 0){
				printf("请先初始化队列\n");
				system("pause");
				break;
			}
			IsEmptyAQueue(Q);
			break;
		case 8:
			if(Q->flag == 0){
				printf("请先初始化队列\n");
				system("pause");
				break;
			}
			GetHead(Q,datatype);
			break;
		case 9:
			if(Q->flag == 0){
				printf("请先初始化队列\n");
				system("pause");
				break;
			}
			Length(Q);
			break;
		case 10:
			if(Q->flag == 0){
				printf("请先初始化队列\n");
				system("pause");
				break;
			}
			TraverseAQueue(Q,&APrint);
			break;
		case 11:
			exit(1);
			break;
		default:
			printf("输入错误，请重新输入\n");
			system("pause");
			menu(Q);	
	}
}
Status Enter (AQueue *Q){
	void *data;
	if(!Scan(Q,&data)){
		printf("error\n");
		system("pause");
		return FALSE;
	}
	
	if(EnAQueue(Q,data)){
		printf("success\n");
		system("pause");
		return TRUE;
	}
	printf("error\n");
	getch();
	return FALSE;
}

Status Delete (AQueue *Q){
	if(DeAQueue(Q)){
		printf("succuss\n");
		getch();
		return TRUE;
	}
	printf("error\n");
	getch();
	return FALSE;
}

Status GetHead (AQueue*Q,char datatype[MAXQUEUE]){
	void *e;
	char t;
	GetHeadAQueue(Q,&e);
	t = datatype[Q->front];
	switch(t){
		case 'i':
			printf("队首数据为%d",*(int*)e);
			system("pause"); 
			break;
		case 'f':
			printf("队首数据为%f",*(float*)e);
			system("pause");
			break;
		case 'c':
			printf("队首数据为%c",*(char*)e);
			system("pause");
			break;
		default:
			printf("error\n");
			getch();
			return FALSE;		
	}
	return TRUE;
} 

Status Length(AQueue*Q){
	int l;
	l = LengthAQueue(Q);
	printf("队列长度为%d\n",l);
	getch();
}

