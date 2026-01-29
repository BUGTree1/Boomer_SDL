#include "screenshot.h"

using namespace std;

#ifdef _WIN32
std::vector<uint32_t> capture_screenshot(int& width, int& height) {
    cout << "TODO: capture_screenshot WINDOW" << endl;
    return std::vector<uint32_t>();
}

#endif //_WIN32
#ifdef __linux__

std::vector<uint32_t> capture_x11(int& width, int& height) {
    cout << "TODO: capture_x11" << endl;
    return std::vector<uint32_t>();
}

std::vector<uint32_t> capture_wayland(int& width, int& height) {
    cout << "TODO: capture_wayland" << endl;
    return std::vector<uint32_t>();
}

std::vector<uint32_t> capture_screenshot(int& width, int& height) {
    const char* session = getenv("XDG_SESSION_TYPE");
    if (session && strcmp(session, "wayland") == 0) {
        return capture_wayland(width, height);
    } else {
        return capture_x11(width, height);
    }
}

#endif //__linux__
