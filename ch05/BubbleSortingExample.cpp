#include <vector>
#include <cassert>

#define MAX_RANDOM 100
#include "Utils.h"

using namespace std;

namespace lsahn
{

void BubbleSorting(vector<int>& array)
{
    for (int i = 0; i < array.size(); ++i)
    {
        for (int j = 0; j < array.size() - i - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                lswap(array[j], array[j + 1]);
            }
        }
    }
}

void BubbleSortingExample()
{
    cout << "+----------------------------+" << endl;
    cout << "|   Bubble Sorting Example   |" << endl;
    cout << "+----------------------------+" << endl;

    vector<int> array;
    array.reserve(10);

    for (int i = 0; i < array.capacity(); i++)
    {
        array.push_back(RandomGen());
    }

    PrintVectorInt(array);
    BubbleSorting(array);
    PrintVectorInt(array);
}

} // lsahn