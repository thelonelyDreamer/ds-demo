#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MaxVertexNum 100//��󶥵����

typedef char VertexType;//������������
typedef int EdgeType;//��Ȩͼ�б���Ȩֵ����������
//typedef int InfoType;

//�ڽӾ���
typedef struct{
	VertexType Vex[MaxVertexNum];//����ֵ
	EdgeType Edge[MaxVertexNum][MaxVertexNum];//�ڽӾ��󣬱߱�
	int vexnum,arcnum;//ͼ�ĵ�ǰ�������ͻ���
} MGraph;//adjacency matrix graph

//�ڽӱ�
typedef struct AcrNode{//�߽ڵ�
	int  adjvex;
	struct AcrNode *next;
	//InfoType *info;
}AcrNode;
typedef struct VNode{//
	VertexType data;
	AcrNode *first;
}Vnode,AdjList[MaxVertexNum];
typedef struct{
	AdjList vertices;
	int vexnum,arcnum;//ͼ�ĵ�ǰ�������ͻ���
	//int kind;//ͼ������
}ALGraph;//Adjacency List Graph

//���е���ʽ�洢�ṹ
typedef struct LinkNode{
	VertexType data;
	struct LinkNode *next;
}LinkNode;
typedef struct{
	LinkNode *front,*rear;
}LinkQueue;

void init_random(MGraph &G);//�����ʼ������ͼ
void transform(MGraph G1,ALGraph &G2);//���ڽӾ���ת�����ڽӱ�
void BFSTraverse(ALGraph G);//�ӵ�һ��Ԫ�ؿ�ʼ��ͼ���й�����ȱ���
void visit(VertexType v);//�Զ���V���з���
void InitQueue(LinkQueue &Q);//�Դ�ͷ������ʽ���н��г�ʼ��
bool IsEmpty(LinkQueue Q);//����ʽ���н����п�
void EnQueue(LinkQueue &Q,VertexType v);//���
bool DeQueue(LinkQueue &Q,VertexType &x);//����
int FistAdjVex(ALGraph G,VertexType u);//�����һ���ڽӵ��λ��
int NextAdjVex(ALGraph G,VertexType u,int w);//��������Ϊw����һ������λ��


//������
int number=0;
int main(void){

	MGraph G1;
	ALGraph G2;
	init_random(G1);
	transform(G1,G2);
	BFSTraverse(G2);
	printf("\n%d",number);
	getchar();
	return 0;
}

void init_random(MGraph &G){
	int i,j,count=0;
	srand((unsigned int)time(NULL));
	G.vexnum=rand ()%100+1;
	for(i=0;i<G.vexnum;i++)
		G.Vex[i]=i;
	for(i=0;i<G.vexnum;i++)
		for(j=0;j<G.vexnum;j++){
			G.Edge[i][j]=rand()%2;
		if(G.Edge[i][j]==1)
			count++;
		}
	G.arcnum=count;
	return;
}

void transform(MGraph G1,ALGraph &G2){
	G2.vexnum=G1.vexnum;
	G2.arcnum=G1.arcnum;
	AcrNode *p,*rear;
	rear=(AcrNode*)malloc(sizeof(AcrNode));
	for(int i=0;i<G2.vexnum;i++){
		G2.vertices[i].data=G1.Vex[i];
		G2.vertices[i].first=NULL;
		for(int j=0;j<G2.vexnum;j++){
			if(G1.Edge[i][j]==1){
				p=(AcrNode*)malloc(sizeof(AcrNode));
				p->adjvex=j;
				p->next=NULL;
				if(G2.vertices[i].first==NULL){
					G2.vertices[i].first=p;
					rear=p;
				}
				else{
					rear->next=p;
					rear=p;
				}
			}
		}
	}
}

void visit(VertexType v){
	printf("%d ",v);
	number++;
	return;
}

void InitQueue(LinkQueue &Q){
	Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
	Q.front->next=NULL;
}

bool IsEmpty(LinkQueue Q){
	if(Q.front==Q.rear)return true;
	else return false;
}

void EnQueue(LinkQueue &Q,VertexType v){
	LinkNode *s;
	s=(LinkNode*)malloc(sizeof(LinkNode));
	s->data=v;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
	return;
}

bool DeQueue(LinkQueue &Q,VertexType &x){
	if(Q.front==Q.rear) return false;
	LinkNode *p;
	p=Q.front->next;
	x=p->data;
	Q.front->next=p->next;
	if(Q.rear==p)
		Q.rear=Q.front;
	free(p);
	return true;
}
	
void BFSTraverse(ALGraph G){
	bool visited[MaxVertexNum];
	for(int i=0;i<G.vexnum;i++)
		visited[i]=false;
	LinkQueue Q;
	InitQueue(Q);
	for(int i=0;i<G.vexnum;i++)
		if(!visited[i]){
			visited[i]=true;
			visit(G.vertices[i].data);
			EnQueue(Q,G.vertices[i].data);
			while(!IsEmpty(Q)){
				VertexType u;
				DeQueue(Q,u);
				for(int w=FistAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
					if(!visited[w]){
						visited[w]=true;
						visit(G.vertices[w].data);
						EnQueue(Q,G.vertices[w].data);
					}
			}
		}
}

int FistAdjVex(ALGraph G,VertexType u){
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vertices[i].data==u)
			break;
	if(G.vertices[i].first==NULL)
		return -1;
	else
		return G.vertices[i].first->adjvex;
}
			
int NextAdjVex(ALGraph G,VertexType u,int w){
	int i;
	for(i=0;i<G.vexnum;i++)
		if(G.vertices[i].data==u)
			break;

	AcrNode *p;
	p=(AcrNode*)malloc(sizeof(AcrNode));
	p=G.vertices[i].first;
	while(p->adjvex!=w&&p->next!=NULL)
			p=p->next;
	if(p->next==NULL)return  -1;
	else 
		return p->next->adjvex;
}