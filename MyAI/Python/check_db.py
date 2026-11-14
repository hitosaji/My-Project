import sqlite3
from pathlib import Path
from database import get_messages

DB_PATH = Path(__file__).resolve().parent / "myai.db"

with sqlite3.connect(DB_PATH) as connection:

    print("=== 会話一覧 ===")

    conversations = connection.execute(
        "SELECT * FROM conversations"
    ).fetchall()

    for conversation in conversations:
        print(conversation)

    print("\n=== メッセージ一覧 ===")

    messages = connection.execute(
        "SELECT * FROM messages"
    ).fetchall()

    for message in messages:
        print(message)
        
    print("\n=== 会話ID 1 の履歴 ===")

    history = get_messages(1)

    for message in history:
        print(message)
        
        