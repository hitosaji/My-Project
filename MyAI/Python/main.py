
from fastapi import FastAPI
from pydantic import BaseModel
from database import (
    init_db,
    create_conversation,
    update_conversation_title,
    delete_conversation,
    save_message,
    get_conversation_persona,
    get_messages,
    get_conversations
)
from pathlib import Path

# FastAPIのインスタンスを作成
app = FastAPI()
# データベースを初期化
init_db()

# 人格設定ファイルの保存場所
BASE_DIR = Path(__file__).resolve().parent.parent
CHARACTERS_DIR = BASE_DIR / "Characters"


# 人格IDに対応する人格設定を読み込む
def load_persona(persona_id: str) -> str | None:

    persona_path = (
        CHARACTERS_DIR / persona_id / "Persona.md"
    ).resolve()

    # Charactersフォルダの外側を参照しないようにする
    if not persona_path.is_relative_to(CHARACTERS_DIR.resolve()):
        return None

    # 人格設定ファイルが存在しない場合
    if not persona_path.is_file():
        return None

    # 人格設定を読み込む
    with open(persona_path, "r", encoding="utf-8") as file:
        persona_prompt = file.read()

    print("人格設定を読み込みました:", persona_path)
    print("人格設定の文字数:", len(persona_prompt))

    return persona_prompt

# 受け取る文章の形式を定義
class ChatRequest(BaseModel):
    message: str
    persona_id: str = "Hiro"
    conversation_id: int | None = None

# トップページへのアクセス
@app.get("/")
def home():
    return {"message": "MyAI Server is running!"}

# 保存されている会話一覧を取得するAPI
@app.get("/conversations")
def conversations():
    conversation_list = get_conversations()
    return {"conversations": conversation_list}

# 会話タイトルを変更するAPI
class TitleUpdateRequest(BaseModel):
    title: str

@app.put("/conversations/{conversation_id}/title")
def update_title(conversation_id: int, request: TitleUpdateRequest):
    title = request.title.strip()

    if not title:
        return {"error": "タイトルを空にすることはできません。"}

    if len(title) > 30:
        return {"error": "タイトルは30文字以内にしてください。"}

    updated = update_conversation_title(conversation_id, title)

    if not updated:
        return {"error": "指定された会話は存在しません。"}

    return {
        "conversation_id": conversation_id,
        "title": title,
        "message": "会話タイトルを更新しました。"
    }

# 特定の会話のメッセージ履歴を取得するAPI
@app.get("/conversations/{conversation_id}/messages")
def conversation_messages(conversation_id: int):

    # 会話が存在するか確認
    existing_persona = get_conversation_persona(conversation_id)

    if existing_persona is None:
        return {"error": "指定された会話は存在しません。"}

    # 会話履歴を取得
    messages = get_messages(conversation_id)

    return {
        "conversation_id": conversation_id,
        "persona_id": existing_persona,
        "messages": messages
    }

# 会話を削除するAPI
@app.delete("/conversations/{conversation_id}")
def delete_conversation_api(conversation_id: int):
    deleted = delete_conversation(conversation_id)

    if not deleted:
        return {"error": "指定された会話は存在しません。"}

    return {
        "conversation_id": conversation_id,
        "message": "会話を削除しました。"
    }

# チャット用API
@app.post("/chat")
def chat(request: ChatRequest):

    print("=== /chat APIが呼び出されました ===", flush=True)

    # 受け取った文章を取得
    user_message = request.message

    # 指定された人格IDから人格設定を読み込む
    persona_prompt = load_persona(request.persona_id)

    if persona_prompt is None:
        return {"error": "指定された人格が見つかりません。"}

    # 仮の返答を作成
    reply = f"こんにちは！MyAIです。あなたは「{user_message}」と送ってくれましたね。"

    # 会話IDが指定されているか確認
    if request.conversation_id is None:

        # 最初のメッセージから会話タイトルを作成
        title = " ".join(user_message.split())

        # タイトルが空の場合
        if not title:
            title = "新しい会話"

        # タイトルが30文字を超える場合は短縮
        if len(title) > 30:
            title = title[:30] + "…"

        # タイトルを設定して新しい会話を作成
        conversation_id = create_conversation(
            request.persona_id,
            title
        )

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

    # AIに渡す人格設定を先頭に追加
    model_messages = [
        {
            "role": "system",
            "content": persona_prompt
        },
        *model_messages
    ]

    # AIに渡す会話履歴を表示
    print("=== AIに渡すメッセージ構成 ===")
    for i, message in enumerate(model_messages):
        print(
            f"{i}: role={message['role']}, "
            f"文字数={len(message['content'])}"
        )

    # AI返答の保存処理を確認
    print("=== AI返答の保存処理を実行 ===")
    save_message(conversation_id, "assistant", reply)

    # 返答と会話IDを送信
    return {
        "conversation_id": conversation_id,
        "reply": reply
    }