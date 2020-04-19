#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef enum Status 
{
	ERROR = 0, SUCCESS = 1
}Status;

typedef int ElemType;

typedef struct SqStack 
{
	ElemType *elem;
	int top;
	int size;
} SqStack;

void main(){
	void QuickSort(int *a,int size); 
	int l;
	int a[20];
	for(l=1;l<20;l++){
		a[l] = rand()%101;
		printf("%d\t",a[l]);
	}
	printf("\n快排（非递归）\n");
		QuickSort(a,20);
	for(l=1;l<20;l++){
		printf("%d\t",a[l]);
	}
}

//快排（枢轴存放） 
int Partition(int *a, int begin, int end){
	int pivotkey;
	int mid;
	mid = (begin + end)/2;
	/*使a[begin]是 三个数中的中间数*/ 
	if(a[begin] > a[end]){
		a[0] = a[begin];
		a[begin] = a[end];
		a[end] = a[0];
	}
	if(a[mid] > a[end]){
		a[0] = a[mid];
		a[mid] = a[end];
		a[end] = a[0];
	}
	if(a[mid] > a[begin]){
		a[0] = a[begin];
		a[begin] = a[mid];
		a[mid] = a[0];
	}
	pivotkey = a[begin];
	a[0] = pivotkey;
	while(begin < end){
		while(begin < end && a[end] >= pivotkey){
			end--;
		}
		a[begin] = a[end];
		while(begin < end && a[begin] <= pivotkey){
			begin++;
		}
		a[end] = a[begin];
	}
	a[begin] = a[0];
	return begin;
}

//快排（非递归版） 
void QuickSort(int *a,int size){
	
	Status initStack(SqStack **s,int sizes);
	Status isEmptyStack(SqStack *s);
	Status getTopStack(SqStack *s,ElemType *e);
	Status pushStack(SqStack *s,ElemType data);
	Status popStack(SqStack *s,ElemType *data);
	int Partition(int *a, int begin, int end);
	
	SqStack *S;
	int begin,end;
	int pivot;
	initStack(&S,10);
	begin = 1;
	end = size-1;
	pushStack(S,begin);
	pushStack(S,end);
	while(!isEmptyStack(S)){
		popStack(S,&end);
		popStack(S,&begin);
		pivot = Partition(a,begin,end);
		if((pivot-1) > begin){
			pushStack(S,begin);
			pushStack(S,pivot-1);
		} 
		if((pivot+1) < end){
			pushStack(S,pivot+1);
			pushStack(S,end);
		}
	}
}  

Status initStack(SqStack **s,int sizes){
	*s=(SqStack*)malloc(sizeof(SqStack));
	if((*s)->elem=(ElemType*)malloc(sizes*sizeof(ElemType))){
		(*s)->size=sizes;
		(*s)->top=-1;
		return SUCCESS;
	}
}

//判断栈是否为空
Status isEmptyStack(SqStack *s){
	if(!s){
		printf("请先初始化\n");
		getch();
		return SUCCESS;
	}
	if(s->top==-1){
		return SUCCESS;
	}
	return ERROR;
}

//得到栈顶元素
Status getTopStack(SqStack *s,ElemType *e){
	if(isEmptyStack(s)){
		return ERROR;
	}
	*e=s->elem[s->top];
	return SUCCESS;
}

//入栈
Status pushStack(SqStack *s,ElemType data){
	if(s->top==s->size-1){
		printf("栈是满的\n");
		return ERROR;
	}
	s->top++;
	s->elem[s->top]=data;
	return SUCCESS;
}

//出栈
Status popStack(SqStack *s,ElemType *data){
	if(isEmptyStack(s)){
		return ERROR;
	}
	*data=s->elem[s->top];
	s->top--;
	return SUCCESS;
}
