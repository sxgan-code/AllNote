

导入依赖

```xml
<dependency>
    <groupId>com.github.pagehelper</groupId>
    <artifactId>pagehelper-spring-boot-starter</artifactId>
    <version>1.4.0</version>
</dependency>
```

实现分页

```java
 @RequestMapping("/pageList")
    @ResponseBody
    public List<Book> getList(@Param("pageNum") Integer pageNum,@Param("pageSize") Integer pageSize){
        PageHelper.startPage(pageNum,pageSize);// 注意必须放在查询之前
        List<Book> bookList = bookServer.getBookList();
        PageInfo<Book> bookPageInfo = new PageInfo<>(bookList);
        List<Book> list = bookPageInfo.getList();
        return bookPageInfo.getList();
    }
```

