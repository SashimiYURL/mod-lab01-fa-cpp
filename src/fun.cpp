// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            if (inWord && !hasDigit) {
                ++count;
            }
            inWord = false;
            hasDigit = false;
        } else {
            inWord = true;
            if (std::isdigit(str[i])) {
                hasDigit = true;
            }
        }
    }
    if (inWord && !hasDigit) {
        ++count;
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool startsWithUpper = false;
    bool onlyLowercase = true;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            if (inWord && startsWithUpper && onlyLowercase) {
                ++count;
            }
            inWord = false;
            startsWithUpper = false;
            onlyLowercase = true;
        } else {
            if (!inWord) {
                startsWithUpper = std::isupper(str[i]);
                inWord = true;
            } else {
                if (!std::islower(str[i])) {
                    onlyLowercase = false;
                }
            }
        }
    }
    if (inWord && startsWithUpper && onlyLowercase) {
        ++count;
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    unsigned int currentLength = 0;

    for (size_t i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ' ') {
            if (currentLength > 0) {
                totalLength += currentLength;
                wordCount++;
                currentLength = 0;
            }
        } else {
            currentLength++;
        }
    }
    if (currentLength > 0) {
        totalLength += currentLength;
        wordCount++;
    }

    if (wordCount == 0) return 0;

    double averageLength = static_cast<double>(totalLength) / wordCount;
    return static_cast<unsigned int>(std::round(averageLength));
}
