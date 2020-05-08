use school
db.createCollection("teacher")
db.student.count()
db.student.dataSize()
show collections
db.teacher.drop()
db.student.renameCollection("stu")
show collections

db.student.save({name:"lim",age:24})

db.student.save([
    {name:"mmc",age:22},
    {name:"lihao",age:23}
])

db.student.find()
db.student.find({name:"lim"})
db.student.findOne()

db.student.find({
    age:{$gte:20},
    age:{$lte:30}
})

db.student.find({
    age:{$in:[20,22]}
})

db.teacher.save({name:"Jack",role:["班主任","年级主任","副校长"]})
db.teacher.find({role:{$all:["班主任","副校长"]}})

db.student.find({age:{$not:{$gte:20,$lte:30}}})

db.student.save([
    {name:"sxd",age:25},
    {name:"whd",age:16},
    {name:"xxh",age:22}
])
db.student.find().sort({age:-1})
db.student.find().sort({age:1}).skip(2).limit(10)

db.student.distinct("age").sort(function(){return -1}).slice(0,3)

db.student.updateMany({age:16},{$set:{class:"2-6"}})
db.student.updateMany({age:{$gte:20,$lte:30}},{$set:{class:"2-8"}})

// 删除
db.student.updateMany({age:16},{$unset:{age:1}})

// 增加2
db.student.updateMany({},{$inc:{age:2}})

// 删除符合条件的信息
db.student.remove({class:"2-7"})

// 添加索引
db.student.createIndex({name:1})
db.student.dropIndex("name_1")

// 索引
db.student.createIndex({name:1},{background:true,name:"myname"})

// 创建唯一性索引
db.student.createIndex({name:1},{background:true,unique:true,name:"mysss"})

db.getCollection("teacher").find({})
db.teacher.update({name:"Jack"},{$push:{role:"教务主任"}})
db.teacher.update({name:"Jack"},{$pull:{role:"副校长"}})

// 删除全部内容
db.teacher.remove({})

mongodump --host=localhost --port=27017 -u admin -p 123456 --authenticationDatabase=admin -d school -o E:/
mongorestore --host=localhost --port=27017 -u admin -p 123456 --authenticationDatabase=admin --drop -d school E:/school