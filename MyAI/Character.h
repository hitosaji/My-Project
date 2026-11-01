#pragma once
#include <string>

class Character
{
private:
   
    std::string m_characterID;
    std::string m_displayName;
    std::string m_persona;

public:
    // 人格資料を読み込む
    bool LoadPersona(const std::string& characterID, 
                     const std::string& displayName,
                     const std::string& filePath);

    // 人格資料を取得する
    const std::string& GetPersona() const;

    // 読み込み済みか確認する
    bool IsLoaded() const;
};
