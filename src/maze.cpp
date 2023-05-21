#include "maze.hh"

Maze:: Maze(int size)
{
    srand((unsigned) time(NULL));
    this->size = size;
    switch(size)
    {
        case 6:
        {
            readMaze("mazes/maze6x6.txt");
            /*
            maze[0][0] = Square(0,0,0,0,7);
            maze[0][1] = Square(0,1,0,0,8);
            maze[0][2] = Square(0,2,0,0,2);
            maze[0][3] = Square(0,3,0,0,8);
            maze[0][4] = Square(0,4,0,0,8);
            maze[0][5] = Square(0,5,0,0,6);

            maze[1][0] = Square(1,0,0,0,9);
            maze[1][1] = Square(1,1,0,0,7);
            maze[1][2] = Square(1,2,0,0,10);
            maze[1][3] = Square(1,3,0,0,7);
            maze[1][4] = Square(1,4,0,0,6);
            maze[1][5] = Square(1,5,0,0,9);

            maze[2][0] = Square(2,0,0,0,9);
            maze[2][1] = Square(2,1,0,0,9);
            maze[2][2] = Square(2,2,0,1,7);
            maze[2][3] = Square(2,3,0,1,3);
            maze[2][4] = Square(2,4,0,0,9);
            maze[2][5] = Square(2,5,0,0,9);

            maze[3][0] = Square(3,0,0,0,9);
            maze[3][1] = Square(3,1,0,0,9);
            maze[3][2] = Square(3,2,0,1,11);
            maze[3][3] = Square(3,3,0,1,10);
            maze[3][4] = Square(3,4,0,0,9);
            maze[3][5] = Square(3,5,0,0,9);

            maze[4][0] = Square(4,0,0,0,15);
            maze[4][1] = Square(4,1,0,0,5);
            maze[4][2] = Square(4,2,0,0,8);
            maze[4][3] = Square(4,3,0,0,14);
            maze[4][4] = Square(4,4,0,0,9);
            maze[4][5] = Square(4,5,0,0,9);

            maze[5][0] = Square(5,0,1,0,13);
            maze[5][1] = Square(5,2,0,0,10);
            maze[5][2] = Square(5,3,0,0,13);
            maze[5][3] = Square(5,4,0,0,8);
            maze[5][4] = Square(5,5,0,0,4);
            maze[5][5] = Square(5,6,0,0,10);
            */
            break;
        }
        case 16:
        {
            readMaze("mazes/maze16x16.txt");
            break;
        }
        default:
        {
            break;
        }
    }
    start();
}

void Maze:: move(int direction)
{
    if(!maze[position_now_x][position_now_y].is_it_meta())
    {
        position_previous_x = position_now_x;
        position_previous_y = position_now_y;
        switch(direction)
        {
            case 1:
            {
                position_now_x -= 1;
                break;
            }
            case 2:
            {
                position_now_x += 1;
                break;
            }
            case 3:
            {
                position_now_y -= 1;
                break;
            }
            case 4:
            {
                position_now_y += 1;
                break;
            }
            default:
            {
                break;
            }
        }
        maze[position_now_x][position_now_y].visit();
        maze[position_now_x][position_now_y].robot_image();
        maze[position_previous_x][position_previous_y].visited_image();
    }
}

bool Maze:: is_it_start(int x, int y)
{
    return maze[x][y].is_it_start();
}

bool Maze:: is_it_meta(int x, int y)
{
    return maze[x][y].is_it_meta();
}

bool Maze:: is_there_path(int wall_number)
{
    switch(wall_number)
    {
        case 1:
        {
            if(maze[position_now_x][position_now_y].is_path(1) == 1)
            {
                move(1);
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        case 2:
        {
            if(maze[position_now_x][position_now_y].is_path(2) == 1)
            {
                move(2);
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        case 3:
        {
            if(maze[position_now_x][position_now_y].is_path(3) == 1)
            {
                move(3);
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        case 4:
        {
            if(maze[position_now_x][position_now_y].is_path(4) == 1)
            {
                move(4);
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        default:
        {
            return 0;
            break;
        }
    }
}

bool Maze:: was_it_visited(int x, int y)
{
    return maze[x][y].was_it_visited();
}

void Maze:: visit(int x, int y)
{
    maze[x][y].visit();
}

void Maze:: unvisit(int x, int y)
{
    maze[x][y].unvisit();
}

void Maze:: start()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(maze[i][j].is_it_start())
            {
                position_now_x = i;
                position_now_y = j;
            }
        }
    }
}

void Maze:: restart()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            maze[i][j].basic_image();
            maze[i][j].unvisit();
            if(maze[i][j].is_it_start())
            {
                position_now_x = i;
                position_now_y = j;
                maze[i][j].robot_image();
                maze[i][j].visit();
            }
            if(maze[i][j].is_it_meta())
            {
                position_now_x = i;
                position_now_y = j;
                maze[i][j].meta_image();
            }
        }
    }
}  

QImage Maze:: image1(int x, int y)
{
    return maze[x][y].image1(); 
}

QImage Maze:: image2(int x, int y)
{
    return maze[x][y].image2(); 
}

int Maze:: what_size()
{
    return size;
}

Square Maze:: square(int x, int y)
{
    return maze[x][y];
}

void Maze::step()
{
    vector<int> visited;
    vector<int> not_visited;
    if(maze[position_now_x][position_now_y].is_path(1) == 1)
    {
        if(maze[position_now_x - 1][position_now_y].was_it_visited() == 1)
        {
            visited.push_back(1);
        }
        else
        {
            not_visited.push_back(1);
        }   
    }
    if(maze[position_now_x][position_now_y].is_path(2) == 1)
    {
        if(maze[position_now_x + 1][position_now_y].was_it_visited() == 1)
        {
            visited.push_back(2);
        }
        else
        {
            not_visited.push_back(2);
        }   
    }
    if(maze[position_now_x][position_now_y].is_path(3) == 1)
    {
        if(maze[position_now_x][position_now_y - 1].was_it_visited() == 1)
        {
            visited.push_back(3);
        }
        else
        {
            not_visited.push_back(3);
        }   
    }
    if(maze[position_now_x][position_now_y].is_path(4) == 1)
    {
        if(maze[position_now_x][position_now_y + 1].was_it_visited() == 1)
        {
            visited.push_back(4);
        }
        else
        {
            not_visited.push_back(4);
        }   
    }
    if((visited.size() == 0) && (not_visited.size() == 0)) //no way out
    {
        cout << "No way out" << endl;
    }
    if((not_visited.size() > 0)) //if there is any not checked way
    {
        int index = (rand()%(not_visited.size()));
        move(not_visited[index]);
    }
    else //if there is only checked way
    {
        int index = (rand()%(visited.size()));
        move(visited[index]);
    }
}

void Maze:: solveMaze()
{
    while(!(maze[position_now_x][position_now_y].is_it_meta()))
    {
        step();
    }
}

void Maze:: readMaze(string name);
{
    FILE *maze;
    int size = 64;
    char line[size];
    maze=fopen(name,"r");
    if(maze != NULL)
    {
        while(1)
        {
            fgets(line, size, maze);
            if (feof(plik) != 0)
            {
                
            }
        }
    }
    else
    {
        cout << "NO SUCH FILE" << endl;
    }
}