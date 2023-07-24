////////////////////////////////////////////////////////////////////
//
// $Id: myGL.hxx 2023/07/23 15:16:09 kanai Exp $
//
// Copyright (c) 2021 Takashi Kanai
// Released under the MIT license
//
////////////////////////////////////////////////////////////////////

#ifndef _MYGL_HXX
#define _MYGL_HXX 1

#include <GL/glew.h>

#ifdef __APPLE__
//    #include <OpenGL/gl.h>
    #include <OpenGL/gl3.h>
    #include <OpenGL/glu.h>
#elif defined(WIN32) || defined(_WIN32) || defined(_WIN64)
    #include <GL/gl.h>
    #include <GL/glu.h>
#else
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#endif // _MYGL_HXX
