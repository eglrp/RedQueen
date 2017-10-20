
# [【Mysql】从删库到跑路（全20讲）](https://www.bilibili.com/video/av5354244/?from=search&seid=16355277560660555238)的前5讲笔记：

## 字符串类型：

类型     | 说明
-------- | ---
char 	| 固定字符串长度
varchar  | 可变长度字符串
text    | 大文本
enum	| 枚举类型(只能取一个元素)
set		|集合类型(能取多个元素)

## 数据库简介

- 显示所有数据库：show databases;
- 创建数据库：create database XXX;
- 删除数据库：drop database;

## 数据库基本操作

- 创建表
表是数据库存储数据的基本单位。一个表包含若干个字段或记录；
语法：
CREATE TABLE 表名(	属性名 数据类型 [完整约束条件],
					属性名 数据类型 [完整约束条件],
					.
					.
					属性名 数据类型 [完整约束条件]
);

约束条件     | 说明
-------- | ---
primary key 	| 表示该属性为该表的主键，可以唯一的标识对应的记录
foreign key  | 标识该属性为该表的外键，与某表的主键关联
not null    | 标识该属性不能为空
unique	| 标识该属性不能为空
auto_increment		| 标识该属性的值自动增加
default	| 为该属性设置默认值

(不区分大小写)
CREATE TABLE t_booktype(
	id int primary key auto_increment,
	bookTypeName varchar(20),
	bookTypeDesc varchar(200)
);

CREATE TABLE t_book(
	id int primary key auto_increment,
	bookName varchar(20),
	author varchar(10),
	price decimal(6,2),
	bookTypeID int,
	constraint `fk` foreign key (`bookTypeID`) references `t_booktype` (`id`)
);
- 查看表结构
1.查看基本表结构：desc 表名;
desc t_book;
2.查看表详细结构：show create table 表名;
show create table t_booktype;

- 修改表
1.修改表名：alter table t_book rename t_book2;

2.修改字段：alter table t_book2 change bookName bookName2 varchar(20);

3.增加字段：alter table t_book2 add testField int after author;

4.删除字段：alter table t_book2 drop testField;

- 删除表
1.删除表 drop table 表名;

## 查询数据：单表查询

create table `t_student`(
	`id` double,
	`stuName` varchar(80),
	`age` double,
	`sex` varchar(30),
	`gradeName` varchar(60)
);

insert into `t_student` (`id`, `stuName`, `age`, `sex`, `gradeName`) value('1', 'zhangyi','21','male','first');
insert into `t_student` (`id`, `stuName`, `age`, `sex`, `gradeName`) value('2', 'zhanger','22','female','second');
insert into `t_student` (`id`, `stuName`, `age`, `sex`, `gradeName`) value('3', 'zahngsan','23','male','third');
insert into `t_student` (`id`, `stuName`, `age`, `sex`, `gradeName`) value('4', 'zhangsi','21',NULL,'second');
insert into `t_student` (`id`, `stuName`, `age`, `sex`, `gradeName`) value('5', 'zhangwu','24',NULL,'second');

- 查询所有字段
1.select 字段1，字段2，字段3...from 表名;
2.select * from 表名;

- 查询指定字段
1.select 字段1，字段2，字段3...from表名；

- Where条件查询
1.select 字段1，字段2，字段3...from表名 where 条件表达式

- 带IN关键字查询
1.select 字段1，字段2，字段3...from 表名 where 字段 [NOT]in(元素1，元素2，元素3);

- 带BETWEEN AND 的范围查询
1.select 字段1，字段2，字段3...from 表名 where 字段 [NOT]between 取值1 and 取值2;

- 带LIKE的模糊查询
1.select 字段1，字段2，字段3...from 表名 where 字段 [NOT] like "字符串";
"%" 代表任意字符;
"_" 代表单个字符;

- 空值查询
1.select 字段1，字段2，字段3...from 表名 where 字段 is [NOT] NULL;

- 带AND的多条件查询
1.select 字段1，字段2...from 表名 where 条件表达式1 and 条件表达式2 [...AND 条件表达式 n];

- 带OR的多条件查询
1.select 字段1，字段2,...from 表名 where 条件表达式1 or 条件表达式2 [...OR 条件表达式 n];

- DISTINCT去重复查询
1.select distinct 字段名 from 表名;



