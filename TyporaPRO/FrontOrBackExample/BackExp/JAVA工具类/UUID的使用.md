# 概念

UUID(Universally Unique Identifier)全局唯一标识符,是指在一台机器上生成的数字，它保证对在同一时空中的所有机器都是唯一的。按照开放软件基金会(OSF)制定的标准计算，用到了以太网卡地址、纳秒级时间、芯片ID码和许多可能的数字。

## 实例：

```java
@Test
    public void getRandomId(){
        
        UUID uuid =UUID.randomUUID();
        System.out.println(uuid);
//        将随机的UUID转换为一串32位的字符
        String s = uuid.toString().replaceAll("-", "");
        System.out.println("32位:"+s);
//        将随机的UUID转换为一串指定位数(8位)的字符串
        String s1 = uuid.toString().replaceAll("-", "").substring(0,8);
        System.out.println("8位:"+s1);
//        将所有字母转换为大小写
        String s2 = uuid.toString().replaceAll("-", "").toUpperCase();
        System.out.println("大写"+s2);
        System.out.println("小写"+s2.toLowerCase());
        
    }
```

