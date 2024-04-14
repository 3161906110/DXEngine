#pragma once

namespace MGame
{
    
class FDynamicRHI
{
public:
    virtual ~FDynamicRHI() {}

    virtual void Init() = 0;

    virtual void PostInit() {}

    virtual void Shutdown() = 0;
        
    virtual const char* GetName() = 0;
};
 
} // namespace MGame
