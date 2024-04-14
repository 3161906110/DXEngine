#pragma once


namespace MGame
{
   
class IRHICommandContext
{
public:
	virtual ~IRHICommandContext()
	{
	}

	virtual void RHIBeginFrame() = 0;

	virtual void RHIEndFrame() = 0;


	virtual void RHIBeginScene() = 0;

	virtual void RHIEndScene() = 0;
};
} // namespace MGame
