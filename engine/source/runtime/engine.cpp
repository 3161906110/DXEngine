#include "engine.h"
#include "runtime/core/meta/reflection/reflection_register.h"

namespace MGame
{
    
    void MGameEngine::startEngine(const std::string& config_file_path)
    {
        Reflection::TypeMetaRegister::metaRegister();

    }

} // namespace MGame
