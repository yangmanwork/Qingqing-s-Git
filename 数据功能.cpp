//    操作系统 win 8.1
//    编译环境 Visual Stuido 2017

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int ElementType;        //    定义数据类型,可根据需要进行其他类型定义
                                //    链表节点的定义
typedef struct ListNode {
    ElementType  Element;        //    数据域，存放数据
    ListNode* Next;        //    指向下一个链表节点
}Node, *PNode;

//    链表创建函数定义
PNode CreateList(void) {
    int len ;    //    用于定义链表长度
    int val ;    //    用于存放节点数值
    PNode PHead = (PNode)malloc(sizeof(Node));    //    创建分配一个头节点内存空间
//头节点相当于链表的哨兵，不存放数据，指向首节点（第一个节点）
    if (PHead == NULL)    //    判断是否分配成功
    {
        printf("空间分配失败 \n");
        exit(-1);
    }

    PNode PTail = PHead;    //    链表的末尾节点，初始指向头节点
    PTail->Next = NULL;    //    最后一个节点指针置为空
    len=3;       //    输入节点个数
    for (int i = 0; i < len; i++) {

        PNode pNew = (PNode)malloc(sizeof(Node));    //    分配一个新节点
        if (pNew == NULL) {
            printf("分配新节点失败\n");
            exit(-1);
        }
        printf("请输入第 %d 个节点的数据：", i + 1);
        scanf("%d", &val);    //    输入链表节点的数据

        pNew->Element = val;    //    把数据赋值给节点数据域
        PTail->Next = pNew;    //    末尾节点指针指向下一个新节点
        pNew->Next = NULL;        //    新节点指针指向为空
        PTail = pNew;    //    将新节点复制给末尾节点        
    }   
    printf("创建链表成功\n");
    return PHead;    //    返回头节点
}

void InsertList(PNode List, int pos, int val) {
    int position = 0;
    PNode P = List;    //    定义节点p指向头节点
                    //    寻找pos节点的前驱结点
    while (P != NULL&&position<pos - 1)
    {
        P = P->Next;
        ++position;
    }
    PNode Tmp = (PNode)malloc(sizeof(Node));    //    分配一个临时节点用来存储要插入的数据
    if (Tmp == NULL)
    {
        printf("内存分配失败！");
        exit(-1);
    }
    //    插入节点
    Tmp->Element = val;
    Tmp->Next = P->Next;
    P->Next = Tmp;
}


int IsChongfu(PNode List,int val){
	PNode P = List -> Next;
	if (P == NULL){
        printf("链表为空");
        }
        while(P!=NULL){
        	if(P->Element==val){	
        	printf("\n有重复！\n\n");
			return 0;
			break;
			}
		P=P->Next;
		}
		return 1; 
}
void TraverseList(PNode List) {
    PNode P = List->Next;    //    首节点赋值给临时节点P
    printf("遍历链表的值为：");
    if (P == NULL)
        printf("链表为空");
    while (P != NULL)        //当临时节点P不为尾节点时，输出当前节点值 
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

//    主函数 
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
