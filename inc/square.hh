/**
 * @file square.hh
 * 
 * @brief Header file of Square class.
 * 
 */ 
#ifndef SQUARE_HH
#define SQUARE_HH

#include <QImage>
#include <string>
#include <QString>
#include <QDebug>

using namespace std;

/** 
 * @brief The class represents the each and every squere of the maze.
 */
class Square{
  private:
   QImage     square;         /**< A private field holds QImage that represents one square in teh maze. */
   QImage     item;           /**< A private field holds QImage that represents the robot or the "been there" field in the maze. */
   bool       left_wall;      /**< A private value that represents if there is a left wall in a square. 1 - there is, 0 thre is not. */
   bool       right_wall;     /**< A private value that represents if there is a right wall in a square. 1 - there is, 0 thre is not. */
   bool       up_wall;        /**< A private value that represents if there is a top wall in a square. 1 - there is, 0 thre is not. */
   bool       down_wall;      /**< A private value that represents if there is a bottom wall in a square. 1 - there is, 0 thre is not. */
   bool       meta;           /**< A private value that represents if the square is a meta. 1 - it is, 0 - it is not. */
   bool       start;          /**< A private value that represents if the square is a start. 1 - it is, 0 - it is not. */
   int        position[2];    /**< A private field holds the row and column placement of the square */
   int        square_option;  /**< A private field holds information about what kind of square it is. More information in instruction.txt. */
   int        visited = 0;    /**< A private value that represents the information of how many times square was visited. */

  public:
  /**
   * @brief A Square class constructor.
   * @param[in] _x The value of the row.
   * @param[in] _y The value of the column.
   * @param[in] _start The value that informs if the square is a start.
   * @param[in] _meta The value that informs if the square is a meta
   * @param[in] number The type of the square.
   * @param[in] graphics The value of currently used graphics design.
   */
   Square(int x, int y, bool _start, bool _meta, int number, int graphics);
   /**
   * @brief A Corner class constructor.
  */
   Square(){};
   /**
   * @brief The function that returns information if the square was visited.
   * @return Information of how many times square was visited.
   */
   int was_it_visited();
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
   * @brief The function that returns information if the square is a start.
   * @retval Information if the square is start. 1 - it is, 0 - it is not.
   */
   bool is_it_start();
   /**
   * @brief The function that returns information if the square is a start.
   * @retval Information if the square is start. 1 - it is, 0 - it is not.
   */
   bool is_it_meta();
   /**
   * @brief The function that returns information if there is path in the pointed direction.
   * @param[in] _wall_number Direction to go. 1 - up, 2 - down, 3 - right, 4 - left.
   * @retval Information if the re is path in shown direction. 1 - there is, 0 - there is not.
   */
   bool is_path(int wall_number);
   /**
   * @brief The function that returns information if the square needs a corner in top left corner.
   * @retval Information if the corner is needed. 1 - it is, 0 - it is not.
   */
   bool cornerUL();
   /**
   * @brief The function that returns information if the square needs a corner in top right corner.
   * @retval Information if the corner is needed. 1 - it is, 0 - it is not.
   */
   bool cornerUR();
   /**
   * @brief The function that returns information if the square needs a corner in bottom left corner.
   * @retval Information if the corner is needed. 1 - it is, 0 - it is not.
   */
   bool cornerDL();
   /**
   * @brief The function that returns information if the square needs a corner in bottom right corner.
   * @retval Information if the corner is needed. 1 - it is, 0 - it is not.
   */
   bool cornerDR();
   /**
   * @brief The function that sets image2 to a basic image.
   */
   void basic_image();
   /**
   * @brief The function that sets image2 to a meta image.
   */
   void meta_image();
   /**
   * @brief The function that sets image2 to a start image.
   */
   void start_image();
   /**
   * @brief The function that increase visited value by one.
   */
   void visit();
   /**
   * @brief The function that decrease visited value by one.
   */
   void unvisit();
   /**
   * @brief The function that sets visited value to 0.
   */
   void restartVisit();
   /**
   * @brief The function that sets the image1 picture to a chosen graphic style.
   * @param[in] graphics Chosen graphics design of the picture.
   */
   void loadPicture(int graphics);
   /**
   * @brief The function that sets the image2 picture to a chosen graphic style of step picture.
   * @param[in] graphics Chosen graphics design of the picture.
   */
   void visited_image(int graphics);
   /**
   * @brief The function that sets the image1 picture to a chosen graphic style of robot picture.
   * @param[in] graphics Chosen graphics design of the picture.
   */
   void robot_image(int graphics);
   /**
   * @brief The function that returns the QImage image1.
   * @return The QImage class object that represents square.
   */
   QImage image1();
   /**
   * @brief The function that returns the QImage image2.
   * @return The QImage class object that represents step or robor.
   */
   QImage image2();
};

#endif
