#include <stdio.h>
#include<stdlib.h>
#include"sqlite3.h"


int callback(void *para, int col_count, char **col_value, char **col_name) {
	 //   for (int i = 0; i < col_count; i++) {
        printf("<li style='list-style:none;display:block;height:60px;box-shadow:0px 5px 20px #b2b2b2;border-radius:20px'><a style='text-decoration:none;line-height:60px;font-size:30px' href='detail.cgi?%s'>%s</a></li>",col_value[0],col_value[1]);
   // }
    return 0;
}
int show();
//gcc hellocgi.c -o hellocgi.cgi
int main() {
	
    printf("Content-Type: text/html\n\n");

    char *header="<!doctype html>"\
                 "<html>"\
                 "<head>"\
                 "<meta charset='UTF-8'>"\
                 "<title>风云刺杀榜</title>"
                 "</head>"\
                 "<body style='margin:0px;padding:0px'>";
 
                printf("%s\n",header);
                printf("<style>"\
                    ".title{color:red}"\
                    "a{color:#333;}"\
                    "</style>");
                printf("<div style='line-height:100px;color:#fff;background-color:pink;text-align:center;font-size:40px'>追杀令</div>");
		printf("<p style='text-align:center'>请选择您的任务</p>");

                 
                 sqlite3 *db = NULL;
                 int res = sqlite3_open("cms.db",&db);
                 if(res !=0){
                     printf("open db fail\n");
                     return -1;
                 }
                 show(db);
                 sqlite3_close(db);
                 printf("</body></html>");


    return 0;
}

//    int callback(void *para, int col_count, char **col_value, char **col_name) {
 //      printf("<li><a href='detail.cgi?%s'>%s</a><li>\n",col_value[0],col_value[1]);
   //     return 0;
//}

        int show(sqlite3 *db){
	printf("<div style='width:300px;margin:0 auto;background:#ebedee;border-radius:20px'>");
            printf("<ul style='padding:0;text-align:center'>");

            char *sql = "SELECT * FROM news";
            char *err;

            if(0 != sqlite3_exec(db,sql,callback,NULL,&err)){
                printf("%s\n",err);
                exit(-1);
            }
            printf("</ul>");
	    printf("</div>");
            return 3;
        }
//#include<stdio.h>
//int main()
//{
  //   	printf("Context-Type:text/html\n\n");
//	printf("Hello,World!\n");
//	return 0;
//}
