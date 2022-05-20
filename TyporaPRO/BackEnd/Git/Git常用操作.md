# 一、git仓库创建与连接

## 1、全局设置

```sh
git config --global user.name "Daniel"
git config --global user.email "1019232598@qq.com"
```



## 2、本地初始化项目

```sh
#初始化
git init

# 添加文件及远程连接
touch README.md
git add README.md
git commit -m "first commit"
git remote add origin https://gitee.com/healer0604/BeginnerSpringCloud.git
git push -u origin "master"
```

