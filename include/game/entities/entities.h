#pragma once

#include <lib/matlib/vec2.h>

class EntityManager;

void CreateBrick(EntityManager *entity_manager, const Vec2 &pos, const Vec2 &size);
void CreateBorder(EntityManager *entity_manager, const Vec2 &size, const Vec2 &pos);
void CreatePlatform(EntityManager *entity_manager, const Vec2 &platform_pos, const Vec2 &platform_size);
void CreateBall(EntityManager *entity_manager, const Vec2 &platform_pos, const Vec2 &platform_size);