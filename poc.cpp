#pragma leco tool

#include <stdio.h>

import pprent;

int main() {
  for (auto entry : pprent::list(".")) {
    puts(entry);
  }
}

