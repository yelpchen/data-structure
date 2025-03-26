#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std; 

//��ݷ�ʽ������������������ 
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//���嵥���������� 
/*
struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

typedef struct LNode LNode;
typedef struct LNode *LinkList;
*/

//��ʼ����������ͷ�ڵ㣩 
bool InitList1(LinkList &L){
	L = NULL;
	return true;
}

//��ʼ����������ͷ�ڵ㣩 
bool InitList(LinkList &L){
	L = (LNode *)malloc(sizeof(LNode));	//����һ��ͷ�ڵ�
	if(L == NULL)
		return false;
	L->next = NULL;
	return true; 
}
//�ж��Ƿ�Ϊ��
bool Empty(LinkList L){
	if(L == NULL)
		return true;
	else
		return false; 
} 

//��λ����뷽������ͷ��㣩 
bool ListInsert(LinkList &L, int i, int e){
	if(i<1)
		return false;
	LNode *p;//��ǰɨ����
	int j = 0;
	p = L;
	//�ҵ���Ҫ����Ľ�� 
	while(p!=NULL && j<i-1){
		p=p->next;
		j++; 
	} 
	//iֵ����ȷ 
	if(p==NULL)
		return false;
	//�ҵ������в��� 
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	//�൱��InsertNextNode(p,e); 
	printf("Insert %d at %d success!\n",e,i);
	return true; 
} 

//����������p�������Ԫ��e
bool InsertNextNode(LNode *p,int e){
	if(p == NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL)//�ڴ����ʧ�� 
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	printf("Insert %d success!\n",e);
	return true; 
} 

//ǰ�����
bool InsertPriorNode(LNode *p,int e){
	if(p == NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL)//�ڴ����ʧ�� 
		return false;
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	printf("Insert %d success!\n",e);
}

//ɾ������
bool ListDelete(LinkList &L,int i,int &e){
	if(i<1)
		return false;
	LNode *p;
	int j = 0;
	p = L;
	while(p!=NULL &&j<i-1){
		p=p->next;
		j++;
	} 
	if(p==NULL)
		return false;
	LNode *q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
} 

//���ҷ��� 
LNode *GetElem(LinkList L, int i){
	int j = 1;
	LNode *p = L->next;
	if(i == 0)
		return L;
	if(i < 1)
		return 	NULL;
	while(p!=NULL && j<i){
		p = p->next;
		j++;
	}
	return p;
}

//ToString
void ToString(LinkList L) {
	LNode *p = L->next;
	while(p!=NULL){
		p = p->next;
		printf("%d,",p->data);
	}
	printf("\n");
}

int main(){
	
//	LNode *p = (LNode *)malloc(sizeof(LNode)); 
//	cout << "is NULL:" << Empty(p) << endl;
// 	free(p);
	
	LinkList L;		//����������ָ�� 
	InitList(L);	//��ʼ���ձ�
	ListInsert(L,1,1);
	InsertNextNode(L,2);
	InsertNextNode(L,3);
	InsertPriorNode(L,4);
	ToString(L);
	printf("%d\n",L->data); 
	
	
	printf("SizeOf(LinkList):%d\n",sizeof(L));
	cout << "is NULL:" << Empty(L) ;
	
	return 0;
} 
