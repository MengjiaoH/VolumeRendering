#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "common.h"
#include "loadRaw.h"

class framebufferObj{

private:
    GLuint FBO = 0;
    GLuint* FBO_colorbuffer = NULL;
    GLuint FBO_depthbuffer = 0;
    GLint   previewport[4];

public:

  framebufferObj() = default;
  ~framebufferObj(){
      if (FBO_colorbuffer) delete [] FBO_colorbuffer;
    }

  void init(unsigned int width, unsigned int height, Data data);

  void generateColorTexture(unsigned int width, unsigned int height, size_t i, Data data);
  void generateDepthTexture(unsigned int width, unsigned int height);

  //bind framebuffer to pipeline. We will  call this method in the render loop
  void bind(unsigned int width, unsigned int height);
    void bindFBO(){
      glBindFramebuffer(GL_FRAMEBUFFER, FBO);
      glViewport(previewport[0], previewport[1],previewport[2],previewport[3]);
    }


  //unbind framebuffer from pipeline. We will call this method in the render loop
  void unbind(){
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(previewport[0],previewport[1],previewport[2],previewport[3]);
  }
//
//
//  void reset(unsigned int width, unsigned int height, Data data);

  GLenum getColorTexture(){ return FBO_colorbuffer[0];}
//
  void clear() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glDeleteFramebuffers(1, &FBO);
    glDeleteRenderbuffers(1, &FBO_depthbuffer);
    if (FBO_colorbuffer) {
      glDeleteTextures(1, FBO_colorbuffer);
      delete [] FBO_colorbuffer;
      FBO_colorbuffer = NULL;
    }
  }

};
