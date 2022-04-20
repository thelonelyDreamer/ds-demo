```c++
#include<stdio.h>
#include<stdlib.h>
#define Element int

//定义每个节点的一些数据信息
typedef struct Information{
	char info[20];
}Info,*InfoPtr;

//定义二叉排序树的节点
typedef struct BSTNode{
	Element weight;
	InfoPtr infoPtr;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
}BSTNode,*BSTNodePtr;

// 对节点进行遍历
void* visitNode(BSTNodePtr nodePtr);
// 根据外部文件建立BST
BSTNodePtr initBSTWithFile(char* path);
// 建立一个只有三个节点的BST
BSTNodePtr BSTExample();
// 向BST树中插入一个节点
BSTNodePtr insertOneNode(Element weight,InfoPtr infoPtr,BSTNodePtr root);
// 中序遍历
int midOrderTraversal(BSTNodePtr root);
// 查找元素
BSTNodePtr findPosition(BSTNodePtr root,Element x);
// 返回一个待插入节点的父节点
BSTNodePtr findPositionBeforeInsert(BSTNodePtr root,Element x);

int main(void){
	
	midOrderTraversal(initBSTWithFile("input/test.txt"));
	printf("congratulations!");
	return 0;
}

// 对节点进行遍历
void* visitNode(BSTNodePtr nodePtr){
	if(NULL != nodePtr)
		printf("%d\n",nodePtr->weight);
	return NULL;
}

// 建立一个只有三个节点的BST
BSTNodePtr BSTExample(){
	BSTNodePtr temp = insertOneNode(2,NULL,NULL);
	temp = insertOneNode(1,NULL,temp);
	temp = insertOneNode(3,NULL,temp);
	return temp;
}

// 向BST树中插入一个节点
BSTNodePtr insertOneNode(Element weight,InfoPtr infoPtr,BSTNodePtr root){
	BSTNodePtr temp;
	temp = (BSTNodePtr)malloc(sizeof(BSTNode));
	temp->lchild=temp->rchild=NULL;
	temp->weight=weight;
	temp->infoPtr=infoPtr;
	if(NULL==root){
		return temp;
	}else{
		BSTNodePtr parent=findPositionBeforeInsert(root,weight);
		if(parent->weight>=weight)
			parent->lchild=temp;
		else
			parent->rchild=temp;
		return root;	
	}
}

// 中序遍历
int midOrderTraversal(BSTNodePtr root){
	
	if(NULL==root) return 1;
	if(NULL!=root->lchild) 
		midOrderTraversal(root->lchild);
	visitNode(root);
	if(NULL!=root->rchild)
		midOrderTraversal(root->rchild);
	
	return 1;
}

// 查找元素
BSTNodePtr findPosition(BSTNodePtr root,Element x){
	if(!root||x==root->weight) return root;
	else if(x<=root->weight) return findPosition(root->lchild,x);
	else return findPosition(root->lchild,x);
}

// 返回一个待插入节点的父节点
BSTNodePtr findPositionBeforeInsert(BSTNodePtr root,Element x){
	if(NULL == root) return NULL;
	BSTNodePtr temp = root;
	BSTNodePtr result=NULL;//返回值
	while(temp!=NULL){
		result = temp;
		if(x<=result->weight)
			temp=result->lchild;
		else
			temp=result->rchild;
	}	
	return result;
}

BSTNodePtr initBSTWithFile(char* path){
	FILE* fp = fopen(path,"r");
	if(NULL==fp){
		printf("Can't not open the file");
		return NULL;
	}
	int temp;
	BSTNodePtr root=NULL;
	while(EOF!=fscanf(fp,"%d",&temp)){
		root = insertOneNode(temp,NULL,root);
	}
	return root;
}
```

