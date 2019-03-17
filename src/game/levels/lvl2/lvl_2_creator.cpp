#include <game/levels/lvl_2_creator.h>

void Lvl2Creator::Init(){
  InitEntities();
  InitSystems();
}
void Lvl2Creator::Dispose(){
  engine->GetEntityManager()->RemoveEntities();
  engine->GetSystemManager()->RemoveSystems();
}
