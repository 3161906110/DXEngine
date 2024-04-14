            #pragma once
#include <d3d11.h>

#include "runtime/function/render/rhi/rhi_context.h"
#include "runtime/function/render/rhi/dynamic_rhi.h"
#include<cassert>

namespace MGame
{

class FD3D11DynamicRHI : public FDynamicRHI, public IRHICommandContext
{
public:

	/** Initialization constructor. */
	FD3D11DynamicRHI();
	FD3D11DynamicRHI(HWND window): m_window(window), m_device(nullptr), m_context(nullptr), m_render_target_view(nullptr), m_depth_stencil_view(nullptr), m_depth_stencil_buffer(nullptr), m_screen_view_port()
	{}

	/** Destructor */
	virtual ~FD3D11DynamicRHI();
	virtual void InitD3DDevice();

	// FDynamicRHI interface.
	virtual void Init() override;
	virtual void PostInit() override;
	virtual void Shutdown() override;
    

	virtual void RHIBeginFrame() override;
	virtual void RHIEndFrame() override;
	virtual void RHIBeginScene() override;
	virtual void RHIEndScene() override;

	virtual const char* GetName() override { return "D3D11"; }

	HWND GetWindow() const { return m_window; }

	ID3D11Device* GetDevice() const { return m_device; }

	ID3D11DeviceContext* GetDeviceContext() const { return m_context; }

private:
	HWND m_window;
	ID3D11Device * m_device;
	IDXGISwapChain* m_swap;
	ID3D11DeviceContext* m_context;
	ID3D11RenderTargetView* m_render_target_view;
	ID3D11Texture2D* m_depth_stencil_buffer;        // 深度模板缓冲区
	ID3D11DepthStencilView *m_depth_stencil_view;   // 深度模板视图
    D3D11_VIEWPORT m_screen_view_port;                      // 视口
};

} // namespace MGame
