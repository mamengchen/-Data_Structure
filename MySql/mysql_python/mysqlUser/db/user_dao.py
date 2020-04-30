from db.mysql_db import pool

class UserDao:
    def login(self,username,password):
        try:
            con=pool.get_connection()
            cursor=con.cursor()
            sql="SELECT COUNT(*) FROM t_user WHERE username=%s AND "\
            "AES_DECRYPT(UNHEX(password),'123456')=%s"
            cursor.execute(sql,(username,password))
            result=cursor.fetchone()[0]
            return True if result==1 else False
        except Exception as e:
            print(e)
        finally:
            if "con" in dir():
                con.close()


    def search_user_role(self,username):
        try:
            con=pool.get_connection()
            cursor=con.cursor()
            sql="SELECT r.role FROM t_role r JOIN t_user u ON r.id=u.role_id AND u.username=%s"
            cursor.execute(sql,(username,))
            result=cursor.fetchone()[0]
            return result
        except Exception as e:
            print(e)
        finally:
            if "con" in dir():
                con.close()

    # 插入用户
    def insert(self, username, password, email, role_id):
        try:
            con = pool.get_connection()
            con.start_transaction()
            cursor = con.cursor()
            sql = "INSERT INTO t_user(username,password,email,role_id)" \
                    " VALUES (%s,HEX(AES_ENCRYPT(%s,'123456')),%s,%s)"
            cursor.execute(sql, (username, password, email, role_id))
            con.commit()
        except Exception as e:
            if "con" in dir():
                con.rollback()
            print(e)
        finally:
            if "con" in dir():
                con.close()

    # 查询用户总页数
    def search_count_page(self):
        try:
            con=pool.get_connection()
            cursor=con.cursor()
            sql="SELECT CEIL(COUNT(*)/10) FROM t_user"
            cursor.execute(sql)
            count_page=cursor.fetchone()[0]
            return count_page
        except Exception as e:
            print(e)
        finally:
            if "con" in dir():
                con.close()

    # 查询用户分页信息
    def search_list(self,page):
        try:
            con=pool.get_connection()
            cursor=con.cursor()
            sql = "SELECT u.id,u.username,r.role" \
                  " FROM t_user u JOIN t_role r" \
                  " ON u.role_id=r.id" \
                  " LIMIT %s,%s"
            cursor.execute(sql,((page-1)*10,10))
            role=cursor.fetchall()
            return role
        except Exception as e:
            print(e)
        finally:
            if "con" in dir():
                con.close()

    # 修改用户信息
    def update(self,id,username,password,email,role_id):
        try:
            con=pool.get_connection()
            con.start_transaction()
            cursor=con.cursor()
            sql="UPDATE t_user SET username=%s,password=HEX(AES_ENCRYPT(%s,'123456')),email=%s,role_id=%s" \
                "WHERE id=%s"
            cursor.execute(sql,(username,password,email,role_id,id))
            con.commit()
        except Exception as e:
            if "con" in dir():
                con.rollback()
            print(e)
        finally:
            if "con" in dir():
                con.close()

    # 删除用户
    def delete_by_id(self,id):
        try:
            con=pool.get_connection()
            con.start_transaction()
            cursor=con.cursor()
            sql="DELETE  FROM t_user WHERE id=%s"
            cursor.execute(sql,(id,))
            con.commit()
        except Exception as e:
            if "con" in dir():
                con.rollback()
            print(e)
        finally:
            if "con" in dir():
                con.close()