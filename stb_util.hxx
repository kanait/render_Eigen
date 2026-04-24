////////////////////////////////////////////////////////////////////
//
// $Id: stb_util.hxx 2021/06/13 15:20:47 kanai Exp $
//
// Copyright (c) 2021 Takashi Kanai
// Released under the MIT license
//
////////////////////////////////////////////////////////////////////

#ifndef _STB_UTIL_HXX
#define _STB_UTIL_HXX 1

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "GLPanel.hxx"

class mySTB {

public:

  int stb_load_texture( const char* const filename, GLPanel& pane ) {
    int w, h, comp;
    stbi_set_flip_vertically_on_load(true);
    // Keep native channels to stay consistent with the channel count passed to GL.
    // Forcing STBI_rgb while using `comp` (original channels) can mismatch on RGBA PNGs.
    unsigned char* image = stbi_load(filename, &w, &h, &comp, 0);
    if(image == nullptr)
      throw(std::string("Failed to load texture"));

    // GLPanel::loadTexture currently supports 3/4 channels.
    if (comp != 3 && comp != 4) {
      stbi_image_free(image);
      throw(std::string("Unsupported texture channels (expected 3 or 4)"));
    }

    unsigned int id = pane.loadTexture( image, w, h, comp );

    stbi_image_free(image);

    return id;
  };

  void stb_capture_and_write( const char* filename, int w, int h, int c, GLPanel& pane )
  {
    std::vector<unsigned char> img( w*h*c );
    pane.capture( &(img[0]), w, h, c );
    // stbi_flip_vertically_on_write(true); // 効かない
    stbi_write_png( filename, w, h, c, &(img[0]), w*c );
    std::cout << "save " << w << "x" << h << " png image <" << filename << "> done. " << std::endl;
  };

};

#endif // STB_UTIL_HXX
