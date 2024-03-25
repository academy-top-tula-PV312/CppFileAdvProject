// CppFileAdvProject.cpp 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

char* IntToString(int number);
void FileCreate(const char* fileName);
void FileWork(const char* fileName);

int main()
{
    char fileName[] = "file01.dat";
    //FileCreate(fileName);
    FileWork(fileName);
    //std::cout << IntToString(1);
}

char* IntToString(int number)
{
    int count{ 2 };
    char* dest = new char[count];
    dest[0] = '0' + number % 10;
    dest[1] = '\0';
    number /= 10;

    int mod;
    char* temp;
    while (number)
    {
        mod = number % 10;

        temp = new char[++count];
        for (int i{}; i < count; i++)
            temp[i + 1] = dest[i];
        temp[0] = mod + '0';

        delete[] dest;
        dest = temp;

        number /= 10;
    }

    return dest;
}

void FileCreate(const char* fileName)
{
    FILE* file = fopen(fileName, "w");
    
    int width;
    int height;

    std::cout << "Input width: ";
    std::cin >> width;
    std::cout << "Input height: ";
    std::cin >> height;

    fputs(IntToString(width), file);
    fputc(' ', file);
    fputs(IntToString(height), file);

    fclose(file);
}

void FileWork(const char* fileName)
{
    FILE* file = fopen(fileName, "r");

    int size{ 1024 };
    char* buffer = new char[size];

    fgets(buffer, size, file);

    fclose(file);

    int widthLen = strchr(buffer, ' ') - buffer;
    char* widthStr = new char[widthLen + 1];
    strncpy(widthStr, buffer, widthLen);
    widthStr[widthLen] = '\0';

    int width = atoi(widthStr);
    
    char* heightStr = new char[strlen(buffer) - widthLen];
    strcpy(heightStr, buffer + widthLen + 1);

    int height = atoi(heightStr);

    int square = width * height;

    file = fopen(fileName, "a");
    fputc('\n', file);
    fputs(IntToString(square), file);
    fclose(file);
}
