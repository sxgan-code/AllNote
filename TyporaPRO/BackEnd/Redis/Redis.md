# 一、Redis简介

`REmote DIctionary Server`(`Redis`) 是一个由 `Salvatore Sanfilippo` 写的` key-value `存储系统，是跨平台的非关系型数据库。

`Redis `是一个开源的使用` ANSI C `语言编写、遵守` BSD `协议、支持网络、可基于内存、分布式、可选持久性的键值对(`Key-Value`)存储数据库，并提供多种语言的` API`。

`Redis `通常被称为数据结构服务器，因为值（`value`）可以是字符串(`String`)、哈希(`Hash`)、列表(`list`)、集合(`sets`)和有序集合`(sorted sets)`等类型。

基本的数据结构有以下几种：

- String: 字符串
- Hash: 散列
- List: 列表
- Set: 集合
- Sorted Set: 有序集合

## 1、相较于其他产品的特点

Redis 与其他 key - value 缓存产品有以下三个特点：

- Redis支持数据的持久化，可以将内存中的数据保存在磁盘中，重启的时候可以再次加载进行使用。
- Redis不仅仅支持简单的key-value类型的数据，同时还提供list，set，zset，hash等数据结构的存储。
- Redis支持数据的备份，即master-slave模式的数据备份。

## 2、优势

性能极高 – Redis能读的速度是110000次/s,写的速度是81000次/s 。

丰富的数据类型 – Redis支持二进制案例的 Strings, Lists, Hashes, Sets 及 Ordered Sets 数据类型操作。

原子 – Redis的所有操作都是原子性的，意思就是要么成功执行要么失败完全不执行。单个操作是原子性的。多个操作也支持事务，即原子性，通过MULTI和EXEC指令包起来。

丰富的特性 – Redis还支持 publish/subscribe, 通知, key 过期等等特性。

