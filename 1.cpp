#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef int ElementType;        
                                
typedef struct ListNode {
    ElementType  Element;       
    ListNode* Next;       
}Node, *PNode;


PNode Create_List(void) {                         //创建新的链表 
    int len ;   
    int val ;   
    PNode PHead = (PNode)malloc(sizeof(Node));    

    if (PHead == NULL)    
    {
        printf("空间分配失败 \n");
        exit(-1);
    }

    PNode PTail = PHead;    
    PTail->Next = NULL;   
    len=0;      
    for (int i = 0; i < len; i++) {

        PNode pNew = (PNode)malloc(sizeof(Node));    
        if (pNew == NULL) {
            printf("分配新节点失败\n");
            exit(-1);
        }
       printf("请输入第 %d 个节点的数据：", i + 1);
        scanf("%d", &val);    

        pNew->Element = val;    
        PTail->Next = pNew;    
        pNew->Next = NULL;       
        PTail = pNew;   
    }   
    
    return PHead;    
}

void Insert_List(PNode List, int pos, int val) {                 //在表List的pos位置插入值为val的元素 （插入） 
    int position = 0;
    PNode P = List;    
                    
    while (P != NULL&&position<pos - 1)
    {
        P = P->Next;
        ++position;
    }
    PNode Tmp = (PNode)malloc(sizeof(Node));    
    if (Tmp == NULL)
    {
        printf("内存分配失败！");
        exit(-1);
    }
   
    Tmp->Element = val;
    Tmp->Next = P->Next;
    P->Next = Tmp;
}


int Is_Same(PNode List,int val){                      //在表List中查询是否有值与val相同的元素，有则返回false，没有则返回true （查重） 
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
void Go_List(PNode List) {            //遍历链表List 
    PNode P = List->Next;   
    printf("遍历链表的值为：");
    if (P == NULL)
        printf("链表为空");
    while (P != NULL)        
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}

int Get_Num(PNode List ,int val){              //在表List中查找值为val的元素序号 （按值查找） 
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

int Get_Elem(PNode List,int num){              //在表List中查找序号的num的值 （按序号查找） 
	if(num<0){
		return 99999999;
	}
	int i=0;
	int k;
	PNode P = List->Next;
	
	while(P!=NULL&&i<num){
		P=P->Next; 
		++i;
	} 
	k=P->Element;
} 

int Change_Value(PNode List,int num,int val){              //把表List中，序号为num 的元素的值替换为val （修改链表的值） 
	PNode P = List->Next;
	int k=1;
	while(P!=NULL&&k<num){
		P=P->Next;
		++k;
	}
	P->Element=val;
}
void init()
{
	
	char a;
	char reg;
	int password;
    printf("Welcome to Peppa pig lottery-station");
   
    printf("Do you have accounts?[Y/N]");
    scanf("%c",&a);
    if(a == 'Y'| a == 'y' ) //login
    {
    	printf("Please input your id munber:");
    	scanf("%d",id);
    	Insert_List(userid, 1, id);
		printf("Please input your password:");
		scanf("%d",&password);
	
		if(id==0)//只有0号是管理员 
		{
			admin();//管理员登录 
		} 
		
    	else if(id=={1,2,3,4,5,6,7,8,9})
		{
			person();//普通用户登录 
		} 
		else
		{
			printf("User can't be found!Write N to reginster\n");
			scanf("%c",&reg);
			if(reg=='N')
			{
				register();
			}
			
		}
			
	}
	else if(a == 'N' | a == 'n')
	{
		register();
	}
    

}
void person()
{
	//读取用户信息 
	int choose;
	int newpass;
	printf("your id is:\n"+id);
	id=Get_Elem(userid,1);
	printf("your balance is:\n"+balance);
	Get_Elem(balance,1);
	printf("your number of lottery:\n"+number);
	printf("write 1 to change password\n");
	printf("write 2 to buy lottery\n");
	scanf("%d",&choose);
	if(choose==1)
	{
		printf("Please write your new password:");
		scanf("%d",&newpass);1
		//存入链表未完成
		
		printf("change sucess!");
		 
	}
	else if(choose==2)
	{
		//修改链表信息未完成 
		printf("OK!");
	}
		
}
void admin()
{

	int number;
	PNode lottery = Create_List();
	printf("your id is:\n"+id);                    //管理员id 
	printf("your number of lottery:\n"+number);    //彩票数 
	
	printf("write 1 to add lottery");
	printf("write 2 to delete lottery");
	printf("write 3 to select lottery");
	int input,lnum;
	scanf("%d",input);
	
	if(input==1)
	{
		int adder;
	    printf("the lottery num:\n",lnum);
	    printf("please input the addnum:",adder);
		scanf("%d",adder);
		
		lnum+=adder;
		printf("您当前设置彩票总数为：",lnum);	
    } 
    if(input==2)
    {
    	int reduce;
    	printf("the lottery num:\n",lnum);
    	printf("请输入删除过期彩票数目:",reduce);
    	scanf("%d",reduce);
    	
    	lnum-=reduce;
    	printf("您当前所剩彩票总数为:",lnum);
	}
	if(input==3)
	{
		printf("select the lottery:");
		
		//查询彩票
	    printf("当前彩票有:\n");
		Go_List(lottery);
	 
	}
}
void register()
{
	int password;
	printf("Please register an account~~\n");
	printf("please write your id:");
	scanf("%d",id);
	printf("please write your password:\n");
	scanf("%d",&password);
	Insert_List(userid,1,id);
	Insert_List(passwd, 1, password);
	Insert_List(balance, 1, 0);
	Insert_List(amount, 1, 0);
	printf("regisetr success!\n");
}
void logout()
{
	char choose1;
    printf("您是否选择注销账户[N/Y]\n");
	scanf("%c",choose1);
	if(choose1 == 'Y'| choose1 == 'y' )
	{
		printf("您已注销~~\n");
		init();
	}
	else if(choose1 == 'N'| choose1 == 'n')
	    if(id==0)
		{
			admin();
		}	
		else
		{
			init();
		}
}


int main()
{
	PNode userid = Create_List();
	PNode passwd = Create_List();
	PNode balance = Create_List();
	PNode amount = Create_List();
	int id; 
	init();
	
	void admin();
	void logout();
	

}

