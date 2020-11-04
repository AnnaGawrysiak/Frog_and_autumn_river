#include <iostream>
#include <vector>
//#include <ctime>
//#include <cstdlib>
#include <algorithm>

using namespace std;

int how_much_time(int position_of_leaves[], int width, int size_);

int main()
{
//srand( time( 0 ) );
// dodajemy test zaby

   int width_of_a_river = 5;

   const int size_ = 8;

   int A[size_];

    A[0] = 1;
    A[1] = 3;
    A[2] = 1;
    A[3] = 4;
    A[4] = 2;
    A[5] = 3;
    A[6] = 5;
    A[7] = 4;

  // for (int i = 0; i < size; i++)
  // {
   //    A[i] = ((rand()%5)+ 1);
   //    cout << A[i] << endl;
  // }

   int time = how_much_time(A, width_of_a_river, size_);

   if (time > 0)
        cout << "Frog needs to wait for " << time << " seconds until there are enough leaves to jump across the river. " << endl;

    else
        cout << "The are not enough leaves for the frog to jump across the river. " << endl;

    return 0;
}

int how_much_time(int position_of_leaves[], int width, int size_)
{

    vector <bool> gaps;

    for (int i = 0 ; i < width; i++)
    {
        gaps.push_back(false);
    }

    int time = 0;
    int leaf = 0;

    for (time = 0; time < size_; time++)
    {

    if (gaps[position_of_leaves[time]] == false)
        {
            gaps[position_of_leaves[time]] = true;
            leaf++;
        }

            if (leaf == width)
            {
                return time;
            }
    }

    return -1;
}

/*int how_much_time(int position_of_leaves[], int width)
{

    vector <int> gaps;

    for (int i = 0 ; i < width; i++)
    {
        gaps.push_back(i + 1);
    }

    int time = 0;

    for (time = 0; time < 8; time++)
    {

        gaps.erase(remove(gaps.begin(), gaps.end(), position_of_leaves[time]), gaps.end());

            if (gaps.empty())
            {
                return time;
            }
    }

    return -1;
}
*/
