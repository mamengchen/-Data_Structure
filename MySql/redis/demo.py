"""
redis
"""
# from redis_db import pool
# import redis
# import time
#
# con=redis.Redis(
#     connection_pool=pool
# )
#
# con.set("countery","英国")
# con.set("city","伦敦")
# # con.expire("city",5)
# # time.sleep(6)
# city=con.get("city").decode("utf-8")
# print(city)
# del con

"""
redis 操作字符串
"""
# from redis_db import pool
# import redis
#
# try:
#     con=redis.Redis(
#         connection_pool=pool
#     )
#     con.delete("countery","city")
#     con.mset({"country":"德国","city":"伦敦"})
#     result=con.mget("country","city")
#     for one in result:
#         print(one.decode("utf-8"))
#
# except Exception as e:
#     print(e)
# finally:
#     del con

"""
redis 操作列表
"""
# from redis_db import pool
# import redis
#
# try:
#     con=redis.Redis(
#         connection_pool=pool
#     )
#     con.flushall() # 清空redis
#     con.rpush("dname","青铜","白银","黄金","王者")
#     con.rpop("dname")
#     result=con.lrange("dname",0,-1)
#     for one in result:
#         print(one.decode("utf-8"))
#
# except Exception as e:
#     print(e)
# finally:
#     del con

"""
redis 集合
"""
from redis_db import pool
import  redis

try:
    con=redis.Redis(
        connection_pool=pool
    )
    con.sadd("employee",8000,8001,8002,8003)
    con.srem("employee",8002)
    result=con.smembers("employee")
    for one in result:
        print(one.decode("utf-8"))
    con.zadd("IT",{"mayun":0,"huateng":0,"dinglei":0})
    con.zincrby("IT",10,"mayun")
    result=con.zrevrange("IT",0,-1)
    for one in result:
        print(one.decode("utf-8"))

except Exception as e:
    print(e)
finally:
    del con



"""
模拟秒杀
"""
from concurrent.futures import ThreadPoolExecutor
from redis_db import pool
import redis
import  random

s=set()
while True:
    if len(s) == 1000:
        break
    sdate = random.randint(10000,20000)
    s.add(sdate)

try:
    con = redis.Redis(
        connection_pool=pool
    )
    con.delete("kill_total","kill_num","kill_flag","kill_user")
    con.set("kill_total",50)
    con.set("kill_num",0)
    con.set("kill_flag",1)
    con.expire("kill_flag",600)
except Exception as e:
    print(e)
finally:
    del con

execthear=ThreadPoolExecutor(200)
def buy():
    connection = redis.Redis(
        connection_pool=pool
    )
    pipline=connection.pipeline()
    try:
        if connection.exists("kill_flag"):
            pipline.watch("kill_num","kill_user")
            total=int(pipline.get("kill_total").decode("utf-8"))
            num=int(pipline.get("kill_num").decode("utf-8"))
            if num < total:
                pipline.multi()
                pipline.incr("kill_num")
                user_id = s.pop()
                pipline.rpush("kill_user",user_id)
                pipline.execute()
    except Exception as e:
        print(e)
    finally:
        if "pipline" in dir():
            pipline.reset()
        del connection

for i in range(0,1000):
    execthear.submit(buy())

print("秒杀已经结束")