#pragma once
#include<Windows.h>
#include "runtime/function/render/rhi/rhi_command_list.h"

namespace MGame
{
    RHICommandListImmediate* createRHICommandList(HWND window);
    
} // namespace MGame
