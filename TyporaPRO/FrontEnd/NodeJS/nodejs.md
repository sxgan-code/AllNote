# 一、Node.js安装

## 1.下载并安装

下载地址为：https://nodejs.org/en/

## 2.检查是否安装成功

```shell
node -v
npm -v
```

![image-20210819002754473](image/image-20210819002754473.png)

3、安装镜像

为了提高我们的效率，可以使用淘宝的镜像：http://npm.taobao.org/

　　输入：

```shell
npm install -g cnpm –registry=https://registry.npm.taobao.org
```

即可安装npm镜像，以后再用到npm的地方直接用cnpm来代替就好了。　　

检查是否安装成功：

![image-20210819003058334](image/image-20210819003058334.png)

查看正在使用的镜像

```shell
npm get registry
```

![image-20210819004302285](image/image-20210819004302285.png)

未切换，手动切换

```shell
npx nrm use taobao
```

## 3.配置环境变量

![image-20210819005037589](image/image-20210819005037589.png)

# 二、搭建vue项目环境

## 　　1、安装vue-cli

官网：https://cli.vuejs.org/zh/guide/installation.html

### 关于旧版本

Vue CLI 的包名称由 `vue-cli` 改成了 `@vue/cli`。 如果你已经全局安装了旧版本的 `vue-cli` (1.x 或 2.x)，你需要先通过 `npm uninstall vue-cli -g` 或 `yarn global remove vue-cli` 卸载它。

### Node 版本要求

Vue CLI 4.x 需要 [Node.js](https://nodejs.org/) v8.9 或更高版本 (推荐 v10 以上)。你可以使用 [n](https://github.com/tj/n)，[nvm](https://github.com/creationix/nvm) 或 [nvm-windows](https://github.com/coreybutler/nvm-windows) 在同一台电脑中管理多个 Node 版本。

可以使用下列任一命令安装这个新的包：

```bash
npm install -g @vue/cli
# OR
yarn global add @vue/cli
```

安装之后，你就可以在命令行中访问 `vue` 命令。你可以通过简单运行 `vue`，看看是否展示出了一份所有可用命令的帮助信息，来验证它是否安装成功。

你还可以用这个命令来检查其版本是否正确：

```bash
vue --version
```

### 升级

如需升级全局的 Vue CLI 包，请运行：

```bash
npm update -g @vue/cli

# 或者
yarn global upgrade --latest @vue/cli
```

### 项目依赖

上面列出来的命令是用于升级全局的 Vue CLI。如需升级项目中的 Vue CLI 相关模块（以 `@vue/cli-plugin-` 或 `vue-cli-plugin-` 开头），请在项目目录下运行 `vue upgrade`：

```shell
用法： upgrade [options] [plugin-name]

（试用）升级 Vue CLI 服务及插件

选项：
  -t, --to <version>    升级 <plugin-name> 到指定的版本
  -f, --from <version>  跳过本地版本检测，默认插件是从此处指定的版本升级上来
  -r, --registry <url>  使用指定的 registry 地址安装依赖
  --all                 升级所有的插件
  --next                检查插件新版本时，包括 alpha/beta/rc 版本在内
  -h, --help            输出帮助内容
```

## 2.全局安装webpack

官网：https://webpack.docschina.org/concepts/

在命令行执行   

```shell
npm install webpack webpack-cli -g --save-dev
#-g -----全局安装
#--save-dev ----- 信息写入package.json的devDependencies中
```

查看

```shell
webpack -v
```

![image-20210819092903453](image/image-20210819092903453.png)

