#pragma once

#include "runtime/function/render/render_pass_base.h"


namespace MGame
{
    
    class RenderPass : public RenderPassBase
    {
    public:

        void Initialize(const RenderPassInitInfo* init_info) override;
        void PostInitialize() override;

        virtual void Draw();
    };
} // namespace MGame
