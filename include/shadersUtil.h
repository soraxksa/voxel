#ifndef SHADERSUTIL_H_
#define SHADERSUTIL_H_

#include <stdio.h>
#include <glad/glad.h>


static unsigned CreateShader(const char *source, GLenum shader_type);
unsigned CreateShaderFromSource(const char *vertex_source, const char *fragment_source);
unsigned CreateShaderFromFiles(const char *vertex_file, const char *fragment_file);


#endif
