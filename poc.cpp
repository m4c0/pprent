#pragma leco tool

#include <stdio.h>

import pprent;

int main() {
  for (auto entry : pprent::list(".")) {
    puts(entry);
  }
  // TODO: how to deal with non-existent dirs?
  for (auto entry : pprent::list("rxxxaxx")) {
    puts(entry);
  }
}

