#include "viewPort.h"
#include "glm/ext.hpp"

extern Data volumeData;

GLFWwindow* window;

GLuint texture3D; // volume
GLuint textureTF; // transfer function

static framebufferObj fbo;
static framebufferObj frontfaceFBO;
static framebufferObj backfaceFBO;
static face frontface;
static face backface;
static Quad quad; // used to render screen to quad texture
static volumeObj volume;

float sample_rate = 1.0f;
float plane_sample_rate;
float unit_voxel;
Vertices vertices;

static const GLfloat debug_triangle[] = {
  -1.0f, -1.0f, 0.0f,
  1.0f, -1.0f, 0.0f,
  0.0f, 1.0f, 0.0f,
};

std::vector<glm::vec3> triangle{
  glm::vec3(-1.0f, -1.0f, 0.0f),
  glm::vec3(1.0f, -1.0f, 0.0f),
  glm::vec3(0.0f, 1.0f, 0.0f)
};

std::vector<glm::vec3> volume_bb {
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(-1.0f, 1.0f, 1.0f),
        glm::vec3(-1.0f, -1.0f, 1.0f),
        glm::vec3(1.0f, -1.0f, 1.0f),
        glm::vec3(1.0f, -1.0f, -1.0f),
        glm::vec3(1.0f, 1.0f, -1.0f),
        glm::vec3(-1.0f, 1.0f, -1.0f),
        glm::vec3(-1.0f, -1.0f, -1.0f)
};

std::vector<glm::vec3> texture_bb{
        glm::vec3(1.0f, 1.0f, 1.0f),
        glm::vec3(0.0f, 1.0f, 1.0f),
        glm::vec3(0.0f, 0.0f, 1.0f),
        glm::vec3(1.0f, 0.0f, 1.0f),
        glm::vec3(1.0f, 0.0f, 0.0f),
        glm::vec3(1.0f, 1.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(0.0f, 0.0f, 0.0f)
};


void fetchVertices(Vertices &vertices, std::string face) {
    int start, end;
    if (face == "front") {
        start = 0; end = volume_bb.size() - 1;
    }else if(face == "back"){
        start = 1; end = volume_bb.size();
    }
    const glm::mat4& mvp = GetMVPMatrix();
    for(int i = start; i < end; i++){
        glm::vec4 temp;
        temp = mvp * glm::vec4(volume_bb[i], 1.0f);
        vertices.vertex_array.push_back(temp.x / temp.w);
        vertices.vertex_array.push_back(temp.y / temp.w);
        vertices.vertex_array.push_back(temp.z / temp.w);
        vertices.texture_array.push_back(texture_bb[i].x);
        vertices.texture_array.push_back(texture_bb[i].y);
        vertices.texture_array.push_back(texture_bb[i].z);
    }
}

int ShowViewPort(){
  std::cout << "  ========== Start Show View Port ==========" << std::endl;
    if (!glfwInit()) {
          fprintf( stderr, "Failed to initialize GLFW\n" );
		      return -1;
        }else{
          std::cout << std::endl;
          std::cout << "  Done Initialize GLFW  " << std::endl;
      }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(CameraWidth(), CameraHeight(), "Texture Based Volume Renderer", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }
    // Ensure we can capture the escape key being pressed below
  	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

//     glfwSetKeyCallback(window, key_callback);
//     glfwSetWindowSizeCallback(window, window_size_callback);
//     glfwSetCursorPosCallback(window, cursor_position_callback);
// //    glfwSetScrollCallback(window, scroll_callback);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glewExperimental = GL_TRUE;
    /*
    ** Initialize GLEW
    */
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
    }else{
      std::cout << std::endl;
      std::cout << "  Done Initialize GLEW " << std::endl;
    }
    // GLenum error = glGetError();
    // std::cout << std::endl;
    // std::cout << "  ========== OpenGL Info ========== " << std::endl;
    // std::cout << std::endl;
    // // print out some info about the graphics drivers
    // std::cout << "  OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    // std::cout << "  GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    //
	  // if (error != GL_NO_ERROR){
		//     std::cout << "  OpenGL Error: " << error << std::endl;
	  // }

    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    //glEnable(GL_DEPTH_TEST);
    // // Accept fragment if it closer to the camera than the former one
    // glDepthFunc(GL_LESS);

    check_error_gl("setup environment checking");

    std::cout << std::endl;
    std::cout << "  ========== Start Loading Textures ========== " << std::endl;

    /*
    ** Load Volume as 3D Texture
    */
    texture3D = loadTexture3D(volumeData);
    std::cout << std::endl;
    std::cout << "  == 3D Texture Location is: " << texture3D << std::endl;

    /*
    ** Load Transfer Function as 1D Texture
    */
    loadTF(textureTF, volumeData);
    std::cout << std::endl;
    std::cout << "  == Transfer Function Texture Location is: " << textureTF << std::endl;

    /*
    ** Initialize frambuffer
    */
    // fbo.init(CameraWidth(), CameraHeight(), volumeData);
    // frontfaceFBO.init(CameraWidth(), CameraHeight(), volumeData);
    // backfaceFBO.init(CameraWidth(), CameraHeight(), volumeData);

    /*
    ** Initialize volume compose
    */
    //volume.init();

    /*
    ** Initialize Quad Object to render screen in a 2D texture
    */
    // quad.init();
    // frontface.init();

    std::cout << std::endl;
    std::cout << "  ========= Done Initialize Start Rendering ==========  " << std::endl;
    /*
    ** Begin Render
    */
    unit_voxel = 1.0f / volumeData.depth;
    plane_sample_rate = unit_voxel / sample_rate;

    /*
    ** Debug
    */
    const glm::mat4& mvp = GetMVPMatrix();
    std::cout << glm::to_string(mvp) << std::endl;
    std::vector<GLfloat> tdata;
    for(int i= 0; i < triangle.size(); i++){
      glm::vec4 temp = mvp * glm::vec4(triangle[i], 1.0f);
      tdata.push_back(temp.x / temp.w);
      tdata.push_back(temp.y / temp.w);
      tdata.push_back(temp.z / temp.w);
    }

    GLuint vertex_array;
    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);
    GLuint programID = loadShader( "VFace.glsl", "FFace.glsl" );
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(debug_triangle),debug_triangle, GL_STATIC_DRAW);
    GLuint MatrixID = glGetUniformLocation(programID, "MVP");
    glm::mat4 MVP = GetMVPMatrix();
    do{

  		// Clear the screen
  		glClear( GL_COLOR_BUFFER_BIT );

  		// Use our shader
  		glUseProgram(programID);
      glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

  		// 1rst attribute buffer : vertices
  		glEnableVertexAttribArray(0);
  		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
  		glVertexAttribPointer(
  			0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
  			3,                  // size
  			GL_FLOAT,           // type
  			GL_FALSE,           // normalized?
  			0,                  // stride
  			(void*)0            // array buffer offset
  		);

  		// Draw the triangle !
  		glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle

  		glDisableVertexAttribArray(0);

  		// Swap buffers
  		glfwSwapBuffers(window);
  		glfwPollEvents();

  	} // Check if the ESC key was pressed or the window was closed
  	while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
  		   glfwWindowShouldClose(window) == 0 );

//     while (!glfwWindowShouldClose(window))
//     {
//       glClear( GL_COLOR_BUFFER_BIT );
//
//       // Use our shader
//       glUseProgram(programID);
//
//       // 1rst attribute buffer : vertices
//       glEnableVertexAttribArray(0);
//       glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//       glVertexAttribPointer(
//         0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
//         3,                  // size
//         GL_FLOAT,           // type
//         GL_FALSE,           // normalized?
//         0,                  // stride
//         (void*)0            // array buffer offset
//       );
//
//       // Draw the triangle !
//       glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
//
//       glDisableVertexAttribArray(0);
//
//       // if(!vertices.vertex_array.empty()) { vertices.vertex_array.clear(); vertices.texture_array.clear();}
//       //   fetchVertices(vertices, "front");
//       //   frontfaceFBO.bind(CameraWidth(), CameraHeight());
//       //   frontface.draw(vertices);
//       //   frontfaceFBO.unbind();
// //        quad.draw(fbo.getColorTexture());
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     } // end while
    //glfwDestroyWindow(window);
    glfwTerminate();
}
