#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "glfw_code.h"
#include "shadersUtil.h"


int main()
{
	GLFWwindow *window = init("opengl3.3", 640, 480);

	if(!window)
	{
		fprintf(stderr, "window null\n");
		return -1;
	}

	const char *vertexShaderSource = 
		"#version 330 core\n"
		"layout(location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x-0.2f, aPos.y-0.2f, aPos.z, 1.0);\n"
		"}\0";

	const char *fragmentShaderSource =
       		"#version 330 core\n"
		"out vec4 Color;\n"
		"void main()\n"
		"{\n"
		"    Color = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
		"}\0";

	printf("##########\n%s\n##########\n%s\n###########\n", vertexShaderSource, fragmentShaderSource);

	float data[] = {
	       -0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	unsigned shaderProgram = CreateShaderFromSource(vertexShaderSource, fragmentShaderSource);

	unsigned VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	unsigned VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);



	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(VAO);
		glUseProgram(shaderProgram);
		//render
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;    
}
