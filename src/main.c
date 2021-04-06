#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "glfw_code.h"
#include "shadersUtil.h"
#include "filesUtil.h"


int main()
{
	GLFWwindow *window = init("opengl3.3", 640, 480);

	if(!window)
	{
		fprintf(stderr, "window null\n");
		return -1;
	}


	float data[] = {
	       -0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};

	unsigned shader_program = CreateShaderFromFiles("../src/shaders/vertex.vs", "../src/shaders/fragment.vs");

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
		glUseProgram(shader_program);
		//render
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;    
}
