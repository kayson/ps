
#include <QtOpenGL/QGLWidget>
#include "World.h"

#include <iostream>

class MyOpenGL : public QGLWidget {
  Q_OBJECT
public:

  MyOpenGL( QWidget *parent = 0,
            const QGLWidget *shareWidget = 0, Qt::WindowFlags f = 0 );

  virtual ~MyOpenGL();

  void update();

  void setObjectChoice(int id){ object_choice = id; }

public slots:

  void buttonTeapot(bool state){
    setObjectChoice(0);
    update();
  }

  void buttonDodecahedron(bool state){
    setObjectChoice(1);
    update();
  }

protected:

  void initializeGL();
  void resizeGL( int width, int height );
  void paintGL();

  void mousePressEvent ( QMouseEvent * event );
  void mouseReleaseEvent ( QMouseEvent * event );
  void mouseMoveEvent ( QMouseEvent * event );

private:

  int object_choice;

  int mouse_state;
  int mouse_x;
  int mouse_y;

  World *w;

  float scene_zoom;
  float scene_xRot;
  float scene_yRot;
};
