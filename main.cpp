#include <iostream> //for console input/output
#include <fstream> //for file input/output
#include <windows.h> //for access to the console
#include <conio.h> //for getch()
#include <string>
#include "constants.h"
#include "unitclass.h"

bool loadMap(const char* path);

int main()
{
    if(loadMap(con::PATH_TO_LEVEL))
    {
        getch();
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
