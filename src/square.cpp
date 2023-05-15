#include "square.hh"

Square:: Square(int x, int y, bool _start, bool _meta, int number)
{
    position[0] = x;
    position[1] = y;
    square_option = number;
    meta = _meta;
    start = _start;
    if(start)
    {
        item.load(":img/robot.png");
        bool visited = 1;
    }
    else if (!meta)
    {
        item.load(":img/basic.png");
    }
    switch(square_option)
    {
        case 1:
        {
            left_wall = 0;
            right_wall = 0;
            up_wall = 0;
            down_wall = 0;
            if(start)
            {
                square.load(":/img/no_walls_start.png");
            }
            else if(meta)
            {
                square.load(":/img/no_walls_meta.png");
            }
            else
            {
                square.load(":/img/no_walls_basic.png");
            }
            break;
        }
        case 2:
        {
            left_wall = 0;
            right_wall = 0;
            up_wall = 1;
            down_wall = 0;
            if(start)
            {
                square.load(":/img/up_wall_start.png");
            }
            else if(meta)
            {
                square.load(":/img/up_wall_meta.png");
            }
            else
            {
                square.load(":/img/up_wall_basic.png");
            }
            break;
        }
        case 3:
        {
            left_wall = 0;
            right_wall = 1;
            up_wall = 0;
            down_wall = 0;
            if(start)
            {
                square.load(":/img/right_wall_start.png");
            }
            else if(meta)
            {
                square.load(":/img/right_wall_meta.png");
            }
            else
            {
                square.load(":/img/right_wall_basic.png");
            }
            break;
        }
        case 4:
        {
            left_wall = 0;
            right_wall = 0;
            up_wall = 0;
            down_wall = 1;
            if(start)
            {
                square.load(":/img/down_wall_start.png");
            }
            else if(meta)
            {
                square.load(":/img/down_wall_meta.png");
            }
            else
            {
                square.load(":/img/down_wall_basic.png");
            }
            break;
        }
        case 5:
        {
            left_wall = 1;
            right_wall = 0;
            up_wall = 0;
            down_wall = 0;
            if(start)
            {
                square.load(":/img/left_wall_start.png");
            }
            else if(meta)
            {
                square.load(":/img/left_wall_meta.png");
            }
            else
            {
                square.load(":/img/left_wall_basic.png");
            }
            break;
        }
        case 6:
        {
            left_wall = 0;
            right_wall = 1;
            up_wall = 1;
            down_wall = 0;
            if(start)
            {
                square.load(":/img/ur_walls_start.png");
            }
            else if(meta)
            {
                square.load(":/img/ur_walls_meta.png");
            }
            else
            {
                square.load(":/img/ur_walls_basic.png");
            }
            break;
        }
        case 7:
        {
            left_wall = 1;
            right_wall = 0;
            up_wall = 1;
            down_wall = 0;
            if(start)
            {
                square.load(":/img/ul_walls_start.png");
            }
            else if(meta)
            {
                square.load(":/img/ul_walls_meta.png");
            }
            else
            {
                square.load(":/img/ul_walls_basic.png");
            }
            break;
        }
        case 8:
        {
            left_wall = 0;
            right_wall = 0;
            up_wall = 1;
            down_wall = 1;
            if(start)
            {
                square.load(":/img/ud_walls_start.png");
            }
            else if(meta)
            {
                square.load(":/img/ud_walls_meta.png");
            }
            else
            {
                square.load(":/img/ud_walls_basic.png");
            }
            break;
        }
        case 9:
        {
            left_wall = 1;
            right_wall = 1;
            up_wall = 0;
            down_wall = 0;
            if(start)
            {
                square.load(":/img/lr_walls_start.png");
            }
            else if(meta)
            {
                square.load(":/img/lr_walls_meta.png");
            }
            else
            {
                square.load(":/img/lr_walls_basic.png");
            }
            break;
        }
        case 10:
        {
            left_wall = 0;
            right_wall = 1;
            up_wall = 0;
            down_wall = 1;
            if(start)
            {
                square.load(":/img/dr_walls_start.png");
            }
            else if(meta)
            {
                square.load(":/img/dr_walls_meta.png");
            }
            else
            {
                square.load(":/img/dr_walls_basic.png");
            }
            break;
        }
        case 11:
        {
            left_wall = 1;
            right_wall = 0;
            up_wall = 0;
            down_wall = 1;
            if(start)
            {
                square.load(":/img/dl_walls_start.png");
            }
            else if(meta)
            {
                square.load(":/img/dl_walls_meta.png");
            }
            else
            {
                square.load(":/img/dl_walls_basic.png");
            }
            break;
        }
        case 12:
        {
            left_wall = 1;
            right_wall = 1;
            up_wall = 1;
            down_wall = 0;
            if(start)
            {
                square.load(":/img/url_walls_start.png");
            }
            else if(meta)
            {
                square.load(":/img/url_walls_meta.png");
            }
            else
            {
                square.load(":/img/url_walls_basic.png");
            }
            break;
        }
        case 13:
        {
            left_wall = 1;
            right_wall = 0;
            up_wall = 1;
            down_wall = 1;
            if(start)
            {
                square.load(":/img/udl_walls_start.png");
            }
            else if(meta)
            {
                square.load(":/img/udl_walls_meta.png");
            }
            else
            {
                square.load(":/img/udl_walls_basic.png");
            }
            break;
        }
        case 14:
        {
            left_wall = 0;
            right_wall = 1;
            up_wall = 1;
            down_wall = 1;
            if(start)
            {
                square.load(":/img/udr_walls_start.png");
            }
            else if(meta)
            {
                square.load(":/img/udr_walls_meta.png");
            }
            else
            {
                square.load(":/img/udr_walls_basic.png");
            }
            break;
        }
        case 15:
        {
            left_wall = 1;
            right_wall = 1;
            up_wall = 0;
            down_wall = 1;
            if(start)
            {
                square.load(":/img/drl_walls_start.png");
            }
            else if(meta)
            {
                square.load(":/img/drl_walls_meta.png");
            }
            else
            {
                square.load(":/img/drl_walls_basic.png");
            }
            break;
        }
        case 16:
        {
            left_wall = 1;
            right_wall = 1;
            up_wall = 1;
            down_wall = 1;
            if(start)
            {
                square.load(":/img/all_walls_start.png");
            }
            else if(meta)
            {
                square.load(":/img/all_walls_meta.png");
            }
            else
            {
                square.load(":/img/all_walls_basic.png");
            }
            break;
        }
    }
}

void Square:: visited_image()
{
    item.load(":/img/been_there.png");
}

void Square:: basic_image()
{
    item.load(":/img/basic.png");
}

void Square:: robot_image()
{
    item.load(":/img/robot.png");
}

void Square:: meta_image()
{
    item.load(":/img/meta.png");
}

void Square:: visit()
{
    visited = 1;
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

bool Square:: was_it_visited()
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