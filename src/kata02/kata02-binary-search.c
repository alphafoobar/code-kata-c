int chop(int key, const int *array, int offset, int length) {
    while (offset < length) {
        const int remaining = length - offset;
        int point = offset + remaining / 2;
        if (array[point] == key) {
            return point;
        }
        if (array[point] > key) {
            length = point;
        } else {
            offset = point + 1;
        }
    }
    return -1;
}
