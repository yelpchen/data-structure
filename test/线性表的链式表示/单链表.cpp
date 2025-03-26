#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std; 

//快捷方式建立单链表（重命名） 
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;
//定义单链表结点类型 
/*
struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

typedef struct LNode LNode;
typedef struct LNode *LinkList;
*/

//初始化单链表（无头节点） 
bool InitList1(LinkList &L){
	L = NULL;
	return true;
}

//初始化单链表（有头节点） 
bool InitList(LinkList &L){
	L = (LNode *)malloc(sizeof(LNode));	//分配一个头节点
	if(L == NULL)
		return false;
	L->next = NULL;
	return true; 
}
//判断是否为空
bool Empty(LinkList L){
	if(L == NULL)
		return true;
	else
		return false; 
} 

//按位序插入方法（带头结点） 
bool ListInsert(LinkList &L, int i, int e){
	if(i<1)
		return false;
	LNode *p;//当前扫描结点
	int j = 0;
	p = L;
	//找到需要插入的结点 
	while(p!=NULL && j<i-1){
		p=p->next;
		j++; 
	} 
	//i值不正确 
	if(p==NULL)
		return false;
	//找到结点进行插入 
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	//相当于InsertNextNode(p,e); 
	printf("Insert %d at %d success!\n",e,i);
	return true; 
} 

//后插操作：在p结点后插入元素e
bool InsertNextNode(LNode *p,int e){
	if(p == NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL)//内存分配失败 
		return false;
	s->data = e;
	s->next = p->next;
	p->next = s;
	printf("Insert %d success!\n",e);
	return true; 
} 

//前插操作
bool InsertPriorNode(LNode *p,int e){
	if(p == NULL)
		return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if(s == NULL)//内存分配失败 
		return false;
	s->next = p->next;
	p->next = s;
	s->data = p->data;
	p->data = e;
	printf("Insert %d success!\n",e);
}

//删除操作
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

//查找方法 
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
	
	LinkList L;		//声明单链表指针 
	InitList(L);	//初始化空表
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
