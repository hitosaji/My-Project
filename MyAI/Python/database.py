
import sqlite3
from pathlib import Path

# データベースの保存場所
DB_PATH = Path(__file__).resolve().parent / "myai.db"

# データベースを初期化
def init_db():
    print("データベース保存先:", DB_PATH)

    # データベースに接続
    with sqlite3.connect(DB_PATH) as connection:

        # テーブル同士の関連付けを有効にする
        connection.execute("PRAGMA foreign_keys = ON")

        # 会話情報を保存するテーブル
        connection.execute("""
            CREATE TABLE IF NOT EXISTS conversations (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                persona_id TEXT NOT NULL,
                title TEXT NOT NULL DEFAULT '新しい会話',
                created_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP
            )
        """)

        # メッセージを保存するテーブル
        connection.execute("""
            CREATE TABLE IF NOT EXISTS messages (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                conversation_id INTEGER NOT NULL,
                role TEXT NOT NULL,
                content TEXT NOT NULL,
                created_at TEXT NOT NULL DEFAULT CURRENT_TIMESTAMP,
                FOREIGN KEY (conversation_id)
                    REFERENCES conversations(id)
                    ON DELETE CASCADE
            )
        """)

        connection.commit()

 # 新しい会話を作成する
def create_conversation(persona_id: str, title: str = "新しい会話") -> int:

    # データベースに接続
    with sqlite3.connect(DB_PATH) as connection:

        # 会話を登録
        cursor = connection.execute("""
            INSERT INTO conversations (persona_id, title)
            VALUES (?, ?)
        """, (persona_id, title))

        # 登録を確定
        connection.commit()

        # 作成された会話のIDを返す
        return cursor.lastrowid

# メッセージを保存する
def save_message(conversation_id: int, role: str, content: str) -> int:

    # データベースに接続
    with sqlite3.connect(DB_PATH) as connection:

        # 外部キー制約を有効にする
        connection.execute("PRAGMA foreign_keys = ON")

        # メッセージを登録
        cursor = connection.execute("""
            INSERT INTO messages (conversation_id, role, content)
            VALUES (?, ?, ?)
        """, (conversation_id, role, content))

        # 登録を確定
        connection.commit()

        # 保存されたメッセージのIDを返す
        return cursor.lastrowid

    # 会話IDから人格IDを取得する
def get_conversation_persona(conversation_id: int) -> str | None:

    # データベースに接続
    with sqlite3.connect(DB_PATH) as connection:

        # 指定された会話IDの人格IDを取得
        cursor = connection.execute("""
            SELECT persona_id
            FROM conversations
            WHERE id = ?
        """, (conversation_id,))

        # 検索結果を取得
        row = cursor.fetchone()

        # 会話が存在しなければ None を返す
        if row is None:
            return None

        # 人格IDを返す
        return row[0]

# 会話履歴を取得する
def get_messages(conversation_id: int) -> list[dict]:

    # データベースに接続
    with sqlite3.connect(DB_PATH) as connection:

        # 指定された会話IDのメッセージを取得
        cursor = connection.execute("""
            SELECT role, content, created_at
            FROM messages
            WHERE conversation_id = ?
            ORDER BY id ASC
        """, (conversation_id,))

        # 検索結果をすべて取得
        rows = cursor.fetchall()

        # 取得したデータを辞書形式にして返す
        return [
            {
                "role": row[0],
                "content": row[1],
                "created_at": row[2]
            }
            for row in rows
        ]