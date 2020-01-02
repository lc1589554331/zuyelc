#include <stdio.h>
#include<stdlib.h>
#include"sqlite3.h"


int callback(void *para, int col_count, char **col_value, char **col_name) {
            for (int i = 1; i < col_count; i++) {
            printf("<li style='list-style:none;text-align:left;height:30px;line-height:30px'>%s:%s\n</li>", col_name[i], col_value[i]);
	    printf("\n");
      }
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
                 "<body style='list-style:none;padding:0px;'>";
                printf("%s\n",header);
                printf("<style>"\
                    ".title{color:red}"\
                    "a{color:#333;}"\
                    "</style>");
                printf("<div style='line-height:40px;color:#fff;background-color:pink;text-align:center;'>追杀令</div>");





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
            printf("<ul style='width:200px;margin:0 auto'>");
	   char *id = getenv("QUERY_STRING");

            char sql[100];
            char *err;

	    sprintf(sql,"select * from news where id = %d",atoi(id));

            if(0 != sqlite3_exec(db,sql,callback,NULL,&err)){
                printf("%s\n",err);
                exit(-1);
            }
            printf("</ul>");
            return 0;
        }

