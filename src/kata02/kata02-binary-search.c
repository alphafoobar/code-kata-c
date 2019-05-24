#include "kata02-binary-search.h"

int chop(const int key, const int *array, int low, int high) {
    while (low < high) {
        const int remaining = high - low;
        const int point = low + remaining / 2;
        const int value = array[point];

        if (value == key) {
            return point;
        }

        if (value > key) {
            high = point;
        } else {
            low = point + 1;
        }
    }
    return -1;
}
