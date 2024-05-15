#include "platform/platform.h"

// Windows platform layer
#if KPLATFORM_WINDOWS

#include <windows.h>
#include <windowsx.h> // Parameter input extraction

typedef struct internal_state
{
    HINSTANCE h_instance;
    HWND hwnd;
} internal_state;

b8 platform_startup(
    platform_state *plat_state,
    const char *application_name,
    i32 x,
    i32 y,
    i32 width,
    i32 height)
{
    plat_state->internal_state = malloc(sizeof(internal_state));
    internal_state *state = (internal_state *)plat_state->internal_state;
}

#endif