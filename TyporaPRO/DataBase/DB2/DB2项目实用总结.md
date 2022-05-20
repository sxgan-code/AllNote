# 一、数据类型转换

## 1、varchar类型转int并排序

```sql
 -- id varchar(20),可以为null
 select id from table order by cast(COALESCE(id,'0') as int)
```

