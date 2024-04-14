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
        m_render_target_view = nullptr;
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
        if (m_render_target_view != nullptr)
        {
           m_render_target_view = nullptr;
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
        m_render_target_view = nullptr;
    }

    void FD3D11DynamicRHI::RHIBeginFrame()
    {
        // 测试窗口颜色
       // m_context->ClearRenderTargetView(m_target, color);
       static float black[4] = { 0.0f, 0.0f, 0.0f, 1.0f };    // RGBA = (0,0,0,255)

       m_context->ClearRenderTargetView(m_render_target_view, black);
       m_context->ClearDepthStencilView(m_depth_stencil_view, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
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

        int client_width = 1280;
        int client_height = 720;

        DXGI_SWAP_CHAIN_DESC sd;
        sd.BufferDesc.Width = client_width;
        sd.BufferDesc.Height = client_height;
        sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
        sd.BufferDesc.RefreshRate.Numerator = 60;
        sd.BufferDesc.RefreshRate.Denominator = 1;
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
        m_device->CreateRenderTargetView(pBackBuffer, nullptr, &m_render_target_view);
        pBackBuffer->Release();


        // 深度模板缓冲区

        D3D11_TEXTURE2D_DESC depthStencilDesc;

        depthStencilDesc.Width = client_width;
        depthStencilDesc.Height = client_height;
        depthStencilDesc.MipLevels = 1;
        depthStencilDesc.ArraySize = 1;
        depthStencilDesc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;

        depthStencilDesc.SampleDesc.Count = 1;
        depthStencilDesc.SampleDesc.Quality = 0;

        depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;
        depthStencilDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
        depthStencilDesc.CPUAccessFlags = 0;
        depthStencilDesc.MiscFlags = 0;

        m_device->CreateTexture2D(&depthStencilDesc, nullptr, &m_depth_stencil_buffer);

        m_device->CreateDepthStencilView(m_depth_stencil_buffer, nullptr, &m_depth_stencil_view);

        m_context->OMSetRenderTargets(1, &m_render_target_view, m_depth_stencil_view);

        m_screen_view_port.TopLeftX = 0;
        m_screen_view_port.TopLeftY = 0;
        m_screen_view_port.Width    = static_cast<float>(client_width);
        m_screen_view_port.Height   = static_cast<float>(client_height);
        m_screen_view_port.MinDepth = 0.0f;
        m_screen_view_port.MaxDepth = 1.0f;

        m_context->RSSetViewports(1, &m_screen_view_port);

    }

}