#include <iostream>
#include <windows.h>

int main()
{

    HANDLE hMapFile = OpenFileMappingA(
        FILE_MAP_READ,
        FALSE,
        "Global\\CatalanNumbers");

    if (hMapFile == NULL)
    {
        std::cerr << "Could not open file mapping object (" << GetLastError() << ")\n";
        return 1;
    }

    // Get the size of the shared memory
    MEMORY_BASIC_INFORMATION mbi;
    VirtualQuery(hMapFile, &mbi, sizeof(mbi));
    SIZE_T size = mbi.RegionSize;

    int *pData = (int *)MapViewOfFile(
        hMapFile,
        FILE_MAP_READ,
        0,
        0,
        size);

    if (pData == NULL)
    {
        std::cerr << "Could not map view of file (" << GetLastError() << ")\n";
        CloseHandle(hMapFile);
        return 1;
    }

    // Output the Catalan numbers
    std::cout << "Catalan Numbers:\n";
    for (SIZE_T i = 0; i < size / sizeof(int); ++i)
    {
        std::cout << pData[i] << " ";
    }
    std::cout << "\n";

    // Clean up
    UnmapViewOfFile(pData);
    CloseHandle(hMapFile);

    return 0;
}
