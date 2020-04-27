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

SELECT AVG(sal+IFNULL(comm,0)) FROM t_emp;

select SUM(sal)
FROM t_emp WHERE deptno IN(10,20);

SELECT  MAX(sal+IFNULL(comm,0))
FROM t_emp where deptno IN(10,30);

select MAX(LENGTH(ename))
FROM t_emp WHERE deptno IN(10,30);

select MIN(sal+IFNULL(comm,0))
FROM t_emp WHERE deptno IN(10,30);

select COUNT(*) FROM t_emp;
SELECT COUNT(comm) FROM t_emp;
select * from t_emp;

select COUNT(*) 
FROM t_emp WHERE deptno IN (10, 20) AND sal >= 2000 AND DATEDIFF(NOW(),hiredate)/365 >= 15;

SELECT deptno,COUNT(*),AVG(sal),MAX(sal),MIN(sal)
FROM t_emp
GROUP BY deptno WITH ROLLUP;

SELECT deptno,GROUP_CONCAT(ename),COUNT(*)
FROM t_emp
GROUP BY deptno;

SELECT deptno,COUNT(*)
FROM t_emp
GROUP BY deptno HAVING AVG(sal)>=2000;

SELECT deptno
FROM t_emp
WHERE hiredate>="1982-01-01"
GROUP BY deptno HAVING COUNT(*)>=2;

# 查询每名员工的部门信息
SELECT e.ename,e.empno,d.dname
FROM t_emp e JOIN t_dept d ON e.deptno=d.deptno;

SELECT *
FROM t_emp e JOIN t_dept d WHERE e.deptno=d.deptno;

SELECT *
FROM t_emp e,t_dept d WHERE e.deptno=d.deptno;

# 查询每个员工的工号、姓名、部门名称、底薪、职位、工资等级？
SELECT e.empno,e.ename,d.dname,e.sal,e.job,s.grade
FROM t_emp e JOIN t_dept d ON e.deptno=d.deptno
JOIN t_salgrade s ON e.sal BETWEEN s.losal AND s.hisal;

# 查询与SCOTT相同部门的员工都有谁
SELECT ename
FROM t_emp WHERE deptno=(SELECT deptno FROM t_emp WHERE ename="SCOTT") AND ename!="SCOTT";

SELECT e2.ename
FROM t_emp e1 JOIN t_emp e2 ON e1.deptno=e2.deptno
WHERE e1.ename="SCOTT" AND e2.ename!="SCOTT";

# 查询底薪超过公司平均底薪的员工信息

SELECT *
FROM t_emp e JOIN (SELECT AVG(sal) AS avg FROM t_emp) t ON e.sal >= t.avg; 

# 查询RESEARCH部门的人数、最高底薪、最低底薪、平均底薪、平均工龄？
SELECT COUNT(*),MAX(t.sal),MIN(t.sal),AVG(t.sal),FLOOR(AVG(DATEDIFF(NOW(),t.hiredate)/365))
FROM t_emp t JOIN t_dept d ON t.deptno = d.deptno
WHERE d.dname = "RESEARCH";

#查询每种职业的最高工资、最低工资、平均工资、最高工资等级和最低工资等级

SELECT t.job,
MAX(t.sal+IFNULL(t.comm,0)),
MIN(t.sal+IFNULL(t.comm,0)),
AVG(t.sal+IFNULL(t.comm,0)),
MAX(s.grade),
MIN(s.grade)
FROM t_emp t JOIN t_salgrade s ON (t.sal+IFNULL(t.comm,0)) BETWEEN s.losal AND s.hisal
GROUP BY t.job;

# 查询每个底薪超过部门平均底薪的员工信息
SELECT *
FROM t_emp t JOIN (SELECT deptno,AVG(sal) as avg FROM t_emp GROUP BY deptno) e
ON t.deptno=e.deptno AND t.sal > e.avg;

# 查询每个部门的名称和部门的人数
SELECT d.dname,COUNT(e.deptno)
FROM t_dept d LEFT JOIN t_emp e ON e.deptno=d.deptno
GROUP BY d.dname;


#查询每个部门的名称和部门的人数？如果没有部门的员工，部门名称用NULL代替
(
SELECT d.dname,COUNT(e.deptno)
FROM t_dept d LEFT JOIN t_emp e ON e.deptno=d.deptno
GROUP BY d.deptno
) UNION
(
SELECT d.dname,COUNT(*)
FROM t_dept d RIGHT JOIN t_emp e ON e.deptno=d.deptno
GROUP BY d.deptno
);

#查询每名员工的编号，姓名，部门，月薪，工资等级，工龄，上司编号，上司姓名，上司部门？

SELECT e.empno,e.ename,d.dname,
e.sal+IFNULL(e.comm,0),s.grade,
FLOOR(DATEDIFF(NOW(),e.hiredate)/365),
t.empno AS mempno,t.ename AS mename,t.dname AS mdname
FROM t_emp e LEFT JOIN t_dept d ON e.deptno=d.deptno
LEFT JOIN t_salgrade s ON e.sal BETWEEN s.losal AND s.hisal
LEFT JOIN (
SELECT em.empno,em.ename,dm.dname
FROM t_emp em LEFT JOIN t_dept dm ON em.deptno=dm.deptno
) t ON e.mgr=t.empno;