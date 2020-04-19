#include"sort.h"
/*void main (){
	void menu ();
	while(1){
		menu();
	}
}*/

void menu (){
	void messDatas();
	void littleArray ();
	int i;
	system("cls");
	printf("**************************\n");
	printf("1.������������\n");
	printf("2.����С�������\n"); 
	printf("3.�˳�\n");
	printf("**************************\n");
	if(!scanf("%d",&i)){
		//fllush(stdin);
		printf("�������\n");
		system("pause");
	}
	
	switch(i){
		case 1:
			messDatas();
			break;
		case 2:
			littleArray();
			break;
		case 3:
			exit(1);
		default:
			printf("�������\n");
			system("pause");
			menu();
	}
}

void messDatas(){
	int i;
	long l;
	int max = 0;
	int a[100000];
	long s,e;
	
	system("cls");
	printf("**************************\n");
	printf("1. 10000������Բ�������\n");
	printf("2. 50000������Բ�������\n");
	printf("3. 100000������Բ�������\n");
	printf("4. 10000������Թ鲢����\n");
	printf("5. 50000������Թ鲢����\n");
	printf("6. 100000������Թ鲢����(��Ҫѡ�������������)\n");
	printf("7. 10000������Կ��ţ��ݹ�棩\n");
	printf("8. 50000������Կ��ţ��ݹ�棩\n");
	printf("9. 100000������Կ��ţ��ݹ�棩\n");
	printf("10. 10000������Լ�������\n");
	printf("11. 50000������Լ�������\n");
	printf("12. 100000������Լ�������\n");
	printf("13. 10000������Ի�����������\n");
	printf("14. 50000������Ի�����������\n");
	printf("15. 100000������Ի�����������\n");
	printf("**************************\n");
	if(!scanf("%d",&i)){
		printf("�������\n");
		system("pause");
	}
	//fllush(stdin);
	switch(i){
		case 1:
			for(l=1;l<10000;l++){
				a[l] = rand()%101;
			}
			s = clock();
			insertSort(a,10000);
			e = clock();
			break;
		case 2:
			for(l=1;l<50000;l++){
				a[l] = rand()%101;
			}
			s = clock();
			insertSort(a,50000);
			e = clock();
			break;
		case 3:
			for(l=1;l<100000;l++){
				a[l] = rand()%101;
			}
			s = clock();
			insertSort(a,100000);
			e = clock();
			break;
		case 4:
			for(l=1;l<10000;l++){
				a[l] = rand()%101;
			}
			s = clock();
			MergeSort(a,1,10000,a);
			e = clock();
			break;
		case 5:
			for(l=1;l<50000;l++){
				a[l] = rand()%101;
			}
			s = clock();
			MergeSort(a,1,50000,a);
			e = clock();
			break;
		case 6:
			for(l=1;l<100000;l++){
				a[l] = rand()%101;
			}
			s = clock();
			MergeSort(a,1,100000,a);
			e = clock();
			break;
		case 7:
			for(l=1;l<10000;l++){
				a[l] = rand()%101;
			}
			s = clock();
			QuickSort_Recursion(a,1,10000);
			e = clock();
			break;
		case 8:
			for(l=1;l<50000;l++){
				a[l] = rand()%101;
			}
			s = clock();
			QuickSort_Recursion(a,1,50000);
			e = clock();
			break;
		case 9:
			for(l=1;l<100000;l++){
				a[l] = rand()%101;
			}
			s = clock();
			QuickSort_Recursion(a,1,100000);
			e = clock();
			break;
		case 10:
			for(l=1;l<10000;l++){
				a[l] = rand()%101;
				if(max < a[l]){
					max =a[l];
				}
			}
			s = clock();
			CountSort(a,10000,max);
			e = clock();
			break;
		case 11:
			for(l=1;l<50000;l++){
				a[l] = rand()%101;
				if(max < a[l]){
					max =a[l];
				}
			}
			s = clock();
			CountSort(a,50000,max);
			e = clock();
			break;
		case 12:
			for(l=1;l<100000;l++){
				a[l] = rand()%101;
				if(max < a[l]){
					max =a[l];
				}
			}
			s = clock();
			CountSort(a,100000,max);
			e = clock();
			break;
		case 13:
			for(l=1;l<10000;l++){
				a[l] = rand()%101;
			}
			s = clock();
			RadixCountSort(a,10000);
			e = clock();
			break;
		case 14:
			for(l=1;l<50000;l++){
				a[l] = rand()%101;
			}
			s = clock();
			RadixCountSort(a,50000);
			e = clock();
			break;
		case 15:
			for(l=1;l<100000;l++){
				a[l] = rand()%101;
			}
			s = clock();
			RadixCountSort(a,100000);
			e = clock();
			break;
		default:
			printf("�������\n");
			system("pause");
			menu();
	}
	printf("\n����ʱ��%ld ms\n",e-s);
	system("pause");	
}
