#pragma once
#ifndef __SCREENSHOT_H__
#define __SCREENSHOT_H__

#include <vector>
#include <cstdint>
#include <cstring>
#include <string>
#include <stdexcept>
#include <cstdlib>

#ifdef _WIN32
    #include <windows.h>
#elif __linux__
    #include <unistd.h>
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    #include <dbus/dbus.h>
    #include <fcntl.h>
    #include <sys/stat.h>
#endif

std::vector<uint32_t> capture_screenshot(int& width, int& height);

#endif //__SCREENSHOT_H__
