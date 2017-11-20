#include <iostream>
#include "common.h"
#include "loadShaders.h"


class Quad{
private:
    GLuint program = 0;
    GLuint Qvertex_array;
    GLuint Qvertex_buffer;
    GLuint posShaderLocation;
    GLuint textureShaderLocation;
    float quad_data[12] = { 1.0f, 1.0f, 0.0f,
                            -1.0f, 1.0f, 0.0f,
                            1.0f, -1.0f, 0.0f,
                            -1.0f, -1.0f, 0.0f
                            };
public:
    Quad() = default;
    void init();
    void draw(GLuint texture);

};

class face{
private:
    GLuint program = 0;
    GLuint Fvertex_array;
    GLuint Fvertex_buffer;
    GLuint Ftexture_buffer;
    GLuint FposLocation;
    GLuint FtexLocation;

public:
    face() = default;
    void init();
    void draw(Vertices vertices);

};

class volumeObj{
private:
    GLuint program = 0;
    GLuint volume_vertex_array;
    GLuint volume_vertex_buffer;
    GLuint volume_texture_buffer;
    // variables for shaders
    GLuint volume_posShader;
    GLuint volume_texShader;
    GLuint volume_dataTexShader;
    GLuint volume_preTexShader;
    GLuint volume_tfTexShader;
    GLuint sample_rateShader;

public:
    void init();
    void bind();
    void activeTexture(GLuint texture3D, GLuint textureTF, GLuint pre_slice, float sample_rate);
    //void draw(Vertices vertices);
};