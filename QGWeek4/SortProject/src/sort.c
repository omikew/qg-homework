#include"sort.h"

//ֱ�Ӳ������� 
void insertSort(int *a,int n){
	int i,j;
	for(i = 2;i <= n;i++){
		if(a[i] < a[i-1]){
			a[0] = a[i];
			for(j = i-1;a[j] > a[0];j--){
				a[j+1] = a[j];
			}
			a[j+1] = a[0];
		}
	}
}

//�鲢���򣨺ϲ����飩 
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int j,k,l;
	for(j = mid+1,k = begin; begin <= mid && j <= end; k++){
		if(temp[begin] < temp[j]){
			a[k] = temp[begin++];
		}else{
			a[k] = temp[j++];
		}
	}
	if(begin <= mid){
		for(l = 0; l <= mid-begin; l++){
			a[k+l] = temp[begin+l];
		}
	}
	if(j <= end){
		for(l = 0; l <= end-j; l++){
			a[k+l] = temp[j+l];
		}
	}	
} 

//�鲢����
void MergeSort(int *a,int begin,int end,int *temp){
	int mid;
	int *t; 
	t = (int*)malloc((end+1)*sizeof(int));
	if(begin == end){
		a[begin] = temp[begin];
	}else{
		mid = (begin+end)/2;
		MergeSort(t,begin,mid,temp);
		MergeSort(t,mid+1,end,temp);
		MergeArray(a,begin,mid,end,t);
	}
}  

//���ţ��ݹ�棩
void QuickSort_Recursion(int *a, int begin, int end){
	int pivot;
	if((end-begin) >= 20){
		pivot = Partition(a,begin,end);
		QuickSort_Recursion(a,begin,pivot-1);
		QuickSort_Recursion(a,pivot+1,end);
	}else{
		insertSort(a,end);
	}
}

//���ţ������ţ� 
int Partition(int *a, int begin, int end){
	int pivotkey;
	int mid;
	mid = (begin + end)/2;
	/*ʹa[begin]�� �������е��м���*/ 
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

//���ţ��ǵݹ�棩 
void QuickSort(int *a,int size){
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

//��������
void CountSort(int *a, int size , int max){
	//�ռ�
	int *b;
	int *c;
	int i,j;
	b = (int*)malloc((max+1)*sizeof(int));
	c = (int*)malloc((size)*sizeof(int));
	for(i = 1; i < size; i++){
		c[i] = a[i];
	}
	for(i = 0; i <= max; i++){
		b[i] = 0;
	}
	for(i = 1; i < size; i++){
		b[a[i]]++;
	}
	//ͳ��
	for(i = 1; i <= max; i++){
		b[i] += b[i-1];
	} 
	//����
	i = size-1;
	while(i > 0){
		a[--b[c[i]]+1] = c[i];
		i--;
	} 
	free(b);
	free(c);
} 

//��������
void RadixCountSort(int *a,int size){
	int bucket[10];
	int *temp;
	int bits;
	int i;
	temp = (int*)malloc((size)*sizeof(int));
	for(bits=1; bits<=10; bits*=10){
		for(i = 1; i < size; i++){
			temp[i] = a[i];
		}
		for(i=0; i<10; i++){
			bucket[i] = 0;
		}
		//�ռ�
		for(i=1; i<size; i++){
			bucket[a[i]/bits%10]++;
		} 
		//ͳ��
		for(i=1; i<10; i++){
			bucket[i] += bucket[i-1];
		} 
		//����
		i = size-1;
		while(i>0){
			a[--bucket[temp[i]/bits%10]+1] = temp[i];
			i--;
		}
	}
	
}

//��ɫ����
void ColorSort(int *a,int size){
	int i;
	int *p1,*p2,*p;
	p1 = &a[1];
	p2 = &a[size-1];
	for(p = p1+1; p != p2; p++){
		while(*p != 1){
			if(*p == 0){
				a[0] = *p;
				*p = *p1;
				*p1 = a[0];
				p1++;
			}else{
				a[0] = *p;
				*p = *p2;
				*p2 = a[0];
				p2--;
			}
		}
		if(p == p2)
			break;
	}
} 
//�ҵ���K����
void FindK(int *a,int begin,int end,int K){
	int pivot;
	pivot = Partition(a,begin,end);
	if(pivot == K){
		printf("��%d����Ϊ%d\n",K,a[pivot]);
	}
	else if(K < pivot){
		FindK(a,begin,pivot-1,K);
	}
	else if(K > pivot){
		FindK(a,pivot+1,end,K);
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

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyStack(SqStack *s){
	if(!s){
		printf("���ȳ�ʼ��\n");
		getch();
		return SUCCESS;
	}
	if(s->top==-1){
		return SUCCESS;
	}
	return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopStack(SqStack *s,ElemType *e){
	if(isEmptyStack(s)){
		return ERROR;
	}
	*e=s->elem[s->top];
	return SUCCESS;
}

//��ջ
Status pushStack(SqStack *s,ElemType data){
	if(s->top==s->size-1){
		printf("ջ������\n");
		return ERROR;
	}
	s->top++;
	s->elem[s->top]=data;
	return SUCCESS;
}

//��ջ
Status popStack(SqStack *s,ElemType *data){
	if(isEmptyStack(s)){
		return ERROR;
	}
	*data=s->elem[s->top];
	s->top--;
	return SUCCESS;
}
