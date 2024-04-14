#include "runtime/function/render/window_system.h"
#include <backends/imgui_impl_win32.h>


extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace MGame
{

	LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_CLOSE:
			PostQuitMessage(69);
			break;
		}

		if (ImGui_ImplWin32_WndProcHandler(hwnd, msg, wParam, lParam))
		{
			return true;
		}

		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	WindowSystem::~WindowSystem()
	{
		// TODO 释放窗口
		m_window = nullptr;
	}

	void WindowSystem::Initialize(WindowCreateInfo create_info)
	{
		m_width = create_info.width;
		m_height = create_info.height;

		const auto pClassName = "hw3dbutts";
		// register window class
		WNDCLASSEX wc = { 0 };
		wc.cbSize = sizeof(wc);
		wc.style = CS_OWNDC;
		wc.lpfnWndProc = WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = GetModuleHandle(nullptr);
		wc.hIcon = nullptr;
		wc.hCursor = nullptr;
		wc.hbrBackground = nullptr;
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = pClassName;
		wc.hIconSm = nullptr;
		RegisterClassEx(&wc);

		// creat window
		m_window = CreateWindowEx(
			0, pClassName,
			"MGame Window",
			WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
			200, 200, m_width, m_height,
			nullptr, nullptr, GetModuleHandle(nullptr), nullptr
		);

		// show window
		ShowWindow(m_window, SW_SHOW);
	}

	void WindowSystem::SetTitle(const char* title)
	{

	}

	void WindowSystem::PollEvents()
	{
		MSG msg;
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				b_is_close = true;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
	}

	bool WindowSystem::ShouldClose() const
	{
		return b_is_close;
	}

	std::array<int, 2> WindowSystem::GetWindowSize() const
	{
		return { m_width, m_height };
	}

}