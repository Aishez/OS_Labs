#include <iostream>
#include <windows.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <number_of_catalan_numbers>\n";
        return 1;
    }

    int n = std::stoi(argv[1]);
    HANDLE hMapFile = CreateFileMappingA(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        n * sizeof(int),
        "Global\\CatalanNumbers");

    if (hMapFile == NULL)
    {
        std::cerr << "Could not create file mapping object (" << GetLastError() << ")\n";
        return 1;
    }

    int *pData = (int *)MapViewOfFile(
        hMapFile,
        FILE_MAP_WRITE,
        0,
        0,
        n * sizeof(int));

    if (pData == NULL)
    {
        std::cerr << "Could not map view of file (" << GetLastError() << ")\n";
        CloseHandle(hMapFile);
        return 1;
    }

    // Generate Catalan numbers and write to shared memory
    pData[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        // Generate next Catalan number using the formula
        pData[i] = pData[i - 1] * 2 * (2 * i - 1) / (i + 1);
    }

    // Clean up
    UnmapViewOfFile(pData);
    CloseHandle(hMapFile);

    return 0;
}
