//    ����ϵͳ win 8.1
//    ���뻷�� Visual Stuido 2017

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int ElementType;        //    ������������,�ɸ�����Ҫ�����������Ͷ���
                                //    ����ڵ�Ķ���
typedef struct ListNode {
    ElementType  Element;        //    �����򣬴������
    ListNode* Next;        //    ָ����һ������ڵ�
}Node, *PNode;

//    ��������������
PNode CreateList(void) {
    int len ;    //    ���ڶ���������
    int val ;    //    ���ڴ�Žڵ���ֵ
    PNode PHead = (PNode)malloc(sizeof(Node));    //    ��������һ��ͷ�ڵ��ڴ�ռ�
//ͷ�ڵ��൱��������ڱ�����������ݣ�ָ���׽ڵ㣨��һ���ڵ㣩
    if (PHead == NULL)    //    �ж��Ƿ����ɹ�
    {
        printf("�ռ����ʧ�� \n");
        exit(-1);
    }

    PNode PTail = PHead;    //    �����ĩβ�ڵ㣬��ʼָ��ͷ�ڵ�
    PTail->Next = NULL;    //    ���һ���ڵ�ָ����Ϊ��
    len=3;       //    ����ڵ����
    for (int i = 0; i < len; i++) {

        PNode pNew = (PNode)malloc(sizeof(Node));    //    ����һ���½ڵ�
        if (pNew == NULL) {
            printf("�����½ڵ�ʧ��\n");
            exit(-1);
        }
        printf("������� %d ���ڵ�����ݣ�", i + 1);
        scanf("%d", &val);    //    ��������ڵ������

        pNew->Element = val;    //    �����ݸ�ֵ���ڵ�������
        PTail->Next = pNew;    //    ĩβ�ڵ�ָ��ָ����һ���½ڵ�
        pNew->Next = NULL;        //    �½ڵ�ָ��ָ��Ϊ��
        PTail = pNew;    //    ���½ڵ㸴�Ƹ�ĩβ�ڵ�        
    }   
    printf("��������ɹ�\n");
    return PHead;    //    ����ͷ�ڵ�
}

void InsertList(PNode List, int pos, int val) {
    int position = 0;
    PNode P = List;    //    ����ڵ�pָ��ͷ�ڵ�
                    //    Ѱ��pos�ڵ��ǰ�����
    while (P != NULL&&position<pos - 1)
    {
        P = P->Next;
        ++position;
    }
    PNode Tmp = (PNode)malloc(sizeof(Node));    //    ����һ����ʱ�ڵ������洢Ҫ���������
    if (Tmp == NULL)
    {
        printf("�ڴ����ʧ�ܣ�");
        exit(-1);
    }
    //    ����ڵ�
    Tmp->Element = val;
    Tmp->Next = P->Next;
    P->Next = Tmp;
}


int IsChongfu(PNode List,int val){
	PNode P = List -> Next;
	if (P == NULL){
        printf("����Ϊ��");
        }
        while(P!=NULL){
        	if(P->Element==val){	
        	printf("\n���ظ���\n\n");
			return 0;
			break;
			}
		P=P->Next;
		}
		return 1; 
}
void TraverseList(PNode List) {
    PNode P = List->Next;    //    �׽ڵ㸳ֵ����ʱ�ڵ�P
    printf("���������ֵΪ��");
    if (P == NULL)
        printf("����Ϊ��");
    while (P != NULL)        //����ʱ�ڵ�P��Ϊβ�ڵ�ʱ�������ǰ�ڵ�ֵ 
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}

int getCode(PNode List ,int val){
	int j;
	PNode P = List->Next; 
	j=0;
	while(P!=NULL){
		P=P->Next;
		++j;
		if(val==P->Element){
		break;
		}
	}	
		return j;

}

//    ������ 
int main() {
	int val=2;
    PNode userid = CreateList(); 
    if(IsChongfu(userid,val)){
	InsertList(userid, 1 , val);
	}
	PNode password = CreateList(); 
	TraverseList(userid) ;
	TraverseList(password)  ;
	int k=getCode(userid , val);
	printf("%d",&k);
    return 0;
}
