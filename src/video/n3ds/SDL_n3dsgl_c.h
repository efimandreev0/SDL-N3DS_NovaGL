//
// Created by Notebook on 06.04.2026.
//

#ifndef SDL_n3dsgl_c_h_
#define SDL_n3dsgl_c_h_

#include "../../events/SDL_events_c.h"
#include "../SDL_sysvideo.h"

extern int N3DS_GL_LoadLibrary(_THIS, const char *path);

extern void *N3DS_GL_GetProcAddress(_THIS, const char *proc);

extern void N3DS_GL_UnloadLibrary(_THIS);

extern SDL_GLContext N3DS_GL_CreateContext(_THIS, SDL_Window *window);

extern int N3DS_GL_MakeCurrent(_THIS, SDL_Window *window, SDL_GLContext context);

extern int N3DS_GL_SetSwapInterval(_THIS, int interval);

extern int N3DS_GL_GetSwapInterval(_THIS);

extern int N3DS_GL_SwapWindow(_THIS, SDL_Window *window);

extern void N3DS_GL_DeleteContext(_THIS, SDL_GLContext context);

#endif // SDL3_SDL_N3DSGL_C_H
