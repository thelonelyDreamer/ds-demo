//-----ջ��˳��洢��ʾ-----
#ifdef ElemType

typedef struct{
	ElemType *base;//��ջ����֮ǰ������֮��base��ֵΪNULL
	ElemType *top;//ջ��ָ��
	int stacksize;//��ǰ�ѷ���Ĵ�ȡ�ռ䣬��Ԫ��Ϊ��λ
}SqStack;