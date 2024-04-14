#pragma once
#include "runtime/function/render/rhi/rhi_context.h"

namespace MGame
{
class RHICommandListBase
{
public:
	~RHICommandListBase();

    void SetContext(IRHICommandContext* InContext)
	{
		Context = InContext;
	}

	inline IRHICommandContext& GetContext()
	{
		return *Context;
	}

private:
	IRHICommandContext* Context;
};


class RHICommandList : public RHICommandListBase
{

};

class RHICommandListImmediate : public RHICommandList
{

};
} // namespace MGame
