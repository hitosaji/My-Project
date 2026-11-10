
from fastapi import FastAPI

# FastAPIのインスタンスを作成
app = FastAPI()

# トップページへのアクセス
@app.get("/")
def home():
    return {"message": "MyAI Server is running!"}
