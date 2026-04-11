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

    #define RET_GL_FUNC(name) if (strcmp(proc, #name) == 0) return (void *)name;

    // --- State & Core ---
    RET_GL_FUNC(glEnable);
    RET_GL_FUNC(glDisable);
    RET_GL_FUNC(glIsEnabled);
    RET_GL_FUNC(glGetError);
    RET_GL_FUNC(glGetFloatv);
    RET_GL_FUNC(glGetIntegerv);
    RET_GL_FUNC(glGetString);
    RET_GL_FUNC(glHint);

    // --- Clear & Viewport ---
    RET_GL_FUNC(glClear);
    RET_GL_FUNC(glClearColor);
    RET_GL_FUNC(glClearDepthf);
    RET_GL_FUNC(glClearDepth);
    RET_GL_FUNC(glClearStencil);
    RET_GL_FUNC(glViewport);
    RET_GL_FUNC(glScissor);

    // --- Depth, Blend & Rasterization ---
    RET_GL_FUNC(glDepthFunc);
    RET_GL_FUNC(glDepthMask);
    RET_GL_FUNC(glDepthRangef);
    RET_GL_FUNC(glDepthRange);
    RET_GL_FUNC(glBlendFunc);
    RET_GL_FUNC(glAlphaFunc);
    RET_GL_FUNC(glCullFace);
    RET_GL_FUNC(glFrontFace);
    RET_GL_FUNC(glShadeModel);
    RET_GL_FUNC(glPolygonOffset);
    RET_GL_FUNC(glLineWidth);
    RET_GL_FUNC(glPolygonMode);
    RET_GL_FUNC(glColorMaterial);

    // --- Color ---
    RET_GL_FUNC(glColor3b);
    RET_GL_FUNC(glColor3bv);
    RET_GL_FUNC(glColor3d);
    RET_GL_FUNC(glColor3dv);
    RET_GL_FUNC(glColor3f);
    RET_GL_FUNC(glColor3fv);
    RET_GL_FUNC(glColor3i);
    RET_GL_FUNC(glColor3iv);
    RET_GL_FUNC(glColor3s);
    RET_GL_FUNC(glColor3sv);
    RET_GL_FUNC(glColor3ub);
    RET_GL_FUNC(glColor3ubv);
    RET_GL_FUNC(glColor3ui);
    RET_GL_FUNC(glColor3uiv);
    RET_GL_FUNC(glColor3us);
    RET_GL_FUNC(glColor3usv);
    RET_GL_FUNC(glColor4b);
    RET_GL_FUNC(glColor4bv);
    RET_GL_FUNC(glColor4d);
    RET_GL_FUNC(glColor4dv);
    RET_GL_FUNC(glColor4f);
    RET_GL_FUNC(glColor4fv);
    RET_GL_FUNC(glColor4i);
    RET_GL_FUNC(glColor4iv);
    RET_GL_FUNC(glColor4s);
    RET_GL_FUNC(glColor4sv);
    RET_GL_FUNC(glColor4ub);
    RET_GL_FUNC(glColor4ubv);
    RET_GL_FUNC(glColor4ui);
    RET_GL_FUNC(glColor4uiv);
    RET_GL_FUNC(glColor4us);
    RET_GL_FUNC(glColor4usv);
    RET_GL_FUNC(glColorMask);

    // --- Normals ---
    RET_GL_FUNC(glNormal3b);
    RET_GL_FUNC(glNormal3bv);
    RET_GL_FUNC(glNormal3d);
    RET_GL_FUNC(glNormal3dv);
    RET_GL_FUNC(glNormal3f);
    RET_GL_FUNC(glNormal3fv);
    RET_GL_FUNC(glNormal3i);
    RET_GL_FUNC(glNormal3iv);
    RET_GL_FUNC(glNormal3s);
    RET_GL_FUNC(glNormal3sv);

    // --- Matrices & Transforms ---
    RET_GL_FUNC(glMatrixMode);
    RET_GL_FUNC(glLoadIdentity);
    RET_GL_FUNC(glPushMatrix);
    RET_GL_FUNC(glPopMatrix);
    RET_GL_FUNC(glTranslatef);
    RET_GL_FUNC(glTranslated);
    RET_GL_FUNC(glRotatef);
    RET_GL_FUNC(glRotated);
    RET_GL_FUNC(glScalef);
    RET_GL_FUNC(glScaled);
    RET_GL_FUNC(glMultMatrixf);
    RET_GL_FUNC(glMultMatrixd);
    RET_GL_FUNC(glLoadMatrixf);
    RET_GL_FUNC(glLoadMatrixd);
    RET_GL_FUNC(glOrtho);
    RET_GL_FUNC(glOrthof);
    RET_GL_FUNC(glFrustumf);
    RET_GL_FUNC(glFrustum);
    RET_GL_FUNC(glFrustumx);

    // --- Textures ---
    RET_GL_FUNC(glGenTextures);
    RET_GL_FUNC(glDeleteTextures);
    RET_GL_FUNC(glBindTexture);
    RET_GL_FUNC(glIsTexture);
    RET_GL_FUNC(glTexImage2D);
    RET_GL_FUNC(glTexSubImage2D);
    RET_GL_FUNC(glTexImage1D);
    RET_GL_FUNC(glTexSubImage1D);
    RET_GL_FUNC(glTexParameteri);
    RET_GL_FUNC(glTexParameterf);
    RET_GL_FUNC(glTexParameterfv);
    RET_GL_FUNC(glTexParameteriv);
    RET_GL_FUNC(glCompressedTexImage2D);
    RET_GL_FUNC(glActiveTexture);
    RET_GL_FUNC(glClientActiveTexture);
    RET_GL_FUNC(glMultiTexCoord4f);
    RET_GL_FUNC(glMultiTexCoord2fARB);
    RET_GL_FUNC(glActiveTextureARB);
    RET_GL_FUNC(glClientActiveTextureARB);
    RET_GL_FUNC(glTexEnvi);
    RET_GL_FUNC(glTexEnvf);
    RET_GL_FUNC(glTexEnvfv);

    // --- TexGen ---
    RET_GL_FUNC(glTexGend);
    RET_GL_FUNC(glTexGendv);
    RET_GL_FUNC(glTexGenf);
    RET_GL_FUNC(glTexGenfv);
    RET_GL_FUNC(glTexGeni);
    RET_GL_FUNC(glTexGeniv);

    // --- TexCoord ---
    RET_GL_FUNC(glTexCoord1d);
    RET_GL_FUNC(glTexCoord1dv);
    RET_GL_FUNC(glTexCoord1f);
    RET_GL_FUNC(glTexCoord1fv);
    RET_GL_FUNC(glTexCoord1i);
    RET_GL_FUNC(glTexCoord1iv);
    RET_GL_FUNC(glTexCoord1s);
    RET_GL_FUNC(glTexCoord1sv);
    RET_GL_FUNC(glTexCoord2d);
    RET_GL_FUNC(glTexCoord2dv);
    RET_GL_FUNC(glTexCoord2f);
    RET_GL_FUNC(glTexCoord2fv);
    RET_GL_FUNC(glTexCoord2i);
    RET_GL_FUNC(glTexCoord2iv);
    RET_GL_FUNC(glTexCoord2s);
    RET_GL_FUNC(glTexCoord2sv);
    RET_GL_FUNC(glTexCoord3d);
    RET_GL_FUNC(glTexCoord3dv);
    RET_GL_FUNC(glTexCoord3f);
    RET_GL_FUNC(glTexCoord3fv);
    RET_GL_FUNC(glTexCoord3i);
    RET_GL_FUNC(glTexCoord3iv);
    RET_GL_FUNC(glTexCoord3s);
    RET_GL_FUNC(glTexCoord3sv);
    RET_GL_FUNC(glTexCoord4d);
    RET_GL_FUNC(glTexCoord4dv);
    RET_GL_FUNC(glTexCoord4f);
    RET_GL_FUNC(glTexCoord4fv);
    RET_GL_FUNC(glTexCoord4i);
    RET_GL_FUNC(glTexCoord4iv);
    RET_GL_FUNC(glTexCoord4s);
    RET_GL_FUNC(glTexCoord4sv);

    // --- VBOs (Vertex Buffer Objects) ---
    RET_GL_FUNC(glGenBuffers);
    RET_GL_FUNC(glDeleteBuffers);
    RET_GL_FUNC(glBindBuffer);
    RET_GL_FUNC(glBufferData);
    RET_GL_FUNC(glBufferSubData);

    // --- Vertex Arrays (Client State) ---
    RET_GL_FUNC(glEnableClientState);
    RET_GL_FUNC(glDisableClientState);
    RET_GL_FUNC(glVertexPointer);
    RET_GL_FUNC(glTexCoordPointer);
    RET_GL_FUNC(glColorPointer);
    RET_GL_FUNC(glNormalPointer);

    // --- Immediate Mode ---
    RET_GL_FUNC(glBegin);
    RET_GL_FUNC(glEnd);
    RET_GL_FUNC(glArrayElement);

    // --- Vertex ---
    RET_GL_FUNC(glVertex2d);
    RET_GL_FUNC(glVertex2dv);
    RET_GL_FUNC(glVertex2f);
    RET_GL_FUNC(glVertex2fv);
    RET_GL_FUNC(glVertex2i);
    RET_GL_FUNC(glVertex2iv);
    RET_GL_FUNC(glVertex2s);
    RET_GL_FUNC(glVertex2sv);
    RET_GL_FUNC(glVertex3d);
    RET_GL_FUNC(glVertex3dv);
    RET_GL_FUNC(glVertex3f);
    RET_GL_FUNC(glVertex3fv);
    RET_GL_FUNC(glVertex3i);
    RET_GL_FUNC(glVertex3iv);
    RET_GL_FUNC(glVertex3s);
    RET_GL_FUNC(glVertex3sv);
    RET_GL_FUNC(glVertex4d);
    RET_GL_FUNC(glVertex4dv);
    RET_GL_FUNC(glVertex4f);
    RET_GL_FUNC(glVertex4fv);
    RET_GL_FUNC(glVertex4i);
    RET_GL_FUNC(glVertex4iv);
    RET_GL_FUNC(glVertex4s);
    RET_GL_FUNC(glVertex4sv);

    // --- Drawing ---
    RET_GL_FUNC(glDrawArrays);
    RET_GL_FUNC(glDrawElements);
    RET_GL_FUNC(glFlush);
    RET_GL_FUNC(glFinish);

    // --- Fog ---
    RET_GL_FUNC(glFogf);
    RET_GL_FUNC(glFogfv);
    RET_GL_FUNC(glFogi);
    RET_GL_FUNC(glFogiv);
    RET_GL_FUNC(glFogx);

    // --- Pixels ---
    RET_GL_FUNC(glReadPixels);
    RET_GL_FUNC(glPixelStorei);
    RET_GL_FUNC(glPixelStoref);
    RET_GL_FUNC(glDrawBuffer);
    RET_GL_FUNC(glClipPlane);

    // --- Stencil ---
    RET_GL_FUNC(glStencilFunc);
    RET_GL_FUNC(glStencilMask);
    RET_GL_FUNC(glStencilOp);

    // --- Framebuffers & Renderbuffers (FBO) ---
    RET_GL_FUNC(glGenFramebuffers);
    RET_GL_FUNC(glDeleteFramebuffers);
    RET_GL_FUNC(glBindFramebuffer);
    RET_GL_FUNC(glGenRenderbuffers);
    RET_GL_FUNC(glDeleteRenderbuffers);
    RET_GL_FUNC(glBindRenderbuffer);
    RET_GL_FUNC(glRenderbufferStorage);
    RET_GL_FUNC(glFramebufferRenderbuffer);

    // --- Display Lists ---
    RET_GL_FUNC(glGenLists);
    RET_GL_FUNC(glNewList);
    RET_GL_FUNC(glEndList);
    RET_GL_FUNC(glCallList);
    RET_GL_FUNC(glCallLists);
    RET_GL_FUNC(glDeleteLists);

    // --- Attribute Stack ---
    RET_GL_FUNC(glPushAttrib);
    RET_GL_FUNC(glPopAttrib);
    RET_GL_FUNC(glPushClientAttrib);
    RET_GL_FUNC(glPopClientAttrib);

    #undef RET_GL_FUNC

    return NULL;
}