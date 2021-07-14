#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

    }

    int quick_find(vector<int>& arr, int low, int high, int k) {
        int mid = partition(arr, low, high);
        if (mid+1 == k)
            return mid;
        else if (mid+1 < k)
            return quick_find(arr, mid+1, high, k-mid-1);
        else
            return quick_find(arr, low, mid, k);

    }

    int partition(vector<int> &arr, int low, int high) {
        if (low == high) {
            return low;
        }

        int cmp = arr[high];
        int pos = 0;
        for (int i = 0; i < high; i++) {
            if (arr[i] < cmp) {
                int tmp = arr[pos];
                arr[pos] = arr[i];
                arr[i] = tmp;
                pos++;
            }
        }

        arr[high] = arr[pos];
        arr[pos] = cmp;
        return pos;
    }
};