from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware
import uvicorn
import sqlite3 as sql


app = FastAPI()

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)
con = sql.connect('bd.db', uri=True, check_same_thread=False)



with con:
    cur = con.cursor()
    cur.execute("CREATE TABLE IF NOT EXISTS `log` (`name` STRING, `Message` STRING, `Time` STRING, `ID`  INTEGER PRIMARY KEY) ")


@app.get('/')
async def main():
    return "hi"

@app.get('/info')
async def Inf():
    cur.execute("SELECT name FROM `log`")
    rows1 = cur.fetchall()
    cur.execute("SELECT Message FROM `log`")
    rows2 = cur.fetchall()
    inf = [dict() for x in range(0)]

    for i in range(len(rows1)):
        inf.append({str(rows1[i]):rows2[i]})
    print(inf)

    return inf


@app.get("/info/{id}")
async def stud(id :int):
    return {"id": id}


if __name__ == '__main__':
    uvicorn.run(app)