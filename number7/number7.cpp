#include <iostream>
#include <chrono>
#include <windows.h>

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::tm t1 = { 0, 0, 0, 12, 3, 116 };
    std::tm t2 = { 0, 0, 0, 21, 2, 2016 }; 

    std::time_t time1 = std::mktime(&t1);
    std::time_t time2 = std::mktime(&t2);

    if (time1 != -1 && time2 != -1)
    {
        double difference = std::difftime(time1, time2) / (60 * 60 * 24);
        std::cout << "Разность в днях: " << difference ;
    }
    else
    {
        std::cout << "Ошибка в вычислении разности дат" ;
    }

    return 0;
}



#include <iostream>
#include <windows.h>

double average(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++) 
    {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int array[] = { 5, 10, 15, 20, 25 };
    int size = sizeof(array) / sizeof(array[0]);

    double avg = average(array, size);
    std::cout << "Среднее арифметическое элементов массива: " << avg;

    return 0;
}



#include <iostream>
#include <windows.h>

void countPosNegZero(int arr[], int size)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int positive = 0, negative = 0, zero = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            positive++;
        }
        else if (arr[i] < 0) 
        {
            negative++;
        }
        else
        {
            zero++;
        }
    }

    std::cout << "Положительные числа: " << positive ;
    std::cout << "Отрицательные числа: " << negative ;
    std::cout << "Нулевые числа: " << zero;
}




#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>


void initializeMatrix(std::vector<std::vector<int>>& matrix, int size)
{
    matrix.resize(size, std::vector<int>(size, 0));
}


void initializeMatrix(std::vector<std::vector<double>>& matrix, int size) 
{
    matrix.resize(size, std::vector<double>(size, 0.0));
}


void initializeMatrix(std::vector<std::vector<char>>& matrix, int size)
{
    matrix.resize(size, std::vector<char>(size, '0'));
}


void printMatrix(const std::vector<std::vector<int>>& matrix)
{
    for (const auto& row : matrix) 
    {
        for (int value : row)
        {
            std::cout << value << "  ";
        }
    }
}


void printMatrix(const std::vector<std::vector<double>>& matrix)
{
    for (const auto& row : matrix) 
    {
        for (double value : row) 
        {
            std::cout << value << "  ";
        }
    }
}


void printMatrix(const std::vector<std::vector<char>>& matrix) 
{
    for (const auto& row : matrix)
    {
        for (char value : row)
        {
            std::cout << value << "  ";
        }
    }
}

template <typename T>
void findMinMaxDiagonal(const std::vector<std::vector<T>>& matrix, T& minVal, T& maxVal)
{
    minVal = matrix[0][0];
    maxVal = matrix[0][0];
    for (size_t i = 0; i < matrix.size(); i++) 
    {
        if (matrix[i][i] < minVal)
        {
            minVal = matrix[i][i];
        }
        if (matrix[i][i] > maxVal)
        {
            maxVal = matrix[i][i];
        }
    }
}

template <typename T>
void sortRows(std::vector<std::vector<T>>& matrix) 
{
    for (auto& row : matrix) 
    {
        std::sort(row.begin(), row.end());
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<std::vector<int>> intMatrix;
    initializeMatrix(intMatrix, 3);
    intMatrix[0][0] = 1;
    intMatrix[1][1] = 2;
    intMatrix[2][2] = 3;

    std::cout << "Исходная матрица:";
    printMatrix(intMatrix);

    int minVal, maxVal;
    findMinMaxDiagonal(intMatrix, minVal, maxVal);
    std::cout << "Минимальный элемент на главной диагонали: " << minVal;
    std::cout << "Максимальный элемент на главной диагонали: " << maxVal;

    sortRows(intMatrix);
    std::cout << "Матрица после сортировки элементов по возрастанию для каждой строки:" ;
    printMatrix(intMatrix);

    return 0;
}



#include <iostream>
#include <windows.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b;
    std::cout << "Введите два целых числа: ";
    std::cin >> a >> b;
    int result = gcd(a, b);
    std::cout << "Наибольший общий делитель: " << result;
    return 0;
}




#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

int generateSecretNumber() 
{
    srand(time(0));
    int num;
    do 
    {
        num = rand() % 10000;
    } while (num < 1000);
    return num;
}

void checkGuess(int secret, int guess, int& bulls, int& cows) 
{
    if (secret == 0 && guess == 0) 
    {
        return;
    }
    checkGuess(secret / 10, guess / 10, bulls, cows);
    if (secret % 10 == guess % 10)
    {
        cows++;
    }
    else
    {
        bulls++;
    }
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int secretNumber = generateSecretNumber();
    int attempts = 0;
    int guess;
    do 
    {
        std::cout << "Введите ваше предположение: ";
        std::cin >> guess;
        int bulls = 0, cows = 0;
        checkGuess(secretNumber, guess, bulls, cows);
        std::cout << "Быки: " << bulls << ", Коровы: " << cows;
        attempts++;
    } while (guess != secretNumber);
    std::cout << "Поздравляю! Вы угадали число за " << attempts << " попыток.";
    return 0;
}

