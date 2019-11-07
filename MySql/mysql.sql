create table tb5(
id smallint unsigned auto_increment primary key,
username varchar(20) not null unique key,
age tinyint unsigned);

create table tb6(
id smallint unsigned auto_increment primary key,
username varchar(20) not null unique key,
sex enum('1','2','3') default '3');

insert tb6(username) values('tom');

外键约束的要求
1.父表和子表必须使用相同的存储引擎，而且禁止 使用临时表。
2.数据表的存储引擎只能位InnoDB。
3.外键列和参数列必须具有相似的数据类型。
其中数字的长度或是否有符号位必须相同；而字符的长度则可以不同。
4.外键列和参照列必须创建索引。如果外键列不存在索引的话，MySql将自动创建索引。

create table provinces(
id smallint unsigned primary key auto_increment,
pname varchar(20) not null);

show create table provinces;
//查看表结构

create table users(
id smallint unsigned primary key auto_increment,
username varchar(10) not null,
pid smallint unsigned,
foreign key (pid) references provinces(id)
);
外键约束的参照操作
1.cascade : 从父表删除或更新且自行删除或更新子表中匹配的行
2.set null: 从父表删除或更新行，并设置子表中的外键列
位NULL。如果使用该选项，必须保证子表列没有指定NOT NULL
3.restrict : 拒绝对父表的删除或更新操作。
4.no action : 标准sql的关键字， 在Mysql中与restrict相同