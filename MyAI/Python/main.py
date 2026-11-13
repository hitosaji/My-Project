
from fastapi import FastAPI
from pydantic import BaseModel
from database import init_db

# FastAPIのインスタンスを作成
app = FastAPI()
# データベースを初期化
init_db()


# 受け取る文章の形式を定義
class ChatRequest(BaseModel):
    message: str


# トップページへのアクセス
@app.get("/")
def home():
    return {"message": "MyAI Server is running!"}


# チャット用API
@app.post("/chat")
def chat(request: ChatRequest):

    # 受け取った文章を取得
    user_message = request.message

    # 仮の返答を作成
    reply = f"こんにちは！MyAIです。あなたは「{user_message}」と送ってくれましたね。"

    # 返答を送信
    return {"reply": reply}
