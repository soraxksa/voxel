#ifndef CALLBACKS_H_
#define CALLBACKS_H_

static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}
 
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

GLFWwindow* init(const char *window_name, int32_t width, int32_t height)
{
	GLFWwindow *window;

	glfwSetErrorCallback(error_callback);

	/* Initialize the library */
	if (!glfwInit())
	{
		fprintf(stderr, "glfwInit()\n");
		return 0;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, window_name, NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		fprintf(stderr, "glfwCreateWindow()\n");
		return 0;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSwapInterval(1);

	glfwSetKeyCallback(window, key_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	glClearColor( 0.2f, 0.1f, 0.7f, 0.5f );

	return window;
}


#endif
