#include "runtime/function/render/render_pass.h"
#include "runtime/function/render/rhi/d3d11/d3d11_rhi.h"

namespace MGame
{
    class UIPass : public RenderPass
    {
    public:
        void Initialize(const RenderPassInitInfo* init_info) override final;

        void Draw() override final;

        // TODO 先放这里
        void InitImGui(FD3D11DynamicRHI& rhi);

    };
} // namespace MGame