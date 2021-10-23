#include<stdio.h>
#include<stdlib.h>

#define ElementType int

#define bool char
#define true 1
#define false 0

// ������ڵ� 
struct ListNode{
	ElementType data;
	struct ListNode* next; 
}; 
typedef struct ListNode ListNode,*PListNode;
// ��������Ϣ
struct SLListInfo{
	
}; 
//������ 
struct SingleList{
	PListNode head,rear;//ͷ�ڵ� 
	int length;//������ 
	struct SLListInfo *info;//����������Ϣ 
}; 
typedef struct SingleList SingleList,*PSingleList;
// ��ʼ������ 
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
// ������� 
void clearSLList(PSingleList list){
	PListNode temp,p = list->head->next;
	while(p!=NULL){
		temp = p;
		p=p->next;
		free(temp);
	}
	list->length=0;
}
//�������� 
void destroySLList(PSingleList list){
	clearSLList(list);
	free(list->info);
	free(list->head);
	free(list); 
}
// ����Ԫ��
void add2List(ElementType e,PSingleList list){
	PListNode node=(PListNode)malloc(sizeof(ListNode));
	node->data=e;
	node->next=NULL;
	list->rear->next=node; 
	list->rear =node;
	list->length++; 
} 
// ɾ��Ԫ�� 
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
