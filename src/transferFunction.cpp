#include "transferFunction.h"
#include <list>


void loadTF(GLuint &textureTF, Data data){
    std::cout << std::endl;
    std::cout << "  ========== Load Transfer Function As 2D Texture ========== " << std::endl;
    // std::list<transferControlPoint> ColorKnots = new std::list<transferControlPoint> {
    //     new transferControlPoint(.91f, .7f, .61f, 0.0f, 0),
    //     new transferControlPoint(.91f, .7f, .61f, 0.0f, 40),
    //     new transferControlPoint(.91f, .7f, .61f, 0.2f, 60),
    //     new transferControlPoint(.91f, .7f, .61f, 0.05f, 63),
    //     new transferControlPoint(.91f, .7f, .61f, 0.0f, 80),
    //     new transferControlPoint(1.0f, 1.0f, .85f, 0.9f, 82),
    //     new transferControlPoint(1.0f, 1.0f, .85f, 1.0f, 256)
    //     };
    GLubyte texels[32] =
        {
          234, 179, 156, 0,
          234, 179, 156, 0,
          234, 179, 156, 51,
          234, 179, 156, 13,
          234, 179, 156, 0,
          255, 255, 217, 230,
          255, 255, 217, 255,
        };

    check_error_gl("before texture");
    glGenTextures(1, &textureTF);
    glBindTexture(GL_TEXTURE_2D, textureTF);
    //glTexImage2D(GL_TEXTURE_1D, 0, GL_RGBA, ColorKnots.size(), 1, 0, GL_RGBA, GL_UNSIGNED_BYTE, ColorKnots);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 3, 1, 0, GL_RGBA, data.GL_dataType, texels);
    check_error_gl("generate texture");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    std::cout << "  ========== DONE Load Transfer Function As 2D Texture ==========" << std::endl;
}
