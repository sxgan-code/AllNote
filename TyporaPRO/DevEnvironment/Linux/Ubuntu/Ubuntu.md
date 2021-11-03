# 一、Ubuntu配置

## 1、查看电脑参数

### 查看位数

```sh
getconf LONG_BIT
```

### 查看CPU

```sh
cat /proc/cpuinfo 
```

### 查看内存

```sh
free -m
```

### 查看硬盘分区

```sh
fdisk -l
```

### 查看网卡信息或者ip地址

```sh
ifconfig
```

### 查看详细的网卡工作模式

```sh
ethtool eth0
```

## 2、常用命令

```sh
# 清屏
clear

```

