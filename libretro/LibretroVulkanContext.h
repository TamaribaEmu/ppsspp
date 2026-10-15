#pragma once

#include "libretro/LibretroGraphicsContext.h"

class LibretroVulkanContext : public LibretroHWRenderContext {
public:
	LibretroVulkanContext();
   ~LibretroVulkanContext() override { Shutdown(); }
	bool Init() override;
	void Shutdown() override;
	void SwapBuffers() override;

	void *GetAPIContext() override;
	void CreateDrawContext() override;

	void ContextReset() override;
	void ContextDestroy() override;
	// A new internal resolution while the game runs: the swapchain's images take the new size
	// (a context reset, as the other backends use, does not work with Vulkan).
	void ResizeBackbuffer();

	GPUCore GetGPUCore() override { return GPUCORE_VULKAN; }
	const char *Ident() override { return "Vulkan"; }
};
