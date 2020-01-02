#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

typedef struct {
        char *name;
        char *age;
        char *adress;

}news;


int insert(sqlite3 *db, news new) {
    char *err;
    char sql[200];

    sprintf(sql, "INSERT INTO news (name,age,address) VALUES ('%s','%s','%s')", new.name,new.age,new.adress);

    if (0 != sqlite3_exec(db, sql, NULL, NULL, &err)) {
        printf("\t%s\n", err);
        exit(-1);
    }

    return 0;
}





int callback(void *para, int col_count, char **col_value, char **col_name) {

    for (int i = 0; i < col_count; i++) {
        printf("%s: %s \n", col_name[i], col_value[i]);
    }

//    printf("%s: %s \n", col_name[1], col_value[2]);

	printf("\t----------------------------------\n");

    return 0;
}



int show(sqlite3 *db)
{

	char *err;
    	char sql[100];

    	sprintf(sql, "\t\tSELECT * FROM news");

    	if (0 != sqlite3_exec(db, sql, callback, NULL, &err)) {
        	printf("\t\t%s\n", err);
        	exit(-1);
   	 }
	return 0;

}





int del(sqlite3 *db,int x)
{
	char *err;
        char sql[100];
	sprintf(sql, "DELETE FROM news WHERE id='%d'",x);
	if (0 != sqlite3_exec(db, sql, callback, NULL, &err)) {
                printf("%s\n", err);
                exit(-1);
         }
        return 0;


}



int modify(sqlite3 *db,news new,int x)
{
	char *err;
        char sql[100];
        sprintf(sql, "UPDATE news SET name='%s',age='%s',adress='%s' WHERE id='%d'",new.name,new.age,new.adress,x);
        if (0 != sqlite3_exec(db, sql, callback, NULL, &err)) {
                printf("%s\n", err);
                exit(-1);
         }


return 0;
}








int main()

{
	sqlite3 *db = NULL;	
	int flag=1;
	int x;
	int res = sqlite3_open("cms.db", &db);
    	if (res != 0) {
        	printf("open db fail\n");
        	return -1;
   	 }

	while(flag){
		int y;
		printf("-----------------江湖追杀令----------------\n");
		printf("\t\t1.录入刺杀令\n");
		printf("\t\t2.刺杀达成令\n");
		printf("\t\t3.修改刺杀令\n");
		printf("\t\t4.查看刺杀令\n");
		printf("\t\t5.退出刺杀令\n");
		printf("-------------------------------锦衣卫-宣---\n");
		scanf("%d",&y);
		
		switch(y){
			case 1:{
				news new;
				printf("\t\t输入目标姓名");
				new.name=malloc(sizeof(char));
				new.age=malloc(sizeof(char));
				new.adress=malloc(sizeof(char));

				scanf("%s",new.name);
				printf("\t\t输入目标年龄");
				scanf("%s",new.age);
				printf("\t\t输入目标所在位置");
				scanf("%s",new.adress);
			//	printf("%s",new->title);
				insert(db,new);
				};break;


			case 2:show(db); 
			       printf("\t\t输入要删除的目标\n");
			       scanf("\t%d",&x);
			       del(db,x);break;

			case 3:
			       {
			       news n;
			       show(db);
			       printf("\t\t输入要修改的目标\n");
                               scanf("%d",&x);
                               printf("\t\t输入目标姓名\n");
                               n.name=malloc(sizeof(char));
                               n.age=malloc(sizeof(char));
                               n.adress=malloc(sizeof(char));
                               scanf("%s",n.name);
                               printf("\t\t输入目标年龄\n");
                               scanf("%s",n.age);
                               printf("\t\t输入目标所在位置\n");
                               scanf("%s",n.adress);
			       modify(db,n,x);
			       };break;
			       
			case 4:
			       show(db);break;

			case 5: 
			       flag=0;
		
			       break;


			default :
			       printf("\t\t请输入正确序号1-5\n");

		}




	
	
	}
	sqlite3_close(db);
	return 0;
}
