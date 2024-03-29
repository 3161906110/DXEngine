#include "runtime/function/render/window_system.h"

namespace MGame
{

	WindowSystem::~WindowSystem()
	{
		// TODO �ͷŴ���
		m_window = nullptr;
	}

	void WindowSystem::initialize(WindowCreateInfo create_info)
	{
		m_width = create_info.width;
		m_height = create_info.height;

		const auto pClassName = "hw3dbutts";
		// register window class
		WNDCLASSEX wc = { 0 };
		wc.cbSize = sizeof(wc);
		wc.style = CS_OWNDC;
		wc.lpfnWndProc = DefWindowProc;
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
}