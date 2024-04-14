#include "runtime/function/render/rhi/d3d11/d3d11_rhi.h"

#pragma comment(lib, "d3d11.lib")

namespace MGame
{

    FD3D11DynamicRHI::FD3D11DynamicRHI()
    {
        m_window = 0;
        m_swap = 0;
        m_device = nullptr;
        m_context = nullptr;
        m_target = nullptr;
    }


    FD3D11DynamicRHI::~FD3D11DynamicRHI()
    {

    }

    void FD3D11DynamicRHI::Init()
    {
	    InitD3DDevice();
    }

    void FD3D11DynamicRHI::PostInit()
    {

    }


    void FD3D11DynamicRHI::Shutdown()
    {
        //释放资源
        if (m_target != nullptr)
        {
            m_target = nullptr;
        }
        if (m_context != nullptr)
        {
            m_context->Release();
        }
        if (m_swap != nullptr)
        {
            m_swap->Release();
        }
        if (m_device != nullptr)
        {
            m_device->Release();
        }


        m_window = 0;
        m_device = nullptr;
        m_context = nullptr;
        m_swap = nullptr;
        m_target = nullptr;
    }

    void FD3D11DynamicRHI::RHIBeginFrame()
    {
        // 测试窗口颜色
        const float color[] = { 0.f, 0.f, 255.f, 1.0f };
        m_context->ClearRenderTargetView(m_target, color);

    }

	void FD3D11DynamicRHI::RHIEndFrame()
    {
        m_swap->Present(1u, 0u);
    }


	void FD3D11DynamicRHI::RHIBeginScene()
    {

    }

	void FD3D11DynamicRHI::RHIEndScene()
    {
        
    }

    void FD3D11DynamicRHI::InitD3DDevice()
    {
        DXGI_SWAP_CHAIN_DESC sd;
        sd.BufferDesc.Width = 0;
        sd.BufferDesc.Height = 0;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.BufferDesc.RefreshRate.Numerator = 0;
        sd.BufferDesc.RefreshRate.Denominator = 0;
        sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
        sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
        sd.SampleDesc.Count = 1;
        sd.SampleDesc.Quality = 0;
        sd.BufferUsage    = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        sd.BufferCount    = 1;
        sd.OutputWindow = m_window;
        sd.Windowed      = true;
        sd.SwapEffect    = DXGI_SWAP_EFFECT_DISCARD;
        sd.Flags          = 0;    

        D3D11CreateDeviceAndSwapChain(
            nullptr,
            D3D_DRIVER_TYPE_HARDWARE,
            nullptr,
            0,
            nullptr,
            0,
            D3D11_SDK_VERSION,
            &sd,
            &m_swap,
            &m_device,
            nullptr,
            &m_context
        );

        // 获取帧缓冲区视图
        ID3D11Resource* pBackBuffer = nullptr;
        m_swap->GetBuffer(0, _uuidof(ID3D11Resource), reinterpret_cast<void**>(&pBackBuffer));
        m_device->CreateRenderTargetView(pBackBuffer, nullptr, &m_target);
        pBackBuffer->Release();
    }

}