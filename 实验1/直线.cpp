//#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL/glut.h>

void lineBres(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1); //dx�ľ���ֵ
    int dy = abs(y2 - y1); //dy�ľ���ֵ
    int p = 2 * dy - dx;   //�����ʼֵ
    int twody = 2 * dy, twodxdy = 2 * (dy - dx);
    int x, y; //��ǰλ��
    int xEnd; //����x
    if (x1 > x2)
    {
        x = x2;
        y = y2;
        xEnd = x1;
    } //��ֱ֤�߷����Ǵ�����
    else
    {
        x = x1;
        y = y1;
        xEnd = x2;
    }
    glVertex2i(x, y); //������һ����
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
    glClear(GL_COLOR_BUFFER_BIT); //�����ɫ������
    glColor3f(0.5f, 0.5f, 0.5f);  //���û�����ɫ

    glBegin(GL_POINTS); //��ÿ��������Ϊһ������д���

    lineBres(-200, -300, 200, 300); //����ֱ�ߣ���(-200,-300)��(200,300)��

    glEnd();   //ֹͣ����
    glFlush(); //ˢ�»���
}

int main(int agrc, char *argv[])
{
    glutInit(&agrc, argv);                       //��ʼ��GLUT��
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //ָ����ʾģʽ(�����棬RGB��ɫ)
    glutInitWindowSize(800, 800);                //���ó�ʼ���ڵĴ�С(800*800)
    glutInitWindowPosition(0, 0);                //���ó�ʼ���ڵ�λ��(0,0)
    glutCreateWindow("1-2 Circle");              //���ڱ�������ʾ������

    //��ʾ����Ҫ����
    glutDisplayFunc(display);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);     //���������ɫ������Ϊ����ɫ
    glMatrixMode(GL_PROJECTION);              //���õ�ǰ����ģʽ[ͶӰ����]
    gluOrtho2D(-400.0, 400.0, -400.0, 400.0); //ָ����Ļ�����Ӧ��ģ�����귶Χ

    glutMainLoop(); //����GLUT�¼�����ѭ��
    return 0;
}