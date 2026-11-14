
from fastapi import FastAPI
from pydantic import BaseModel
from database import (
    init_db,
    create_conversation,
    save_message,
    get_conversation_persona,
    get_messages
)

# FastAPIのインスタンスを作成
app = FastAPI()
# データベースを初期化
init_db()


# 受け取る文章の形式を定義
class ChatRequest(BaseModel):
    message: str
    persona_id: str = "Hiro"
    conversation_id: int | None = None

# トップページへのアクセス
@app.get("/")
def home():
    return {"message": "MyAI Server is running!"}


# チャット用API
@app.post("/chat")
def chat(request: ChatRequest):

    print("=== /chat APIが呼び出されました ===", flush=True)

    # 受け取った文章を取得
    user_message = request.message

    # 仮の返答を作成
    reply = f"こんにちは！MyAIです。あなたは「{user_message}」と送ってくれましたね。"

    # 会話IDが指定されているか確認
    if request.conversation_id is None:

        # 指定されていなければ新しい会話を作成
        conversation_id = create_conversation(request.persona_id)

    else:

        # 指定された会話IDから人格IDを取得
        existing_persona = get_conversation_persona(request.conversation_id)

        # 会話が存在するか確認
        if existing_persona is None:
            return {"error": "指定された会話は存在しません。"}

        # 人格IDが一致するか確認
        if existing_persona != request.persona_id:
            return {"error": "指定された人格は、この会話では使用できません。"}

        # 指定された会話IDを使用
        conversation_id = request.conversation_id

    # ユーザーのメッセージを保存
    save_message(conversation_id, "user", user_message)

    # 会話履歴を取得
    history = get_messages(conversation_id)

    # AIに渡す形式に変換
    model_messages = [
        {
            "role": message["role"],
            "content": message["content"]
        }
        for message in history
    ]

    # AIに渡す会話履歴を表示
    print("=== AIに渡す会話履歴 ===")
    for message in model_messages:
        print(message)

    # AI返答の保存処理を確認
    print("=== AI返答の保存処理を実行 ===")
    save_message(conversation_id, "assistant", reply)

    # 返答と会話IDを送信
    return {
        "conversation_id": conversation_id,
        "reply": reply
    }
