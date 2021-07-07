#include <iostream>
#include <Windows.h>
#include "Header.h"

using namespace std;

int main()
{   
    setlocale(LC_ALL, "ru");
    system("color 2");//ЦВЕТ ТЕКСТА КОНСОЛИ 

    SYSTEMTIME t;
    SYSTEM_INFO sysI;
    MEMORYSTATUSEX memory;
   
    setLength(&memory);//Header.h Инициализирует переменную memory
    
    GlobalMemoryStatusEx(&memory);
    GetSystemTime(&t);
    GetSystemInfo(&sysI);

    
    cout << "Year: "; cout << t.wYear << endl << endl;
   
    switch (sysI.wProcessorArchitecture)
    {
    case PROCESSOR_ARCHITECTURE_INTEL: cout << "Архитектура: x86." << '\n'; break;
    case PROCESSOR_ARCHITECTURE_IA64: cout << "Архитектура: Intel Itanium-based ." << '\n'; break;
    case PROCESSOR_ARCHITECTURE_ARM64: cout << "Архитектура: ARM64." << '\n'; break;
    case PROCESSOR_ARCHITECTURE_ARM: cout << "Архитектура: ARM." << '\n'; break;
    case PROCESSOR_ARCHITECTURE_AMD64: cout << "Архитектура: x64 (AMD or Intel). " << '\n'; break;
    case PROCESSOR_ARCHITECTURE_UNKNOWN:cout << "Архитектура: Unknown architecture. " << '\n'; break;
    }
   
    cout << "-----------------------" << '\n';
    cout <<"Страничная память: " << sysI.dwPageSize << '\n';
    cout << "-----------------------" << '\n';
    cout << "Объем RAM (Байты):  " << memory.ullTotalPhys << '\n';
    cout << "-----------------------" << '\n';
    cout << "Виртуальное адресное пространство (Байты): " << memory.ullTotalVirtual << '\n';
    cout << "-----------------------" << '\n' << '\n';

    
    system("pause");
    return EXIT_SUCCESS;
}
