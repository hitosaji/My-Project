
#include "Character.h"

#include <fstream>
#include <sstream>

bool Character::LoadPersona(const std::string& filePath)
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

    m_persona = buffer.str();

    // 読み込んだ内容が空でないか確認
    return !m_persona.empty();
}

const std::string& Character::GetPersona() const
{
    return m_persona;
}

bool Character::IsLoaded() const
{
    return !m_persona.empty();
}
