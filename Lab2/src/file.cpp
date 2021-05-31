#include "file.h"

const MyFile::Position MyFile::npos = {SIZE_MAX, SIZE_MAX};

bool operator==(const MyFile::Position &rhs, const MyFile::Position &lhs) {
  return (rhs.c == lhs.c) && (lhs.line == rhs.line);
}

bool operator!=(const MyFile::Position &rhs, const MyFile::Position &lhs) {
  return !(rhs == lhs);
}

MyFile::Position MyFile::compare(MyFile &other) {
  Position diff{};
  char ch1{}, ch2{};

  while (!this->eof()) {
    this->get(ch1);
    other.get(ch2);
    diff.c += 1;

    if (ch1 != ch2)
      return diff;

    if (ch1 == '\n') {
      diff.line += 1;
      diff.c = 0;
    }
  }

  return npos;
}

MyFile::MyFile(const std::string &s, std::ios_base::openmode mode)
    : std::fstream(s, mode) {}