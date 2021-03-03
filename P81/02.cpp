#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 8;

//表示棋盘向量，8个元素的值都是为0
vector<int> board(MAX);

void show_result()
{
    //i表示y，board[i]表示x
    for(size_t i = 0; i < board.size(); i++)
    {
        cout<< "(" << i << "," << board[i] << ")";
    }
    cout << endl;
}

//使用循环来解
int check_cross() 
{
    //这种坐标表示方法，表示他们既不在同一行也不在同一列
    //这里的j和i都代表y坐标，就是行
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = i + 1; j < board.size() -1; j++)
        {
            //y坐标相减是否等于x坐标相减
            if ((j-i) == (size_t)abs(board[j] - board[i]))
                return 1;
        }
    }

    return 0;
}

void put_chess()
{
    while(next_permutation(board.begin(), board.end()))
    {
        //这个排列所代表的坐标是否有界
        //判断是否是一个解
        if(!check_cross())
        {
            show_result();//若是解，则打印坐标
        }
    }
}

int main()
{
    //初始化为0-7
    for(size_t i = 0; i < board.size(); i++)
    {
        board[i] = i;
    }

    //将棋子放到棋盘上面，即生成下一个排列
    put_chess();
    return 0;
}