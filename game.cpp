#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>


using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int playerX, playerY;
int objX, objY;
int objX2, objY2;
int objX3, objY3;
int objX4, objY4;

int dangerX, dangerY;
int dangerX2, dangerY2;
int dangerX3, dangerY3;
int dangerX4, dangerY4;
int dangerX5, dangerY5;
int dangerX6, dangerY6;
int dangerX7, dangerY7;
int dangerX8, dangerY8;
int dangerX9, dangerY9;

int Points;

enum eDirecton { NONE = 0, RIGHT, LEFT, UP, DOWN};
eDirecton dir;
int speed;

string difficulty;

void Initialization()
{
    srand(time(0));
    gameOver = false;
    Points = 0;
    dir = NONE;
    playerX = rand() % width;
    playerY = rand() % height;
    objX = rand() % width;
    objY = rand() % height;
    objX2 = rand() % width;
    objY2 = rand() % height;
    objX3 = rand() % width;
    objY3 = rand() % height;
    objX4 = rand() % width;
    objY4 = rand() % height;

    dangerX = rand() % width;
    dangerY = rand() % height;
    dangerX2 = rand() % width;
    dangerY2 = rand() % height;
    dangerX3 = rand() % width;
    dangerY3 = rand() % height;
    dangerX4 = rand() % width;
    dangerY4 = rand() % height;
    dangerX5 = rand() % width;
    dangerY5 = rand() % height;
    dangerX6 = rand() % width;
    dangerY6 = rand() % height;
    dangerX7 = rand() % width;
    dangerY7 = rand() % height;
    dangerX8 = rand() % width;
    dangerY8 = rand() % height;
    dangerX9 = rand() % width;
    dangerY9 = rand() % height;
    Points = 0;
}

void Create()
{
    system("cls");

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < 20 ; j++)
        {
            if (j == 0)
                cout << "|";
            if (i == playerY && j == playerX)
                cout << "0";
            else if (i == objY && j == objX)
                cout << "@";
            else if (i == objY2 && j == objX2)
                cout << "@";
            else if (i == objY3 && j == objX3)
                cout << "@";
            else if (i == objY4 && j == objX4)
                cout << "@";
            else if (i == dangerY && j == dangerX)
                cout << "^";
            else if (i == dangerY2 && j == dangerX2)
                cout << "^";
            else if (i == dangerY3 && j == dangerX3)
                cout << "^";
             else if (i == dangerY4 && j == dangerX4)
                cout << "^";
             else if (i == dangerY5 && j == dangerX5)
                cout << "^";
             else if (i == dangerY6 && j == dangerX6)
                cout << "^";
             else if (i == dangerY7 && j == dangerX7)
                cout << "^";
             else if (i == dangerY8 && j == dangerX8)
                cout << "^";
             else if (i == dangerY9 && j == dangerX9)
                cout << "^";
            else
            {
                    cout << " ";
            }

            if (j == width - 1)
               cout << "|";
        }
        cout << endl;
    }

    cout << " ";
    for (int i = 0; i < width + 1; i++)
        cout << "_";
    cout << endl;
    cout << " Points:" << Points << endl;
}

void Controls()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            default:
                break;
        }
    }
}

void Logic()
{


    if (dir == LEFT){
        playerX = playerX - 1;


    }

    else if (dir == RIGHT){
        playerX = playerX + 1;


    }

    else if (dir == UP){
        playerY = playerY - 1;

    }
    else if (dir == DOWN){
        playerY = playerY + 1;


    }


    if (playerX >= width) playerX = 0; else if (playerX < 0) playerX = width;
    if (playerY >= height) playerY = 0; else if (playerY < 0) playerY = height;

    if(playerX == dangerX && playerY == dangerY || playerX == dangerX2 && playerY == dangerY2 || playerX == dangerX3 && playerY == dangerY3
       || playerX == dangerX4 && playerY == dangerY4 || playerX == dangerX5 && playerY == dangerY5 || playerX == dangerX6 && playerY == dangerY6
       || playerX == dangerX7 && playerY == dangerY7 || playerX == dangerX8 && playerY == dangerY8 || playerX == dangerX9 && playerY == dangerY9)
    {
        gameOver = true;
    }

    if (playerX == objX && playerY == objY)
    {
        srand(time(0));
        Points += 10;
        objX = rand() % width;
        objY = rand() % height;

    }
    if (playerX == objX2 && playerY == objY2)
    {
        srand(time(0));
        Points += 10;
        objX2 = rand() % width;
        objY2 = rand() % height;

    }
    if (playerX == objX3 && playerY == objY3)
    {
        srand(time(0));
        Points += 10;
        objX3 = rand() % width;
        objY3 = rand() % height;

    }
    if (playerX == objX4 && playerY == objY4)
    {
        srand(time(0));
        Points += 10;
        objX4 = rand() % width;
        objY4 = rand() % height;

    }
}
int main(){


    cout << "Enter Desired Speed Value" << endl << "Easy: Speed > 100" << endl << "Normal: Speed > 50" << endl << "Hard: Speed < 50" << endl;
    cin >> speed;
    if (speed < 50){
        difficulty = "Hard";
    }
    if (speed >= 50 && speed < 100){
        difficulty = "Normal";
    }
    if (speed >= 100){
        difficulty = "Easy";
    }
    cout << "you chose " << difficulty << " " << system("pause");


    Initialization();

    while (!gameOver)
    {
        Create();
        Controls();
        Logic();
        Sleep(speed);
    }

    if (gameOver){
        system("cls");
        cout << "Game Over, You Scored " << Points << " Points";
    }


    return 0;
}

