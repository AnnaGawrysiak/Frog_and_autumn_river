#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <unordered_set>

using namespace std;

int how_much_time(int position_of_leaves[], int width);

int main()
{
    srand( time( 0 ) );

   int width_of_a_river = 5;

   const int size = 10;

   int A[size];

   for (int i = 0; i < size; i++)
   {
       A[i] = ((rand()%5)+ 1);
       cout << A[i] << endl;
   }

   int time = how_much_time(A, width_of_a_river);

   if (time > 0)
        cout << "Frog needs to wait for " << time << " seconds until there are enough leaves to jump across the river. " << endl;

    else
        cout << "The are not enough leaves for the frog to jump across the river. " << endl;

    return 0;
}

int how_much_time(int position_of_leaves[], int width)
{

    int gaps[5];

    for (int i = 0 ; i < width; i++)
    {
        gaps[i] = (i + 1);
    }

    vector <int>covered_gaps;

    int size = 10;

    int time = 0;

    for (time = 0; time < size; time++)
    {
        vector<int>::iterator it = find(covered_gaps.begin(), covered_gaps.end(), position_of_leaves[time]);

        if (it != covered_gaps.end())
            cout << "" << endl;
        else
            covered_gaps.push_back(position_of_leaves[time]);

            unordered_multiset<int> mv(begin(covered_gaps), end(covered_gaps));
            unordered_multiset<int> ma(begin(gaps), end(gaps));

            if (mv == ma)
            {
                return time+1;
            }
    }

    return -1;
}
