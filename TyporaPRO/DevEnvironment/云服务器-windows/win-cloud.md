# 常见问题

## 服务器上的配置mysql数据库外网可访问

进入mysql：

```shell
mysql -uroot -p
```

输入密码。

选择mysql数据库：

```mysql
use mysql;
```

增加允许远程访问的用户或者允许现有用户的远程访问。
给root授予在任意主机（%）访问任意数据库的所有权限。

```mysql
update user set host='%' where user='root' and host='localhost';
```

退出mysql：

```mysql
exit
```

重启数据库：

```shell
sudo service mysql restart
```

