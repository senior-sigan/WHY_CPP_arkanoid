#include <whycpp/whycpp.h>
#include <game/arkanoid_ecs.h>

int main(int argc, char *argv[]) {
  RunApp<ArkanoidECS>(ApplicationConfig(224, 256, "Application", false));
  return 0;
}