# Log4j使用

日志是应用软件中不可缺少的部分，Apache的开源项目[log4j](http://www.codeceo.com/article/log4j-usage.html)是一个功能强大的日志组件,提供方便的日志记录。在apache网站：[jakarta.apache.org/log4j](http://jakarta.apache.org/log4j) 可以免费下载到Log4j最新版本的软件包。

## 导入包

```xml
<!-- https://mvnrepository.com/artifact/log4j/log4j -->
<dependency>
    <groupId>log4j</groupId>
    <artifactId>log4j</artifactId>
    <version>1.2.16</version>
</dependency>
```

## web.xml配置

```xml
 <!--Log4jConfigListener监听器，用来监听日志的启动：-->
    <listener>
        <listener-class>org.springframework.web.util.Log4jConfigListener</listener-class>
    </listener>
 <!--log4j文件的加载路径：不过我后来又尝试了一下，好像<context-param>不需要进行配置也可以运行log4j。-->
  <!--  log4j日志输出 -->
    <context-param>
        <param-name>log4jConfigLocation</param-name>
        <param-value>classpath:log4j.properties</param-value>
    </context-param>
```

## log4j.properties配置文件

```properties
 ### 设置###
log4j.rootLogger = debug,stdout,D,E,info

### 输出信息到控制抬 ###
log4j.appender.stdout = org.apache.log4j.ConsoleAppender
log4j.appender.stdout.Target = System.out
log4j.appender.stdout.layout = org.apache.log4j.PatternLayout
log4j.appender.stdout.layout.ConversionPattern = [%-5p] %d{yyyy-MM-dd HH:mm:ss,SSS} method:%l%n%m%n

### 输出DEBUG 级别以上的日志到=E://logs/error.log ###
log4j.appender.D = org.apache.log4j.DailyRollingFileAppender
log4j.appender.D.File = E://logs/Debug.log
log4j.appender.D.Append = true
log4j.appender.D.Threshold = DEBUG 
log4j.appender.D.layout = org.apache.log4j.PatternLayout
log4j.appender.D.layout.ConversionPattern = %-d{yyyy-MM-dd HH:mm:ss}  [ %t:%r ] - [ %p ]  %m%n

### 输出ERROR 级别以上的日志到=E://logs/error.log ###
log4j.appender.E = org.apache.log4j.DailyRollingFileAppender
log4j.appender.E.File =E://logs/error.log 
log4j.appender.E.Append = true
log4j.appender.E.Threshold = ERROR 
log4j.appender.E.layout = org.apache.log4j.PatternLayout
log4j.appender.E.layout.ConversionPattern = %-d{yyyy-MM-dd HH:mm:ss}  [ %t:%r ] - [ %p ]  %m%n

#2 文件大小到达指定尺寸的时候产生一个新的文件 
log4j.appender.info = org.apache.log4j.RollingFileAppender
#日志文件输出目录
log4j.appender.info.File=log/tibet.log
#定义文件最大大小
log4j.appender.info.MaxFileSize=10mb
###输出日志信息###
#最低级别
log4j.appender.info.Threshold=INFO
log4j.appender.info.layout=org.apache.log4j.PatternLayout
log4j.appender.info.layout.ConversionPattern=[%p][%d{yy-MM-dd}][%c]%m%n
#4 mybatis 显示SQL语句部分
log4j.logger.org.mybatis=DEBUG
#log4j.logger.cn.tibet.cas.dao=DEBUG
#log4j.logger.org.mybatis.common.jdbc.SimpleDataSource=DEBUG#
#log4j.logger.org.mybatis.common.jdbc.ScriptRunner=DEBUG#
#log4j.logger.org.mybatis.sqlmap.engine.impl.SqlMapClientDelegate=DEBUG#
#log4j.logger.java.sql.Connection=DEBUG
log4j.logger.java.sql=DEBUG
log4j.logger.java.sql.Statement=DEBUG
log4j.logger.java.sql.ResultSet=DEBUG
log4j.logger.java.sql.PreparedStatement=DEBUG
```

## Log4j基本使用方法

Log4j由三个重要的组件构成：

> 日志信息的优先级
>
> 日志信息的输出目的地
>
> 日志信息的输出格式

日志信息的优先级从高到低有`ERROR`、`WARN`、 `INFO`、`DEBUG`，分别用来指定这条日志信息的重要程度；日志信息的输出目的地指定了日志将打印到控制台还是文件中；而输出格式则控制了日志信息的显 示内容。

### 定义配置文件

其实您也可以完全不使用配置文件，而是在代码中配置Log4j环境。但是，使用配置文件将使您的应用程序更加灵活。Log4j支持两种配置文件格式

> XML格式的文件
>
> Java特性文件properties（键=值）

下面我们介绍使用Java特性文件做为配置文件的方法：

#### 1.配置根Logger，其语法为：

```properties
  log4j.rootLogger = [ level ] , appenderName, appenderName, …              
```

其中，level 是日志记录的优先级由高到低，分为`OFF、FATAL、ERROR、WARN、INFO、DEBUG、ALL`或者您定义的级别。Log4j建议只使用四个级别，优先级从高到低分别是`ERROR、WARN、INFO、DEBUG`。通过在这里定义的级别，您可以控制到应用程序中相应级别的日志信息的开关。

比如在这里定义了`INFO`级别，则应用程序中所有`DEBUG`级别的日志信息将不被打印出来。 `appenderName`就是指日志信息输出到哪个地方。您可以同时指定多个输出目的地。

#### 2.配置日志信息输出目的地Appender，其语法为：

```properties
log4j.appender.appenderName = fully.qualified.name.of.appender.class  
log4j.appender.appenderName.option1 = value1  
…  
log4j.appender.appenderName.option = valueN
其中，Log4j提供的appender有以下几种：
org.apache.log4j.ConsoleAppender（控制台），  
org.apache.log4j.FileAppender（文件），  
org.apache.log4j.DailyRollingFileAppender（每天产生一个日志文件），  
org.apache.log4j.RollingFileAppender（文件大小到达指定尺寸的时候产生一个新的文件），  
org.apache.log4j.WriterAppender（将日志信息以流格式发送到任意指定的地方）
```

#### 3.配置日志信息的格式（布局），其语法为：

```properties
log4j.appender.appenderName.layout = fully.qualified.name.of.layout.class  
log4j.appender.appenderName.layout.option1 = value1  
…  
log4j.appender.appenderName.layout.option = valueN
```

其中，Log4j提供的layout有以下几种：

```properties
org.apache.log4j.HTMLLayout（以HTML表格形式布局），  
org.apache.log4j.PatternLayout（可以灵活地指定布局模式），  
org.apache.log4j.SimpleLayout（包含日志信息的级别和信息字符串），  
org.apache.log4j.TTCCLayout（包含日志产生的时间、线程、类别等等信息）
```

Log4J采用类似C语言中的printf函数的打印格式格式化日志信息，打印参数如下： 

```c
%m 输出代码中指定的消息
%p 输出优先级，即DEBUG，INFO，WARN，ERROR，FATAL  
%r 输出自应用启动到输出该log信息耗费的毫秒数  
%c 输出所属的类目，通常就是所在类的全名  
%t 输出产生该日志事件的线程名  
%n 输出一个回车换行符，Windows平台为“rn”，Unix平台为“n”  
%d 输出日志时间点的日期或时间，默认格式为ISO8601，也可以在其后指定格式，比如：%d{yyy MMM dd HH:mm:ss,SSS}，输出类似：2002年10月18日 22：10：28，921  
%l 输出日志事件的发生位置，包括类目名、发生的线程，以及在代码中的行数。举例：Testlog4.main(TestLog4.java:10)
```

### 在代码中使用Log4j

#### 1.得到记录器

```java
//使用Log4j，第一步就是获取日志记录器，这个记录器将负责控制日志信息。其语法为：
public static Logger getLogger( String name)
//通过指定的名字获得记录器，如果必要的话，则为这个名字创建一个新的记录器。Name一般取本类的名字，比如：
static Logger logger = Logger.getLogger ( ServerWithLog4j.class.getName () )
```

#### 2.读取配置文件

```java
//当获得了日志记录器之后，第二步将配置Log4j环境，其语法为：
BasicConfigurator.configure (); //自动快速地使用缺省Log4j环境。  
PropertyConfigurator.configure ( String configFilename);：//读取使用Java的特性文件编写的配置文件。  
DOMConfigurator.configure ( String filename ) ;//读取XML形式的配置文件。
```

#### 3.插入记录信息（格式化日志信息）

当上两个必要步骤执行完毕，您就可以轻松地使用不同优先级别的日志记录语句插入到您想记录日志的任何地方，其语法如下：

```java
Logger.debug ( Object message ) ;  
Logger.info ( Object message ) ;  
Logger.warn ( Object message ) ;  
Logger.error ( Object message ) ;
```

### 日志级别

每个Logger都被了一个日志级别（log level），用来控制日志信息的输出。日志级别从高到低分为：

> off 最高等级，用于关闭所有日志记录。
>
> fatal 指出每个严重的错误事件将会导致应用程序的退出。
>
> error 指出虽然发生错误事件，但仍然不影响系统的继续运行。
>
> warm 表明会出现潜在的错误情形。
>
> info 一般和在粗粒度级别上，强调应用程序的运行全程。
>
> debug 一般用于细粒度级别上，对调试应用程序非常有帮助。
>
> all 最低等级，用于打开所有日志记录。

上面这些级别是定义在`org.apache.log4j.Level`类中。`Log4j`只建议使用4个级别，优先级从高到低分别是`error,warn,info和debug`。通过使用日志级别，可以控制应用程序中相应级别日志信息的输出。例如，如果使用了info级别，则应用程序中所有低于info级别的日志信息(如debug)将不会被打印出来。

# Log4j2使用（推荐）

## 导入依赖

```xml
<!-- https://mvnrepository.com/artifact/org.apache.logging.log4j/log4j-slf4j-impl -->
<dependency>
    <groupId>org.apache.logging.log4j</groupId>
    <artifactId>log4j-slf4j-impl</artifactId>
    <version>2.11.2</version>
</dependency>

<!-- https://mvnrepository.com/artifact/org.apache.logging.log4j/log4j-web -->
<dependency>
    <groupId>org.apache.logging.log4j</groupId>
    <artifactId>log4j-web</artifactId>
    <version>2.11.2</version>
</dependency>

<!-- https://mvnrepository.com/artifact/org.apache.logging.log4j/log4j-jcl -->
<dependency>
    <groupId>org.apache.logging.log4j</groupId>
    <artifactId>log4j-jcl</artifactId>
    <version>2.11.2</version>
</dependency>
```

## 在web.xml添加配置

```xml
  <!-- log4j2-begin-->
  <!--监听器和过滤器-->
  <listener>
    <listener-class>org.apache.logging.log4j.web.Log4jServletContextListener</listener-class>
  </listener>

  <filter>
    <filter-name>log4jServletFilter</filter-name>
    <filter-class>org.apache.logging.log4j.web.Log4jServletFilter</filter-class>
  </filter>
  <filter-mapping>
    <filter-name>log4jServletFilter</filter-name>
    <url-pattern>/*</url-pattern>
    <dispatcher>REQUEST</dispatcher>
    <dispatcher>FORWARD</dispatcher>
    <dispatcher>INCLUDE</dispatcher>
    <dispatcher>ERROR</dispatcher>
  </filter-mapping>

  <context-param>
    <param-name>log4jConfiguration</param-name>
    <param-value>classpath:log4j2.xml</param-value>
  </context-param>
  <!--动态修改log4j2.xml：容器会每60秒扫描log4j的配置文件-->
  <context-param>
    <param-name>log4jRefreshInterval</param-name>
    <param-value>60000</param-value>
  </context-param>
  <!-- log4j2-end -->
```

## 添加logs4j2.xml配置文件

```xml
<?xml version="1.0" encoding="UTF-8"?>
<!--日志级别以及优先级排序: OFF > FATAL > ERROR > WARN > INFO > DEBUG > TRACE > ALL -->
<!--Configuration后面的status，这个用于设置log4j2自身内部的信息输出，可以不设置，当设置成trace时，你会看到log4j2内部各种详细输出-->
<configuration  status="INFO">
    <!-- 变量配置 应该是日志文件保存路径-->
    <Properties>
        <!-- （*必须,各应用需要修改） 部署应用的名称,命名规则 :全部小写字母、中短横线、数字,与微服务命名,disconf中命名一致 -->
        <property name="APPNAME">park-service</property>
        <!-- （各应用需要修改）日志文件本地存放目录路径 建议各个环境跟生产环境统一起来,方便维护 -->
        <!--sys:catalina.home  tomcat的根目录-->
        <Property name="logBaseFolder">${sys:catalina.home}/logs/zcrTest/</Property>
        <!-- *必须并强制遵守 日志文件的编码 -->
        <property name="log_charset">UTF-8</property>
        <!--输出日志格式-->
        <property name="log_pattern">
            %d{yyyy-MM-dd HH:mm:ss} [%t] %-5p %c{1}:%L - %msg%n
        </property>
    </Properties>

    <!--先定义所有的appender-->
    <appenders>
        <!--这个输出控制台的配置-->
        <console name="Console" target="SYSTEM_OUT">
            <!--输出日志的格式 %l :表示某个类-->
            <PatternLayout pattern="[%d{HH:mm:ss:SSS}] [%t] %-5p %c{1}:%L - %msg%n"/>
        </console>

        <!-- 这个会打印出所有的info及以下级别的信息，每次大小超过size，则这size大小的日志会自动存入按年份-月份建立的文件夹下面并进行压缩，作为存档-->
        <RollingFile name="RollingFileInfo" fileName="${logBaseFolder}/${APPNAME}-info.log"
                     filePattern="${logBaseFolder}/%d{yyyy-MM}/${APPNAME}-info-%d{yyyy_MM_dd}.log.gz">
            <ThresholdFilter level="info" onMatch="ACCEPT" onMismatch="DENY"/>
            <!-- 日志输出格式 -->
            <PatternLayout charset="${log_charset}" pattern="${log_pattern}" />
            <!-- 以下是日志压缩包目录的建议格式名称 建议1天归档依次，压缩文件上线建议为200,这里预估每个磁盘存储空间200G左右，每个压缩包最大值200MB -->
            <Policies>
                <TimeBasedTriggeringPolicy  modulate="true" interval="1"/>
                <SizeBasedTriggeringPolicy size="20 MB"/>
            </Policies>
        </RollingFile>

        <RollingFile name="RollingFileError" fileName="${logBaseFolder}/${APPNAME}-error.log"
                     filePattern="${logBaseFolder}/%d{yyyy-MM}/${APPNAME}-error-%d{yyyy_MM_dd}.log.gz">
            <ThresholdFilter level="error" onMatch="ACCEPT" onMismatch="DENY"/>
            <PatternLayout charset="${log_charset}" pattern="${log_pattern}" />
            <Policies>
                <TimeBasedTriggeringPolicy  modulate="true" interval="1"/>
                <SizeBasedTriggeringPolicy size="20 MB"/>
            </Policies>
        </RollingFile>
    </appenders>

    <!--然后定义logger，只有定义了logger并引入的appender，appender才会生效-->
    <loggers>
        <!--过滤掉spring和mybatis的一些无用的DEBUG信息-->
        <logger name="org.springframework" level="INFO"/>
        <logger name="org.mybatis" level="INFO"/>

        <root level="all">
            <appender-ref ref="Console"/>
            <appender-ref ref="RollingFileInfo"/>
            <appender-ref ref="RollingFileError"/>
        </root>
    </loggers>

</configuration>
```

