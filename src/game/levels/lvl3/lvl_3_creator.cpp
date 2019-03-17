#include <game/levels/lvl_3_creator.h>

void Lvl3Creator::Init(){
  InitEntities();
  InitSystems();
}
void Lvl3Creator::Dispose(){
  engine->GetEntityManager()->RemoveEntities();
  engine->GetSystemManager()->RemoveSystems();
}
