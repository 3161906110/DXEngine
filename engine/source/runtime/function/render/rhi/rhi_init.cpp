#include "runtime/function/render/rhi/rhi_init.h"

#include "runtime/function/render/rhi/d3d11/d3d11_rhi.h"

namespace MGame
{

    RHICommandListImmediate* createRHICommandList(HWND window)
    {
        static const char cur_rhi_type[] = "d3d11";
        RHICommandListImmediate* rhi_command_list = new RHICommandListImmediate();

        if(strcmp(cur_rhi_type, "d3d11") == 0)
        {
            // TODO
            FD3D11DynamicRHI* rhi = new FD3D11DynamicRHI(window);
            rhi->Init();

            rhi_command_list->SetContext(rhi);
        }
        return rhi_command_list;
    }
    
} // namespace MGame
