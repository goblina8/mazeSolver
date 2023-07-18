#include "square.hh"

void Square:: visited_image(int graphics)
{
    if(graphics == 1)
    {
        item.load(":/img/been_there.png");
    }
    else
    {
        item.load(":/img/step.png");
    }
}

void Square:: basic_image()
{
    item = QImage();
}

void Square:: start_image()
{
    item = QImage();
}

void Square:: robot_image(int graphics)
{
    if(graphics == 1)
    {
        item.load(":/img/robot.png");
    }
    else
    {
        item.load(":/img/person.png");
    }
}

void Square:: meta_image()
{
    item = QImage();
}

void Square:: visit()
{
    visited++;
}

void Square:: unvisit()
{
    visited--;
}

void Square:: restartVisit()
{
    visited = 0;
}

bool Square:: is_it_start()
{
    return start;
}

bool Square:: is_it_meta()
{
    return meta;
}

bool Square:: is_path(int wall_number)
{
    switch(wall_number)
    {
        case 1: //up
        {
            if(up_wall == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        }
        case 2: //down
        {
            if(down_wall == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        }
        case 3: //right
        {
            if(left_wall == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        }
        case 4: //left
        {
            if(right_wall == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        }
    }
    return 0;
}

int Square:: was_it_visited()
{
    return visited;
}

QImage Square:: image1()
{
    return square;
}

QImage Square:: image2()
{
    return item;
}

int Square:: position_x()
{
    return position[0];
}

int Square:: position_y()
{
    return position[1];
}



Square:: Square(int x, int y, bool _start, bool _meta, int number, int graphics)
{
    position[0] = x;
    position[1] = y;
    square_option = number;
    meta = _meta;
    start = _start;
    if(start)
    {
        if(graphics == 1)
        {
            item.load(":img/robot.png");
        }
        if(graphics == 2)
        {
            item.load(":img/person.png");
        }
        visited++;
    }
    switch(square_option)
    {
        case 1:
        {
            left_wall = 0;
            right_wall = 0;
            up_wall = 0;
            down_wall = 0;
            break;
        }
        case 2:
        {
            left_wall = 0;
            right_wall = 0;
            up_wall = 1;
            down_wall = 0;
            break;
        }
        case 3:
        {
            left_wall = 0;
            right_wall = 1;
            up_wall = 0;
            down_wall = 0;
            break;
        }
        case 4:
        {
            left_wall = 0;
            right_wall = 0;
            up_wall = 0;
            down_wall = 1;
            break;
        }
        case 5:
        {
            left_wall = 1;
            right_wall = 0;
            up_wall = 0;
            down_wall = 0;
            break;
        }
        case 6:
        {
            left_wall = 0;
            right_wall = 1;
            up_wall = 1;
            down_wall = 0;
            break;
        }
        case 7:
        {
            left_wall = 1;
            right_wall = 0;
            up_wall = 1;
            down_wall = 0;
            break;
        }
        case 8:
        {
            left_wall = 0;
            right_wall = 0;
            up_wall = 1;
            down_wall = 1;
            break;
        }
        case 9:
        {
            left_wall = 1;
            right_wall = 1;
            up_wall = 0;
            down_wall = 0;
            break;
        }
        case 10:
        {
            left_wall = 0;
            right_wall = 1;
            up_wall = 0;
            down_wall = 1;
            break;
        }
        case 11:
        {
            left_wall = 1;
            right_wall = 0;
            up_wall = 0;
            down_wall = 1;
            break;
        }
        case 12:
        {
            left_wall = 1;
            right_wall = 1;
            up_wall = 1;
            down_wall = 0;
            break;
        }
        case 13:
        {
            left_wall = 1;
            right_wall = 0;
            up_wall = 1;
            down_wall = 1;
            break;
        }
        case 14:
        {
            left_wall = 0;
            right_wall = 1;
            up_wall = 1;
            down_wall = 1;
            break;
        }
        case 15:
        {
            left_wall = 1;
            right_wall = 1;
            up_wall = 0;
            down_wall = 1;
            break;
        }
        case 16:
        {
            left_wall = 1;
            right_wall = 1;
            up_wall = 1;
            down_wall = 1;
            break;
        }
    }
    loadPicture(graphics);
}


void Square:: loadPicture(int graphics)
{
    QString name;
    QString begin = ":/img/";
    QString end = ".png"; 
    //END OR BASIC
    if(meta)
    {
        name.append('E');
    }
    else
    {
        name.append('B');
    }
    //UP WALL
    if(up_wall)
    {
        name.append('u');
    }
    else
    {
        name.append('_');
    }
    //DOWN WALL
    if(down_wall)
    {
        name.append('d');
    }
    else
    {
        name.append('_');
    }
    if(left_wall)
    {
        name.append('l');
    }
    else
    {
        name.append('_');
    }
    //RIGHT WALL
    if(right_wall)
    {
        name.append('r');
    }
    else
    {
        name.append('_');
    }
    //WHAT TYPE
    if(graphics == 1)
    {
        name.append('1');
    }
    if(graphics == 2)
    {
        name.append('2');
    }
    QString fullPath = begin + name + end;
    this->square.load(fullPath);
}