#include "shadersUtil.h"


static unsigned CreateShader(const char *source, GLenum shader_type)
{
	printf("Creating shader\n");
	unsigned int shader;
	shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	int  success;
	char infoLog[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		char *type;
		if(shader_type == GL_VERTEX_SHADER)
			type = "VERTEX";
		else	type = "FRAGMENT";

		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		fprintf(stderr, "MYERROR: SHADER %s, COMPILATION FAILED:\n%s\n", type, infoLog); 
	}

	return shader; 
}

unsigned CreateShaderFromSource(const char *vertex_source, const char *fragment_source)
{
	unsigned vertexShader   = CreateShader(vertex_source, GL_VERTEX_SHADER);
	unsigned fragmentShader = CreateShader(fragment_source, GL_FRAGMENT_SHADER);

	unsigned shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

        int  success;
	char infoLog[512];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success); 
	if(!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		fprintf(stderr, "MYERROR: SHADER PROGRAM, LINKING ERROR:\n%s\n", infoLog);
	}

	return shaderProgram;

}
