#include "shadersUtil.h"
#include "filesUtil.h"


static unsigned CreateShader(const char *source, GLenum shader_type)
{
	printf("Creating shader\n");
	unsigned int shader;
	shader = glCreateShader(shader_type);
	glShaderSource(shader, 1, &source, NULL);
	glCompileShader(shader);

	int  success;
	char info_log[512];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		char *type;
		if(shader_type == GL_VERTEX_SHADER)
			type = "VERTEX";
		else	type = "FRAGMENT";

		glGetShaderInfoLog(shader, 512, NULL, info_log);
		fprintf(stderr, "MYERROR: SHADER %s, COMPILATION FAILED:\n%s\n", type, info_log); 
	}

	return shader; 
}

unsigned CreateShaderFromSources(const char *vertex_source, const char *fragment_source)
{
	unsigned vertex_shader   = CreateShader(vertex_source, GL_VERTEX_SHADER);
	unsigned fragment_shader = CreateShader(fragment_source, GL_FRAGMENT_SHADER);

	unsigned shader_program = glCreateProgram();
	glAttachShader(shader_program, vertex_shader);
	glAttachShader(shader_program, fragment_shader);
	glLinkProgram(shader_program);

        int  success;
	char info_log[512];
	glGetProgramiv(shader_program, GL_LINK_STATUS, &success); 
	if(!success) {
		glGetProgramInfoLog(shader_program, 512, NULL, info_log);
		fprintf(stderr, "MYERROR: SHADER PROGRAM, LINKING ERROR:\n%s\n", info_log);
	}

	return shader_program;
}

unsigned CreateShaderFromFiles(const char *vertex_file, const char *fragment_file)
{
	const char *vertex_source = load_file(vertex_file, 0);
	const char *fragment_source = load_file(fragment_file, 0);

	unsigned shader_program = CreateShaderFromSources(vertex_source, fragment_source);

	free((void*)vertex_source);
	free((void*)fragment_source);

	return shader_program;

}
