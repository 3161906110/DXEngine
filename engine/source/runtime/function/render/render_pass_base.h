#pragma once

namespace MGame
{
    
    struct RenderPassInitInfo
    {};

    class RenderPassBase
    {
    public:
        virtual void Initialize(const RenderPassInitInfo* init_info) = 0;
        virtual void PostInitialize();

    };

} // namespace MGame

