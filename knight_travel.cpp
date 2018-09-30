//
// Created by DayWong on 27/09/2018.
//
//knight travels around several contries

#include<iostream>
#include<iomanip>
using namespace std;

const int M = 8;
const int N = 8;
int Knight[M][N];
int Count = 0;
int number_of_way = 0;
int walk[8][2] = {{1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

void print()
{
    number_of_way++;
    cout << "number:" << number_of_way << endl;
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
            cout << setw(3) << Knight[i][j];
        cout << endl;
    }
}

void knight(int Location_x, int Location_y)
{
    Count++;
    Knight[Location_x][Location_y] = Count;

    if(Count == 64)
    {
        print();
    }
    else
    {
        int m, n;
        for(int i = 0; i < 8; i++)
        {
            m = Location_x + walk[i][0];
            n = Location_y + walk[i][1];
            if(m >= 0 && m < M && n >= 0 && n < N)
                if(Knight[m][n] == 0)  //never been there before
                {
                    knight(m, n);
                }
        }
    }
    Knight[Location_x][Location_y] = 0;
    Count--; //结束或者路不通的时候都需要退到上一步，此时count需要 -1
}

int main(void)
{
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            Knight[i][j] = 0;
    //print();
    knight(0, 0);

    return 0;
}