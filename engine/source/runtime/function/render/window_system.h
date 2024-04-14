#pragma once

#include<Windows.h>
#include<array>

namespace MGame
{
     struct WindowCreateInfo
     {
         int         width {1280};
         int         height {720};
         const char* title {"MGame"};
         bool        is_fullscreen {false};
     };

     class WindowSystem
     {
     public:
        WindowSystem() = default;
        ~WindowSystem();
        void               Initialize(WindowCreateInfo create_info);
        void               SetTitle(const char* title);
        void               PollEvents();
        HWND               GetWindow() const { return m_window; };

        bool              ShouldClose() const;
        std::array<int, 2> GetWindowSize() const;

     private:
         HWND m_window {nullptr};
         int         m_width {0};
         int         m_height {0};

         bool m_is_focus_mode {false};
         bool b_is_close      {false};

     };
} // namespace MGame
