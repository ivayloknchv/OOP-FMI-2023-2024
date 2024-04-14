#pragma once

bool isDigit(char ch);

bool isValidSymbol(char ch);

int truncStart(const char* str);

int truncEnd(const char* str);

void parseField(const char* source, char* destination);

char convertEntityReference(const char* str, int& jumpPositions);

