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



use demo
select * from t_emp;
select empno,ename,sal from t_emp;

select
empno,
sal*12 AS "nysal"
from t_emp;

select empno,ename,sal from t_emp LIMIT 0,5;
select empno,ename,sal from t_emp LIMIT 5,5;
select empno,ename,sal from t_emp LIMIT 10,5;


select 
from t_emp
where (sal > 1000 AND sal < 3000) 
select empno,ename,sal from t_emp LIMIT 10;

select empno,ename,sal from t_emp order by sal;
select empno,ename,sal from t_emp order by sal DESC;
select empno,sal,hiredate from t_emp order by sal,hiredate DESC;
select empno,ename,sal from t_emp order by sal DESC LIMIT 5;

select job from t_emp;
select distinct job from t_emp;

select empno,ename,sal
from t_emp
where (deptno = 10 OR deptno = 30) AND sal >= 1000;

select empno,ename,sal,hiredate
from t_emp
where deptno = 10 AND (IFNULL(comm,0)+sal)*12 >= 15000 AND DATEDIFF(NOW(),hiredate)/365 >= 20;

select *
from t_emp
where deptno IN (10,20,30) AND job != "SALESMAN" AND hiredate < "1981-5-20";


select *
from t_emp where comm is NULL
and sal BETWEEN 2000 and 3000
AND ename LIKE "_LAKE";

select * 
from t_emp where comm is null
and ename REGEXP "^[\\u4e00-\\u9fa5]{2,4}$";

select *
from t_emp 
where not deptno in(10,20) XOR sal >= 2000; 