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

int MyFile::size_B(){
  this->seekg(0,std::ios::end);
  auto size = this->tellg();
  this->seekg(0,std::ios::beg);
  return size;
}

void MyFile::fill_f(const char* str, size_t bytes)
{
  *this << std::endl;
  this->seekp(0, std::ios::end);
  this->write(str, bytes);    
}

void MyFile::fill_f(std::string &str)
{
  *this << std::endl;
  this->seekp(0, std::ios::end);
  this->write(str.c_str(), str.size());
}

void MyFile::read_f(char *out, int size)
{
  this->read(out, size);
}

void MyFile::read_f(std::string &out)
{
  char *tmp = new char[size_B()];
  out.resize(size_B());
  this->read(tmp, size_B());
  out.assign(tmp);
}

void MyFile::end_put(const char* c, int size)
{
  seekp(0, std::ios::end);
  write(c, size);
}