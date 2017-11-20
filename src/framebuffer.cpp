#include "framebuffer.h"

/*
** Methods Of framebufferObj Class
*/

extern framebufferObj fbo;

void framebufferObj::init(unsigned int width, unsigned int height, Data data){
	clear();
	FBO_colorbuffer = new GLuint[1]; // front face; back face; one for render
	check_error_gl("before FBO init");
	glGenFramebuffers(1, &FBO);
	glBindFramebuffer(GL_FRAMEBUFFER, FBO); // bind to pipeline

	generateDepthTexture(width, height);//generate empty texture
	check_error_gl("FBO depth buffers");

	std::cout << std::endl;
	std::cout << " ========== Generating TEXTURE TO PIPLINE ========== " << std::endl;

	glGenTextures(1, FBO_colorbuffer);
	for(size_t i = 0; i < 1; i++){
		check_error_gl("FBO color buffers");
		generateColorTexture(width, height, i, data);//generate empty texture
	}
	std::cout << " ========== Done Generating Textures  ==========" << std::endl;
	//Check for FBO completeness
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE){
		std::cout << "Error! FrameBuffer is not complete" << std::endl;
		std::cin.get();
		std::terminate();
	}
	//unbind framebuffer
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	check_error_gl("FBO init complete");
}

//void framebufferObj::reset(unsigned int width, unsigned int height, Data data){
//	check_error_gl("Reset FBO color buffers");
//	glBindFramebuffer(GL_FRAMEBUFFER, FBO);
//	for (size_t i = 0; i < 3; i++) {
//		generateColorTexture(width, height, i, data);//generate empty texture
//	}
//	glBindFramebuffer(GL_FRAMEBUFFER, 0);
//}

void framebufferObj::generateColorTexture(unsigned int width, unsigned int height, size_t i, Data data){
	GLubyte *dummyData = new GLubyte[width * height * 4]();
	glBindTexture(GL_TEXTURE_2D, FBO_colorbuffer[i]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, data.GL_dataType, dummyData);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, FBO_colorbuffer[i], 0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void framebufferObj::generateDepthTexture(unsigned int width, unsigned int height){
	check_error_gl("generate depth buffer");
	glGenRenderbuffers(1, &FBO_depthbuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, FBO_depthbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, FBO_depthbuffer);
  	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	check_error_gl("Done depth buffer");
}

void framebufferObj::bind(unsigned int width, unsigned int height){
    glGetIntegerv(GL_VIEWPORT, previewport);
    glViewport(0, 0, width, height);
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    GLenum DrawBuffers[1] = { GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1, DrawBuffers);
}