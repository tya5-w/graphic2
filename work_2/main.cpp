#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

//Material
const GLfloat AmbientMat[4] = {1.0, 1.0, 1.0, 1.0};
const GLfloat DiffuseMat[4] = {0.1, 0.1, 0.1, 1.0};
const GLfloat SpecularMat[4] = {1.0, 1.0, 1.0, 1.0};
const GLfloat ShininessMat[1] = {20.0};

//Light0
const GLfloat lightPosition0[4] = {0, 14, -30, 1.0};
const GLfloat Ambient0[4]       = {3.1, 0.1, 0.1, 1.0};
const GLfloat Diffuse0[4]       = {1.0, 0.0, 0.0, 1.0};
const GLfloat Specular0[4]      = {1.0, 0.0, 0.0, 1.0};
const GLfloat Shininess0[1]     = {100.0};

//Light1
const GLfloat lightPosition1[4] = {-15, -8, 0, 1.0};
const GLfloat Ambient1[4]       = {0.1, 0.1, 0.1, 1.0};
const GLfloat Diffuse1[4]       = {1.0, 1.0, 2.0, 1.0};
const GLfloat Specular1[4]      = {0.0, 1.0, 0.0, 1.0};
const GLfloat Shininess1[1]     = {100.0};

//Light3
const GLfloat lightPosition2[4] = {10, -5, -10, 1.0};
const GLfloat Ambient2[4]       = {0.1, 0.1, 0.1, 1.0};
const GLfloat Diffuse2[4]       = {0.1, 0.1, 0.3, 1.0};
const GLfloat Specular2[4]      = {0.0, 0.0, 1.0, 1.0};
const GLfloat Shininess2[1]     = {20.0};


void setup(){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    //Material
    glMaterialfv(GL_FRONT, GL_AMBIENT, AmbientMat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, DiffuseMat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, SpecularMat);
    glMaterialfv(GL_FRONT, GL_SHININESS, ShininessMat);

    //  LIGHT 0
        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition0);
        glLightfv(GL_LIGHT0, GL_AMBIENT, Ambient0);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, Diffuse0);
        glLightfv(GL_LIGHT0, GL_SPECULAR, Specular0);
        glLightfv(GL_LIGHT0, GL_SHININESS, Shininess0);

    //  LIGHT 1
        glEnable(GL_LIGHT1);
        glLightfv(GL_LIGHT1, GL_POSITION, lightPosition1);
        glLightfv(GL_LIGHT0, GL_AMBIENT, Ambient1);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse1);
        glLightfv(GL_LIGHT1, GL_SPECULAR, Specular1);
        glLightfv(GL_LIGHT1, GL_SHININESS, Shininess1);

    //  LIGHT 2
        glEnable(GL_LIGHT2);
        glLightfv(GL_LIGHT2, GL_POSITION, lightPosition2);
        glLightfv(GL_LIGHT2, GL_AMBIENT, Ambient2);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, Diffuse2);
        glLightfv(GL_LIGHT2, GL_SPECULAR, Specular2);
        glLightfv(GL_LIGHT2, GL_SHININESS, Shininess2);

}

void reshape(int width,int height){
    glViewport(0,0,width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,(double)(width/height), 0.1, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(10.0,7.0,13.0,0.0,0.1,0.0,0.0,1.0,0.0);
}


void display(void){
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glutSolidTeapot(3);
    glPopMatrix();
    glutSwapBuffers();
}



int main(int argc,  char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitDisplayMode(GLUT_DOUBLE |GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Hello 3D");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    setup();
    glutMainLoop();
    return 0;
}
