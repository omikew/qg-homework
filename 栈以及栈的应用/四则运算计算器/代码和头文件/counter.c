#include"LinkStack.h"
#include<string.h>

void main(){
	Status Change(LinkStack*S,char a[20]);
	Status Count (LinkStack*S,char a[20]);
	
	char b[20];
	int i;
	LinkStack*S=NULL;
	
	
	while(1){
		system("cls");
		printf("输入exit退出\n");
		initLStack(&S);
		printf("请输入运算式\n");
		if(!Change(S,b)){
			printf("输入错误\n");
			getch();
			S=NULL;
			continue;
		}
	    Count(S,b);
	    S=NULL;
	}
	
	/*while(1){
		initLStack(&S);
		Change(S,b);
	    printf("%s",b);
	    S=NULL;
	}*/
}

Status Change(LinkStack*S,char a[20]){
	char s[20];
	char r;
	int i,j;
	int flag=1;	//0:前面是数字，1：前面是运算符 
	scanf("%s",s);
	if(!strcmp(s,"exit")){
		exit(1);
	}
	for(i=0,j=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			if(flag==0){
				a[j-1]=(a[j-1]-'0')*10+s[i];
			}else{
				a[j++]=s[i];
			}
			flag=0;
		}
		else if(s[i]=='('){
			pushLStack(S,s[i]);
			flag=1;
		}
		else if(s[i]==')'){
			if(S->top==NULL){
				return ERROR;
			}
			while(S->top->data!='('){
				if(!popLStack(S,&a[j++])){
					return ERROR;
				}
			}
			popLStack(S,&r);
			flag=1;
		}
		else if(s[i]=='*'||s[i]=='/'){
			while(1){
				if(S->top==NULL||S->top->data=='+'||S->top->data=='-'||S->top->data=='('){
					pushLStack(S,s[i]);
					break;
				}else{
					popLStack(S,&a[j++]);
				} 	
			}
			flag=1;
		}
		else if(s[i]=='+'||s[i]=='-'){
			while(1){
				if(S->top==NULL||S->top->data=='('){
					pushLStack(S,s[i]);
					break;
				}else{
					popLStack(S,&a[j++]);
				}
			}
			flag=1;
		}
		else{
			return ERROR;
		}
	}
	while(S->top){
		popLStack(S,&a[j++]);
	}
	return SUCCESS;
}

Status Count (LinkStack*S,char a[20]){
	int i;
	char m,n;
	if(!S){
		return ERROR;
	}
	for(i=0;a[i];i++){
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'){
			popLStack(S,&m);
			popLStack(S,&n);
			if(a[i]=='+'){
				pushLStack(S,n+m-'0');
			}
			if(a[i]=='-'){
				pushLStack(S,n-m+'0');
			}
			if(a[i]=='*'){
				pushLStack(S,(n-'0')*(m-'0')+'0');
			}
			if(a[i]=='/'){
				pushLStack(S,(n-'0')/(m-'0')+'0');
			}
		}else{
			pushLStack(S,a[i]);
		}
	}
	popLStack(S,&m);
	printf("计算结果：%d\n",(m-'0'));
	getch();
}
