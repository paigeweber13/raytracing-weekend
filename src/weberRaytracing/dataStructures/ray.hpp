//
// Created by riley on 2/22/21.
//

#ifndef WEBERRAYTRACING_RAY_HPP
#define WEBERRAYTRACING_RAY_HPP

#include "vec3.hpp"

namespace weberRaytracing::dataStructures {
  class ray {
  public:
    // constructors
    ray() {}

    ray(const point3 &origin, const vec3 &direction)
        : orig(origin), dir(direction) {}

    // accessors
    point3 origin() const { return orig; }

    vec3 direction() const { return dir; }

    // point distance 't' away from origin
    point3 at(double t) const {
      return orig + t * dir;
    }

  public:
    point3 orig;
    vec3 dir;
  };
}

#endif //WEBERRAYTRACING_RAY_HPP
