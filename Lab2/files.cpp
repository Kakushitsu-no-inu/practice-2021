#include "file.h"
#include <iostream>

int main() {
  // MyFile file1{"1.txt"};
  // MyFile file2{"2.txt"};

  // if ((!file1) || !file2) {
  //   std::cerr << "Не можливо відкрити файл" << std::endl;
  //   return EXIT_FAILURE;
  // }

  // auto pos = file1.compare(file2);

  // std::string str;
  // file1.read_f(str);
  // std::cout << str << std::endl;

  // file1.close();
  // file2.close();

  // if (pos == MyFile::npos) {
  //   std::cout << "Файли однакові" << std::endl;
  // } else {
  //   std::cout << "Відмінність у рядку - " << pos.line << ", позиції - " << pos.c
  //             << std::endl;
  // }

  std::cout << "\nБінарні файли\n";
  MyFile file3("3.dat");
  char c[] = "abcdefg";
  char c1[] = "hijklmn";
  // file3.fill_f(c, 8);
  std::string tmp;
  file3.read_f(tmp);
  std::cout << tmp << std::endl;
  file3.end_put(c1, 8);
  file3.close();
  return 0;
}