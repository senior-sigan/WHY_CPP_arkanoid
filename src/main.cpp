#include <whycpp/whycpp.h>
#include "arkanoid.h"

int main(int argc, char *argv[]) {
  RunApp<Arkanoid>({256, 144, "Arkanoid", false});

  return 0;
}