/**
 * @file controlPanel.hh
 * 
 * @brief Header file of ControlPanel class
 * 
 */ 
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

/** 
 * @brief The class represents the window used by the user when using the application.
 */
class ControlPanel: public QWidget { 
  Q_OBJECT
  private: 
   QWidget        *_parent;              /**< A private field holds pointer to this QWidget parent. */               
   PaintView      *_PaintView;           /**< A private field holds pointer to  PaintView class object. */
   QPushButton    *_CloseButton;         /**< A private field holds pointer to a object of QPushButton class. */
   QPushButton    *_RestartButton;       /**< A private field holds pointer to a object of QPushButton class. */
   QPushButton    *_SolveButton;         /**< A private field holds pointer to a object of QPushButton class. */
   QPushButton    *_StepButton;          /**< A private field holds pointer to a object of QPushButton class. */
   QPushButton    *_StepBackButton;      /**< A private field holds pointer to a object of QPushButton class. */
   QPushButton    *_LoadButton;          /**< A private field holds pointer to a object of QPushButton class. */
   QLabel         *_stepsNumber;         /**< A private field holds pointer to a object of QLabel class. */
   QLabel         *_bestPath;            /**< A private field holds pointer to a object of QLabel class. */
   QLabel         *_Time;                /**< A private field holds pointer to a object of QLabel class. */
   QLabel         *_bestPathLabel;       /**< A private field holds pointer to a object of QLabel class. */
   QLabel         *_stepsNumberLabel;    /**< A private field holds pointer to a object of QLabel class. */
   QLabel         *_TimeLabel;           /**< A private field holds pointer to a object of QLabel class. */
   QLabel         *_algorithmLabel;      /**< A private field holds pointer to a object of QLabel class. */
   QComboBox      *_comboBoxMaze;        /**< A private field holds pointer to a object of QComboBox class. */
   QComboBox      *_comboBoxAlgorithm;   /**< A private field holds pointer to a object of QComboBox class. */
   QStringList    _fileNames;            /**< A private field holds pointer to a object of QStringList class. */
   int            _index;                /**< A private field holds the current index number of used graphics. */
   int            _algorithm = 0;        /**< A private field holds the current index number of used algorithm. */

 public:
  /**
   * @brief A ControlPanel class constructor.
   * @param[in] parent The pointer to Widget's parent.
  */
  ControlPanel(QWidget *parent = nullptr);
  /**
   * @brief A function that returns pointerto the Maze class object.
   * @return Maze class object.
  */
  Maze *maze() {return _PaintView->maze();}
  /**
   * @brief A function that returns pointerto the PaintView class object.
   * @return PaintView class object.
  */
  PaintView *paintView() {return _PaintView;}
  /**
   * @brief A function that returns current steps number made in the maze.
  */
  void stepsNumber() {_stepsNumber->setText(QString::number(maze()->stepsNumber()));}
  /**
   * @brief A function that returns the shortest steps number possible to get from the start to the meta in the maze.
  */
  void bestPathNumber() {_bestPath->setText(QString::number(maze()->bestPath()));}

 signals:
  /**
   * @brief A signal that report the sign.
  */
  void reportSign(const QString &);
  /**
   * @brief A signal that report closing the application.
  */
  void reportClosing(); 

 public slots:
 /**
   * @brief A function that reset the steps number, the whole path and puts the robot in the start position.
  */
  void restartMaze();
  /**
   * @brief A function that is adding the last move to remembered queue and increase the number of steps done. Function moves the robot one step in the maze according to chosen algorithm.
  */
  void stepInMaze();
  /**
   * @brief A function that repeats the stepInMaze function until the robots reaches the end of labirynth.
  */
  void solveMaze();
  /**
   * @brief A function that changes the graphinc in the maze according to the chosen design.
  */
  void loadGraphics();
  /**
   * @brief A function that is moving the robot to the last position and reduce the step number by one.
  */
  void stepBack();
  /**
   * @brief Function that react on changing the index with loading the right maze.
   * @param[in] index Current chosen index.
  */
  void on_fileName_currentIndexChanged(int index);
  /**
   * @brief Function that react on changing the index with loading the right algorithm to use.
   * @param[in]  index Current chosen index.
  */
  void on_algorithm_currentIndexChanged(int index);
}; 

#endif