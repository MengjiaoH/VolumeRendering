#include "loadTexture3D.h"

GLuint loadTexture3D(Data data){
    std::cout << std::endl;
    int maxDepth = data.depth;
    std::cout << "  ========== Load Volume As 3D Texture ========== " << std::endl;
    std::cout << "  Data Depth is: " << maxDepth << std::endl;
    char* data_ptr = (char*) data.raw_data_ptr;
    if(data_ptr == NULL)
        throw std::runtime_error("Data Loaded Unsuccessfully ");

    check_error_gl("before texture");

    GLuint texture3D;
    glGenTextures(1, &texture3D);
    glBindTexture(GL_TEXTURE_3D, texture3D);
    std::cout << "data GL type: " << data.GL_dataType << std::endl;
    glTexImage3D(GL_TEXTURE_3D, 0, GL_RED, data.dimX, data.dimY, data.dimZ, 0, GL_RED, data.GL_dataType, data_ptr);

    check_error_gl("generate texture");

    //glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    check_error_gl("filter texture");

    std::cout << "  ========== DONE Load Volume As 3D Texture ==========" << std::endl;
    return texture3D;
}
