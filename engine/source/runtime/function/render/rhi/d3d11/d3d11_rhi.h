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
	FD3D11DynamicRHI(HWND window): m_window(window), m_device(nullptr), m_context(nullptr), m_target(nullptr){}

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

private:
	HWND m_window;
	ID3D11Device * m_device;
	IDXGISwapChain* m_swap;
	ID3D11DeviceContext* m_context;
	ID3D11RenderTargetView* m_target;
};

} // namespace MGame
