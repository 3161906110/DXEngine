#pragma once

#include <imgui.h>
#include <backends/imgui_impl_dx11.h>
#include <backends/imgui_impl_win32.h>


#include "runtime/function/render/passes/ui_pass.h"

namespace MGame
{


    void UIPass::Initialize(const RenderPassInitInfo* init_info)
    {
    }


    void UIPass::Draw()
    {
        ImGui_ImplDX11_NewFrame();     
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        // ImGui内部示例窗口
        //ImGui::ShowAboutWindow();
        static bool show_demo_window = true;
        if (show_demo_window)
        {
            ImGui::ShowDemoWindow(&show_demo_window);
        }
        //ImGui::ShowUserGuide();


       ImGui::Render();
       ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
    }

    void UIPass::InitImGui(FD3D11DynamicRHI& rhi)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     
        io.ConfigWindowsMoveFromTitleBarOnly = true;           
        
        ImGui::StyleColorsDark();
        ImGui_ImplWin32_Init(rhi.GetWindow());
        ImGui_ImplDX11_Init(rhi.GetDevice(), rhi.GetDeviceContext());
    }

} // namespace MGame
