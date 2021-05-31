#pragma once
#include <fstream>
#include <ios>

class MyFile : public std::fstream {
public:
  struct Position {
    size_t line{1};
    size_t c{0};
  };

  static const Position npos;

  MyFile() = default;

  explicit MyFile(const std::string &s,
                  std::ios_base::openmode mode = std::ios_base::in |
                                                 std::ios_base::out);

  ~MyFile() = default;

  Position compare(MyFile &other);
};

bool operator==(const MyFile::Position &rhs, const MyFile::Position &lhs);
bool operator!=(const MyFile::Position &rhs, const MyFile::Position &lhs);