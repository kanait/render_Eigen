////////////////////////////////////////////////////////////////////
//
// $Id: myGL.hxx 2024/07/07 18:32:21 kanai Exp $
//
// Copyright (c) 2021-2024 Takashi Kanai
// Released under the MIT license
//
////////////////////////////////////////////////////////////////////

#ifndef _MYGL_HXX
#define _MYGL_HXX 1

#include <GL/glew.h>

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
#elif defined(WIN32) || defined(_WIN32) || defined(_WIN64)
    #include <GL/gl.h>
    #include <GL/glu.h>
#else
    #include <GL/gl.h>
    #include <GL/glu.h>
#endif

#endif // _MYGL_HXX
