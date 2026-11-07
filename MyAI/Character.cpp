
#include "Character.h"

#include <fstream>
#include <sstream>

bool Character::LoadPersona(const std::string& characterID, 
const std::string& displayName,const std::string& filePath)
{
    // ファイルを開く
    std::ifstream file(filePath);

    if (!file.is_open())
    {
        return false;
    }

    // ファイルの内容を読み込む
    std::ostringstream buffer;
    buffer << file.rdbuf();

    std::string persona = buffer.str();

    if (persona.empty())
    {
        return false;
    }

    // 人格情報を保存する
    m_characterID = characterID;
    m_displayName = displayName;
    m_persona = persona;

    return true;
}

const std::string& Character::GetPersona() const
{
    return m_persona;
}

bool Character::IsLoaded() const
{
    return !m_persona.empty();
}
