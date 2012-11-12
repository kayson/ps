#include "myexample.hh"

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    myexample *w = new myexample();
    w->show();

   // World *w = new World();
//    w->createWorld();
//    w->runSimulation();

    return app.exec();
}
