#include <game/components/audio_component.h>
#include <game/components/bonuses/resize_bonus_component.h>
#include <game/components/rect_collider_component.h>
#include <game/components/rectangle_render_component.h>
#include <game/systems/resize_bonus_system.h>
#include <lib/ecs/entity.h>
#include <iostream>

void ApplyBonus(Entity* entity, Entity* bonus) {
  auto bc = bonus->Get<ResizeBonusComponent>();
  auto render = entity->Get<RectangleRenderComponent>();
  auto box = entity->Get<RectColliderComponent>();
  // todo: save bonus to the vector

  box->size.x *= bc->power;
  render->size.x *= bc->power;

  bonus->Get<AudioComponent>()->Play();
}

bool ResizeBonusSystem::Filter(Entity* entity) const {
  return entity->Contains<ResizeBonusComponent>() && entity->Contains<RectColliderComponent>();
}
void ResizeBonusSystem::Update(Context& ctx, Entity* entity) {
  auto bc = entity->Get<ResizeBonusComponent>();
  auto rc = entity->Get<RectColliderComponent>();

  for (auto& collision : rc->GetCollisions()) {
    if (collision.entity->GetTag() != "platform") continue;
    rc->is_sleeping = true;  // TODO: it'd be better to remove this object immediately

    ApplyBonus(collision.entity, entity);
  }
}
