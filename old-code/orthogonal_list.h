#ifdef MaxVertexNum 
typedef struct ArcNode{
	int tailvex,headvex;
	struct AcrNode *hlink,*tlink;
	InfoType info;
}ArcNode;
typedef struct VNode{
	VertexType data;
	ArcNode *fistin,*fistout;
}VNode;
typedef struct{
	VNode xlist[MaxVertexNum];
	int vexnum,arcnum;
}OLGraph;
#endif
