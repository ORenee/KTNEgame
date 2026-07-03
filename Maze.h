/**
 * @file Maze.h
 * @author Renee Olds
 */

#ifndef MAZE_
#define MAZE_

#include <array>
#include <set>
#include <stack>

struct Position{
    int x;
    int y;
};

int solveMaze();

/* delete this

class Maze{
    
    private:
        std::array<Location, 4> maze1 = {{Location one(0, 0, 3), Location two(1, 0, 3), Location three(0, 1, 2), Location four(1, 1, 0)}};
        struct Location{
            int x;
            int y;
            int walls; // 1 for north wall, 2 for west wall, 3 for both, 0 for neither
            Location(int xi, int yi, int w){
                x = xi;
                y = yi;
                walls = w;
            }

        }
        struct identifyMaze{
            int ident1;
            int ident2;
            std::array<Location, 6> thisMaz;
        }
        int startx;
        int starty;
        int destx;
        int desty;
        std::set<Location> correctPath;
        std::array<Location, 4>* thisMaze = &maze1;
    public:
        Maze(int iden, int stx,, int sty, int dex, int dey);

        bool solveMaze(int x, int y);

        ~Maze() = default;
        
    // private:

    //     bool maze[4][4] = { {true, false, true, true}, {true, true, true, false}, {false, true, false, true}, {true, true, true, true} };
    //     bool wasHere[4][4];
    //     bool correctPath[4][4];
    //     int startX = 0;
    //     int startY = 1;
    //     int endX = 3;
    //     int endY = 2;

    //     bool solve(int x, int y);

    // public:

    //     Maze() = default;

    //     ~Maze() = default;

    //     void solveMaze();
};

*/
//delete this
#endif