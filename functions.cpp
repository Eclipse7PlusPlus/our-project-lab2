#include <iostream>
#include <cstdint>
#include "header.h"

bool CheckSize(int32_t size) {
    return size > 0 && size <= MAX_SIZE;
}

int32_t MaxElementPosition(const int32_t* array, int32_t size) {
    int32_t maxPosition = 0;
    for (int32_t i = 1; i < size; ++i) {
        if (array[i] > array[maxPosition]) {
            maxPosition = i;
        }
    }
    return maxPosition + 1; 
}

int32_t MinElementPosition(int32_t* array, int32_t size) {
    int32_t minPosition = 0;
    for (int32_t i = 1; i < size; ++i) {
        if (array[i] < array[minPosition]) {
            minPosition = i;
        }
    }
    return minPosition + 1; 
}

int32_t isPrime(int32_t num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;

    for (int32_t i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

void PrimeNumbers(int32_t* array, int32_t size) {
    std::cout << "Prime numbers: ";
    for (int32_t i = 0; i < size; ++i) {
        if (isPrime(array[i])) {
            std::cout << array[i] << ' ';
        }
    }
    std::cout << '\n';
}

int32_t SumOfPrimes(int32_t* array, int32_t size) {
    int32_t sum = 0;
    for (int32_t i = 0; i < size; ++i) {
        if (isPrime(array[i])) {
            sum += array[i];
        }
    }
    return sum;
}

void ReverseArray(int32_t* array, int32_t size) {
    for (int32_t i = 0; i < size / 2; ++i) {
        int32_t temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

int32_t DeleteNegativeNumbersFromArray(int32_t* array, int32_t size) {
    int32_t newSize = 0;
    for (int32_t i = 0; i < size; ++i) {
        if (array[i] >= 0) {
            array[newSize++] = array[i];
        }
    }
    for (int32_t i = newSize; i < size; ++i) {
        array[i] = 0;
    }
    return newSize;
}
