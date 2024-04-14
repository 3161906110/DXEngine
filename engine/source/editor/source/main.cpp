#include "runtime/engine.h"
#include <iostream>
#include "runtime/function/render/rhi/rhi_init.h"
#include "runtime/function/render/window_system.h"

int main(int argc, char** argv)
{
    MGame::MGameEngine().startEngine("");
    MGame::WindowCreateInfo window_create_info;
    MGame::WindowSystem window_system = MGame::WindowSystem();
    window_system.Initialize(window_create_info);
    MGame::RHICommandListImmediate* rhi_command_list = MGame::createRHICommandList(window_system.GetWindow());
    while (true)
    {
        window_system.PollEvents();
        if (window_system.ShouldClose())
        {
            break;
        }
        rhi_command_list->GetContext().RHIBeginFrame();
        rhi_command_list->GetContext().RHIEndFrame();
    }
    delete rhi_command_list;
    return 0;
}
