
/**
 * @file mainWindow.hh
 * 
 * @brief Header file of MainWindow class.
 * 
 * */
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

/** 
 * @brief The class represents the main window of the application.
 */
class MainWindow: public QMainWindow { 
  Q_OBJECT
  private:
   ControlPanel   *_ControlPanel;         /**< A private field holds pointer to the ControlPanel class object. */
   void keyPressEvent(QKeyEvent *event);  /**< A private function that take care of key press event */

  public:
   /**
    * @brief A MainWindow class constructor.
    * @param[in] parent The pointer to Widget's parent.
    */
   MainWindow(QWidget *parent = nullptr);
   /**
    * @brief A function responsible for closing the window.
    * @param[in] event The pointer to event that happend.
    */
   virtual void closeEvent( QCloseEvent * event );
   /**
    * @brief The function that checks if the window can be closed.
    * @retval Information if the window can be closed. 1 - can be, 0 - can not be.
    */
   bool canBeClosed();                     

  public slots:
  /**
    * @brief A function taking care of current status.
    */
   void receiveStatus(const QString &);  
   /**
    * @brief A function closing the application.
    */
   void whenClosed();  
}; 

#endif
