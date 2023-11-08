from fastapi import FastAPI
import uvicorn
import sqlite3 as sql

app = FastAPI()
con = sql.connect('bd.db', uri=True, check_same_thread=False)



with con:
    cur = con.cursor()
    cur.execute("CREATE TABLE IF NOT EXISTS `log` (`name` STRING, `Message` STRING, `Time` STRING, `ID`  INTEGER PRIMARY KEY) ")



cur.execute(f"INSERT INTO `log` VALUES ('Ivan', 'asnkbfljasf', '1073018371803', '1')")
con.commit()


@app.get('/')
def Authors():
    cur.execute("SELECT * FROM `log`")
    rows = cur.fetchall()
    return rows

@app.get('/names')
def Authors():
    cur.execute("SELECT name FROM `log`")
    rows = cur.fetchall()
    return {'Names':rows}

@app.get('/msg')
def func_hello():
    cur.execute("SELECT Message FROM `log`")
    rows = cur.fetchall()
    return {'Message':rows}



if __name__ == '__main__':
    uvicorn.run(app)