//
// Created by riley on 2/13/21.
//

#ifndef WEBERRAYTRACING_VEC3_HPP
#define WEBERRAYTRACING_VEC3_HPP

// STL
#include <cmath>

// 3rd party
#include <fmt/core.h>

using std::sqrt;

namespace weberRaytracing::dataStructures {
  class vec3 {
    // this class was copied directly from Shirley's book:
    // https://raytracing.github.io/books/RayTracingInOneWeekend.html#thevec3class

  public:
    // constructors
    vec3() : e{0, 0, 0} {}

    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    // accessors
    double x() const { return e[0]; }

    double y() const { return e[1]; }

    double z() const { return e[2]; }

    double r() const { return e[0]; }

    double g() const { return e[1]; }

    double b() const { return e[2]; }

    double operator[](int i) const { return e[i]; }

    std::string toString() const {
      return fmt::format("{:f} {:f} {:f}", e[0], e[1], e[2]);
    }

    // direct access modifier
    double &operator[](int i) { return e[i]; }

    // simple math
    vec3 operator-() const { return {-e[0], -e[1], -e[2]}; }

    vec3 &operator+=(const vec3 &v) {
      e[0] += v.e[0];
      e[1] += v.e[1];
      e[2] += v.e[2];
      return *this;
    }

    vec3 &operator*=(const double t) {
      e[0] *= t;
      e[1] *= t;
      e[2] *= t;
      return *this;
    }

    vec3 &operator/=(const double t) {
      return *this *= 1 / t;
    }

    // basic linear algebra
    double length() const {
      return sqrt(length_squared());
    }

    double length_squared() const {
      return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

  public:
    // attributes: this is the actual content
    double e[3];
  };


  // type aliases: we will also use vec3 for colors and points
  using point3 = vec3;
  using color = vec3;


  // vec3 Utility Functions

  // output
  inline std::ostream &operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
  }

  // static math functions
  inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return {u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]};
  }

  inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return {u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]};
  }

  inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return {u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]};
  }

  inline vec3 operator*(double t, const vec3 &v) {
    return {t * v.e[0], t * v.e[1], t * v.e[2]};
  }

  inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
  }

  inline vec3 operator/(vec3 v, double t) {
    return (1 / t) * v;
  }

  // really only useful in testing
  inline bool operator==(const vec3 &lhs, const vec3 &rhs) {
    return lhs.e[0] == rhs.e[0] && lhs.e[1] == rhs.e[1] && lhs.e[2] == rhs.e[2];
  }

  inline bool operator!=(const vec3 &lhs, const vec3 &rhs) {
    return !(lhs == rhs);
  }

  // basic linear algebra
  inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
           + u.e[1] * v.e[1]
           + u.e[2] * v.e[2];
  }

  inline vec3 cross(const vec3 &u, const vec3 &v) {
    return {u.e[1] * v.e[2] - u.e[2] * v.e[1],
            u.e[2] * v.e[0] - u.e[0] * v.e[2],
            u.e[0] * v.e[1] - u.e[1] * v.e[0]};
  }

  inline vec3 unit_vector(vec3 v) {
    return v / v.length();
  }

  inline vec3 normalize(vec3 v) {
    return unit_vector(v);
  }
}


#endif //WEBERRAYTRACING_LINEARALGEBRA_VEC3_HPP
