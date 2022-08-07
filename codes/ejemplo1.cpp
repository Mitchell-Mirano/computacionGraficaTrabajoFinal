#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>

 //Definimos 4 puntos de control
GLfloat ctrlpoints[4][3] = {{-4.0, -4.0, 0.0}, { -2.0, 4.0, 0.0},
                            {2.0, -4.0, 0.0}, {4.0, 4.0, 0.0}};
void init(void){
    glClearColor(0.94, 0.94, 0.94, 0.0);

    glShadeModel(GL_FLAT);
  //para usar el evaluador definir la asignación polinómica unidimensional
  //adecuada mediante glMap*.
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4,&ctrlpoints[0][0]);
  //habilita al evaluador unidimensional para vertices tridimensionales
    glEnable(GL_MAP1_VERTEX_3);
}

void display(void){
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
        glLineWidth(2);

    glBegin(GL_LINE_STRIP);
     //glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= 30; i++)
            glEvalCoord1f((GLfloat) i/30.0);//se usa en lugar de glVertex
    glEnd();

 /* El siguiente código muestra los puntos de control como puntos. */
        glPointSize(6.0);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
            for (int i = 0; i < 4; i++)
                glVertex3fv(&ctrlpoints[i][0]);
        glEnd();

glFlush();
}

void reshape(int w, int h) {
        glViewport(0, 0, (GLsizei) w, (GLsizei) h);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        if (w <= h)
            glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w,
            5.0*(GLfloat)h/(GLfloat)w, -5.0, 5.0);

        else
            glOrtho(-5.0*(GLfloat)w/(GLfloat)h,
            5.0*(GLfloat)w/(GLfloat)h, -5.0, 5.0, -5.0, 5.0);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
}

int main(int argc, char** argv) {
        glutInit(&argc, argv);
        glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize (500, 500);
        glutInitWindowPosition (500, 100);
        glutCreateWindow ("CURVA DE BÉZIER");
     // glutCreateWindow (argv[0]);
        init ();
        glutDisplayFunc(display);
        glutReshapeFunc(reshape);
        glutMainLoop();
        return 0;
}
