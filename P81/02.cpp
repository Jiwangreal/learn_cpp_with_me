#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 8;

//��ʾ����������8��Ԫ�ص�ֵ����Ϊ0
vector<int> board(MAX);

void show_result()
{
    //i��ʾy��board[i]��ʾx
    for(size_t i = 0; i < board.size(); i++)
    {
        cout<< "(" << i << "," << board[i] << ")";
    }
    cout << endl;
}

//ʹ��ѭ������
int check_cross() 
{
    //���������ʾ��������ʾ���ǼȲ���ͬһ��Ҳ����ͬһ��
    //�����j��i������y���꣬������
    for (size_t i = 0; i < board.size(); i++)
    {
        for (size_t j = i + 1; j < board.size() -1; j++)
        {
            //y��������Ƿ����x�������
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
        //�������������������Ƿ��н�
        //�ж��Ƿ���һ����
        if(!check_cross())
        {
            show_result();//���ǽ⣬���ӡ����
        }
    }
}

int main()
{
    //��ʼ��Ϊ0-7
    for(size_t i = 0; i < board.size(); i++)
    {
        board[i] = i;
    }

    //�����ӷŵ��������棬��������һ������
    put_chess();
    return 0;
}