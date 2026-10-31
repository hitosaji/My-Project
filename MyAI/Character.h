#pragma once
#include <string>
using namespace std;

class Character
{
private:
    string m_persona;

public:
    // 人格資料を読み込む
    bool LoadPersona(const std::string& filePath);

    // 人格資料を取得する
    const std::string& GetPersona() const;

    // 読み込み済みか確認する
    bool IsLoaded() const;
};
