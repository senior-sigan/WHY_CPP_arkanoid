#include <game/arkanoid_ecs.h>
#include <whycpp/whycpp.h>

int main(int argc, char *argv[]) {
  RunApp<ArkanoidECS>(ApplicationConfig(224, 256, "Application", false, 2, 16, true));
  return 0;
}