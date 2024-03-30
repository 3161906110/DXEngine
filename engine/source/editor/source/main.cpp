#include "runtime/engine.h"
#include <iostream>
#include<Windows.h>
#include "runtime/function/render/window_system.h"

int main(int argc, char** argv)
{
    MGame::WindowCreateInfo window_create_info;
    MGame::WindowSystem().initialize(window_create_info);

    MGame::MGameEngine().startEngine("");
    while (true)
    {

    }
    return 0;
}
