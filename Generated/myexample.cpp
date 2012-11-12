
#include "myexample.hh"

myexample::myexample(){
  setupUi(this);
}

myexample::~myexample(){}

void myexample::handleMenuAction(QAction *action){

  if( action == actionQuit ){
    close();
  }
}

void myexample::buttonTeapot(bool state){
  text->setText("Add Cone");
}

void myexample::buttonDodecahedron(bool state){
  text->setText("Add Gravity");
}


