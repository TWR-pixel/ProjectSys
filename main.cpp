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

    
    cout << "Year: "; cout << t.wYear << endl << endl;;
    
    enum arch { x86INTEL, IntelItaniumBased = 6, ARM64 = 12, ARM = 5, x64AMD_or_Intel = 9,UNKNOWN = 0xffff};//АРХИТЕКТУРЫ ПРОЦЕССОРОВ

    
    switch (sysI.wProcessorArchitecture)
    {
    case x86INTEL: cout << "Архитектура: x86 INTEL." << '\n'; break;
    case IntelItaniumBased: cout << "Архитектура: Intel Itanium-based." << '\n'; break;
    case ARM64: cout << "Архитектура: ARM64." << '\n'; break;
    case ARM: cout << "Архитектура: ARM." << '\n'; break;
    case x64AMD_or_Intel: cout << "Архитектура: x64 (AMD or Intel). " << '\n'; break;
    case UNKNOWN:cout << "Архитектура: Unknown architecture. " << '\n'; break;
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
