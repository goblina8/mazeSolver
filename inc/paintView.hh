/**
 * @file paintView.hh
 * 
 * @brief Header file of PaintView class.
 * 
 */ 
#ifndef PAINTVIEW_HH
#define PAINTVIEW_HH

#include <QWidget>
#include <QImage>
#include <QTimer>
#include <QPainter>
#include <QBrush>
#include <QPalette>
#include <iostream>
#include <QSizePolicy>
#include "maze.hh"

using namespace std;

#define MAX_GRAPHICS 2

/** 
 * @brief The class responsible for painting the whole graphics included in maze.
 */
class PaintView: public QWidget{ 
  Q_OBJECT
 private:
  QImage     _Robot;          /**< A private field holds QImage. */
  Maze      *_Maze;           /**< A private field holds the pointer to a Maze class object. */
  QWidget   *_parent;         /**< A private field holds the pointer to a widget parent. */
  double     mazeHeight = 0;  /**< A private field with information about the height of the maze. */
  double     mazeWidth = 0;   /**< A private field with information about the width of the maze. */
  double     itemHeight = 0;  /**< A private field with information about the height of the inside square element. */
  double     itemWidth = 0;   /**< A private field with information about the width of the inside square element. */
  double     _y_start = 0;    /**< A private field with information about height where to start painting. */
  double     _x_start = 0;    /**< A private field with information about width where to start painting. */
  int        _x = 0;          /**< A private field with information how much the next object should be move in x. */
  int        _y = 0;          /**< A private field with information how much the next object should be move in y. */
  int        Hmin = 228;      /**< A private field with information about minimum height. */
  int        Hmax = 973;      /**< A private field with information about maximum height. */
  int        Wmin = 306;      /**< A private field with information about minimum width. */
  int        Wmax = 1638;     /**< A private field with information about maximum width. */
  int        graphics = 1;    /**< A private field with number of currently used graphic design, */

 public:
 /**
   * @brief A PaintView class constructor.
   * @param[in] parent The pointer to Widget's parent.
   * @param[in] name The name of the file to load the maze.
   */
  PaintView(QWidget *parent = nullptr, string name = "a");
  /**
   * @brief A function that returns pointer to the Maze class object.
   * @return PaintView class object.
   */
  Maze *maze() {return _Maze;}
  /**
   * @brief A function that returns value of mazeHeight.
   * @return Value of the height of the maze.
   */
  double heightMaze() {return mazeHeight;}
  /**
   * @brief A function that returns value of mazeWidth.
   * @return Value of the width of the maze.
   */
  double widthMaze() {return mazeWidth;}
  /**
   * @brief A function that paints the whole maze.
   * @param[in] event Information about events in the winodow.
   */
  void paintEvent( QPaintEvent * event );
  /**
   * @brief A function that creates the new maze.
   * @param[in] name The name of file with the maze informations.
   */
  void newMaze(string name);
  /**
   * @brief A function that changes the maze design.
   */
  void changeGraphics();
}; 

#endif
