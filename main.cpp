#include <iostream> //for console input/output
#include <fstream> //for file input/output
#include <windows.h> //for access to the console
#include <conio.h> //for getch()
#include <string>
#include <ctime>
#include <random>
#include "constants.h"
#include "unitclass.h"
#include "playerclass.h"
#include "appleclass.h"
#include "pointsclass.h"

bool loadMap(const char* path);
void setWindow(const int WIDTH, const int HEIGHT);
void goTo(int x, int y);
char readCharacter(int x, int y);

int main()
{
    char gamePlayed {'T'}; //T for TRUE, F for FALSE
    while(gamePlayed == 'T')
    {
        system("cls");
    if(loadMap(con::PATH_TO_LEVEL))
    {
        setWindow(con::SCREEN_WIDTH, con::SCREEN_HEIGHT);
        PlayerClass snake(con::HALF_THE_WIDTH, con::HALF_THE_HEIGTH,
                          con::INITIAL_X_VELOCITY, con::INITIAL_Y_VELOCITY,
                          con::INITIAL_DIRECTION, con::INITIAL_DEAD_STATUS, con::INITIAL_EXIT_STATUS);
        PointsClass points(con::INITIAL_POINTS);
        points.showPoints(con::POINTS_X_POS, con::POINTS_Y_POS);
        snake.placeSnake();
        std::srand((unsigned int)std::time(nullptr));
        AppleClass apple;
        char input {0};
            while(!snake.died())
            {
                if(kbhit())
                {
                    input = getch();
                }
                snake.handleInput(input);
                if(snake.exited())
                    gamePlayed = false;
                snake.update(points, con::POINTS_X_POS, con::POINTS_Y_POS, apple);
                Sleep(70);
            }
            if(!snake.exited())
            {
                system("cls");
                goTo(con::HALF_THE_WIDTH - 4, con::HALF_THE_HEIGTH);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                std::cout << "GAME OVER";
                goTo(con::HALF_THE_WIDTH - 4, con::HALF_THE_HEIGTH + 1);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                std::cout << "SCORE: " << points.getPoints();
                goTo(con::HALF_THE_WIDTH - 8, con::HALF_THE_HEIGTH + 2);
                std::cout << "Press R to restart";
                goTo(con::HALF_THE_WIDTH  -7, con::HALF_THE_HEIGTH + 3);
                std::cout << "Press Q to quit";
                gamePlayed = getch();
                switch(gamePlayed)
                {
                case 'q':
                case 'Q':
                    gamePlayed = 'F';
                    break;
                case 'r':
                case 'R':
                    gamePlayed = 'T';
                    break;
                }
            }
        }
    }
    return 0;
}

bool loadMap(const char* path)
{
    bool success = true;
    std::fstream levelFile;
    levelFile.open(path);
    std::string line;
    if(levelFile.is_open())
    {
        while(!levelFile.eof())
        {
            getline(levelFile, line);
            std::cout << line << '\n';
        }
    }
    else
        success = false;
    return success;
}

void setWindow(const int WIDTH, const int HEIGHT)
{
    _COORD windowCoord;
    windowCoord.X = WIDTH;
    windowCoord.Y = HEIGHT;

    _SMALL_RECT windowRect;
    windowRect.Top = 0;
    windowRect.Left = 0;
    windowRect.Bottom = HEIGHT;
    windowRect.Right = WIDTH - 1;

    HANDLE windowHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(windowHandle, windowCoord);
    SetConsoleWindowInfo(windowHandle, TRUE, &windowRect);

    CONSOLE_CURSOR_INFO consoleCursor;
    consoleCursor.dwSize = 100;
    consoleCursor.bVisible = false;
    SetConsoleCursorInfo(windowHandle, &consoleCursor);
}

void goTo(int x, int y)
{
    COORD cursorCoord;
    cursorCoord.X = x;
    cursorCoord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorCoord);
}

char readCharacter(int x, int y)
{
    goTo(x, y);
    DWORD howMany = 1;
    char character = '\0';
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if(consoleHandle != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))
    {
        DWORD read = 0;
        if(!ReadConsoleOutputCharacterA(consoleHandle, &character, howMany,
            bufferInfo.dwCursorPosition, &read) || read != 1)
            character = '\0';
    }
    return character;
}
