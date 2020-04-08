// Lesson3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include "pch.h"
#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <math3D.h>

#define VERTICES_COUNT 3
#define DRAW_MODE GL_TRIANGLES

// 申请顶点缓存对象，之后都将操作该对象
GLuint VBO;

void RenderSceneCB();
void CreateVertexBuffer();


int main(int argc, char** argv)
{
    std::cout << "Hello OpenGL Lesson3!\n"; 

	glutInit(&argc, argv);

	// 双缓冲 + RGBA
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	//窗口设置
	glutInitWindowSize(400, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tutorial 02");


	// 必须注册一个DisplayFunc，否则会报错！（glutMainLoop调用后，必须注册该回调）
	glutDisplayFunc(RenderSceneCB);


	GLenum ret = glewInit();
	if (ret != GLEW_OK)
	{
		//std::cout << "[Error]:glew init failed!" << std::endl;
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(ret));
		return -1;
	}


	//创建顶点缓存对象VBOs
	CreateVertexBuffer();


	// 开启窗口主循环
	glutMainLoop();

	return 0;
}

// 所有渲染相关逻辑
void RenderSceneCB()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	// 在shader着色器教程中，顶点着色器使用的属性(位置、法线)是有索引来对它们进行映射的，这样你能够绑定C/C++程序中的数据和着色其中的
	// 属性名称，而且必须要为每一个顶点属性添加索引。我们加载到buffer中的顶点位置在固定功能管线中默认是索引为0的顶点属性。必须开启每一个顶点的属性。
	glEnableVertexAttribArray(0);
	// 这里再次绑定我们的buffer，准备开始draw call
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// 告知管线如何解析buffer中的数据：属性的索引（这个索引默认是0）、属性中元素的个数（x,y,z）、元素的数据类型、是否在管线使用前单位化、缓冲中的那个属性的两个实例间的bit数距离（步长）
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	// 绘制，这个指令才是GPU真正开始工作的地方（真正产生Draw call的地方--顺序绘制和索引绘制）
	glDrawArrays(DRAW_MODE, 0, VERTICES_COUNT);
	// 不使用顶点时，建议禁用他们，这是个好习惯
	glDisableVertexAttribArray(0);


	// 因为开启了双缓冲，所以这里切换Front/Back buffer
	glutSwapBuffers();
}

void CreateVertexBuffer()
{
	Vector3f Vertices[VERTICES_COUNT];
	Vertices[0] = Vector3f(-0.2f, -0.2f, 0.0f);
	Vertices[1] = Vector3f(0.2f, -0.2f, 0.0f);
	Vertices[2] = Vector3f(0.0f, 0.2f, 0.0f);

	//Vertices[0] = Vector3f(-1.0f, -1.0f, 0.0f);
	//Vertices[1] = Vector3f(1.0f, -1.0f, 0.0f);
	//Vertices[2] = Vector3f(0.0f, 1.0f, 0.0f);


	// 申请VBO
	fprintf(stderr, "VBO addr=%d\n", VBO);
	// glGen*前缀函数：用来产生不同类型的对象（第一个参数：定义创建的对象数量，第二个参数：申请buffer的地址，除非glDelete*,否则再次调用不会重复产生相同handles）
	glGenBuffers(1, &VBO); 
	fprintf(stderr, "VBO addr=%d\n", VBO);
	// OpenGL绑定方式很独特：将申请的buffer与一个目标Target进行绑定，然后在该目标Target上执行命令，这些指令只会作用在绑定的在该目标Target上的对象，直到又另外的对象绑定到该目标。
	// GL_ARRAY_BUFFER表示这个buffer将存储一个顶点数组
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// 绑定了对象后，我们需要向其添加数据，指定：绑定目标，数据位数，数据地址，数据模式
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
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
