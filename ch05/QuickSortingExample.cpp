#include <vector>
#include <cassert>

#define MAX_RANDOM 100
#include "Utils.h"

using namespace std;

namespace lsahn
{

int LomutoPartitioning(vector<int>& array, int begin, int end)
{
    int pivot = array[end];
    int pivot_index = end;
    int lli = -1;

    for (int i = begin; i <= end; ++i)
    {
        if ((lli == -1) && (array[i] > pivot))
        {
            lli = i;
        }
        else if ((lli != -1) && (array[i] <= pivot))
        {
            lswap(array[lli], array[i]);
            if (i == end)
            {
                pivot_index = lli;
            }
            lli += 1;
        }
    }

    return pivot_index;
}

void __QuickSorting(vector<int>& array, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int sorted_index = LomutoPartitioning(array, l, r);
    __QuickSorting(array, l, sorted_index - 1);
    __QuickSorting(array, sorted_index + 1, r);
}

void QuickSorting(vector<int>& array)
{
    __QuickSorting(array, 0, array.size() - 1);
}

void QuickSortingExample()
{
    cout << "+---------------------------+" << endl;
    cout << "|   Quick Sorting Example   |" << endl;
    cout << "+---------------------------+" << endl;

    vector<int> array;
    array.reserve(10);

    for (int i = 0; i < array.capacity(); i++)
    {
        array.push_back(RandomGen());
    }

    PrintVectorInt(array);
    QuickSorting(array);
    PrintVectorInt(array);
}

} // lsahn