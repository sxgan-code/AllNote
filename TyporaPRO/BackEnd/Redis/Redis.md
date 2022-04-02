# 一、Redis简介

`REmote DIctionary Server`(`Redis 远程字典服务`) 是一个由 `Salvatore Sanfilippo` 写的` key-value `存储系统，是跨平台的非关系型数据库。

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

丰富的数据类型 – Redis支持二进制案例的 `Strings, Lists, Hashes, Sets `及 `Ordered Sets `数据类型操作。

原子 – Redis的所有操作都是原子性的，意思就是要么成功执行要么失败完全不执行。单个操作是原子性的。多个操作也支持事务，即原子性，通过`MULTI`和`EXEC`指令包起来。

丰富的特性 – `Redis`还支持 `publish/subscribe,` 通知, `key `过期等等特性。



# 二、Redis常用命令

## 1、Redis 配置

`Redis `的配置文件位于 `Redis `安装目录下，文件名为 **`redis.conf`**(Windows 名为 `redis.windows.conf`)。

你可以通过 `CONFIG`命令查看

```sh
# 语法
config get CONFIG_SETTING_NAME
# 例如获取所有配置
127.0.0.1:6379> config get *
```

### 编辑配置-配置密码

```sh
# 语法
config set CONFIG_SETTING_NAME NEW_CONFIG_VALUE
# 例如更改密码
127.0.0.1:6379> config set requirepass Daniel2118
OK
# 当设置密码后需要登录才能使用，提示如下：
127.0.0.1:6379> config get *
(error) NOAUTH Authentication required.
# 此时输入密码即可
127.0.0.1:6379> Auth Daniel2118
OK
```

### 配置说明

```shell
daemonize no	
# Redis 默认不是以守护进程的方式运行，可以通过该配置项修改，使用 yes 启用守护进程（Windows 不支持守护线程的配置为 no ）

pidfile /var/run/redis.pid	
#当 Redis 以守护进程方式运行时，Redis 默认会把 pid 写入 /var/run/redis.pid 文件，可以通过 pidfile 指定

port 6379	
#指定 Redis 监听端口，默认端口为 6379，作者在自己的一篇博文中解释了为什么选用 6379 作为默认端口，因为 6379 在手机按键上 MERZ 对应的号码，而 MERZ 取自意大利歌女 Alessia Merz 的名字

bind 127.0.0.1	
# 绑定的主机地址

timeout 300	
#当客户端闲置多长秒后关闭连接，如果指定为 0 ，表示关闭该功能
	
loglevel notice	
#指定日志记录级别，Redis 总共支持四个级别：debug、verbose、notice、warning，默认为 notice

logfile stdout	
#日志记录方式，默认为标准输出，如果配置 Redis 为守护进程方式运行，而这里又配置为日志记录方式为标准输出，则日志将会发送给 /dev/null

databases 16	
#设置数据库的数量，默认数据库为0，可以使用SELECT 命令在连接上指定数据库id
	
save <seconds> <changes>
#指定在多长时间内，有多少次更新操作，就将数据同步到数据文件，可以多个条件配合
#默认配置文件中提供了三个条件：分别表示
save 900 1 #900 秒（15 分钟）内有 1 个更改
save 300 10 #300 秒（5 分钟）内有 10 个更改
save 60 10000 # 60 秒内有 10000 个更改

rdbcompression yes	
#指定存储至本地数据库时是否压缩数据，默认为 yes，Redis 采用 LZF 压缩，如果为了节省 CPU 时间，可以关闭该选项，但会导致数据库文件变的巨大

dbfilename dump.rdb	
#指定本地数据库文件名，默认值为 dump.rdb

dir ./	
#指定本地数据库存放目录

slaveof <masterip> <masterport>	
#设置当本机为 slave 服务时，设置 master 服务的 IP 地址及端口，在 Redis 启动时，它会自动从 master 进行数据同步

masterauth <master-password>	
#当 master 服务设置了密码保护时，slave 服务连接 master 的密码

requirepass foobared	
#设置 Redis 连接密码，如果配置了连接密码，客户端在连接 Redis 时需要通过 AUTH <password> 命令提供密码，默认关闭

maxclients 128	
#设置同一时间最大客户端连接数，默认无限制，Redis 可以同时打开的客户端连接数为 Redis 进程可以打开的最大文件描述符数，如果设置 maxclients 0，表示不作限制。当客户端连接数到达限制时，Redis 会关闭新的连接并向客户端返回 max number of clients reached 错误信息
	
maxmemory <bytes>	
#指定 Redis 最大内存限制，Redis 在启动时会把数据加载到内存中，达到最大内存后，Redis 会先尝试清除已到期或即将到期的 Key，当此方法处理 后，仍然到达最大内存设置，将无法再进行写入操作，但仍然可以进行读取操作。Redis 新的 vm 机制，会把 Key 存放内存，Value 会存放在 swap 区

appendonly no	
#指定是否在每次更新操作后进行日志记录，Redis 在默认情况下是异步的把数据写入磁盘，如果不开启，可能会在断电时导致一段时间内的数据丢失。因为 redis 本身同步数据文件是按上面 save 条件来同步的，所以有的数据会在一段时间内只存在于内存中。默认为 no

appendfilename appendonly.aof	
#指定更新日志文件名，默认为 appendonly.aof
	
appendfsync everysec	
#指定更新日志条件，共有 3 个可选值：
#no：表示等操作系统进行数据缓存同步到磁盘（快）
#always：表示每次更新操作后手动调用 fsync() 将数据写到磁盘（慢，安全）
#everysec：表示每秒同步一次（折中，默认值）
	
vm-enabled no	
#指定是否启用虚拟内存机制，默认值为 no，简单的介绍一下，VM 机制将数据分页存放，由 Redis 将访问量较少的页即冷数据 swap 到磁盘上，访问多的页面由磁盘自动换出到内存中（在后面的文章我会仔细分析 Redis 的 VM 机制）
	
vm-swap-file /tmp/redis.swap	
#虚拟内存文件路径，默认值为 /tmp/redis.swap，不可多个 Redis 实例共享
	
vm-max-memory 0	
#将所有大于 vm-max-memory 的数据存入虚拟内存，无论 vm-max-memory 设置多小，所有索引数据都是内存存储的(Redis 的索引数据 就是 keys)，也就是说，当 vm-max-memory 设置为 0 的时候，其实是所有 value 都存在于磁盘。默认值为 0

vm-page-size 32	
#Redis swap 文件分成了很多的 page，一个对象可以保存在多个 page 上面，但一个 page 上不能被多个对象共享，vm-page-size 是要根据存储的 数据大小来设定的，作者建议如果存储很多小对象，page 大小最好设置为 32 或者 64bytes；如果存储很大大对象，则可以使用更大的 page，如果不确定，就使用默认值
	
vm-pages 134217728	
#设置 swap 文件中的 page 数量，由于页表（一种表示页面空闲或使用的 bitmap）是在放在内存中的，，在磁盘上每 8 个 pages 将消耗 1byte 的内存。
	
vm-max-threads 4	
#设置访问swap文件的线程数,最好不要超过机器的核数,如果设置为0,那么所有对swap文件的操作都是串行的，可能会造成比较长时间的延迟。默认值为4

glueoutputbuf yes	
#设置在向客户端应答时，是否把较小的包合并为一个包发送，默认为开启

hash-max-zipmap-entries 64
hash-max-zipmap-value 512	
#指定在超过一定的数量或者最大的元素超过某一临界值时，采用一种特殊的哈希算法

activerehashing yes	
#指定是否激活重置哈希，默认为开启（后面在介绍 Redis 的哈希算法时具体介绍）
	
include /path/to/local.conf	
#指定包含其它的配置文件，可以在同一主机上多个Redis实例之间使用同一份配置文件，而同时各个实例又拥有自己的特定配置文件
```

## 2、数据类型

Redis支持五种数据类型：`string`（字符串），`hash`（哈希），`list`（列表），`set`（集合）及`zset`(`sorted set`：有序集合)。

### String（字符串）

string 是 redis 最基本的类型，你可以理解成与 Memcached 一模一样的类型，一个 `key `对应一个 `value`。

string 类型是二进制安全的。意思是 redis 的 string 可以包含任何数据。比如jpg图片或者序列化的对象。

string 类型是 Redis 最基本的数据类型，string 类型的值最大能存储` 512MB`

```sh
# 语法
set key value
# 示例：
# 添加
127.0.0.1:6379> set key 'daniel'
OK
# 获取
127.0.0.1:6379> get key
"daniel"
# 删除
127.0.0.1:6379> del key
(integer) 1
```

### Hash（哈希）

`Redis hash` 是一个键值(`key=>value`)对集合。

`Redis hash` 是一个 `string `类型的 `field `和 `value `的映射表，`hash `特别适合用于存储对象。

```sh
# 语法
hmset field 'value' [field 'value' ...]
# 示例：
# 添加
127.0.0.1:6379> hmset hmsettest f1 'v1' f2 'v2'
OK
# 查看
127.0.0.1:6379> hget hmsettest f1
"v1"
127.0.0.1:6379> hget hmsettest f2
"v2"
# 删除
127.0.0.1:6379> del hmsettest
(integer) 1
```

Redis `HMSET`, `HGET`命令，`HMSET`*设置了两个` field=>value `对, HGET 获取对应 **`field`** 对应的 **`value`**。

每个 `hash `可以存储 ${2^{32} -1} $键值对（40多亿）。

### List（列表）

Redis 列表是简单的字符串列表，按照插入顺序排序。你可以添加一个元素到列表的头部（左边）或者尾部（右边）

```shell
# 示例
127.0.0.1:6379> lpush list java
(integer) 1
127.0.0.1:6379> lpush list c
(integer) 2
127.0.0.1:6379> lpush list spring
(integer) 3
127.0.0.1:6379> lpush list springmvc
(integer) 4
127.0.0.1:6379> lpush list springboot
(integer) 5
127.0.0.1:6379> lpush list springcloud
(integer) 6
127.0.0.1:6379> lpush list nocs
(integer) 7
# 查看 0-5
127.0.0.1:6379> lrange list 0 5
1) "nocs"
2) "springcloud"
3) "springboot"
4) "springmvc"
5) "spring"
6) "c"
```

列表最多可存储 ${2^{32}-1}$元素 (`4294967295`, 每个列表可存储`40`多亿)

### Set（集合）

`Redis `的 `Set `是 `string `类型的无序集合。

集合是通过哈希表实现的，所以添加，删除，查找的复杂度都是` O(1)`

#### sadd 命令

添加一个 `string `元素到 `key `对应的 `set `集合中，成功返回 `1`，如果元素已经在集合中返回` 0`

```sh
# 示例
127.0.0.1:6379> sadd set redis
(integer) 1
127.0.0.1:6379> sadd set a
(integer) 1
127.0.0.1:6379> sadd set b
(integer) 1
127.0.0.1:6379> sadd set c
(integer) 1
127.0.0.1:6379> sadd set a
(integer) 0
# 查看
127.0.0.1:6379> smembers set
1) "a"
2) "redis"
3) "c"
4) "b"
127.0.0.1:6379>
```

==注意==：以上实例中 `rabbitmq `添加了两次，但根据集合内`元素的唯一性`，第二次插入的元素将被忽略。

集合中最大的成员数为${2^{23}-1}$(4294967295, 每个集合可存储40多亿个成员)。

#### zset(sorted set：有序集合)

Redis `zset `和 `set `一样也是`string`类型元素的集合,且`不允许重复`的成员。

不同的是每个元素都会关联一个`double`类型的分数。redis正是通过分数来为集合中的成员进行从小到大的排序。

`zset`的成员是`唯一`的,但分数(`score`)却可以重复

```sh
# 示例
127.0.0.1:6379> zadd zset  0 a
(integer) 1
127.0.0.1:6379> zadd zset 1 b
(integer) 1
127.0.0.1:6379> zadd zset 0 c
(integer) 1
127.0.0.1:6379> zadd zset 0 d
(integer) 1
# 查看
127.0.0.1:6379> zrangebyscore zset 0 2
1) "a"
2) "c"
3) "d"
4) "b"
```

# 三、Redis命令详解

## 1、启动命令

Redis 命令用于在 redis 服务上执行操作。

要在 redis 服务上执行命令需要一个 redis 客户端。Redis 客户端在我们之前下载的的 redis 的安装包中。

Redis 客户端的基本语法为：

```sh
$ redis-cli
```

以下实例讲解了如何启动 redis 客户端：

启动 redis 服务器，打开终端并输入命令 **redis-cli**，该命令会连接本地的 redis 服务。

```sh
$ redis-cli
redis 127.0.0.1:6379>
redis 127.0.0.1:6379> PING
PONG
```

在以上实例中我们连接到本地的 redis 服务并执行 **PING** 命令，该命令用于检测 redis 服务是否启动。

#### 在远程服务上执行命令

如果需要在远程 redis 服务上执行命令，同样我们使用的也是 **redis-cli** 命令。

```sh
$ redis-cli -h host -p port -a password
```



以下实例演示了如何连接到主机为 127.0.0.1，端口为 6379 ，密码为 mypass 的 redis 服务上。

```sh
$redis-cli -h 127.0.0.1 -p 6379 -a "mypass"
redis 127.0.0.1:6379>
redis 127.0.0.1:6379> PING

PONG
```

## 2、字符串命令

下表列出了常用的 redis 字符串命令：

```sh
1	SET key value
#设置指定 key 的值。
2	GET key
#获取指定 key 的值。
3	GETRANGE key start end
#返回 key 中字符串值的子字符
4	GETSET key value
#将给定 key 的值设为 value ，并返回 key 的旧值(old value)。
5	GETBIT key offset
#对 key 所储存的字符串值，获取指定偏移量上的位(bit)。
6	MGET key1 [key2..]
#获取所有(一个或多个)给定 key 的值。
7	SETBIT key offset value
#对 key 所储存的字符串值，设置或清除指定偏移量上的位(bit)。
8	SETEX key seconds value
#将值 value 关联到 key ，并将 key 的过期时间设为 seconds (以秒为单位)。
9	SETNX key value
#只有在 key 不存在时设置 key 的值。
10	SETRANGE key offset value
#用 value 参数覆写给定 key 所储存的字符串值，从偏移量 offset 开始。
11	STRLEN key
#返回 key 所储存的字符串值的长度。
12	MSET key value [key value ...]
#同时设置一个或多个 key-value 对。
13	MSETNX key value [key value ...]
#同时设置一个或多个 key-value 对，当且仅当所有给定 key 都不存在。
14	PSETEX key milliseconds value
##这个命令和 SETEX 命令相似，但它以毫秒为单位设置 key 的生存时间，而不是像 SETEX 命令那样，以秒为单位。
15	INCR key
#将 key 中储存的数字值增一。
16	INCRBY key increment
#将 key 所储存的值加上给定的增量值（increment） 。
17	INCRBYFLOAT key increment
#将 key 所储存的值加上给定的浮点增量值（increment） 。
18	DECR key
#将 key 中储存的数字值减一。
19	DECRBY key decrement
#key 所储存的值减去给定的减量值（decrement） 。
20	APPEND key value
#如果 key 已经存在并且是一个字符串， APPEND 命令将指定的 value 追加到该 key 原来值（value）的末尾。
```

## 3、hash 命令

下表列出了 redis hash 基本的相关命令

```sh
1	HDEL key field1 [field2]
#删除一个或多个哈希表字段
2	HEXISTS key field
#查看哈希表 key 中，指定的字段是否存在。
3	HGET key field
#获取存储在哈希表中指定字段的值。
4	HGETALL key
#获取在哈希表中指定 key 的所有字段和值
5	HINCRBY key field increment
#为哈希表 key 中的指定字段的整数值加上增量 increment 。
6	HINCRBYFLOAT key field increment
#为哈希表 key 中的指定字段的浮点数值加上增量 increment 。
7	HKEYS key
#获取所有哈希表中的字段
8	HLEN key
#获取哈希表中字段的数量
9	HMGET key field1 [field2]
#获取所有给定字段的值
10	HMSET key field1 value1 [field2 value2 ]
#同时将多个 field-value (域-值)对设置到哈希表 key 中。
11	HSET key field value
#将哈希表 key 中的字段 field 的值设为 value 。
12	HSETNX key field value
#只有在字段 field 不存在时，设置哈希表字段的值。
13	HVALS key
#获取哈希表中所有值。
14	HSCAN key cursor [MATCH pattern] [COUNT count]
#迭代哈希表中的键值对。
```



## 3、列表（List）命令

下表列出了列表相关的基本命令

```sh
1	BLPOP key1 [key2 ] timeout
#移出并获取列表的第一个元素， 如果列表没有元素会阻塞列表直到等待超时或发现可弹出元素为止。
2	BRPOP key1 [key2 ] timeout
#移出并获取列表的最后一个元素， 如果列表没有元素会阻塞列表直到等待超时或发现可弹出元素为止。
3	BRPOPLPUSH source destination timeout
#从列表中弹出一个值，将弹出的元素插入到另外一个列表中并返回它； 如果列表没有元素会阻塞列表直到等待超时或发现可弹出元素为止。
4	LINDEX key index
#通过索引获取列表中的元素
5	LINSERT key BEFORE|AFTER pivot value
#在列表的元素前或者后插入元素
6	LLEN key
#获取列表长度
7	LPOP key
#移出并获取列表的第一个元素
8	LPUSH key value1 [value2]
#将一个或多个值插入到列表头部
9	LPUSHX key value
#将一个值插入到已存在的列表头部
10	LRANGE key start stop
#获取列表指定范围内的元素
11	LREM key count value
#移除列表元素
12	LSET key index value
#通过索引设置列表元素的值
13	LTRIM key start stop
#对一个列表进行修剪(trim)，就是说，让列表只保留指定区间内的元素，不在指定区间之内的元素都将被删除。
14	RPOP key
#移除列表的最后一个元素，返回值为移除的元素。
15	RPOPLPUSH source destination
#移除列表的最后一个元素，并将该元素添加到另一个列表并返回
16	RPUSH key value1 [value2]
#在列表中添加一个或多个值
17	RPUSHX key value
#为已存在的列表添加值
```

## 4、集合命令

下表列出了 Redis 集合基本命令

```sh
1	SADD key member1 [member2]
#向集合添加一个或多个成员
2	SCARD key
#获取集合的成员数
3	SDIFF key1 [key2]
#返回第一个集合与其他集合之间的差异。
4	SDIFFSTORE destination key1 [key2]
#返回给定所有集合的差集并存储在 destination 中
5	SINTER key1 [key2]
#返回给定所有集合的交集
6	SINTERSTORE destination key1 [key2]
#返回给定所有集合的交集并存储在 destination 中
7	SISMEMBER key member
#判断 member 元素是否是集合 key 的成员
8	SMEMBERS key
#返回集合中的所有成员
9	SMOVE source destination member
#将 member 元素从 source 集合移动到 destination 集合
10	SPOP key
#移除并返回集合中的一个随机元素
11	SRANDMEMBER key [count]
#返回集合中一个或多个随机数
12	SREM key member1 [member2]
#移除集合中一个或多个成员
13	SUNION key1 [key2]
#返回所有给定集合的并集
14	SUNIONSTORE destination key1 [key2]
#所有给定集合的并集存储在 destination 集合中
15	SSCAN key cursor [MATCH pattern] [COUNT count]
#迭代集合中的元素
```

## 5、有序集合命令

下表列出了 redis 有序集合的基本命令

```sh
1	ZADD key score1 member1 [score2 member2]
#向有序集合添加一个或多个成员，或者更新已存在成员的分数
2	ZCARD key
#获取有序集合的成员数
3	ZCOUNT key min max
#计算在有序集合中指定区间分数的成员数
4	ZINCRBY key increment member
#有序集合中对指定成员的分数加上增量 increment
5	ZINTERSTORE destination numkeys key [key ...]
#计算给定的一个或多个有序集的交集并将结果集存储在新的有序集合 destination 中
6	ZLEXCOUNT key min max
#在有序集合中计算指定字典区间内成员数量
7	ZRANGE key start stop [WITHSCORES]
#通过索引区间返回有序集合指定区间内的成员
8	ZRANGEBYLEX key min max [LIMIT offset count]
#通过字典区间返回有序集合的成员
9	ZRANGEBYSCORE key min max [WITHSCORES] [LIMIT]
#通过分数返回有序集合指定区间内的成员
10	ZRANK key member
#返回有序集合中指定成员的索引
11	ZREM key member [member ...]
#移除有序集合中的一个或多个成员
12	ZREMRANGEBYLEX key min max
#移除有序集合中给定的字典区间的所有成员
13	ZREMRANGEBYRANK key start stop
#移除有序集合中给定的排名区间的所有成员
14	ZREMRANGEBYSCORE key min max
#移除有序集合中给定的分数区间的所有成员
15	ZREVRANGE key start stop [WITHSCORES]
#返回有序集中指定区间内的成员，通过索引，分数从高到低
16	ZREVRANGEBYSCORE key max min [WITHSCORES]
#返回有序集中指定分数区间内的成员，分数从高到低排序
17	ZREVRANK key member
#返回有序集合中指定成员的排名，有序集成员按分数值递减(从大到小)排序
18	ZSCORE key member
#返回有序集中，成员的分数值
19	ZUNIONSTORE destination numkeys key [key ...]
#计算给定的一个或多个有序集的并集，并存储在新的 key 中
20	ZSCAN key cursor [MATCH pattern] [COUNT count]
#迭代有序集合中的元素（包括元素成员和元素分值）
```

# 四、Redis的发布订阅

Redis 发布订阅 (`pub/sub`) 是一种消息通信模式：发送者 (pub) 发送消息，订阅者 (sub) 接收消息























