## 前言

[官方文档](https://swagger.io/docs/)

`Swagger`是一个可以根据你的代码，自动生成接口文档的一个工具，并且可以用作接口测试工具

如果你使用的是 Springboot 2.6 版本，需要配置，否则报下面的错，现在 Springboot 3.0 和 Springboot 2.5.8 不需要配置下面这

```
Caused by: java.lang.NullPointerException: Cannot invoke "org.springframework.web.servlet.mvc.condition.PatternsRequestCondition.getPatterns()" because "this.condition" is null
```

spring:

这个mvc的配置是springboot2.6.1不支持swagger3的折衷配置，后面考虑升级Springboot版本或降级版本

```yml
  mvc:
    pathmatch:
      matching-strategy: ant_path_matcher
```

## 引入依赖

`Swagger 3.0`版本只需要引入这一个依赖

```xml
<!-- https://mvnrepository.com/artifact/io.springfox/springfox-boot-starter -->
<dependency>
    <groupId>io.springfox</groupId>
    <artifactId>springfox-boot-starter</artifactId>
    <version>3.0.0</version>
</dependency>
```

## 添加配置类

```java
/**
 * Swagger3配置
 * 如果使用了springboot2.6.1 还需在application.yml中配置mvc，因为springboot2.6.1与swagger3不兼容
 * @author GanShaoXi
 * @versions 1.0.0
 */
@SpringBootConfiguration
@EnableOpenApi
public class Swagger3Config {
    /**
     * ture 启用Swagger3.0， false 禁用（生产环境要禁用）
     */
    Boolean swaggerEnabled = true;
    
    @Bean
    public Docket createRestApi() {
        return new Docket(DocumentationType.OAS_30)
                .apiInfo(apiInfo())
                // 是否开启
                .enable(swaggerEnabled)
                .select()
                // 扫描的路径使用@Api的controller
                .apis(RequestHandlerSelectors.withMethodAnnotation(ApiOperation.class))
                // 指定路径处理PathSelectors.any()代表所有的路径
                .paths(PathSelectors.any())
                .build();
    }
    
    private ApiInfo apiInfo() {
        return new ApiInfoBuilder()
                .title("Swagger3接口文档")
                .description("Danel音乐软件接口文档")
                //作者信息
                .contact(new Contact("Daniel", "https://daniel-0510.github.io/", "1019232598@qq.com"))
                .version("1.0")
                .build();
    }
}
```

## 添加接口类描述

在类上添加注解 `@Api(tags = "客户端登录与注册接口")`注解，tags里面是你对这个 controller类 的描述

```java
@Api(tags = "客户端登录与注册接口")
@Controller
public class LoginController {
    // ......
}
```

## 添加接口描述

```java
@ApiOperation("客户端账号密码登录校验")
@RequestMapping(value = "/client/login",method = RequestMethod.POST)
@ResponseBody
public ResultMap verifyClientLogin(@RequestBody Map<String,String> maps) {
    String email = maps.get("logemail");
    String password = maps.get("logpass");
    ResultMap resultMap = consumerService.verifyLogin(email, password);
    return resultMap;
}
```

## 添加实体类描述

实体类也可以增加注解，也可以不加，主要是 controller 加就行

实体类上面增加`@ApiModel(value = "Blog", description = "社区交流、匿名举报帖子实体类")`，下面的字段增加

`@ApiModelProperty(value = "主键")`，value 是 Swagger 生成的文档中显示的名字，description 是你对实体类的描述

```java
@ApiModel(value = "Admin", description = "管理用户信息实体类")
@Component
public class Admin {
    @ApiModelProperty(value = "主键")
    private Integer id;
    @ApiModelProperty(value = "管理用户名")
    private String name;
    @ApiModelProperty(value = "管理用户密码")
    private String password;
}
```

启动项目，访问http://localhost:9090/music/api/swagger-ui/，`/music/api/`为项目配置的`context-path`