#include<stdio.h>
#include<stdlib.h>

#define ElementType int

#define bool char
#define true 1
#define false 0

// 单链表节点 
struct ListNode{
	ElementType data;
	struct ListNode* next; 
}; 
typedef struct ListNode ListNode,*PListNode;
// 单链表信息
struct SLListInfo{
	
}; 
//单链表 
struct SingleList{
	PListNode head,rear;//头节点 
	int length;//链表长度 
	struct SLListInfo *info;//链表其他信息 
}; 
typedef struct SingleList SingleList,*PSingleList;
// 初始化链表 
PSingleList initSLList(){
	PSingleList temp = (PSingleList)malloc(sizeof(SingleList));
	temp->length=0;
	PListNode head = (PListNode)malloc(sizeof(SingleList));
	head->next=NULL;
	temp->rear=head;
	temp->head=head;
	temp->info=(struct SLListInfo*)malloc(sizeof(struct SLListInfo));
	return temp;
}
// 清空链表 
void clearSLList(PSingleList list){
	PListNode temp,p = list->head->next;
	while(p!=NULL){
		temp = p;
		p=p->next;
		free(temp);
	}
	list->length=0;
}
//销毁链表 
void destroySLList(PSingleList list){
	clearSLList(list);
	free(list->info);
	free(list->head);
	free(list); 
}
// 插入元素
void add2List(ElementType e,PSingleList list){
	PListNode node=(PListNode)malloc(sizeof(ListNode));
	node->data=e;
	node->next=NULL;
	list->rear->next=node; 
	list->rear =node;
	list->length++; 
} 
// 删除元素 
bool deleteFromList(ElementType e,PSingleList list){
	if(list->length<=0) return false;
	PListNode pre,p;
	pre=list->head;
	p=pre->next;
	while(p->data!=e&&p!=NULL){
		pre=p;
		p=p->next;
	}
	if(p==NULL) return false;
	if(p==list->rear){
		list->rear=pre;
		pre->next=NULL;
		free(p);
	}else{
		pre->next=p->next;
		free(p);
	}
	return true;
}
 
int main(int argc,char** argv){
	
	return 0;
}
