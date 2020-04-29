import pymysql.cursors

connect=pymysql.Connect(
    host='localhost',
    port=3366,
    user='root',
    passwd='123456',
    db='demo',
    charset='utf8'
)

cur=connect.cursor()
cur.execute("select ename,sal,hiredate from t_emp")
for i in cur:
    print("{0},{1},{2}".format(i[0],i[1],i[2]))

connect.close()

"""
sql注入攻击
"""
# import pymysql.cursors
#
# config={
#     "host":"localhost",
#     "port":3366,
#     "user":"root",
#     "passwd":"123456",
#     "db":"vega",
#     "charset":"utf8"
# }
#
# connect = pymysql.Connect(**config)
# cursor=connect.cursor()
# username="1 OR 1=1"
# password="1 OR 1=1"
# sql="SELECT COUNT(*) FROM t_user WHERE username="+username+\
# " AND AES_DECRYPT(UNHEX(password),'123456')="+password
# cursor.execute(sql)
# print(cursor.fetchone()[0])
# connect.close()

"""
解决方案
"""
import pymysql.cursors

config={
    "host":"localhost",
    "port":3366,
    "user":"root",
    "passwd":"123456",
    "db":"vega",
    "charset":"utf8"
}

connect = pymysql.Connect(**config)
cursor=connect.cursor()
username="1 OR 1=1"
password="1 OR 1=1"
sql="SELECT COUNT(*) FROM t_user WHERE username=%s"\
" AND AES_DECRYPT(UNHEX(password),'123456')=%s"
cursor.execute(sql,(username,password))
print(cursor.fetchone()[0])
connect.close()



import  pymysql.cursors

try:
    connect=pymysql.Connect(
        host='localhost',
        port=3366,
        user='root',
        passwd='123456',
        db='demo',
        charset='utf8'
    )
    cursor=connect.cursor()
    sql="INSERT INTO t_emp(empno,ename,job,mgr,hiredate,sal,comm,deptno) " \
    "VALUES(%s,%s,%s,%s,%s,%s,%s,%s)"
    cursor.execute(sql,(9600,"赵娜","SALESMAN",None,"1985-12-1",2500,None,10))
    connect.commit()
except Exception as e:
    if "connect" in dir():
        connect.rollback()
    print(e)
finally:
    if "connect" in dir():
        connect.close()
