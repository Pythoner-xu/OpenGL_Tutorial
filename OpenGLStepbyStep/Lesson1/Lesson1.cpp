// Lesson1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void framebuffersize_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void ProcessInput(GLFWwindow* window);

void RenderScene();

int main()
{
    std::cout << "Hello OpenGL World Lesson1!\n"; 

	// step1:initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // OpenGL Context 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 核心模式

	// step2:create window
	GLFWwindow* window = glfwCreateWindow(800, 600, "Lesson 1", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create window!" << std::endl;
		glfwTerminate();

		return -1;
	}

	glfwMakeContextCurrent(window); // 设置OpengGL上下文为窗口上下文
	glfwSetFramebufferSizeCallback(window, framebuffersize_callback); // 设置窗口大小监听回调
	glfwSetKeyCallback(window, key_callback); // 设置按键监听

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to init glew!" << std::endl;
		glfwTerminate();
		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{
		// 处理输入
		ProcessInput(window);

		// 绘制
		RenderScene();
		
		// 切换frontbuffer和backbuffer
		glfwSwapBuffers(window);
		// 事件轮询
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}



void framebuffersize_callback(GLFWwindow * window, int width, int height)
{
	std::cout << "framebufer size:" << width << "," << height << std::endl;
	glViewport(0, 0, width, height);
}

void key_callback(GLFWwindow * window, int key, int scancode, int action, int mode)
{
	std::cout << "key=" << key << ", " << "scancode=" << scancode << ", " << "action=" << action << ", " << "mode=" << mode << ", " << std::endl;
}

void ProcessInput(GLFWwindow * window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}



// 渲染场景
void RenderScene() 
{
	// 【状态设置函数】设置清屏颜色
	glClearColor(0.5f, 0, 0, 1);
	// 【状态应用函数】清空颜色缓冲
	glClear(GL_COLOR_BUFFER_BIT);
}
















// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


