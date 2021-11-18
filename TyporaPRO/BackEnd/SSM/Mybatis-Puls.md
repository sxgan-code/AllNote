一、

导入依赖

```xml
<dependency>
    <groupId>com.baomidou</groupId>
    <artifactId>mybatis-plus-boot-starter</artifactId>
    <version>Latest Version</version>
</dependency>
```

导入配置

```yml
spring:
  # mysql 配置
  datasource:
    driver-class-name: com.mysql.cj.jdbc.Driver
    url: jdbc:mysql://rm-2ze5r466gf23tkopqqo.mysql.rds.aliyuncs.com:3306/daniel?serverTimezone=UTC
    username: daniel
    password: Daniel2118
mybatis-plus:
  type-aliases-package: com.daniel.file.entity
  mapper-locations: classpath:mapperxml/*Mapper.xml
  configuration:
    # 是否开启自动驼峰命名规则（camel case）映射，即从经典数据库列名 A_COLUMN（下划线命名） 到经典 Java 属性名 aColumn（驼峰命名） 的类似映射,注意实体类标明表名通过注解 @TableName()
    map-underscore-to-camel-case: false
```

