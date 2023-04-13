#include <iostream>
#include "Windows.h"

using namespace std;

int  arSize  = 0;
int* arr     = 0;
int  minimum = 0;
int  maximum = 0;
int  minIdx  = 0;
int  maxIdx  = 0;
int  av      = 0;

DWORD WINAPI min_max(LPVOID) {
    minimum = arr[0];
    maximum = arr[0];
    for (int i = 0; i < arSize; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
            minIdx = i;
        }
        Sleep(7);
        if (arr[i] > maximum) {
            maximum = arr[i];
            maxIdx = i;
        }
        Sleep(7);
    }
    cout << "MIN element: " << minimum << endl;
    cout << "MAX element: " << maximum << endl;

    return 0;
}

DWORD WINAPI average(LPVOID) {
    av = 0;
    for (int i = 0; i < arSize; i++) {
        av += arr[i];
        Sleep(12);
    }
    av /= arSize;
    cout << "Average: " << av << endl;

    return 0;
}


int main()
{
    cout << "Input array Size: ";
    cin >> arSize;
    arr = new int[arSize];
    cout << "Input array elements: ";
    for (auto i = 0; i < arSize; i++)
        cin >> arr[i];

    HANDLE hMin_Max = CreateThread(NULL, 0, min_max, NULL, 0, NULL);
    HANDLE hAverage = CreateThread(NULL, 0, average, NULL, 0, NULL);

    WaitForSingleObject(hMin_Max, INFINITE);
    WaitForSingleObject(hAverage, INFINITE);

    arr[minIdx] = av;
    arr[maxIdx] = av;

    cout << "Array: ";
    for (auto i = 0; i < arSize; i++)
        cout << arr[i] << ' ';
    cout << endl;

    CloseHandle(hMin_Max);
    CloseHandle(hAverage);

    return 0;
}