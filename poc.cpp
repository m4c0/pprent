#pragma leco tool

// TODO: remove this when minirent use "secure" strncpy
#define _CRT_SECURE_NO_WARNINGS
#define PPRENT_IMPLEMENTATION
#include "pprent.hpp"

#include <stdio.h>

int main() {
  for (auto entry : pprent::list(".")) {
    puts(entry);
  }
}

