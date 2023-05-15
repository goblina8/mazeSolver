#include <QApplication>
#include "mainWindow.hh"

using namespace std;

int main( int argc, char * argv[] ) 
{
  QApplication App(argc,argv);
  MainWindow   Window;

  Window.resize(450,400);
  Window.show();
  return App.exec();
}