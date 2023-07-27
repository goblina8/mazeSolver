#include "maze.hh"


Maze:: Maze(string name, int _graphics)
{
    graphics = _graphics;
    srand((unsigned) time(NULL));
    string fullPath = "mazes/"+name;
    readMaze(fullPath);
    setCorners(graphics);
    start();
}

void Maze:: move(int direction)
{
    if(!maze[position_x][position_y].is_it_meta())
    {
        vector<int> xy;
        xy.push_back(position_x);
        xy.push_back(position_y);
        previous_position.push_back(xy);
        switch(direction)
        {
            case 1: //up
            {
                position_x -= 1;
                break;
            }
            case 2: //down
            {
                position_x += 1;
                break;
            }
            case 3: //left
            {
                position_y -= 1;
                break;
            }
            case 4: //right
            {
                position_y += 1;
                break;
            }
            default:
            {
                break;
            }
        }
        maze[position_x][position_y].visit();
        maze[position_x][position_y].robot_image(graphics);
        maze[previous_position.back()[0]][previous_position.back()[1]].visited_image(graphics);
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
            if(maze[position_x][position_y].is_path(1) == 1)
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
            if(maze[position_x][position_y].is_path(2) == 1)
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
            if(maze[position_x][position_y].is_path(3) == 1)
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
            if(maze[position_x][position_y].is_path(4) == 1)
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

void Maze:: restartVisit(int x, int y)
{
    maze[x][y].restartVisit();
}

void Maze:: start()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(maze[i][j].is_it_start())
            {
                position_x = i;
                position_y = j;
            }
        }
    }
}

void Maze:: restart()
{
    if(previous_position.size() > 0)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                maze[i][j].basic_image();
                maze[i][j].restartVisit();
                if(maze[i][j].is_it_start())
                {
                    position_x = i;
                    position_y = j;
                    maze[i][j].robot_image(graphics);
                    maze[i][j].visit();
                }
                if(maze[i][j].is_it_meta())
                {
                    position_x = i;
                    position_y = j;
                    maze[i][j].meta_image();
                }
            }
        }
        while(previous_position.size() != 0)
        {
            previous_position.erase(previous_position.begin()+1);
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

void Maze:: stepBack()
{
    if(previous_position.size() > 0)
    {
        unvisit(position_x, position_y);
        if(maze[position_x][position_y].was_it_visited() == 0)
        {
            maze[position_x][position_y].basic_image();
            if(maze[position_x][position_y].is_it_start() == 1)
            {
               maze[position_x][position_y].start_image();
            }
            if(maze[position_x][position_y].is_it_meta() == 1)
            {
               maze[position_x][position_y].meta_image();
            }
        }
        else
        {
            maze[position_x][position_y].visited_image(graphics);
        }
        position_x = previous_position.back()[0];
        position_y = previous_position.back()[1];
        maze[position_x][position_y].robot_image(graphics);
        previous_position.pop_back();
    }
}

void Maze::stepRandom()
{
    int index;
    vector<int> visited;
    vector<int> not_visited;
    if(maze[position_x][position_y].is_path(1) == 1)
    {
        if(maze[position_x - 1][position_y].was_it_visited() >= 1)
        {
            visited.push_back(1);
        }
        else
        {
            not_visited.push_back(1);
        }   
    }
    if(maze[position_x][position_y].is_path(2) == 1)
    {
        if(maze[position_x + 1][position_y].was_it_visited() >= 1)
        {
            visited.push_back(2);
        }
        else
        {
            not_visited.push_back(2);
        }   
    }
    if(maze[position_x][position_y].is_path(3) == 1)
    {
        if(maze[position_x][position_y - 1].was_it_visited() >= 1)
        {
            visited.push_back(3);
        }
        else
        {
            not_visited.push_back(3);
        }   
    }
    if(maze[position_x][position_y].is_path(4) == 1)
    {
        if(maze[position_x][position_y + 1].was_it_visited() >= 1)
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
        index = (rand()%(not_visited.size()));
        move(not_visited[index]);
    }
    else //if there is only checked way
    {
        index = (rand()%(visited.size()));
        move(visited[index]);
    }
}

qint64 Maze:: solveMazeRandom()
{
    auto start = std::chrono::high_resolution_clock::now();
    while(!(maze[position_x][position_y].is_it_meta()))
    {
        stepRandom();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    return duration.count();
}

void Maze::stepAlgorithm()
{
    cout << "STEP" << endl;
}

qint64 Maze:: solveMazeAlgorithm()
{
    auto start = std::chrono::high_resolution_clock::now();
    cout << "SOLVED" << endl;
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    return duration.count();
}

void Maze:: readMaze(string& name)
{
    ifstream txt;
    int size = 0;
    txt.open(name);
    string line;
    if(txt.is_open())
    {
        getline(txt,line);
        int f = 0;
        if(line[0] == '#')
        {
            if(line[2] != '#')
            {
                size = (line[1]-48)*10+line[2]-48;
                f = f+3;
            }
            else
            {
                size = line[1] - 48;
                f = f+2;
            }
        }
        this->size = size;
        if(line[f] == '#')
        {
            if(line[f+2] != '#')
            {
                this->minSteps = (line[f+1]-48)*10+line[f+2]-48;
            }
            else
            {
                this->minSteps = line[f+1] - 48;
            }
        }
        int x = 0;
        int number = 1;
        bool start = 0;
        bool meta = 0;
        while(x < size)
        {
            getline(txt,line);
            int k = 0;
            int y = 0;
            while(y != size)
            {
                if(line[k] == ' ')
                {
                    maze[x][y] = Square(x,y,start,meta,number, graphics);
                    y++;
                    start = 0;
                    meta = 0;
                }
                else
                {
                    int numb = isdigit(line[k]);
                    if(numb == 0)
                    {
                        if(line[k] == 's')
                        {
                            start = 1;
                        }
                        else if (line[k] == 'm')
                        {
                            meta = 1;
                        }
                    }
                    else
                    {
                        if(isdigit(line[k+1]) == 0)
                        {
                            number = line[k]-48;
                        }
                        else
                        {
                            number = (line[k]-48)*10+line[k+1]-48;
                            k++;
                        }
                    }
                }
                k++;
            }
            x++;
        }
    }
    else
    {
        cout << "NO SUCH FILE" << endl;
    }
}

void Maze:: newGraphics(int tmp)
{
    graphics = tmp;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            maze[i][j].loadPicture(graphics);
            if((i == position_x) && (j == position_y))
            {
               maze[i][j].robot_image(graphics);
            }
        }
    }
}

void Maze:: setCorners(int graphics)
{
    for(int x = 0; x < size; x++)
    {
        for(int y = 0; y < size; y++)
        {
            if(x>0)
            {
                if(y>0)
                {
                    if(maze[x-1][y-1].cornerUL())
                    {
                        maze[x][y].ul_set(graphics);
                    }
                }
                if(y<size-1)
                {
                    if(maze[x-1][y+1].cornerUR())
                    {
                        maze[x][y].ur_set(graphics);
                    }
                }
            }
            if(x<size-1)
            {
                if(y>0)
                {
                    if(maze[x+1][y-1].cornerDL())
                    {
                        maze[x][y].dl_set(graphics);
                    }
                }
                if(y<size-1)
                {
                    if(maze[x+1][y+1].cornerDR())
                    {
                        maze[x][y].dr_set(graphics);
                    }
                }
            }
        }
    }
}