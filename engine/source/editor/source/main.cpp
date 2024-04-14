#include "runtime/engine.h"
#include <iostream>
#include "runtime/function/render/rhi/rhi_init.h"
#include "runtime/function/render/window_system.h"
#include "runtime/function/render/passes/ui_pass.h"
#include "runtime/function/render/rhi/d3d11/d3d11_rhi.h"

int main(int argc, char** argv)
{
    MGame::MGameEngine().startEngine("");
    MGame::WindowCreateInfo window_create_info;
    MGame::WindowSystem window_system = MGame::WindowSystem();
    window_system.Initialize(window_create_info);
    MGame::RHICommandListImmediate* rhi_command_list = MGame::createRHICommandList(window_system.GetWindow());

    MGame::UIPass ui_pass = MGame::UIPass();
    const MGame::RenderPassInitInfo render_pass_init_info;
    ui_pass.Initialize(&render_pass_init_info);

    ui_pass.InitImGui(static_cast<MGame::FD3D11DynamicRHI&>(rhi_command_list->GetContext()));

    while (true)
    {
        window_system.PollEvents();
        if (window_system.ShouldClose())
        {
            break;
        }
        rhi_command_list->GetContext().RHIBeginFrame();

        ui_pass.Draw();
        rhi_command_list->GetContext().RHIEndFrame();
    }
    delete rhi_command_list;
    return 0;
}
