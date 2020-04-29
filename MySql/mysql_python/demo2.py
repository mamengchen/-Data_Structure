"""
使用mysql链接池
"""
# import mysql.connector.pooling
#
# config={
#     "host":"localhost",
#     "port":3366,
#     "user":"root",
#     "password":"123456",
#     "database":"demo"
# }
#
# try:
#     pool = mysql.connector.pooling.MySQLConnectionPool(
#         **config,
#         pool_size=10
#     )
#     con = pool.get_connection()
#     con.start_transaction()
#     cursor=con.cursor()
#     sql="UPDATE t_emp SET sal=sal+%s WHERE deptno=%s"
#     cursor.execute(sql,(200,20))
#     con.commit()
# except Exception as e:
#     if "con" in dir():
#         con.rollback()
#     print(e)

"""
mysql 删除
"""
# import mysql.connector.pooling
#
# config={
#     "host":"localhost",
#     "port":3366,
#     "user":"root",
#     "password":"123456",
#     "database":"demo"
# }
#
# try:
#     pool=mysql.connector.pooling.MySQLConnectionPool(
#         **config,
#         pool_size=10
#     )
#     con = pool.get_connection()
#     con.start_transaction()
#     sql="DELETE e,d FROM t_emp e JOIN t_dept d ON e.deptno=d.deptno WHERE e.deptno=20"
#     cursor=con.cursor()
#     cursor.execute(sql)
#     con.commit()
# except Exception as e:
#     if "con" in dir():
#         con.rollback()
#     print(e)

"""
mysql 循环执行sql
"""
# import mysql.connector.pooling
#
# config={
#     "host":"localhost",
#     "port":3366,
#     "user":"root",
#     "password":"123456",
#     "database":"demo"
# }
#
# try:
#     pool=mysql.connector.pooling.MySQLConnectionPool(
#         **config,
#         pool_size=10
#     )
#     con = pool.get_connection()
#     con.start_transaction()
#     sql="INSERT INTO t_dept(deptno,dname,loc) VALUE(%s,%s,%s)"
#     data=[["100","开发部","beijing"],["110","测试部","shenzheng"]]
#     cursor=con.cursor()
#     cursor.executemany(sql,data)
#     con.commit()
#
# except Exception as e:
#     if "con" in dir():
#         con.rollback()
#     print(e)

"""
使用insert语句，把部门平均底薪超过公司平均底薪的这样部门里的员工信息导入到t_emp_new表里面，并且让这些员工隶属于sales部门
"""
# import mysql.connector.pooling
#
# config={
#     "host":"localhost",
#     "port":3366,
#     "user":"root",
#     "password":"123456",
#     "database":"demo"
# }
#
# try:
#     pool=mysql.connector.pooling.MySQLConnectionPool(
#         **config,
#         pool_size=10
#     )
#     con=pool.get_connection()
#     cursor=con.cursor()
#
#     sql="DROP TABLE t_emp_new"
#     cursor.execute(sql)
#
#     sql="CREATE TABLE t_emp_new LIKE t_emp"
#     cursor.execute(sql)
#
#     sql="SELECT AVG(sal) AS avg FROM t_emp"
#     cursor.execute(sql)
#     result=cursor.fetchone()[0]
#     # print(result)
#
#     sql="SELECT deptno FROM t_emp GROUP BY deptno HAVING AVG(sal)>=%s"
#     cursor.execute(sql,(result,))
#     result=cursor.fetchall()
#     # print(result)
#
#     sql="INSERT INTO t_emp_new SELECT * FROM t_emp WHERE deptno IN ("
#     for i in range(len(result)):
#         if i < len(result)-1:
#             sql+=str(result[i][0])+","
#         else:
#             sql+=str(result[i][0])
#     sql+=")"
#     # print(sql)
#     cursor.execute(sql)
#
#     sql="DELETE FROM t_emp WHERE deptno=%s"
#     resultlist=[]
#     for i in result:
#         resultlist.append(list(i))
#     # print(resultlist)
#     cursor.executemany(sql,resultlist)
#
#     sql="SELECT deptno FROM t_dept WHERE dname=%s"
#     cursor.execute(sql,("SALES",))
#     result=cursor.fetchone()[0]
#     # print(result)
#
#     sql="UPDATE t_emp_new SET deptno=%s"
#     cursor.execute(sql,(result,))
#     con.commit()
# except Exception as e:
#     if "con" in dir():
#         con.rollback()
#     print(e)