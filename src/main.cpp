#include <QApplication>
#include "mainWindow.hh"

using namespace std;

int main( int argc, char * argv[] ) 
{
  QApplication App(argc,argv);
  MainWindow   Window;

  Window.resize(600,400);
  Window.show();
  return App.exec();
}