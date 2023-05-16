#ifndef CONTROLPANEL_HH
#define CONTROLPANEL_HH

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>

#include "maze.hh"
#include "paintView.hh"
using namespace std;

class ControlPanel: public QWidget { 
  Q_OBJECT
 public:
  ControlPanel(QWidget *parent = nullptr);
  Maze *maze() {return _PaintView->maze();}
  PaintView *paintView() {return _PaintView;}

 signals:
  void ReportSign(const QString &);
  void ReportClosing(); 

 public slots:
  //void on_RestartButton_toggled(bool Checked);
  void restartMaze();

 private:                     
  PaintView *_PaintView;
  QPushButton    *_CloseButton;
  QPushButton    *_RestartButton;
}; 

#endif
