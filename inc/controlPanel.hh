#ifndef CONTROLPANEL_HH
#define CONTROLPANEL_HH

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QString>
#include <QComboBox>
#include <QDir>
#include <QFrame>
#include <QFormLayout>

#include <QKeyEvent>

#include "maze.hh"
#include "paintView.hh"
using namespace std;

class ControlPanel: public QWidget { 
  Q_OBJECT
 public:
  ControlPanel(QWidget *parent = nullptr);
  Maze *maze() {return _PaintView->maze();}
  PaintView *paintView() {return _PaintView;}
  void stepsNumber() {_stepsNumber->setText(QString::number(maze()->stepsNumber()));}
  void bestPathNumber() {_bestPath->setText(QString::number(maze()->bestPath()));}

 signals:
  void reportSign(const QString &);
  void reportClosing(); 

 public slots:
  void restartMaze();
  void stepInMaze();
  void solveMaze();
  void loadGraphics();
  void stepBack();
  void on_fileName_currentIndexChanged(int index);
  void on_algorithm_currentIndexChanged(int index);

 private: 
  QWidget        *_parent;                   
  PaintView      *_PaintView;
  QPushButton    *_CloseButton;
  QPushButton    *_RestartButton;
  QPushButton    *_SolveButton;
  QPushButton    *_StepButton;
  QPushButton    *_StepBackButton;
  QPushButton    *_LoadButton;
  QLabel         *_stepsNumber;
  QLabel         *_bestPath;
  QLabel         *_Time;
  QLabel         *_bestPathLabel;
  QLabel         *_stepsNumberLabel;
  QLabel         *_TimeLabel;
  QComboBox      *_comboBoxMaze;
  QComboBox      *_comboBoxAlgorithm;
  QLabel         *_algorithmLabel;
  QStringList    _fileNames;
  int            _index;
  int            _algorithm = 0;
}; 

#endif