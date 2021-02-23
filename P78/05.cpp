// alg_search.cpp
// compile with: /EHsc
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

// Return whether second element is twice the first
bool twice ( int elem1,  int elem2 )
{
     return  2 * elem1 == elem2;
}

int main( )
{
     using  namespace std;
    vector < int> v1, v2;
    list < int> L1;
    vector < int>::iterator Iter1, Iter2;//向量迭代器
    list < int>::iterator L1_Iter, L1_inIter;//列表迭代器

     int i;
     for ( i =  0 ; i <=  5 ; i++ )
    {
        v1.push_back(  5 * i );
    }
     for ( i =  0 ; i <=  5 ; i++ )
    {
        v1.push_back(  5 * i );
    }

     int ii;
     for ( ii =  4 ; ii <=  5 ; ii++ )
    {
        L1.push_back(  5 * ii );
    }

     int iii;
     for ( iii =  2 ; iii <=  4 ; iii++ )
    {
        v2.push_back(  10 * iii );
    }

    //打印出来
    cout <<  "Vector v1 = ( " ;
     for ( Iter1 = v1.begin( ) ; Iter1 != v1.end( ) ; Iter1++ )
        cout << *Iter1 <<  " ";
    cout <<  ")" << endl;

    cout <<  "List L1 = ( " ;
     for ( L1_Iter = L1.begin( ) ; L1_Iter != L1.end( ) ; L1_Iter++ )
        cout << *L1_Iter <<  " ";
    cout <<  ")" << endl;

    cout <<  "Vector v2 = ( " ;
     for ( Iter2 = v2.begin( ) ; Iter2 != v2.end( ) ; Iter2++ )
        cout << *Iter2 <<  " ";
    cout <<  ")" << endl;


     // Searching v1 for first match to L1 under identity
     //在v1.begin( ), v1.end( )区间查找，在L1.begin( ), L1.end( )子区间里面的元素，只要找到就输出
    vector < int>::iterator result1;
    result1 = search (v1.begin( ), v1.end( ), L1.begin( ), L1.end( ) );

     if ( result1 == v1.end( ) )
        cout <<  "There is no match of L1 in v1."
             << endl;
     else
        cout <<  "There is at least one match of L1 in v1"
             <<  "\n and the first one begins at "
             <<  "position " << result1 - v1.begin( ) <<  "." << endl;

     // Searching v1 for a match to v2 under the binary predicate twice
    //twice函数的含义是：v1.begin( ), v1.end( )这个区间里面的元素*2，再与v2.begin( ), v2.end( )进行比较
    vector < int>::iterator result2;
    result2 = search  (v1.begin( ), v1.end( ), v2.begin( ), v2.end( ), twice );

     if ( result2 == v1.end( ) )
        cout <<  "There is no match of L1 in v1."
             << endl;
     else
        cout <<  "There is a sequence of elements in v1 that "
             <<  "are equivalent\n to those in v2 under the binary "
             <<  "predicate twice\n and the first one begins at position "
             << result2 - v1.begin( ) <<  "." << endl;
}

/*
Vector v1 = ( 0 5 10 15 20 25 0 5 10 15 20 25 )
List L1 = ( 20 25 )
Vector v2 = ( 20 30 40 )
There is at least one match of L1 in v1
and the first one begins at position 4.
There is a sequence of elements in v1 that are equivalent
to those in v2 under the binary predicate twice
and the first one begins at position 2.
*/