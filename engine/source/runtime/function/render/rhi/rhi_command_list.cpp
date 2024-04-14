#include "runtime/function/render/rhi/rhi_command_list.h"

namespace MGame
{
    RHICommandListBase::~RHICommandListBase()
    {
        Context = nullptr;
    }

} // namespace MGame
