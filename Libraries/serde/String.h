#pragma once

#include <stddef.h>

class String {
 public:
  String();
  String(const char* c_str);
  String(String& other);
  String(const String& other);

  ~String();

  constexpr size_t size() const;

 private:
  const char* m_data_ptr{nullptr};
};
