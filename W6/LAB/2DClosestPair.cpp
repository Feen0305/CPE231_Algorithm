// Phoorin Chinphuad 66070501043
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 10000

struct PAIR {
    int x, y;
};

float distance(PAIR p1, PAIR p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float min(float x, float y) {
    return (x < y) ? x : y;
}

float bruteForce(PAIR arr[], int n) {
    float min_dist = MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (distance(arr[i], arr[j]) < min_dist)
                min_dist = distance(arr[i], arr[j]);
    return min_dist;
}

bool compareX(PAIR a, PAIR b) {
    return a.x < b.x;
}

bool compareY(PAIR a, PAIR b) {
    return a.y < b.y;
}

float stripClosest(PAIR strip[], int size, float d) {
    float min_dist = d;
    sort(strip, strip + size, compareY); 

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < min_dist; ++j)
            if (distance(strip[i], strip[j]) < min_dist)
                min_dist = distance(strip[i], strip[j]);

    return min_dist;
}

float EfficientClosestPair(PAIR arr[], int n) {
    if (n <= 3)
        return bruteForce(arr, n);

    int mid = n / 2;
    PAIR midPoint = arr[mid];

    float dl = EfficientClosestPair(arr, mid);
    float dr = EfficientClosestPair(arr + mid, n - mid);

    float d = min(dl, dr);

    PAIR strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(arr[i].x - midPoint.x) < d)
            strip[j] = arr[i], j++;

    return min(d, stripClosest(strip, j, d));
}

float closest(PAIR arr[], int n) {
    sort(arr, arr + n, compareX);
    return EfficientClosestPair(arr, n);
}

int main() {
    int size;
    cin >> size;

    PAIR arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i].x >> arr[i].y;
    }

    printf("%.3f", closest(arr, size));

    return 0;
}
