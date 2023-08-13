/**
 * @file frame.hh
 * 
 * @brief Header file of Frame class.
 * 
 */ 
#ifndef FRAME_HH
#define FRAME_HH

#include <iostream>
#include <QImage>
#include <string>
#include <QString>

using namespace std;

/** 
 * @brief The class represents the piece of frame surronding the maze.
 */
class Frame{
  private:
   QImage   frame;      /**< A private field holds QImage. */
   int      x;          /**< A private field with the x value of the row. */
   int      y;          /**< A private field with the y value of the column. */
   int      size;       /**< A private field with information about maze size. */ 
   int      graphics;   /**< A private field with the number of currently used graphics vershion. */

  public:
  /**
   * @brief A Frame class constructor.
   * @param[in] _x The value of the row.
   * @param[in] _y The value of the column.
   * @param[in] graphics The value of currently used graphics design.
   * @param[in] size The size of the maze.
   */
   Frame(int _y, int _x, int _graphics, int _size);
   /**
   * @brief The function that returns x.
   * @return Number of row in which the object is located.
   */
   int position_x();
   /**
   * @brief The function that returns y.
   * @return Number of column in which the object is located.
   */
   int position_y();
   /**
   * @brief Function that sets the graphics value.
   * @param[in] _graphics The value of currently used graphics design.
   */  
   void set(int _graphics);
   /**
   * @brief Function that sets the QImage image of the top left corner.
   */  
   void ul_set();
   /**
   * @brief Function that sets the QImage image of the top right corner.
   */  
   void ur_set();
   /**
   * @brief Function that sets the QImage image of the bottom left corner.
   */  
   void dl_set();
   /**
   * @brief Function that sets the QImage image of the bottom right corner.
   */  
   void dr_set();
   /**
   * @brief Function that sets the QImage image of the left part of the frame.
   */  
   void left_set();
   /**
   * @brief Function that sets the QImage image of the right part of the frame.
   */ 
   void right_set();
   /**
   * @brief Function that sets the QImage image of the top part of the frame.
   */ 
   void up_set();
   /**
   * @brief Function that sets the QImage image of the bottom part of the frame.
   */ 
   void down_set();
   /**
   * @brief The function that returns the QImage.
   * @return The QImage class object that represents corner.
   */
   QImage image();
};

#endif
