create table t_teacher(
 id INT UNSIGNED primary key auto_increment,
 name VARCHAR(20) not null,
 tel VARCHAR(10)
);

insert into `t_teacher` (`name`,`tel`) VALUES("mmc date is","13329157");
insert into t_teacher (name,tel) values("sxd is sb","19970645");

create table t_dept(
deptno int unsigned primary key,
dname varchar(20) not null unique,
tel char(20) unique
);

create table t_tmp(
empno int unsigned primary key,
ename varchar(20) not null,
sex ENUM("男","女") not null,
deptno int unsigned not null,
hiredate DATE not null,
FOREIGN key (deptno) REFERENCES t_dept(deptno)
);

show tables;

create table t_message(
id int unsigned primary key,
content varchar(200) not null,
type enum("公告","通报","个人通知") not null,
create_time TIMESTAMP not null,
INDEX idx_type (type)
);

DROP INDEX idx_type ON t_message;
CREATE INDEX idx_type ON t_message(type);
SHOW INDEX FROM t_message;
ALTER TABLE t_message ADD INDEX idx_type(type);