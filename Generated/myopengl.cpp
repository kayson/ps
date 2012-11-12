
#include "myopengl.hh"

#include <GL/glut.h>

#include <QMouseEvent>

#define NEAR_PLANE 0.01
#define FAR_PLANE 15

MyOpenGL::MyOpenGL( QWidget *parent,
                              const QGLWidget *shareWidget, Qt::WindowFlags f )
  : QGLWidget(QGLFormat(QGL::DepthBuffer|
                        QGL::Rgba|
                        QGL::AlphaChannel),
              parent,shareWidget,f) {}

MyOpenGL::~MyOpenGL(){}

void MyOpenGL::initializeGL(){
  glClearColor( 0.0, 0.0, 0.0, 0.0 );

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  glEnable(GL_LINE_SMOOTH);


  glEnable( GL_POINT_SMOOTH );
  glPointSize( 3.0 );


  mouse_state = -1;

  scene_zoom = -1;
  scene_xRot = -10;
  scene_yRot = 30;

  w = new World();
}

void MyOpenGL::resizeGL( int width, int height ){
  glViewport( 0, 0, width, height );

  glMatrixMode( GL_PROJECTION );
  glLoadIdentity();
  float ratio = float(height)/float(width);
  glFrustum( -NEAR_PLANE, NEAR_PLANE,
             -NEAR_PLANE*ratio, NEAR_PLANE*ratio,
             NEAR_PLANE, FAR_PLANE );

  glMatrixMode( GL_MODELVIEW );
  glLoadIdentity();
}

#define MINOR_TICS_N  50
#define MINOR_TICS_DX 0.2f
#define MAJOR_TICS_N  10
#define MAJOR_TICS_DX 1.0f

void MyOpenGL::paintGL(){

  glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);

  // Rotate and zoom
  glLoadIdentity();
  glTranslatef(0,0,scene_zoom);
  glRotatef(scene_yRot, 1, 0, 0);
  glRotatef(scene_xRot, 0, 1, 0);
  glScalef( .25, .25, .25 );

  // Ticks
  glLineWidth(1);
  glBegin(GL_LINES);
  glColor3f(0.2,0.2,0.2);
  for( int idx = -MINOR_TICS_N ; idx < MINOR_TICS_N ; idx++ ){
    glVertex3f(-MINOR_TICS_DX*MINOR_TICS_N, 0, idx*MINOR_TICS_DX);
    glVertex3f(+MINOR_TICS_DX*MINOR_TICS_N, 0, idx*MINOR_TICS_DX);
    glVertex3f(idx*MINOR_TICS_DX, 0, -MINOR_TICS_DX*MINOR_TICS_N);
    glVertex3f(idx*MINOR_TICS_DX, 0, +MINOR_TICS_DX*MINOR_TICS_N);
  }
  glColor3f(0.5,0.5,0.5);
  for( int idx = -MAJOR_TICS_N ; idx <= MAJOR_TICS_N ; idx++ ){
    glVertex3f(-MAJOR_TICS_DX*MAJOR_TICS_N, 0, idx*MAJOR_TICS_DX);
    glVertex3f(+MAJOR_TICS_DX*MAJOR_TICS_N, 0, idx*MAJOR_TICS_DX);
    glVertex3f(idx*MAJOR_TICS_DX, 0, -MAJOR_TICS_DX*MAJOR_TICS_N);
    glVertex3f(idx*MAJOR_TICS_DX, 0, +MAJOR_TICS_DX*MAJOR_TICS_N);
  }
  glEnd();

  // Coordinates
  glLineWidth(2);
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_LINES);
  glVertex3f(0,0,0); glVertex3f(1,0,0);
  glVertex3f(0,0,0); glVertex3f(0,1,0);
  glVertex3f(0,0,0); glVertex3f(0,0,1);
  glEnd();

  // Draw stuff ---
  switch(object_choice){
  case 0:
    w->addSource(1);
    object_choice = -1;
    break;
  case 1:
    w->addForce(2);
    object_choice = -1;
    break;
  }

  // Particle Simulation
    w->Render();
    for(unsigned int i = 0; i < w->particleVec.size(); i++)
    {
        glBegin( GL_POINTS );
        glColor3f( (w->particleVec.at(i)->life/100.0f) * 0.95f, (w->particleVec.at(i)->life/100.0f) * 0.207f, (w->particleVec.at(i)->life/100.0f) * 0.031f );
        glVertex3f(w->particleVec.at(i)->position.x , w->particleVec.at(i)->position.y, w->particleVec.at(i)->position.z);
        glEnd();
    }
    QWidget::update();
}


void MyOpenGL::mousePressEvent ( QMouseEvent * event ){
  mouse_state = event->button();
  mouse_x = event->x();
  mouse_y = event->y();
}

void MyOpenGL::mouseReleaseEvent ( QMouseEvent * event ){
  mouse_state = -1;
}

void MyOpenGL::mouseMoveEvent ( QMouseEvent * event ){
  switch(mouse_state){
  case 1:
    scene_xRot += .5f*(event->x() - mouse_x);
    scene_yRot += .5f*(event->y() - mouse_y);
    if( scene_yRot < -80 ){ scene_yRot = -80; }
    if( scene_yRot >  80 ){ scene_yRot =  80; }
    mouse_x = event->x();
    mouse_y = event->y();
    QWidget::update(0,0,width(),height());
    break;
  case 2:
    scene_zoom *= 1 - .01f*( event->y() - mouse_y );
    if( scene_zoom < -10 ){ scene_zoom = -10; }
    if( scene_zoom > -1 ){ scene_zoom = -1; }
    mouse_y = event->y();
    QWidget::update(0,0,width(),height());
    break;
  }
}

void MyOpenGL::update(){
  QWidget::update(0,0,width(),height());
}
