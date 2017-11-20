#include "sceneObjects.h"

void Quad::init(){
    std::cout << std::endl;
    std::cout << " ========== Plane Init ========= " << std::endl;
    std::cout << " == Loading plane shaders: " << std::endl;

    program = loadShader("VQuad.glsl","FQuad.glsl");
    ASSERT(program != 0, "Failed to create program");
    check_error_gl("load plane shader");

    glGenVertexArrays(1, &Qvertex_array);
    glBindVertexArray(Qvertex_array);
    ASSERT(Qvertex_array != 0, "Failed to create vertex array object");

    glGenBuffers(1, &Qvertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, Qvertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quad_data), quad_data, GL_STATIC_DRAW);

    posShaderLocation = glGetAttribLocation(program, "pos");
    WARN( posShaderLocation != -1, "Failed to find 'vPosition' location");
    textureShaderLocation = glGetUniformLocation(program, "texture2D");
    WARN( textureShaderLocation != -1, "Failed to find 'vPosition' location");
    std::cout << " ========== DONE ========== " << std::endl;
}

void Quad::draw(GLuint texture){
    glUseProgram(program);
    glBindVertexArray(Qvertex_array);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
    glUniform1i(textureShaderLocation, 0);
    check_error_gl("quad draw");

    glEnableVertexAttribArray(posShaderLocation);
    glBindBuffer(GL_ARRAY_BUFFER, Qvertex_buffer);
    glVertexAttribPointer(posShaderLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glDisableVertexAttribArray(posShaderLocation);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glUseProgram(0);
    check_error_gl("quad draw");
}
void face::init() {
    std::cout << std::endl;
    std::cout << " ========== Face Init ========= " << std::endl;
    std::cout << " == Loading Face shaders: " << std::endl;
    program = loadShader("VFace.glsl", "FFace.glsl");
    ASSERT(program != 0, "Failed to create program");
    check_error_gl("load face shader");

    glGenVertexArrays(1, &Fvertex_array);
    glBindVertexArray(Fvertex_array);
    ASSERT(Fvertex_array != 0, "Failed to create vertex array object");
    glGenBuffers(1, &Fvertex_buffer);
    ASSERT(Fvertex_buffer != 0, "Failed to create vertex buffer object");
    glGenBuffers(1, &Ftexture_buffer);
    ASSERT(Ftexture_buffer != 0, "Failed to create vertex buffer object");

    FposLocation = glGetAttribLocation(program, "pos");
    ASSERT(FposLocation != -1, "Failed to find 'pos' location");
    // FtexLocation = glGetAttribLocation(program, "tex");
    // ASSERT(FtexLocation != -1, "Failed to find 'tex' location");

    std::cout << " ========== DONE Init Face ========== " << std::endl;
}

void face::draw(Vertices vertices){
    glUseProgram(program);
    glBindVertexArray(Fvertex_array);
    size_t data_size = vertices.vertex_array.size();

    glEnableVertexAttribArray(FposLocation);
    glBindBuffer(GL_ARRAY_BUFFER, Fvertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data_size, vertices.vertex_array.data(), GL_DYNAMIC_DRAW);
    check_error_gl("in rendering");
    glVertexAttribPointer(FposLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);

    glEnableVertexAttribArray(FtexLocation);
    glBindBuffer(GL_ARRAY_BUFFER, Ftexture_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data_size, vertices.texture_array.data(), GL_DYNAMIC_DRAW);
    glVertexAttribPointer(FtexLocation, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);


//    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLE_FAN, 0, data_size / 3);
}



void volumeObj::init(){
    std::cout << std::endl;
    std::cout << " ========== Volume Init ========= " << std::endl;
    std::cout << " == Loading volume shaders: " << std::endl;

    program = loadShader("VTextureBasedVolumeRenderer.glsl","FTextureBasedVolumeRenderer.glsl");
    ASSERT(program != 0, "Failed to create program");
    check_error_gl("load volume shader");

    glGenVertexArrays(1, &volume_vertex_array);
    glBindVertexArray(volume_vertex_array);
    ASSERT(volume_vertex_array != 0, "Failed to create vertex array object");

    glGenBuffers(1, &volume_vertex_buffer);
    ASSERT(volume_vertex_buffer != 0, "Failed to create vertex buffer object");

    glGenBuffers(1, &volume_texture_buffer);
    ASSERT(volume_texture_buffer != 0, "Failed to create texture buffer object");

    volume_posShader = glGetAttribLocation(program, "pos");
    ASSERT(volume_posShader != -1, "Failed to find 'pos' location");
    volume_texShader = glGetAttribLocation(program, "tex");
    ASSERT(volume_texShader != -1, "Failed to find 'tex' location");

    volume_preTexShader = glGetUniformLocation(program, "preTex");
    volume_dataTexShader = glGetUniformLocation(program, "dataTex");
    volume_tfTexShader = glGetUniformLocation(program, "tfTex");

    WARN(volume_preTexShader != -1, "Failed to find 'tex2d' location");
    WARN(volume_dataTexShader != -1, "Failed to find 'tex3d' location");
    WARN(volume_tfTexShader != -1, "Failed to find 'textf' location");

    sample_rateShader = glGetUniformLocation(program, "sample_rate");
    ASSERT(sample_rateShader != -1, "Failed to find 'sample_rate' location");

    std::cout << " ========== DONE ========== " << std::endl;

}

void volumeObj::bind(){
    glUseProgram(program);
    glBindVertexArray(volume_vertex_array);
}

void volumeObj::activeTexture(GLuint texture3D, GLuint textureTF, GLuint pre_slice, float sample_rate){

  glUniform1f(sample_rateShader, sample_rate);

  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, pre_slice);
  glUniform1i(volume_preTexShader, 0);

  glActiveTexture(GL_TEXTURE1);
  glBindTexture(GL_TEXTURE_3D, texture3D);
  glUniform1i(volume_dataTexShader, 1);

  glActiveTexture(GL_TEXTURE2);
  glBindTexture(GL_TEXTURE_2D, textureTF);
  glUniform1i(volume_tfTexShader, 2);
    check_error_gl("active texture");
}

//void volumeObj::draw(Vertices vertices){
//
//    size_t data_size = vertices.vertex_array.size();
//
//    glEnableVertexAttribArray(volume_posShader);
//    glBindBuffer(GL_ARRAY_BUFFER, volume_vertex_buffer);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data_size, vertices.vertex_array.data(), GL_DYNAMIC_DRAW);
//    glVertexAttribPointer(volume_posShader, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
//
//    glEnableVertexAttribArray(volume_texShader);
//    glBindBuffer(GL_ARRAY_BUFFER, volume_texture_buffer);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data_size, vertices.texture_array.data(), GL_DYNAMIC_DRAW);
//    glVertexAttribPointer(volume_texShader, 3, GL_FLOAT, GL_FALSE, 0, (void*) 0);
//
//    check_error_gl("in rendering");
//
//    glClear(GL_DEPTH_BUFFER_BIT);
//    glDrawArrays(GL_TRIANGLE_FAN, 0, data_size / 3);
//}
