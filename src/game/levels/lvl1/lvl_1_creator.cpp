#include <game/levels/lvl_1_creator.h>
#include <iostream>

void Lvl1Creator::Init(){
  InitEntities();
  InitSystems();
}
void Lvl1Creator::Dispose(){
  std::cout << "Disposing LVL2" << std::endl;
  engine->GetEntityManager()->RemoveEntities();
  engine->GetSystemManager()->RemoveSystems();
}
