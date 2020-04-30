import mysql.connector.pooling

__config={
    "host":"localhost",
    "port":3366,
    "user":"root",
    "password":"123456",
    "database":"vega"
}

try:
    pool=mysql.connector.pooling.MySQLConnectionPool(
        **__config,
        pool_size=10
    )
except Exception as e:
    print(e)