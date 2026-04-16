//
// Created by Notebook on 06.04.2026.
//
#include "../../SDL_internal.h"
#include "SDL_n3dsgl_c.h"
#include <string.h>

#include <../../../devkitpro/portlibs/3ds/include/NovaGL.h>

int N3DS_GL_LoadLibrary(_THIS, const char *path) {
    (void)path;
    return 0;
}

void N3DS_GL_UnloadLibrary(_THIS) {
}

SDL_GLContext N3DS_GL_CreateContext(_THIS, SDL_Window *window) {
    (void)window;

    gfxExit();

    gfxInitDefault();
    nova_init();

    return (SDL_GLContext)1;
}

int N3DS_GL_MakeCurrent(_THIS, SDL_Window *window, SDL_GLContext context) {
    (void)window;
    (void)context;
    return 0;
}

int N3DS_GL_SetSwapInterval(_THIS, int interval) {
    (void)interval;
    return 0;
}

int N3DS_GL_GetSwapInterval(_THIS) {
    return 1;
}

int N3DS_GL_SwapWindow(_THIS, SDL_Window *window) {
    (void)window;

    // swapping
    novaSwapBuffers();

    return 0;
}

void N3DS_GL_DeleteContext(_THIS, SDL_GLContext context) {
    (void)context;

    // ending NovaGL
    nova_fini();
}

void *N3DS_GL_GetProcAddress(_THIS, const char *proc) {
    (void)_this;
    return novaglGetProcAddress(proc); //epic bruh moment: getting proc address.
}