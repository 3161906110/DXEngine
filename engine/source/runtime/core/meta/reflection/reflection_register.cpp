
#include "runtime/core/meta/json.h"
#include "runtime/core/meta/reflection/reflection.h"
#include "runtime/core/meta/reflection/reflection_register.h"

#include "_generated/reflection/all_reflection.h"

namespace MGame
{
    namespace Reflection
    {
        void TypeMetaRegister::metaUnregister() { TypeMetaRegisterinterface::unregisterAll(); }
    } // namespace Reflection
} // namespace MGame
