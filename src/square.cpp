#include "square.hh"

void Square:: visited_image(int graphics)
{
    QString name = ":/img/step";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    item.load(fullPath);
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
    QString name = ":/img/robot";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    item.load(fullPath);
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

QImage Square:: imageUR()
{
    return ur_corner;
}

QImage Square:: imageUL()
{
    return ul_corner;
}

QImage Square:: imageDL()
{
    return dl_corner;
}

QImage Square:: imageDR()
{
    return dr_corner;
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
    //START
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
    if(start)
    {
        QString name = ":/img/robot";
        QString nr = QString::number(graphics);
        QString end = ".png"; 
        QString fullPath = name + nr + end;
        item.load(fullPath);
        visited++;
    }
}


void Square:: loadPicture(int graphics)
{
    QString name;
    QString begin = ":/img/";
    QString end = ".png"; 
    //TRACE
    if(visited)
    {
        QString name = ":/img/step";
        QString nr = QString::number(graphics);
        QString end = ".png"; 
        QString fullPath = name + nr + end;
        item.load(fullPath);
    }
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

void Square:: ul_set(int graphics)
{
    QString name = ":/img/up_left";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    ul_corner.load(fullPath);
}

void Square:: ur_set(int graphics)
{
    QString name = ":/img/up_right";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    ur_corner.load(fullPath);
}

void Square:: dl_set(int graphics)
{
    QString name = ":/img/down_left";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    dl_corner.load(fullPath);
}

void Square:: dr_set(int graphics)
{
    QString name = ":/img/down_right";
    QString nr = QString::number(graphics);
    QString end = ".png"; 
    QString fullPath = name + nr + end;
    dr_corner.load(fullPath);
}

void Square:: ul_reset()
{
    ul_corner = QImage();
}

void Square:: ur_reset()
{
    ur_corner = QImage();
}

void Square:: dl_reset()
{
    dl_corner = QImage();
}

void Square:: dr_reset()
{
    dr_corner = QImage();
}

bool Square:: cornerUL()
{
    if(right_wall && down_wall)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Square:: cornerUR()
{
    if(left_wall && down_wall)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Square:: cornerDL()
{
    if(right_wall && up_wall)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Square:: cornerDR()
{
    if(left_wall && up_wall)
    {
        return true;
    }
    else
    {
        return false;
    }
}