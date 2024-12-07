#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

namespace lsahn
{

static int BinarySearchRecursive(const vector<int>& arr, int l, int r, int val)
{
    if (l > r)
    {
        return -1;
    }

    int mid = static_cast<int>((l + r) / 2);
    if (arr[mid] == val)
    {
        return mid;
    }
    else if (val < arr[mid])
    {
        r = mid - 1;
    }
    else
    {
        l = mid + 1;
    }

    return BinarySearchRecursive(arr, l, r, val);
}

void BinarySearchRecursiveExample()
{
    vector<int> arr = { 1, 2, 3, 4, 5, 99, 1000, 4893, 2030420, 483943920 };

    int index = BinarySearchRecursive(arr, 0, arr.size() - 1, 5);
    assert(index == 4);

    index = BinarySearchRecursive(arr, 0, arr.size() - 1, 1);
    assert(index == 0);

    index = BinarySearchRecursive(arr, 0, arr.size() - 1, 2030420);
    assert(index == 8);

    index = BinarySearchRecursive(arr, 0, arr.size() - 1, 9999);
    assert(index == -1);
}

} // lsahn