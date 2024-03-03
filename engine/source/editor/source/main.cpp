#include "runtime/engine.h"
#include <iostream>
#include<Windows.h>
#include "runtime/function/render/window_system.h"

int main(int argc, char** argv)
{
    Piccolo::WindowCreateInfo window_create_info;
    Piccolo::WindowSystem().initialize(window_create_info);
    while (1)
    {

    }
    return 0;
}
