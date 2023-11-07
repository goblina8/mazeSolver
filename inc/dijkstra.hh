/**
 * @file dijkstra.hh
 * 
 * @brief Header file of Dijkstra class.
 * 
 */ 
#ifndef DIJKSTRA_HH
#define DIJKSTRA_HH

#include <iostream>
#include <vector>
#include <queue>
#include "square.hh"
using namespace std;

/** 
 * @brief The class represents the Dijkstra Algorithm elements.
 */
class Dijkstra{
  private:
   Square*                vertex[16][16];           /**< A private field with all vetexes that are pointers to the squeres */
   int                    vertex_value[16][16];     /**< A private field with all vetexes values*/
   int                    size;                     /**< A private field that represents the size of the maze that has to be converted into graph */
   int                    source_x = -1;            /**< A private field with information about the source vertex x */
   int                    source_y = -1;            /**< A private field with information about the source vertex y */
   vector<vector<int>>    path;                     /**< A vector with the whole path from where robot is, to the meta calculated by Dijkstra Algorithm */
   vector<int>            move;                     /**< A vector with the whole movement for the path */
   bool                   way_out = -1;             /**< A private field with information if the path was find */
   int                    step_required = -1;       /**< A private field with information how many steps was required rto find the exit */
   int                    step_count = -1;           /**< A private field with which step on the path is next to do */
  public:
  /**
   * @brief A Dijkstra class constructor.
   * @param[in] size The size of current maze.
   * @param[in] size All the squares in the maze.
   */
   Dijkstra(int _size, Square (&_maze)[16][16]);
   /**
   * @brief The function finds path to get out of a maze.
   */
   void solve();
   /**
   * @brief The function gives the whole movement firection an the path that gets the robot out of a maze.
   * @return The path to get out of maze.
   */
   int ReturnMovement();
   /**
   * @brief The function gives the whole path that gets the robot out of a maze. 
   * @return The direction to move.
   */
   vector<int> ReturnPath();
   /**
    * @brief The function gives information did finding the path went well.
    * @retval The information about if there is a way out of maze. 1 - there is, 0 - there is not.
    */
   bool isThereWayOut();
   /**
    * @brief This function increse the value of step_count by 1.
    */
   void step();
   /**
    * @brief This function decrese the value of step_count by 1.
    */
   void stepBack();


};

#endif