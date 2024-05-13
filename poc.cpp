#pragma leco tool

#define PPRENT_IMPLEMENTATION
#include "pprent.hpp"

#include <stdio.h>

int main() {
  for (auto entry : pprent::list(".")) {
    puts(entry);
  }
}

