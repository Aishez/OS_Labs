#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
struct SharedData
{
    int n;
    int catalanNumbers[100];
};

// Function to calculate Catalan number
int calculateCatalanNumber(int n)
{
    if (n == 0)
        return 1;

    int catalan = 1;
    for (int i = 0; i < n; ++i)
    {
        catalan = catalan * 2 * (2 * i + 1) / (i + 2);
    }
    return catalan;
}

void producer(int n)
{
    const wchar_t *name = L"Global\\catalan";
    HANDLE hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, sizeof(SharedData), (LPCSTR)name);

    LPVOID pData = MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(SharedData));
    if (pData == NULL)
    {
        cerr << "Could not map view of file (" << GetLastError() << ")." << endl;
        CloseHandle(hMapFile);
        return;
    }

    // Set the number of Catalan numbers to generate
    SharedData *sharedData = static_cast<SharedData *>(pData);
    sharedData->n = n;

    // Generate Catalan numbers
    for (int i = 0; i < n; ++i)
    {
        sharedData->catalanNumbers[i] = calculateCatalanNumber(i);
    }

    UnmapViewOfFile(pData);
    while (1)
    {
    }
    CloseHandle(hMapFile);
}

// Consumer process
void consumer()
{
    const wchar_t *name = L"Global\\catalan";
    HANDLE hMapFile = OpenFileMapping(
        FILE_MAP_READ, // Read access
        FALSE,         // Do not inherit the name
        (LPCSTR)name); // Name of the mapping object

    if (hMapFile == NULL)
    {
        cerr << "Could not open file mapping object (" << GetLastError() << ")." << endl;
        return;
    }

    // Map the shared memory into this process's address space
    LPVOID pData = MapViewOfFile(hMapFile, FILE_MAP_READ, 0, 0, sizeof(SharedData));
    if (pData == NULL)
    {
        cerr << "Could not map view of file (" << GetLastError() << ")." << endl;
        CloseHandle(hMapFile);
        return;
    }

    SharedData *sharedData = static_cast<SharedData *>(pData);
    for (int i = 0; i < sharedData->n; ++i)
    {
        cout << "Catalan[" << i << "] = " << sharedData->catalanNumbers[i] << endl;
    }
    UnmapViewOfFile(pData);
    CloseHandle(hMapFile);
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        int n = stoi(argv[1]);
        producer(n);
    }
    else
    {
        consumer();
    }

    return 0;
}