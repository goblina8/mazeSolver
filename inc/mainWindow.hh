#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QWidget>
#include <QCloseEvent>
#include <QKeyEvent>
#include <QMessageBox>
#include <QMainWindow>
#include <QStatusBar>
#include <QApplication>

#include "controlPanel.hh"
#include "paintView.hh"
#include "maze.hh"
using namespace std;

class MainWindow: public QMainWindow { 
  Q_OBJECT
 public:
  MainWindow(QWidget *parent = nullptr);
  virtual void closeEvent( QCloseEvent * event );
  bool canBeClosed();                     

 public slots:
  void receiveStatus(const QString &);  
  void whenClosed();  

  private:
   ControlPanel *_ControlPanel;
   void keyPressEvent(QKeyEvent *event);  

}; 

#endif
