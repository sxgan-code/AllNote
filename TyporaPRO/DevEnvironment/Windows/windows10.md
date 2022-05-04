重装系统后的配置

# 一、通用软件安装

## 1.通用软件

### Google

https://www.google.cn/chrome/

### Tim

https://office.qq.com/download.html

### 微信

https://pc.weixin.qq.com/

### QQ音乐

https://y.qq.com/

### Typora

https://www.typora.io/#download

### 百度网盘

https://pan.baidu.com/download

### wps

https://platform.wps.cn/

### 有道云笔记

https://note.youdao.com/download.html

## 2.杀毒软件

火绒：https://www.huorong.cn/person5.html



## 3.娱乐

### Steam ：https://store.steampowered.com/

壁纸引擎：steam内下载

### WeGame：https://www.wegame.com.cn/

## 4.输入法

### 百度输入法：https://shurufa.baidu.com/

## 5.Office2021（可能会失效）

1.运行setup.bat

![image-20210812183706274](image/windows10/image-20210812183706274.png)

2.点击【部署--》添加产品】

![image-20210812183848375](image/windows10/image-20210812183848375.png)

3.根据步骤勾选

❶选择【office 专业增强版 2021（预览版）】

❷勾选需要安装的产品（根据自己的需求勾选，我这里仅勾选World、Excel、PPT）

❸选择体系结构【64位】❹选择通道【office 2021 企业长期版】

❺勾选【创建桌面快捷方式】

❻点击【开始部署】。

![image-20210812184001511](image/windows10/image-20210812184001511.png)

4.点击【是】。

![image-20210812184550950](image/windows10/image-20210812184550950.png)

5.安装中……

![image-20210812184631830](image/windows10/image-20210812184631830.png)

6.点击【关闭】，点击右上角【X】退出。

![image-20210812185250236](image/windows10/image-20210812185250236.png)

7.打开安装包解压后的【Office2021(64bit)】文件夹，鼠标有【Crack】选择【解压到当前文件夹】。

![image-20210812185328301](image/windows10/image-20210812185328301.png)

8.鼠标右击解压后的【OfficeCrack.bat】选择【以管理员身份运行】。

![图片](image/windows10/640-162876420455020)

9.输入【1】。

![image-20210812185936607](image/windows10/image-20210812185936607.png)

10.界面提示“office……2021……产品激活成功”后在键盘上按【Enter键】。

![image-20210812185704941](image/windows10/image-20210812185704941.png)

11.输入【2】。

![image-20210812190001289](image/windows10/image-20210812190001289.png)

12.界面提示“激活模式：自动续期”后点击右上角【X】退出。

![image-20210812185856648](image/windows10/image-20210812185856648.png)

14.安装成功。

![image-20210812191036949](image/windows10/image-20210812191036949.png)

## 6.文本编辑器（sublime安装）

### 安装软件

![image-20210812173608440](image/windows10/image-20210812173608440.png)

### 破解

安装完毕后讲注册机中的Patch.exe复制到安装目录并以管理员运行

![image-20210812173540057](image/windows10/image-20210812173540057.png)

点击patch

![image-20210812173750330](image/windows10/image-20210812173750330.png)

如图成功

![image-20210812173810366](image/windows10/image-20210812173810366.png)

![image-20210812174058728](image/windows10/image-20210812174058728.png)

### 部分设置如下：

```json
{
    //禁用更新
	"update_check": false,
	// ***主题文件的路径***
	"color_scheme": "Packages/Color Scheme - Default/Monokai.sublime-color-scheme",
	// ***设置字体和大小，必须在Settings-User里重写，这里设置没有任何效果***
	"font_face": "Consolas",
	"font_size": 14,

	"theme": "Default.sublime-theme",
	//是否显示行号
	"line_numbers": true,
	// ***是否显示代码折叠按钮***
	"fold_buttons": true,
	//拼写检查
	"spell_check": false,
	// ***代码提示***
	"auto_complete": true,
	// ***代码提示延迟显示***
	"auto_complete_delay": 50,
	// ***默认编码格式***
	"default_encoding": "UTF-8",
	// ***行号边栏和文字的间距***
	"margin": 2,
	// ***Tab键制表符宽度***
	"tab_size": 4,
	// ***自动匹配引号，括号等***
	"auto_match_enabled": true,
	// ***突出显示当前光标所在的行***
	"highlight_line": true,
	// ***设置光标闪动方式***
	"caret_style": "smooth",
	// ***是否特殊显示当前光标所在的括号、代码头尾闭合标记***
	"match_brackets": true,
	// ***是否突出显示圆括号，match_brackets为true生效***
	"match_brackets_square": false,

	// ***是否突出显示大括号，match_brackets为true生效\***
	"match_brackets_braces": false,
	// ***是否突出显示尖括号，match_brackets为true生效***
	"match_brackets_angle": false,
	// ***html和xml下突出显示光标所在标签的两端，影响HTML、XML、CSS等***
	"match_tags": true,

	// ***全文突出显示和当前选中字符相同的字符***
	"match_selection": true,

	// ***设置每一行到顶部，以像素为单位的间距，效果相当于行距***
	"line_padding_top": 1,

	// ***设置每一行到底部，以像素为单位的间距，效果相当于行距***
	"line_padding_bottom": 1,
	// ***制表位的对齐白线是否显示，颜色可在主题文件里设置（guide，activeGuide，stackGuide）***
	"draw_indent_guides": true,
	// ***选中的文本按Ctrl + f时，自动复制到查找面板的文本框里***
	"find_selected_text": true,
	// ***哪些文件会被显示到边栏上***
	"folder_exclude_patterns": [".svn", ".git", ".hg", "CVS"],
	"file_exclude_patterns": ["*.pyc", "*.pyo", "*.exe", "*.dll", "*.obj","*.o", "*.a", "*.lib", "*.so", "*.dylib", "*.ncb", "*.sdf", "*.suo", "*.pdb", "*.idb", ".DS_Store", "*.class", "*.psd", "*.db"],
	// These files will still show up in the side bar, but won't be included in
	// Goto Anything or Find in Files
	"binary_file_patterns": ["*.jpg", "*.jpeg", "*.png", "*.gif", "*.ttf", "*.tga", "*.dds", "*.ico", "*.eot", "*.pdf", "*.swf", "*.jar", "*.zip"],
}

```

### 详细配置

安住ctrl+左键跳转：[sublime详细设置](./sublime设置.md)



# 二、java环境搭建

## 1.JDK1.8安装

### 下载jdk

线上：https://www.oracle.com/java/technologies/javase-downloads.html

本地：windows10环境配置软件包/JDK/

### 安装jdk

![image-20210812111956893](image/windows10/image-20210812111956893.png)

系统变量添加 `JAVA_HOME`（需要新建）

```java
D:\Development\Software\java\jdk1.8.0_261 //配置到jdk的目录下，该目录下有bin、lib等文件夹
```

系统变量中Path配置

```java
%JAVA_HOME%\bin
```

系统变量添加`CLASSPATH`（需要新建）

```java
.;%JAVA_HOME%\lib
```

### 测试

![image-20210811214938692](image/windows10/image-20210811214938692.png)

## 2.IDEA安装(安装版本为2021.1.2)

### 安装路径统一

```java
D:\Development\Software\IDEA2021\IntelliJ IDEA 2021.1
```

### 重置试用期

![image-20210811182910318](image/windows10/image-20210811182910318.png)

![image-20210811183214412](image/windows10/image-20210811183214412.png)

安装插件和导入配置

![image-20210811183812470](image/windows10/image-20210811183812470.png)

## 3.git安装

注：此方法可用于配置gitlab也可用于配置github

### (1).在github中创建一个账号

github：https://github.com/

### (2).下载并安装

git：https://git-scm.com/downloads

### (3).安装成功后打开Git Bash

输入下列命令，设置git全局用户名和邮箱

```shell
Administrator@Healer MINGW64 ~/Desktop
$ git config --global user.name "Daniel-0510"
Administrator@Healer MINGW64 ~/Desktop
$ git config --global user.email "1019232598@qq.com"
```

![image-20210811190055730](image/windows10/image-20210811190055730.png)

### (4).在IDEA中设置Git

在File-->Setting->Version Control-->Git-->Path to Git executable选择你的git安装后的git.exe文件，然后点击Test，测试是否设置成功

![image-20210811190311142](image/windows10/image-20210811190311142.png)

### (5).在IDEA中设置GitHub

File-->Setting->Version Control-->GibHub

　　Host：github.com

　　Token：点击Create API Token，输入在github中注册的用户名和密码生成token

　　点击Test，测试是否连接成功

![image-20210811190439828](image/windows10/image-20210811190439828.png)

### (6).本地拉取git代码

在你需要拉取的目录下打开git命令行，输入以下命令即可拉去，根据自己需求拉去相应的

```shell
Administrator@Healer MINGW64 /f
$ git clone https://github.com/Daniel-0510/animate.css.git
```

### (7).IDEA中使用git拉取

右击项目空白处，点击git--》Manage Remotes，输入对应的代码地址及其名称

![image-20210811192616332](image/windows10/image-20210811192616332.png)

![image-20210811192812539](image/windows10/image-20210811192812539.png)

点击空白处点击git---》pull

![image-20210811193100000](image/windows10/image-20210811193100000.png)

![image-20210811193122329](image/windows10/image-20210811193122329.png)

选择拉取的路径，及其主要分支

## 4.Maven安装

### (1).下载

https://maven.apache.org/download.cgi

![image-20210811195205098](image/windows10/image-20210811195205098.png)

### (2).安装

![image-20210811195331124](image/windows10/image-20210811195331124.png)

![image-20210811195347047](image/windows10/image-20210811195347047.png)

### (3).测试

按住win+r 输入cmd 输入以下命令查看

```shell
mvn -v
```

如果出现

![image-20210811201353203](image/windows10/image-20210811201353203.png)

可尝试在path中配置maven的绝对路径，注意路径配置到bin目录下

![image-20210811201510660](image/windows10/image-20210811201510660.png)

### (4).配置settings文件

![image-20210811202210056](image/windows10/image-20210811202210056.png)

找到第52行，这里是maven默认的仓库

![image-20210811202255923](image/windows10/image-20210811202255923.png)

我们复制第53行

```xml
<localRepository>/path/to/local/repo</localRepository>
```

将它拿到注释外并将中间的内容改成你需要的路径，如图

```xml
<localRepository>D:/Development/Software/Maven/apache-maven-3.8.1-bin/apache-maven-3.8.1/RepMaven</localRepository>
```

这里的路径随便设置，==注意这里是正斜杠==

配置镜像，使用一个即可

```xml
<!-- 1.阿里云仓库 推荐使用-->
<mirror>
    <id>alimaven</id>
    <mirrorOf>central</mirrorOf>
    <name>aliyun maven</name>
    <url>http://maven.aliyun.com/nexus/content/repositories/central/</url>
</mirror>
<!-- 2.华为-->
<mirror>
    <id>huaweicloud</id>
    <mirrorOf>*</mirrorOf>
    <name>huaweicloud maven</name>
    <url>https://mirrors.huaweicloud.com/repository/maven/</url>
</mirror>
<!-- 3.中央仓库1 -->
<mirror>
    <id>repo1</id>
    <mirrorOf>central</mirrorOf>
    <name>Human Readable Name for this Mirror.</name>
    <url>http://repo1.maven.org/maven2/</url>
</mirror>
<!-- 4.中央仓库2 -->
<mirror>
    <id>repo2</id>
    <mirrorOf>central</mirrorOf>
    <name>Human Readable Name for this Mirror.</name>
    <url>http://repo2.maven.org/maven2/</url>
</mirror>
```

![image-20210811203650561](image/windows10/image-20210811203650561.png)

最后配置`jdk`，也要夹在两个``profiles``标签之间(我这里使用的为jdk1.8**)

```xml
<!-- java版本 --> 
	 <profile>
	  <id>jdk-1.8</id>
	  <activation>
		<activeByDefault>true</activeByDefault>
		<jdk>1.8</jdk>
	  </activation>

	  <properties>
		<maven.compiler.source>1.8</maven.compiler.source>
		<maven.compiler.target>1.8</maven.compiler.target>
		<maven.compiler.compilerVersion>1.8</maven.compiler.compilerVersion>
	  </properties>
	</profile>
```

配置完成，在命令行输入`mvn help:system`测试，看到下载链接里面是ailiyun的链接表示配置成功

# 三、MySQL安装

## 1.下载

https://dev.mysql.com/downloads/installer/

Linux ：https://dev.mysql.com/downloads/os-linux.html

![image-20210812122920417](image/windows10/image-20210812122920417.png)

## 2、安装

启动mis文件

选择Custom然后next

![image-20210812123120340](image/windows10/image-20210812123120340.png)

点击选择

![image-20210812123431763](image/windows10/image-20210812123431763.png)

点击execute--》next

![image-20210812123538245](image/windows10/image-20210812123538245.png)

默认即可

![image-20210812123708541](image/windows10/image-20210812123708541.png)

输入密码:`daniel`

![image-20210812123820458](image/windows10/image-20210812123820458.png)

定义服务的名字，一般默认即可

![image-20210812123941006](image/windows10/image-20210812123941006.png)

点击执行

![image-20210812124009620](image/windows10/image-20210812124009620.png)

测试输入密码

![image-20210812124137188](image/windows10/image-20210812124137188.png)

## 3.安装Navicat

下载好后首先安装 Navicat Premium 15 ，此工具安装比较简单，我就不一步一步来了，疯狂下一步就完了。

![img](image/windows10/20201111170208105.png)

开始激活（激活时必须断网）

（激活时必须断网）

（激活时必须断网）

（激活时必须断网）

使用注册机，先退出所有杀毒软件，再打开注册机，否则会一直报错的

![img](image/windows10/20201111170208106.png)

在激活工具的第一个选项(1.Patch)里选择Backup，Host，Navicat 是那个版本就选那个版本，这里就选择Navicat V 15 就好了，然后点击，Patch按钮，选择Navicat的安装位置中的navicat.exe文件

如图：

![img](image/windows10/20201111170208107.png)

![img](image/windows10/20201111170208108.png)

出现以下提示说明Patch成功了。

![img](image/windows10/20201111170209109.png)

License. Product and Language

License里选中Enterprise、在Produce里选择Premium、在Languages里选择Simplified Chinese(简体中文)

![img](image/windows10/20201111170209110.png)

**Resale License**

选择Site License

![img](image/windows10/20201111170209111.png)

Keygen / Offline Activation

点击Generate按钮就会生成一个许可证秘钥，将许可证秘钥复制后就打开Navicat Premium 15

![img](image/windows10/20201111170209112.png)

打开Navicat Premium 15，点击注册

![img](image/windows10/20201111170209113.png)

粘贴秘钥，然后点击激活按钮

![img](image/windows10/20201111170210114.png)

在弹出的界面选择手动激活

![img](image/windows10/20201111170210115.png)

将请求码粘贴到注册机Request Code框中（完整过程看图）

![img](image/windows10/20201111170210116.png)

点击激活页面的激活弹出（说明激活成功）

![img](image/windows10/20201111170210117.png)

![img](image/windows10/20201111170211118.png)

# 四、Oracle 11g安装

## 1.解压

解压后进入包内，点击setup.exe开始安装 。

## 2.安装

一般把那个小对勾取消，点击下一步进行，

![image-20210812145753911](image/windows10/image-20210812145753911.png)

![image-20210812145927429](image/windows10/image-20210812145927429.png)

点击是

![image-20210812150206141](image/windows10/image-20210812150206141.png)

选择创建和配置数据库

下图，选择服务器类，因为桌面类没有高级选项的功能，下一步。

![image-20210812150308277](image/windows10/image-20210812150308277.png)

5.下图，选择单实例数据库，下一步

![image-20210812150325036](image/windows10/image-20210812150325036.png)

6.下图，选择高级安装，下一步

​    ![image-20210812150344020](image/windows10/image-20210812150344020.png)

7，下图选择语言，如果数据库内没有用到其他的语言，就这样默认的就可以了，下一步

![image-20210812150405361](image/windows10/image-20210812150405361.png)

8.下图，选择安装版本，用企业版的，下一步

![image-20210812150425017](image/windows10/image-20210812150425017.png)

9.下面，选择基目录的时候要注意了，最好去新建一个自定义的目录，以后方便自己查询和更改，不要用这个默认的，删除的时候麻烦。下面说一下怎么新建一个自定义目录。

​    ![image-20210812150609198](image/windows10/image-20210812150609198.png)

10.新建自定义目录：在d盘下新建一个文件夹,进入这个文件夹，在里面新建一个文件夹，取名oracle. 注意：这两个文件夹的名字可以自己定义，但是==最好不要用中文名作文件夹的名字==，容易出问题。最好是如下这样的目录结构。

![image-20210812150708634](image/windows10/image-20210812150708634.png)



11.下图，选择‘一般用途事务处理’直接点击下一步：

![image-20210812150817140](image/windows10/image-20210812150817140.png)

12.下图，‘全局数据库名’，可以自己定义。下面的服务标识符也是可以自己定义。一般这两个就使用默认的了。下一步。

![image-20210812150845114](image/windows10/image-20210812150845114.png)

13.下图，就按照默认的来吧，点击下一步。

![image-20210812150901449](image/windows10/image-20210812150901449.png)

14.下图，也选择默认，下一步

![image-20210812151002067](image/windows10/image-20210812151002067.png)

15.下图，还是默认的，点击下一步。

 ![image-20210812151020577](image/windows10/image-20210812151020577.png)

16.下图，直接下一步

![image-20210812151034325](image/windows10/image-20210812151034325.png)

17.下图，配置口令，如果怕麻烦的话，如果仅仅是做学习用的话，统一口令就行。如果以后高级了，可以分别设置口令。这几个用户权限是不同的。我就用统一口令了，输入了   ==`daniel123`==   注意一点：你的这个口令，必须以字母开头，数字开头的话，后面会有很多问题的。

18.

![image-20210812151145763](image/windows10/image-20210812151145763.png)

19.输入上面那个root123后，会弹出如下：在这里要注意了，oracle的密码标准是要字母数字大小写组合的大于八位才行，一般要是仅供学习用的话，不用在意这个。直接点‘是’就行。

 ![image-20210812151227777](image/windows10/image-20210812151227777.png)

20.下图，检测环境：

![image-20210812151324899](image/windows10/image-20210812151324899.png)

![image-20210812151337918](image/windows10/image-20210812151337918.png)

21.如出现下图点击安装

![image-20210812151756908](image/windows10/image-20210812151756908.png)

等待完成后点击

![image-20210812151859880](image/windows10/image-20210812151859880.png)

22.环境检测完后，有的是可以直接点击下一步的，有的会出现如下图：这个时候，一般是下图这样的，那么就应该没多大问题，选择全部忽略，再点击下一步就行了。

![11479F9EB9FA46FFA3B1E0EECC57961B](image/windows10/11479F9EB9FA46FFA3B1E0EECC57961B.png)

25.安装完后出现这个：点击确定就可以完成了。关闭。

![image-20210812152235592](image/windows10/image-20210812152235592.png)

 这样就完成oracle的安装了。

 测试一下，打开oracle自带的sql plus。

![image-20210812152425131](image/windows10/image-20210812152425131.png)

用户名：system   密码口令：daniel123(就是在20步自己定义的那个口令)。顺利进入：注意oracle这里输入的密码口令是不显示的敲完密码直接回车，用了像linux登录的方式。在这 里就可以输入sql语句了。

![image-20210812152516335](image/windows10/image-20210812152516335.png)

## 3.安装PL/SQL developer

一般oracle用的可视化管理工具是pl/sql developer。

注册码

```yaml
product code： 4vkjwhfeh3ufnqnmpr9brvcuyujrx3n3le
serial Number：226959
password: xs374ca
```

设置中文

![image-20210812153056708](image/windows10/image-20210812153056708.png)

## 4.创建用户

![image-20210812153912747](image/windows10/image-20210812153912747.png)

```properties
用户名：system
口令：daniel123
数据库：ORCL
连接为：Normal
```

![image-20210812154114023](image/windows10/image-20210812154114023.png)

选择当前用户All Object 右击Users新建

![image-20210812154247121](image/windows10/image-20210812154247121.png)

输入名称及其口令，此处输入为 名称：daniel 口令：daniel    

点击应用

赋予角色权限

```
connect : 基本操作表的权限，比如增删改查、视图创建等 
resource： 创建一些函数，比如簇、索引，创建表、列等 
dba : 相当于管理员权限，拥有系统所有权限
```

![image-20210812154656790](image/windows10/image-20210812154656790.png)

登录新建的角色即可

![image-20210812154924122](image/windows10/image-20210812154924122.png)

## 5.Navicat链接新建用户

![image-20210812155033199](image/windows10/image-20210812155033199.png)

![image-20210812155149318](image/windows10/image-20210812155149318.png)

成功登录

![image-20210812155228145](image/windows10/image-20210812155228145.png)

# 五、前端软件环境

## 1.WebStorm2021

安装方式与IDEA方式相同，采用重置试用期的方式

![image-20210812195522446](image/windows10/image-20210812195522446.png)

将中文包拖到软件界面，点击restart即可

![image-20210812200246001](image/windows10/image-20210812200246001.png)

## 2.安装node.js

### 下载

https://nodejs.org/zh-cn/

### 安装

下载完成后，双击“node-v14.17.5-x64.msi ”，开始安装：

　　![img](image/windows10/665662-20180115084728303-1430222689.png)

　　![img](image/windows10/665662-20180115084800396-1627818561.png)

　　2、点击“ Next ”按钮
　　![img](image/windows10/665662-20180115084923865-492768019.png)

　　3、选择安装目录，点击“ Next ”按钮

　　![img](image/windows10/665662-20180115085236396-975876816.png)

　　4、选择安装项，此处我选择默认，点击“ Next ”按钮

　　![img](image/windows10/665662-20180115085426553-1061547156.png)

　　5、点击“ Install ”按钮，开始安装

　　![img](image/windows10/665662-20180115085605053-2135284357.png)

　　6、等待安装完成，点击“ Finish ”按钮完成安装

　　![img](image/windows10/665662-20180115085922365-1454511303.png)

### 安装完成查看

　查看是否安装成功

　　A、node -v 查看 node 版本

　　B、npm -v 查看 npm 版本

　　![img](image/windows10/665662-20180115090252662-1620808958.png)

　安装完成后，文件目录如下图

　　![img](image/windows10/665662-20180115090503474-75777811.png)

　　如果 npx 为 `5.2.0`+，会安装一个新的包 `npx`。npx是一个工具，旨在提高从npm注册表使用软件包的体验 ，npm使得它非常容易地安装和管理托管在注册表上的依赖项，npx使得使用CLI工具和其他托管在注册表，大大简化了一些事情。

### 环境配置

#### 缓存路径配置

　　此处的环境配置主要配置的是 npm 安装的全局模块所在的路径，以及缓存cache的路径，之所以要配置，是因为以后在执行类似：

```shell
npm install express [-g] #（后面的可选参数-g，g代表global全局安装的意思）
```

的安装语句时，会将安装的模块安装到【`C:\Users\用户名\AppData\Roaming\npm`】路径中，占C盘空间。
　　例如：我希望将全模块所在路径和缓存路径放在我node.js安装的文件夹中，则在我的安装目录下创建两个文件夹【`node_global`】及【`node_cache`】如下图：

　　![img](image/windows10/665662-20180115091635678-776669326.png)

　　(1)、设置全局目录和缓存目录，创建完两个空文件夹之后，打开`cmd`命令窗口，输入

```shell
npm config set cache "D:\Development\Software\NodeJs\node_cache"
npm config set prefix "D:\Development\Software\NodeJs\node_global"
```

　　![img](image/windows10/665662-20180115091956693-378651395.png)

或者直接修改文件：在C盘下：`C:\Users\Administrator\.npmrc` 修改该文件目录即可

![image-20210817161240519](image/windows10/image-20210817161240519.png)

　　重新配置：A、删除【 C:\Users\yi081\.npmrc 】文件重新生成。如果 .npmrc 不在这个目录下，就 C 盘全局搜一下；B、直接修改编译 .npmrc 文件。

　　

#### 设置环境变量

“我的电脑”-右键-“属性”-“高级系统设置”-“高级”-“环境变量”

　　A、进入环境变量对话框，在【系统变量】下新建【NODE_PATH】，输入【D:\SDE\Node8.9.4\node_modules】

　　B、将【用户变量】下的【Path】修改为【D:\SDE\Node8.9.4\node_global】

　　![img](image/windows10/665662-20180115092642584-1053876751.png)

　　![img](image/windows10/665662-20180115092803146-696636917.png)

　　![img](image/windows10/665662-20180115093048459-1065793142.png)

　　修改完成，点击“ 确定 ”按钮。

## 六、测试

　　配置完后，安装个module测试下，我们就安装最常用的express模块，注意一定要以==管理员的身份==运行cmd窗口，输入如下命令进行模块的全局安装：

```
　`npm install express -g # -g是全局安装的意思`
```



　　注：如果安装时不加 -g 参数，则安装的模块就会安装在当前路径下，上例若不加 -g 参数，则 express 模块会安装在 C:\Users\yi081目录下的 【node_modules】目录下，目录若不存在会自动生成。

![image-20210817162531541](image/windows10/image-20210817162531541.png)

　　打开全局安装目录发现没有 express 的可执行文件，如下图：

　　

　　最后查阅网上资源后，原来，最新express版本中将命令工具分家出来了(项目地址:https://github.com/expressjs/generator)，所以还需要安装一个命令工具，命令如下:

```shell
　　npm install -g express-generator
```

　　![img](image/windows10/665662-20180115100718162-1160280117.png)

　　然后打开我们的安装目录发现 express 被安装在了全局目录下，如下图：

　　![img](image/windows10/665662-20180115100924943-1996052848.png)

　　使用express创建一个工程，输入命令：express helloworld

　　![img](image/windows10/665662-20180115101258146-700728802.png)　

　　转到 helloworld 目录下，命令：cd helloworld

　　![img](image/windows10/665662-20180115101544553-2058587475.png)

　　装载 node 包管理器，执行命令：npm install

　　![img](image/windows10/665662-20180115101748131-1594943293.png)

　　启动 helloworld，输入命令：npm start，如下图，新创建的 helloworld 已经运行在3000端口上

　　![img](image/windows10/665662-20180115102009084-1119193645.png)

　　在浏览器中输入地址：http://localhost:3000/，如下图，访问我们的第一个node web 网页。　　　　

　　![img](image/windows10/665662-20180115102110474-166428104.png)

 

# 六、设计软件类

## 1.PS安装

直装版

## 2.PR安装

直装版

## 3.XD安装

直装版
