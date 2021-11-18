# 环境准备

## 前端准备

```sh
创建项目
vue create fileup
cd fileup

npm install axios -S
npm install element-ui -S

npm install vue-router -S
```

main.js导入elementui

```js
import Vue from 'vue'
import App from './App.vue'

import ElementUI from 'element-ui';
import 'element-ui/lib/theme-chalk/index.css';
import VueRouter from 'vue-router'

Vue.use(ElementUI,VueRouter);

Vue.config.productionTip = false

new Vue({
  render: h => h(App),
}).$mount('#app')

```

路由控制

```js
import Vue from 'vue'
import Router from 'vue-router'

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/',
      component: resolve => require(['../pages/Login.vue'], resolve)
    },
    {
      path: '/home',
      component: resolve => require(['../components/Home.vue'], resolve),
      children:[
        {
          path:'/main',
          component: resolve => require(['../pages/mainPage.vue'], resolve),
        },
        {
          path:'/Consumer',
          component: resolve => require(['../pages/ConsumerPage.vue'], resolve),
        },
        {
          path:'/Singer',
          component: resolve => require(['../pages/SingerPage.vue'], resolve),
        },
        {
          path:'/SongList',
          component: resolve => require(['../pages/SongListPage.vue'], resolve),
        },
        {
          name:'SingerManage',
          path:'/SingerManage/:singerId',
          props: true,
          component: resolve => require(['../pages/SingerManage.vue'], resolve),
        },
      ]
    }
  ]
})

```



## 后端准备

### 导入依赖

```xml
<!--mybatis-plus-->
<dependency>
    <groupId>com.baomidou</groupId>
    <artifactId>mybatis-plus-boot-starter</artifactId>
    <version>3.4.3.1</version>
</dependency>

<!--Jackson包-->
<dependency>
    <groupId>com.fasterxml.jackson.core</groupId>
    <artifactId>jackson-databind</artifactId>
    <version>2.12.4</version>
</dependency>

<!--mysql Driver-->
<dependency>
    <groupId>mysql</groupId>
    <artifactId>mysql-connector-java</artifactId>
    <version>8.0.27</version>
</dependency>
```

### 配置文件

```yml
server:
  port: 9090
  servlet:
    context-path: /file

spring:
  # mysql 配置
  datasource:
    driver-class-name: com.mysql.cj.jdbc.Driver
    url: jdbc:mysql://localhost:3306/daniel?serverTimezone=UTC
    username: root
    password: root123

mybatis-plus:
  type-aliases-package: com.daniel.file.entity
  mapper-locations: classpath:mapperxml/*Mapper.xml
```

```properties
# Spring Boot1.4版本后配置更改为:

spring.http.multipart.maxFileSize = 10Mb  
spring.http.multipart.maxRequestSize=100Mb  
#Spring Boot2.0之后的版本配置修改为:

spring.servlet.multipart.max-file-size = 10MB  
spring.servlet.multipart.max-request-size=100MB
```



# 文件上传

