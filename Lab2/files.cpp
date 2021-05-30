#include "file.h"
#include <iostream>

int main() {
  MyFile file1{"1.txt"};
  MyFile file2{"2.txt"};

  if ((!file1) || !file2) {
    std::cerr << "Не можливо відкрити файл" << std::endl;
    return EXIT_FAILURE;
  }

  auto pos = file1.compare(file2);

  file1.close();
  file2.close();

  if (pos == MyFile::npos) {
    std::cout << "Файли однакові" << std::endl;
  } else {
    std::cout << "Відмінність у рядку - " << pos.line << ", позиції - " << pos.c
              << std::endl;
  }

  return 0;
}