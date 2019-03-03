#include <whycpp/whycpp.h>
#include "arkanoid_ecs.h"

int main(int argc, char *argv[]) {
  RunApp<ArkanoidECS>(ApplicationConfig(256, 144, "Application", false));

  return 0;
}