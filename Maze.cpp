/**
 * @file Maze.cpp
 * @author renee Olds
 */

#include "Maze.h"
#include <iostream>
using namespace std;

int solveMaze()
{
    const char ENTRANCE = 'I';
    const char EXIT = 'O';
    const char WALL = '#';
    const char ROAD = ' ';
    const char EXPLORED = 'e';

    const int ROW = 8;
    const int COLUMN = 16;

    char maze[ROW][COLUMN] =
    {
        "######I########",
        "### ##  ##   ##",
        "# #  ##    # ##",
        "# ## ### ### ##",
        "#      ###   ##",
        "### ## ##### ##",
        "##  ##       ##",
        "###O###########",
    };

    Position mazeEntrance;
    mazeEntrance.x = 0;
    mazeEntrance.y = 6;

    // Make two copies of the original map
    char mazeCopy[ROW][COLUMN];   // Used to calculate the path
    char mazeDisplay[ROW][COLUMN];   // Used to display the path
    
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
        {
            mazeCopy[i][j] = maze[i][j];
            mazeDisplay[i][j] = maze[i][j];
        }
    }

    //Stack path(ROW*COLUMN);
    stack<Position> path;

    Position currentPosition;

    currentPosition = mazeEntrance;

    while (true)
    {   
        if (mazeCopy[currentPosition.x][currentPosition.y] == EXIT) break;

        // Get the maze element at each direction of the current position
        char positionUp = mazeCopy[currentPosition.x - 1][currentPosition.y];
        char positionRight = mazeCopy[currentPosition.x][currentPosition.y + 1];
        char positionDown = mazeCopy[currentPosition.x + 1][currentPosition.y];
        char positionLeft = mazeCopy[currentPosition.x][currentPosition.y - 1];

        // Mark this position as explored, then go up one position
        if (( positionUp == ROAD || positionUp == EXIT ) && currentPosition.x - 1 >= 0)
        {
            path.push(currentPosition);
            mazeCopy[currentPosition.x][currentPosition.y] = EXPLORED;
            currentPosition.x--;
        }

        // Mark this position as explored, then go right one position
        else if (( positionRight == ROAD || positionRight == EXIT) && currentPosition.y + 1 < COLUMN)
        {
            path.push(currentPosition);
            mazeCopy[currentPosition.x][currentPosition.y] = EXPLORED;
            currentPosition.y++;
        }

        // Mark this position as explored, then go down one position
        else if ((positionDown == ROAD || positionDown == EXIT) && currentPosition.x + 1 < ROW)
        {
            path.push(currentPosition);
            mazeCopy[currentPosition.x][currentPosition.y] = EXPLORED;
            currentPosition.x++;
        }

        // Mark this position as explored, then go left one position
        else if ((positionLeft == ROAD || positionLeft == EXIT) && currentPosition.y >= 0)
        {
            path.push(currentPosition);
            mazeCopy[currentPosition.x][currentPosition.y] = EXPLORED;
            currentPosition.y--;
        }

        // Mark this position as a WALL, then go back one position
        else
        {
            mazeCopy[currentPosition.x][currentPosition.y] = WALL;
            currentPosition = path.top();
            path.pop();
        }
    }
    
    int finalSize = path.size();

    Position *rightPath = new Position[ROW*COLUMN];

    for (int i = finalSize - 1; i >= 0; i--)
    {
        rightPath[i] = path.top();
        path.pop();
    }



    // Output the Animation of Walking the path

    for (int i = 0; i < finalSize; i++)
    {
        cout << "Maze" << endl;
        Position tempPosition = rightPath[i];
        mazeDisplay[tempPosition.x][tempPosition.y] = '*';

        for (int a = 0; a < ROW; a++)
        {
            for (int b = 0; b < COLUMN; b++)
            {
                cout << mazeDisplay[a][b];
            }
            cout << endl;
        }

        // Sleep(200);
        // system("cls");
        mazeDisplay[tempPosition.x][tempPosition.y] = ' ';
    }



    // Print out the complete path

    cout << "Original Map: " << endl;
    for (int a = 0; a < ROW; a++)
    {
        for (int b = 0; b < COLUMN; b++)
        {
            cout << maze[a][b];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Right Path: " << endl;

    for (int i = 0; i < finalSize; i++)
    {
        Position temp = rightPath[i];
        cout << temp.x + 1 << "," << temp.y + 1 << '\t';
        if ((i + 1) % 5 == 0) cout << endl;
    }

    cout << endl;

    return 0;
}






/* delete this

// void Maze::solveMaze(){
//     for(int r = 0; r < 4; ++r){
//         for(int c = 0; c < 4; ++c){
//             cout << maze[r][c] << " ";
//             wasHere[r][c] = false;
//             correctPath[r][c] = false;
//         }
//         cout << endl;
//     }
//     bool s = solve(startX, startY);
//     cout << s << endl;
//     for(int r = 0; r < 4; ++r){
//         for(int c = 0; c < 4; ++c){
//             cout << correctPath[r][c] << " ";
//         }
//         cout << endl;
//     }
// }

// bool Maze::solve(int x, int y){
//     if(x == endX && y == endY){
//         return true;
//     }
//     if(!maze[x][y] || wasHere[x][y]){
//         return false;
//     }
//     wasHere[x][y] = true;
//     if(x != 0){
//         if(solve(x-1, y)){
//             correctPath[x][y] = true;
//             return true;
//         }
//     }
//     if(x != 4){
//         if(solve(x+1, y)){
//             correctPath[x][y] = true;
//             return true;
//         }
//     }
//     if(y != 0){
//         if(solve(x, y+1)){
//             correctPath[x][y] = true;
//             return true;
//         }
//     }
//     if(y != 4){
//         if(solve(x, y-1)){
//             correctPath[x][y] = true;
//             return true;
//         }
//     }
//     return false;
// }




Maze::Maze(int iden, int stx, int sty, int dex, int dey){
    startx = stx;
    starty = sty;
    destx = dex;
    desty = dey;
}


bool Maze::solveMaze(int x, int y)
    Location current;
    for(int i = 0; int i < thisMaze->length(); ++i){
        if(thisMaze->at(i).x == x && thisMaze->at(i).y == y){
            current = thisMaze->at(i);
        }
    }

    if((current.x == destx && current.y == desty) || correctPath.){   //this is destination or correct path was here){
        return false
    }
    correctPath.push(current)
    if(no wall north && solveMaze(x+1, y)){
        return true
    }
    if(no wall south && solveMaze(x-1,y)){
        return true
    }
    if(no wall east && solveMaze(x, y+1)){
        return true
    }
    if(no wall west && solveMaze(x, y-1)){
        return true
    }
    correctPath.pop(); // get rid of this position from correct path because it is a dead end
    return false;

*/ //delete this
