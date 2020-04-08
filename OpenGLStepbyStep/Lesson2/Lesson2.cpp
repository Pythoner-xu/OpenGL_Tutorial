// Lesson2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define NDEBUG

#include "pch.h"
#include <iostream>
#include<GL/freeglut.h> // 引入freeglut窗口库

void  RenderFuncCB();

int main(int argc, char ** argv)
{
	std::cout << "Hello OpenGL World Lesson2!\n";

	// 初始化glut
	glutInit(&argc, argv);

	// 设置显示模式：双缓冲、RGBA
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// 窗口设置
	glutInitWindowSize(480, 320);		// 窗口尺寸
	glutInitWindowPosition(100, 100);	// 窗口位置
	glutCreateWindow("Tutorial 01");		// 窗口标题

	// 开始渲染：执行自定义渲染逻辑
	glutDisplayFunc(RenderFuncCB);

	// 主循环：监听窗口系统中的事件，并通过注册的回调传递出去
	glutMainLoop();

	return 0;
}

void RenderFuncCB() 
{
	// 设置清理颜色状态
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	// 清空颜色缓冲
	glClear(GL_COLOR_BUFFER_BIT);
	// 交换前后缓冲 一个用来显示，一个用来写
	glutSwapBuffers();
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
