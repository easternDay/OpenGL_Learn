//#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL/glut.h>

void lineBres(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1); //dx的绝对值
    int dy = abs(y2 - y1); //dy的绝对值
    int p = 2 * dy - dx;   //定义初始值
    int twody = 2 * dy, twodxdy = 2 * (dy - dx);
    int x, y; //当前位置
    int xEnd; //结束x
    if (x1 > x2)
    {
        x = x2;
        y = y2;
        xEnd = x1;
    } //保证直线方向是从左到右
    else
    {
        x = x1;
        y = y1;
        xEnd = x2;
    }
    glVertex2i(x, y); //画出第一个点
    while (x < xEnd)
    {
        x++;
        if (p < 0)
            p += twody;
        else
        {
            y++;
            p += twodxdy;
        }
        glVertex2i(x, y);
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //清楚颜色缓冲区
    glColor3f(0.5f, 0.5f, 0.5f);  //设置画笔颜色

    glBegin(GL_POINTS); //把每个顶点作为一个点进行处理

    lineBres(-200, -300, 200, 300); //绘制直线（从(-200,-300)到(200,300)）

    glEnd();   //停止绘制
    glFlush(); //刷新缓存
}

int main(int agrc, char *argv[])
{
    glutInit(&agrc, argv);                       //初始化GLUT库
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //指定显示模式(单缓存，RGB颜色)
    glutInitWindowSize(800, 800);                //设置初始窗口的大小(800*800)
    glutInitWindowPosition(0, 0);                //设置初始窗口的位置(0,0)
    glutCreateWindow("1-2 Circle");              //窗口标题栏显示的内容

    //显示的主要函数
    glutDisplayFunc(display);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);     //清楚背景颜色并设置为纯黑色
    glMatrixMode(GL_PROJECTION);              //设置当前矩阵模式[投影矩阵]
    gluOrtho2D(-400.0, 400.0, -400.0, 400.0); //指定屏幕区域对应的模型坐标范围

    glutMainLoop(); //进入GLUT事件处理循环
    return 0;
}