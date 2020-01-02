1,配置apache

​	通过命令下载apache

​	找到var下的www文件,打开,创建cgi-bin文件夹

​	找到ETC下面的server-cgi-bin,将地址改为var 下的wwwen文件

   在ETC下的Apache打开终端

​	将下面的三行软连接写入,要用最高权限

 ln -s /etc/apache2/mods-available/cgid.conf /etc/apache2/mods-enabled/cgid.conf

ln -s /etc/apache2/mods-available/cgid.load /etc/apache2/mods-enabled/cgid.load 
ln -s /etc/apache2/mods-available/cgi.load /etc/apache2/mods-enabled/cgi.load

重启Apache服务

在cgi-bin文件下写入含
html下的c文件html,编译成cgi的形式 打开localhost/cgi-bin/xxx.cgi

下载sqlite

gcc -c sqlite3.c 

后面的文件都要编译成该格式

gcc xxx.c sqlite3.o -o lpthread -ldl -xxx.cgi

对数据库的增删该查

创建结构体

增:

初始化char类型的name,age,adress

int insert(sqlite3 *db, news new) {
    char *err;
    char sql[200];

    sprintf(sql, "INSERT INTO news (name,age,address) VALUES ('%s','%s','%s')", new.name,new.age,new.adress);
    
    if (0 != sqlite3_exec(db, sql, NULL, NULL, &err)) {
        printf("\t%s\n", err);
        exit(-1);f
    }
    return 0;
}

将改好的内读进数据库

删

将id 和指针db传入,当接受到输入的值时,删除相对应的值

剩下的相似

网页主页面

由于select函数在编译时总报错,故使用show函数代替



