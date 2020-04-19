#include"sort.h" 

void main(){
	void test();
	while(1){
		test();
	}
}

void test (){
	int i,l,max;
	long k; 
	long s,e;
	int a[100];
	system("cls");
	printf("**************************\n");
	printf("1.测试插入排序\n");
	printf("2.测试归并排序\n"); 
	printf("3.测试快排（递归版）\n");
	printf("4.测试计数排序\n"); 
	printf("5.测试基数计数排序\n"); 
	printf("6.退出\n"); 
	printf("**************************\n");
	if(!scanf("%d",&i)){
		//fllush(stdin);
		printf("输入出错\n");
		system("pause");
	}
	switch(i){
		case 1:
			
			for(l=1;l<10;l++){
				a[l] = rand()%101;
				printf("%d\t",a[l]);
			}
			s = clock();
			insertSort(a,10);
			e = clock();
			break;
		case 2:
			
			for(l=1;l<10;l++){
				a[l] = rand()%101;
				printf("%d\t",a[l]);
			}
			s = clock();
			MergeSort(a,1,10,a);
			e = clock();
			break;
		case 3:
			
			for(l=1;l<10;l++){
				a[l] = rand()%101;
				printf("%d\t",a[l]);
			}
			s = clock();
			QuickSort_Recursion(a,1,10);
			e = clock();
			break;
		case 4:
				for(l=1;l<10;l++){
				a[l] = rand()%101;
				printf("%d\t",a[l]);
					if(max < a[l]){
					max = a[l];
					}
				}
			s = clock();
			CountSort(a,10,max);
			e = clock();
			break;
		case 5:
			for(l=1;l<10;l++){
				a[l] = rand()%101;
				printf("%d\t",a[l]);
			}
			
			s = clock();
			RadixCountSort(a,10);
			e = clock();
			break;
		case 6:
			exit(1);
		default:
			printf("输入出错\n");
			system("pause");
			test();
	}
	printf("\n");
	for(l=1; l<10; l++){
		printf("%d\t",a[l]);
	}
	printf("\n花费时间%ld ms\n",e-s);
	system("pause");
}

void littleArray (){
	int i,l,max;
	long k; 
	long s,e;
	int a[100];
	system("cls");
	printf("**************************\n");
	printf("1.测试插入排序\n");
	printf("2.测试归并排序\n"); 
	printf("3.测试快排（递归版）\n");
	printf("4.测试计数排序\n"); 
	printf("5.测试基数计数排序\n"); 
	printf("6.退出\n"); 
	printf("**************************\n");
	if(!scanf("%d",&i)){
		//fllush(stdin);
		printf("输入出错\n");
		system("pause");
	}
	switch(i){
		case 1:
			s = clock();
			for(k = 0;k < 100000;k++){
				for(l=1;l<100;l++){
				a[l] = rand()%101;
				}
				insertSort(a,100);
			} 
			e = clock();
			break;
		case 2:
			s = clock();
			for(k = 0;k < 100000;k++){
				for(l=1;l<100;l++){
				a[l] = rand()%101;
				}
				MergeSort(a,1,100,a);
			} 
			e = clock();
			break;
		case 3:
			s = clock();
			for(k = 0;k < 100000;k++){
				for(l=1;l<100;l++){
				a[l] = rand()%101;
				}
				QuickSort_Recursion(a,1,100);
			} 
			e = clock();
			break;
		case 4:
			s = clock();
			for(k = 0;k < 100000;k++){
				for(l=1;l<100;l++){
				a[l] = rand()%101;
				if(max < a[l]){
					max =a[l];
				}
				}
				CountSort(a,100,max);
			} 
			e = clock();
			break;
		case 5:
			s = clock();
			for(k = 0;k < 100000;k++){
				for(l=1;l<100;l++){
				a[l] = rand()%101;
				}
				RadixCountSort(a,100);
			} 
			e = clock();
			break;
		case 6:
			exit(1);
		default:
			printf("输入出错\n");
			system("pause");
			littleArray();
	}
	printf("\n花费时间%ld ms\n",e-s);
	system("pause");
}


