/**
 * @file corner.hh
 * 
 * @brief Header file of Corner class
 * 
 */ 
#ifndef CORNER_HH
#define CORNER_HH

#include <iostream>
#include <QImage>
#include <string>
#include <QString>
#include <QDebug>

using namespace std;

/** 
 * @brief The class represents the empty space created as a result of ,aze genetarion and it is inteded to be supplemented with an appropriate picture.
*/
class Corner{
  private:
   QImage  hole;       /**< A private field holds QImage. */
   int     x;          /**< A private field with the x value of the row. */
   int     y;          /**< A private field with the y value of the columnr */
   int     corner;     /**< A private field whose value represents the selected corner. 1 - top left corner. 2 - top right corner. 3 - bottom left corner. 4 - bottom right corner. */
   int     graphics;   /**< A private field with the number of currently used graphics vershion. */

  public:
  /**
   * @brief A Corner class constructor.
   * @param[in] _x The value of the row.
   * @param[in] _y The value of the column.
   * @param[in] _corner The value of corner (1- top left, 2-top right, 3-botton left, 4-bottom right).
   * @param[in] _graphics The value of currently used graphics design.
  */
   Corner(int _x, int _y, int _corner, int _graphics);
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
   * @brief The function that returns the QImage.
   * @return The QImage class object that represents corner.
   */
   QImage image();
   /**
   * @brief Function that sets the graphics value.
   * @param[in] graphics The value of currently used graphics design.
   */  
   void set(int graphics);
   /**
   * @brief Function that checks if the corner is in any bottom corners.
   * @retval Returns 1 when the corner is in any bottom corners, and 0 when it is not.
   */  
   bool cornerX();
   /**
   * @brief Function that checks if the corner is in any right corners.
   * @retval Returns 1 when the corner is in any right corners, and 0 when it is not.
   */  
   bool cornerY();
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
};

#endif