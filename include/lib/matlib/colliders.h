#pragma once

class AABB;
class Manifold;

bool IsIntersecting(const AABB &a, const AABB &b);

Manifold Intersection(const AABB &a, const AABB &b);