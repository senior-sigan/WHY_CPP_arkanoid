#pragma once

#include <lib/matlib/vec2.h>

class EntityManager;

void CreateBonus(EntityManager *entityManager, const Vec2 &pos, double power);
void CreateBrick(EntityManager *entityManager, const Vec2 &pos, const Vec2 &size);
void CreateBorder(EntityManager *entityManager, const Vec2 &size, const Vec2 &pos);
void CreatePlatform(EntityManager *entityManager, const Vec2 &platform_pos, const Vec2 &platform_size);
void CreateBall(EntityManager *entityManager, const Vec2 &platform_pos, const Vec2 &platform_size);