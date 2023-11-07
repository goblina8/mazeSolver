/**
 * @file maze.hh
 * 
 * @brief Header file of Maze class.
 * 
 */ 
#ifndef MAZE_HH
#define MAZE_HH

#include <iostream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "square.hh"
#include "corner.hh"
#include "frame.hh"
#include "dijkstra.hh"

using namespace std;

/** 
 * @brief The class represents the maze.
 */
class Maze{
  private:
   Square                 maze[16][16];                     /**< A private field with all the squeres */
   vector<vector<int>>    previous_position;                /**< A vector with all the orevious positions of the robot. */
   vector<Corner>         corners;                          /**< A vector with all the Corner class objects. */
   vector<Frame>          frames;                           /**< A vector with all the Frame class objects. */
   bool                   meta = 0;                         /**< A private field with information if the maze was solved. 1 - it was, 0 it was not. */
   int                    size = -1;                        /**< A private field with information about the size of the maze. */
   int                    minSteps = -1;                    /**< A private field with information about the minimum steps number needed to solve the maze. */
   int                    position_x = -1;                  /**< A private field number with information about current x position of teh robot in the maze. */
   int                    position_y = -1;                  /**< A private field number with information about current y position of teh robot in the maze. */
   int                    number_of_visited_squares = 0;    /**< A private field with information about number of currently made steps by the robot in the maze. */
   int                    graphics = 1;                     /**< A private field with the number of currently used graphics vershion. */
   qint64                 duration_time = 0;                /**< A private field with the duration time of algorithm. */
   Dijkstra               *D;                               /**< A private field that reptesents Dijkstra Algoryth. */
  

  public:
  /**
   * @brief A Maze class constructor.
   * @param[in] name The name of the file to load the maze.
   * @param[in] graphics The value of currently used graphics design.
   */
   Maze(string name, int graphics);
   /**
   * @brief The function that increase visited value by one in chosen square.
   * @param[in] x The x value of the square.
   * @param[in] y The y value of the square.
   */
   void visit(int x, int y);
   /**
   * @brief The function that decrease visited value by one in chosen square.
   * @param[in] x The x value of the square.
   * @param[in] y The y value of the square.
   */
   void unvisit(int x, int y);
   /**
   * @brief The function that sets visited value to 0 in chosen square.
   * @param[in] x The x value of the square.
   * @param[in] y The y value of the square.
   */
   void restartVisit(int x, int y);
   /**
   * @brief The function that moves robot in chosen direction.
   * @param[in] direction The direction to move robot. 0 - right, 2 - lefy, 3 - top, 4 - bottom.
   */
   void move(int direction); //0,1,2,3 prawo,lewo,gora, dol
   /**
   * @brief The function that sets the whole maze graphics to a style of chosen graphics design.
   * @param[in] graphics Chosen graphics design of the picture.
   */
   void newGraphics(int graphics);
   /**
   * @brief The function that sets corners in the maze.
   * @param[in] graphics Chosen graphics design of the pictures.
   */
   void setCorners(int graphics);
   /**
   * @brief The function that sets frame of the maze.
   * @param[in] graphics Chosen graphics design of the pictures.
   */
   void setFrame(int graphics);
   /**
   * @brief The function that load the maze from the file.
   * @param[in] name Name of chosen file.
   */
   void readMaze(string &name);
    /**
    * @brief The function that calculates movement of the robot due to Dijkstra Algorithm.
    */
   void dijkstra();
   /**
    * @brief The function that moves the robot in the random direction.
    */
   void stepRandom();
   /**
    * @brief The function that moves the robot according to the chosen algorithm.
    */
   void stepAlgorithm();
   /**
    * @brief The function that moves robot to the previous position.
    */
   void stepBack();
   /**
    * @brief The function that prepares the amze to start application.
    */
   void start();
   /**
    * @brief The function that restart maze configuration to the start.
    */
   void restart(); 
   /**
    * @brief The function that returns duration of chosen algorithm.
    */
   qint64 WhatTime();
   /**
    * @brief The function that checks if chosen square is a start.
    * @param[in] x The x position of square.
    * @param[in] y The y position of square.
    * @retval The information if the square if a start. 1 - it is, 0 - it is not.
    */
   bool is_it_start(int x, int y);
   /**
    * @brief The function that checks if chosen square is a meta.
    * @param[in] x The x position of square.
    * @param[in] y The y position of square.
    * @retval The information if the square if a meta. 1 - it is, 0 - it is not.
    */
   bool is_it_meta(int x, int y);
   /**
    * @brief The function that checks if there is path to go in chosen direction.
    * @param[in] wall_number The chosen direction. 1 - up, 2 - down, 3 - right, 4 - left.
    * @retval The information if there is path. 1 - it is, 0 - it is not.
    */
   bool is_there_path(int wall_number);
    /**
    * @brief The function that checks if chosen square was visited.
    * @param[in] x The x position of square.
    * @param[in] y The y position of square.
    * @retval The information if the square was visited. 1 - it was, 0 - it was not.
    */
   bool was_it_visited(int x, int y);
   /**
    * @brief The function that returns the size of corners vector.
    * @retval The size of the corners vector.
    */
   int corner_size();
   /**
    * @brief The function that returns the size of the maze.
    * @return The size of the maze.
    */
   int what_size();
   /**
    * @brief The function that returns the size of frames vector.
    * @return The size of the frames vector.
    */
   int frame_size();
   /**
    * @brief The function that returns the current x position of the robot.
    * @return The current position in x of the robot.
    */
   int now_x() {return position_x;}
   /**
    * @brief The function that returns the current y position of the robot.
    * @return The current position in y of the robot.
    */
   int now_y() {return position_y;}
   /**
    * @brief The function that returns the minimum value of the steps made in the maze.
    * @return The minimum value of the steps made in the maze.
    */
   int bestPath() {return minSteps;}
   /**
    * @brief The function that returns the current value of the steps made in the maze.
    * @return The current value of the steps made in the maze.
    */
   int stepsNumber() {return previous_position.size();}
   /**
    * @brief The function that returns the numbers of steps that was taken during random solving the maze.
    */
   void solveMazeRandom();
   /**
    * @brief The function that returns the numbers of steps that was taken during solving the maze with algorithm.
    */
   void solveMazeAlgorithm();  
   /**
   * @brief The function that returns the QImage image1 from a chosen square.
   * @param[in] x The chosen x value of square.
   * @param[in] y The chosen y value of square.
   * @return The QImage class object that represents square.
   */
   QImage image1(int x, int y);
   /**
   * @brief The function that returns the QImage image2 from a chosen square.
   * @param[in] x The chosen x value of square.
   * @param[in] y The chosen y value of square.
   * @return The QImage class object that represents step or the robot.
   */
   QImage image2(int x, int y);
   /**
   * @brief The function that returns the Squre from a chosen square.
   * @param[in] x The chosen x value of square.
   * @param[in] y The chosen y value of square.
   * @return The chosen squere.
   */
   Square square(int x, int y);
   /**
   * @brief The function that returns chosen Corner class object.
   * @param[in] i The chosen corners class object..
   * @return The Corner class object.
   */
   Corner corner(int i);
   /**
   * @brief The function that returns chosen Frame class object.
   * @param[in] i The chosen frames class object..
   * @return The Frame class object.
   */
   Frame frame(int i);
   /**
   * @brief The function that returns pointer to obcjet of class Dijkstra.
   * @return The Pointer to Dijkstra class object.
   */
   Dijkstra * returnD() {return D;}
};

#endif