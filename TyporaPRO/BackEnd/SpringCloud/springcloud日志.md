## Spring Boot Logging 配置（记录）

我用到的配置

```yml
logging:
  level:
    root: debug
  file:
    path: ./log/${spring.application.name}_${server.port}
  pattern:
    file: '%d{yyyy/MM/dd HH:mm:ss.SSS} %clr(%-5level) [%magenta(%thread)] %cyan(%logger{15}) : %msg%n'
    console: '%d{yyyy/MM/dd HH:mm:ss.SSS} %clr(%-5level) [%magenta(%thread)] %cyan(%logger{15}) : %msg%n'
```

**百分号格式化解释：**

-  %d：日期，大括号里面为日期的显示格式；
- %clr()： 根据内容显示不同颜色的的方法，一般是给“日志级别”这个信息使用的；
- %level：日志级别，百分号和关键字中间的短杠和数字（-5）表示显示这么多个字符的宽度，内容不足则补充空格占位；
- %magenta()：将内容显示为品红色字体。显示为其他颜色可以参考这个图，注意看图中绿色字体;
- (%thread)：线程名;
- %cyan：将内容显示为青色字体;
- %logger：事件发生的位置的所在类的全类名；
- %line：事件发生的位置的行号；
- %msg：事件信息；
- %n：换行，输出跨操作系统的换行符号；

**配置参数：**

- logging.level.* : 作为package（包）的前缀来设置日志级别。
- logging.file :配置日志输出的文件名，也可以配置文件名的绝对路径。
- logging.path :配置日志的路径。如果没有配置logging.file,Spring Boot 将默认使用spring.log作为文件名。
- logging.pattern.console :定义console中logging的样式。
- logging.pattern.file :定义文件中日志的样式。
- logging.pattern.level :定义渲染不同级别日志的格式。默认是%5p.
- logging.exception-conversion-word :.定义当日志发生异常时的转换字
- PID :定义当前进程的ID

#### logging.level

logging.level设置日志级别。我们可以使用TARCE , DEBUG , INFO , WARN , ERROR , FATAL , OFF 。可以使用root级别和package级别来控制日志的输入级别。创建一个具有以下依赖关系的应用程序。

#### logging.file

Spring Boot 默认把日志输入到console，如果我们要把日志输入到文件中，需要配置logging.file 或者logging.path属性性。logging.file属性用来定义文件名。他不仅仅可以配置文件名，也可以路径+文件名。

#### **logging.path**

配置logging.path或者logging.path属性将日志输出到文件夹中。logging.path属性用来定义日志文件路径。

#### logging.patter.console

通过设置logging.patter.console属性我们能改变输出到console的日志样式。日志样式包括时间，日志级别，线程名，日志名以及消息。我们可以按我们的喜好改变日志样式

#### logging.pattern.file

改变文件中的日志样式我们需要设置logging.pattern.file属性。首先通过logging.file或logging.path属性，把日志记录到文件中。