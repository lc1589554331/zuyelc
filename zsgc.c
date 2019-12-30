#include<stdio.h>
#include<stdlib.h>

typedef struct _user{
    char name[5];
    int age[3];
    int tel[11];
}user;
typedef struct _Node    //定义一个节点
{
    user vip;    //存储vip内容
    struct _Node*  next;  //存节点的指针
}Node;
//定义一个链表头文件的指针
Node* head=NULL ;



//第一个函数welcome
void welcome();
//第二个函数add
void add();
//第三个函数del
void del();
//第四个函数change
void change();
//第五个函数find
void find();
void byby();
void show();

 
int main(){
    int i,y;
    
    printf("欢迎加入badman game vip");
    printf("是否继续：0/1 [1是继续，0是终止]\n");
    scanf("%d",&i);
    if(i==0){
        printf("很遗憾，您未能成为我们的vip\n");
    }else{
        while(1){
        welcome();
        scanf("%d",&y);
        switch(y)
        {
            case 1:
            add();                   //增加vip信息
            break;
            case 2:
                                //删除vip信息
            break;
            case 3:
                                //改变vip信息
            break;
            case 4:
            show();            //查找vip信息
            break;
            case 5:
                                //退出学生系统
            break;


        }
        
        }
    }
}

//函数部分
void welcome(){
            int inputnum;
            printf("请执行你接下来的操作\n");
            printf("1.增加vip信息\n");
            printf("2.删除vip信息\n");
            printf("3.改变vip信息\n");
            printf("4.查询vip信息\n");
            printf("5.退出\n");
            scanf("%d",&inputnum);
        }

void add(){
    //开辟节点
    Node* p=(Node*)malloc(sizeof(Node));
    p->next = NULL;
    printf("请输入您的姓名:\n");
    scanf("%s",p->vip.name);
    printf("请输入您的年龄:\n");
    scanf("%d\n",&p->vip.age);
    printf("请输入您的电话号码:\n");
    scanf("%d",&p->vip.tel);
    printf("恭喜你，成为我们的vip,同时也加入全球最帅俱乐部");
}

// void delect(){

// }
//打印学生信息
void show(){
    printf("姓名\n年龄\n电话\n");
    Node* p = head;
    while(p!=NULL){
        printf("%s\n,%d\n,%d\n",p->vip.name,p->vip.age,p->vip.tel);
        p=p->next;
    }
}

void delect()
{

}