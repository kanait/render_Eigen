////////////////////////////////////////////////////////////////////
//
// $Id: myEigen.hxx $
//
// Copyright (c) 2017 by Takashi Kanai. All rights reserved. 
//
////////////////////////////////////////////////////////////////////

#ifndef _MYGL_HXX
#define _MYGL_HXX 1

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
