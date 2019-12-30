#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int id;
    char name[23];
    int age;
    char tel[23];
}User;
void menu();
int add();
int show();
int del();
void change();
// void add(User *p){
//     User User;
//     p->id=2;
//     p->age=12;
//     //p->tel[i]=12313;
//     printf("%ls",&User.id);
// }
int main()
{
    int i=0;
    int x;
    int j;
    int y;
    int e;
    int f;
    int g;
    User u[50];
    while(1){
        menu();
            printf("请选择你要进行的操作");
            scanf("%d",&y);
            switch(y){
                case 1:
                    add(&i,&u[i]);
                    break;
                case 2:
                for(int f;f<i;f++){
                    printf("编号:%d姓名:%s",f,u[f].name);}
                    printf("请输入编号\n");
                    scanf("%d",&e);
                    for(;e<i;e++){
                        del(&u[e],&u[e+1]);
                        };
                        i--;
                break;
                // change(User *u)
                case 3:
                break;
                case 4:
                printf("请输入您想查询第几条");
                int cx;
                scanf("%d",&cx);
                show(&u[cx]);
                case 5:
                for(int z=0;z<i;z++){
                    show(&u[z]);
                }
                    
                    break;
                break;
                default:
                break;
            }
            
            //scanf("%d",&x);
            
        }return 0;
}



void menu(){
    printf("--------------------江湖追杀令------------------\n");
    printf("\t\t0.退出系统\n");
    printf("\t\t1.录入刺杀令\n");
    printf("\t\t2.刺杀达成令\n");
    printf("\t\t3.修改刺杀令\n");
    printf("\t\t4.查看刺杀令\n");
    printf("\t\t5.全部刺杀令\n");
    printf("----------------------------------锦衣卫-宣-----\n");
}


int add(int *i,User *u){

    printf("请输入年龄:");
    scanf("%d",&u->age);
    printf("请输入姓名:");
    scanf("%s",u->name);

    printf("请输入电话号码:");
    scanf("%s",u->tel);
    *i=*i+1;
   return 0;
}
int show(User *u)
{
printf("name:%s,age:%d\n",u->name,u->age);
    return 0;
}

int del(User *i,User *u)
{
    *i=*u;
    return 0;
}

// void change(int *i,User *u){
//     int h;
//     int j;
//     int k;
//     int l;
//     printf("请输入想改谁的信息\n");
//     scanf("%d",&l);
//     for(h=0;h<=*i;h++){
//         if(l=h){
//             printf("您想要修改什么信息\n");
//             printf("1,姓名 2,年龄 3,电话号码\n");
//             scanf("%d",&j);
//             switch(j)
//             {
//             case 1:
//                 printf("请输入你想要修改的值\n");
//                 scanf("%s",u[h]->name);
//                 printf("修改成功");
//                 break;
//             case 2:
//                 printf("请输入你想要修改的值\n");
//                 scanf("%d",&u[h]->age);
//                 printf("修改成功");
//                 break;
//             case 3:
//                 printf("请输入你想要修改的值\n");
//                 scanf("%s",u[h]->tel);
//                 printf("修改成功");
//                 break;
//             default:
//                 break;
//             }
//             break;
//         }
//     }
// }
