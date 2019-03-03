#include <whycpp/whycpp.h>
#include "arkanoid.h"

int main(int argc, char *argv[]) {
  RunApp<Arkanoid>(ApplicationConfig(256, 144, "Application", false));

  return 0;
}