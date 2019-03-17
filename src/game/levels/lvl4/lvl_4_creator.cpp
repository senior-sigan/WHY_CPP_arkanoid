#include <game/levels/lvl_4_creator.h>

void Lvl4Creator::Init(){
  InitEntities();
  InitSystems();
}
void Lvl4Creator::Dispose(){
  engine->GetEntityManager()->RemoveEntities();
  engine->GetSystemManager()->RemoveSystems();
}
