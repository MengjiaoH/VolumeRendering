#pragma once
#ifndef GLM_ENABLE_EXPERIMENTAL
#define GLM_ENABLE_EXPERIMENTAL
#endif

#ifdef USE_GLM
# include <glm/fwd.hpp>
#else
# error "GLM is required here"
#endif

#include <iostream>

void CameraBeginZoom(float x, float y);
void CameraZoom(float x, float y);
void CameraBeginDrag(float x, float y);
void CameraDrag(float x, float y);
void CameraUpdateView();
void CameraUpdateProj(size_t, size_t);
size_t CameraWidth();
size_t CameraHeight();
float CameraZNear();
float CameraZFar();
const glm::mat4& GetProjection();
const glm::mat4& GetMVMatrix();
const glm::mat4& GetMVPMatrix();
const float*     GetMVPMatrixPtr();
