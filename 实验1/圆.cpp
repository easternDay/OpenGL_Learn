//#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

//画笔笔触大小
GLfloat pointsize = 10.0f;

void drawbresenhamcycle(GLint R)
{
	GLint a = 0;
	GLint y = (int)(R * 1.0 / (sqrt(2)));
	GLfloat d0 = 1.25 - R;
	GLfloat d;

	glPointSize(pointsize); //设置画笔大小

	GLint cx = 0, cy = R;
	glVertex2i(0, 0);
	while (a <= y)
	{
		glVertex2i(a, cy);
		glVertex2i(-a, -cy);
		glVertex2i(-a, cy);
		glVertex2i(a, -cy);
		glVertex2i(cy, -a);
		glVertex2i(-cy, -a);
		glVertex2i(-cy, a);
		glVertex2i(cy, a);

		a++;
		if (d0 <= 0)
		{
			d0 = d0 + 2 * a + 3;
			cy = cy;
		}
		else
		{
			d0 = d0 + 2 * (a - cy) + 5;
			cy = cy - 1;
		}
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //清楚颜色缓冲区
	glColor3f(0.5f, 0.5f, 0.5f);  //设置画笔颜色

	glBegin(GL_POINTS); //把每个顶点作为一个点进行处理

	drawbresenhamcycle(225); //绘制函数，输入的参数为半径

	glEnd();   //停止绘制
	glFlush(); //刷新缓存
}

int main(int agrc, char *argv[])
{
	glutInit(&agrc, argv);						 //初始化GLUT库
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //指定显示模式(单缓存，RGB颜色)
	glutInitWindowSize(800, 800);				 //设置初始窗口的大小(800*800)
	glutInitWindowPosition(0, 0);				 //设置初始窗口的位置(0,0)
	glutCreateWindow("1-2 Circle");				 //窗口标题栏显示的内容

	//显示的主要函数
	glutDisplayFunc(display);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	  //清楚背景颜色并设置为纯黑色
	glMatrixMode(GL_PROJECTION);			  //设置当前矩阵模式[投影矩阵]
	gluOrtho2D(-400.0, 400.0, -400.0, 400.0); //指定屏幕区域对应的模型坐标范围

	glutMainLoop(); //进入GLUT事件处理循环
	return 0;
}