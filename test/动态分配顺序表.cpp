#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define InitSize 10 //Ĭ����󳤶�

typedef struct{
	int *data;
	int MaxSize;
	int length;
}SeqList;

//��ʼ��˳��� 
void InitList(SeqList &L){
	L.data = (int *)malloc(InitSize*sizeof(int));
	L.length = 0;
	L.MaxSize = InitSize;
	printf("Init True\n"); 
}

//���ӱ� 
void IncreaseSize(SeqList &L, int len){
	int *p = L.data;
	L.data = (int *)malloc((L.MaxSize+len)*sizeof(int));
	for(int i=0;i<L.length;i++){
		L.data[i] = p[i];
	}
	L.MaxSize = L.MaxSize+len;
	free(p);
	printf("Increase to %d True\n",L.MaxSize);
}

//������� 
bool ListInsert(SeqList &L,int i,int e){
	if(i<1 || i>L.length+1)			//�ж�iֵ�Ƿ���Ч 
		return false;
	if(L.length >= L.MaxSize)		//�жϴ洢�ռ��Ƿ����� 
		IncreaseSize(L,L.MaxSize);
		//return false;
	for(int j=L.length;j>=i;j--)	//ִ�в������ 
		L.data[j]=L.data[j-1];
	L.data[i-1] = e;
	L.length++;
	printf("Insert %d in %d True\n",e,i);
	return true;
}

//ɾ������,���ر�ɾ����ֵe 
bool ListDelete(SeqList &L, int i, int &e){
	if(i<1 || i>L.length+1)			//�ж�iֵ�Ƿ���Ч 
		return false;
	e=L.data[i-1];
	for(int j=i;j<L.length;j++){
		L.data[j-1]=L.data[j];
	}
	L.length--;
	printf("Delete %d in %d True\n",e,i);
	return true;
}

//��λ����
int GetElem(SeqList L, int i){
	printf("�ڣ�%d��λ�õ�ֵ�ǣ�%d\n",i,L.data[i-1]);
	return L.data[i-1]; 
} 

//��ֵ���� 
int LocateElem(SeqList L, int e){
	for(int i=0;i<L.length;i++){
		if(L.data[i] == e){
			printf("ֵ��%d�ĵ�һ��λ���ڣ�%d\n",e,i+1);
			return i+1;
		}
	}
	return 0;
}

//��� 
void ListToString(SeqList &L){
	for(int i=0;i<L.length;i++){
		printf("%d,",L.data[i]); 
	}
	printf("\n��Ϊ��%d����СΪ��%d",L.length,L.MaxSize);
}

//������� 
void RadInsert(SeqList &L, int e){
	srand((unsigned int)time(NULL));
	for(int i=0;i<e;i++){
		ListInsert(L,L.length+1,rand()%e+1);
	}
}

int main(){
	int e;
	SeqList L;
	InitList(L);
	
	RadInsert(L,100);
//	ListInsert(L,L.length+1,1);
//	ListInsert(L,L.length+1,2);
//	ListInsert(L,L.length+1,3);
//	ListInsert(L,L.length+1,4);
//	ListInsert(L,L.length+1,5);
	
	ListDelete(L,L.length,e);
	printf("��ɾ�����ǣ�%d\n",e);
	
	ListInsert(L,L.length+1,e);
	GetElem(L,L.length);
	LocateElem(L,e);
	
	IncreaseSize(L,5);
	
	ListToString(L); 
	return 0;
} 
