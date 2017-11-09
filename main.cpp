#include <iostream>
#include <stdlib.h> //swap

void Exercise3()
{
    // Exercise3: даны два указателя на какой-то диапазон адресов. Требуется для
    // каждой пары соседних адресов (данные по адресу), найти количество одинаковых бит,
    // стоящих на одних позициях

    char chBaseChar     = 'z';
    char* pStartPointer = &chBaseChar;
    char* pEndPointer   = pStartPointer + 101;
    int iPairNumber     = 1;

    if (pStartPointer > pEndPointer)
        std::swap(pStartPointer, pEndPointer);

    while (pStartPointer < pEndPointer)
    {
        int iActiveBits = 0;
        char* pchTempFirst  = pStartPointer;
        char* pchTempSecond = ++pStartPointer;

        unsigned char uchEndedChar = *pchTempFirst & *pchTempSecond;

        while (uchEndedChar)
        {
            if (uchEndedChar & 1)
                ++iActiveBits;
            uchEndedChar >>= 1;
        }

        std::cout << "Pair #" << iPairNumber << ", active ended bits: " << iActiveBits << std::endl;

        ++pStartPointer;
        ++iPairNumber;
    }
}

void Exercise2()
{
    // Exercise2: дано число типа long int. Требуется вычислить число единичных бит
    // (не используя напрямую данное число), с помощью дополнительной переменной типа char*

    const long int lBaseLong = 111127;
    char* pBaseLong     = (char*) &lBaseLong;
    char* pStartPointer = pBaseLong;
    char* pEndPointer   = pStartPointer + sizeof(lBaseLong);
    int   iActiveBitsCount = 0;

    if (pStartPointer > pEndPointer)
        std::swap(pStartPointer, pEndPointer);

    while (pStartPointer != pEndPointer)
    {
        unsigned char uchTempChar = (unsigned char) *pStartPointer;
        while (uchTempChar)
        {
            if (uchTempChar & 1)
                iActiveBitsCount++;

            uchTempChar >>= 1;
        }

        ++pStartPointer;
    }

    std::cout << "Active bits: " << iActiveBitsCount << std::endl;
}

void Exercise1()
{
    // Exercise1: имеются два указателя в памяти. Требуется вывести все адреса,
    // находящиеся между ними

    char chSomeChar     = 'z';
    char* pStartPointer = &chSomeChar;
    char* pEndPointer   = pStartPointer + 100;

    if (pStartPointer > pEndPointer)
        std::swap(pStartPointer, pEndPointer);

    while (++pStartPointer != pEndPointer)
    {
        std::cout << (unsigned long long) pStartPointer << std::endl;
    }
}

int main()
{
//    Exercise3();
//    Exercise2();
//    Exercise1();

    return 0;
}

