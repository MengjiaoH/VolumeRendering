#pragma once
#include "common.h"
#include "camera/camera.h"
#include "transferFunction.h"
#include "datastruct.h"
#include "loadTexture3D.h"
#include "loadShaders.h"
#include "sceneObjects.h"
#include "framebuffer.h"
#include <iostream>
#include <stdio.h>
#ifdef USE_GLM
# include <glm/glm.hpp>
# include <glm/ext.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <glm/gtc/type_ptr.hpp>
#else
# error "GLM is required here"
#endif


int ShowViewPort();

static void error_callback(int error, const char* description)
{
  fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
  { glfwSetWindowShouldClose(window, GLFW_TRUE); }
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
  int left_state  = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
  int right_state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);
  if (left_state == GLFW_PRESS) { CameraDrag(xpos, ypos); }
  else { CameraBeginDrag(xpos, ypos); }
  if (right_state == GLFW_PRESS) { CameraZoom(xpos, ypos); }
  else { CameraBeginZoom(xpos, ypos); }
}
//
//static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
////  float fovy = camera.getFovy() - 5 * yoffset;
////  camera.updateProjMatrix(fovy);
//  camera.updateViewMatrix(yoffset);
//}

static void window_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
  CameraUpdateProj(width, height);
}
