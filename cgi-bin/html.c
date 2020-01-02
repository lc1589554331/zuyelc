#include <stdio.h>
#include<stdlib.h>
#include<sqlite.h>


int callback(void *para, int col_count, char **col_value, char **col_name) {
    printf("<li><a href='detail.cgi?%s'>%s</a><li>\n",col_value[0],col_value[2]);
    return 0;
}

//gcc hellocgi.c -o hellocgi.cgi
int main() {

    printf("Content-Type: text/html\n\n");

    char *header="<!doctype html>"\
                 "<html>"\
                 "<head>"\
                 "<meta charset='UTF-8'>"\
                 "<title>风云刺杀榜</title>"
                 "</head>"\
                 "<body>";
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
                 select(db);
                 sqlite3_close(db);
                 printf("</body></html>");


    return 0;
}

    int callback(void *para, int col_count, char **col_value, char **col_name) {
        printf("<li><a href='detail.cgi?%s'>%s</a><li>\n",col_value[0],col_value[2]);
        return 0;
}

        int select(sqlite3 *db){
            printf("<ul>");

            char *sql = "select * from news";
            char *err;

            if(0! = sqlite3_exec(db,sql,callback,NULL,&err)){
                printf("%s\n",err);
                exit(-1);
            }
            printf("</ul>");
            return 0;
        }