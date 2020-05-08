"""
mongodb 数据库链接
"""
# from mongodb import client
#
# client.school.teacher.insert_one({"name":"scott"})
# client.school.teacher.insert_many([
#     {"name":"陈刚"},
#     {"name":"郭丽丽"}
# ])

"""
mongodb 查询
"""
# from mongodb import client
#
# try:
#     teachers = client.school.teacher.find({})
#     for one in teachers:
#         print("id:{0},name:{1}".format(one["_id"],one["name"]))
#     print("-----------------------")
#     teachers = client.school.teacher.find_one({"name":"scott"})
#     print(teachers["_id"],teachers["name"])
# except Exception as e:
#     print(e)

"""
mongodb 更新数据
"""
# from mongodb import client
#
# try:
#     client.school.teacher.update_many({},{"$set":{"role":["班主任"]}})
#     client.school.teacher.update_one({"name":"scott"},{"$set":{"sex":"女"}})
#     client.school.teacher.update_one({"name":"scott"},{"$push":{"role":"书记"}})
# except Exception as e:
#     print(e)

# from mongodb import client
#
# students = client.school.student.find({}).skip(0).limit(10)
# for one in students:
#     print("id:{0},name:{1}".format(one["_id"],one["name"]))
#
# names = client.school.student.distinct("name")
# for one in names:
#     print(one)
#
# students = client.school.student.find({}).sort([("name",-1)])
# for one in students:
#     print("name:{0},id:{1}".format(one["name"],one["_id"]))

"""
mongodb 保存文件
"""
# from mongodb import client
# from gridfs import GridFS
#
# db = client.school
# gfr = GridFS(db,collection="book")
#
# file = open("H:/C++标准库.pdf","rb")
# args = {
#     "type":"PDF",
#     "keyword":"linux"
# }
# gfr.put(file,filename="C++标准库",**args)
# file.close()

# from mongodb import client
# from gridfs import GridFS
# from bson.objectid import ObjectId
# import math
# import datetime
#
# db = client.school
# gfs = GridFS(db,collection="book")
# book = gfs.find_one({"filename":"C++标准库"})
# print("filename:{0},type:{1},keyword:{2}".format(book.filename,book.type,book.keyword))
# print("%dM"%math.ceil(book.length/1024/1024))
# print("----------------------")
# books = gfs.find({"type":"PDF"})
# for one in books:
#     uploadDate = one.uploadDate + datetime.timedelta(hours=8)
#     uploadDate = uploadDate.strftime("%Y-%m-%d %H:%M:%S")
#     print(one._id,one.filename,uploadDate)
#
# # 判断是否是存储文件
# rs = gfs.exists(ObjectId("5eb4b0b589c442554fdd922d"))
# print(rs)
# rs = gfs.exists(**{"type":"PDF"})
# print(rs)

"""
读取gridfs中存储的文件
"""
# from mongodb import client
# from gridfs import GridFS
# from bson.objectid import ObjectId
#
# db = client.school
# gfs = GridFS(db,collection="book")
# document = gfs.get(ObjectId("5eb4b0b589c442554fdd922d"))
# file = open("E:/C++标准库.pdf","wb")
# file.write(document.read())
# file.close()

"""
gridefs 中删除文件
"""
from mongodb import client
from gridfs import  GridFS
from bson.objectid import ObjectId

db = client.school
gfs = GridFS(db,collection="book")
rs = gfs.exists(ObjectId("5eb4b0b589c442554fdd922d"))
print("删除前:{0}".format(rs))
gfs.delete(ObjectId("5eb4b0b589c442554fdd922d"))
rs = gfs.exists(ObjectId("5eb4b0b589c442554fdd922d"))
print("删除后:{0}".format(rs))