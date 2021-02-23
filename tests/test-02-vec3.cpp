//
// Created by riley on 2/13/21.
//

#include <catch2/catch.hpp>
#include <sstream>

#include "dataStructures/vec3.hpp"

using weberRaytracing::dataStructures::vec3;
using weberRaytracing::dataStructures::point3;
using weberRaytracing::dataStructures::color;

TEST_CASE("01: test constructors and aliases") {
  vec3 v_trivial;
  vec3 v(1, -3.14, 1.14);

  SECTION("default constructor produces 0 vector") {
    REQUIRE(v_trivial.e[0] == 0);
    REQUIRE(v_trivial.e[1] == 0);
    REQUIRE(v_trivial.e[2] == 0);
  }

  SECTION("value constructor produces expected vector") {
    REQUIRE(v.e[0] == 1);
    REQUIRE(v.e[1] == -3.14);
    REQUIRE(v.e[2] == 1.14);
  }

  SECTION("point constructors produce vectors identical to vec3 constructors") {
    REQUIRE(v_trivial == point3());
    REQUIRE(v == point3(1, -3.14, 1.14));
  }

  SECTION("color constructors produce vectors identical to vec3 constructors") {
    REQUIRE(v_trivial == color());
    REQUIRE(v == color(1, -3.14, 1.14));
  }
}

TEST_CASE("02: test accessors") {
  vec3 v(2, -76.3, 0.02);

  SECTION("xyz accessors match actual value") {
    REQUIRE(v.x() == v.e[0]);
    REQUIRE(v.y() == v.e[1]);
    REQUIRE(v.z() == v.e[2]);
  }

  SECTION("rgb accessors match actual value") {
    REQUIRE(v.r() == v.e[0]);
    REQUIRE(v.g() == v.e[1]);
    REQUIRE(v.b() == v.e[2]);
  }

  SECTION("[] accessors match actual value") {
    REQUIRE(v[0] == v.e[0]);
    REQUIRE(v[1] == v.e[1]);
    REQUIRE(v[2] == v.e[2]);
  }

  SECTION("direct access modifiers do, in fact, change value") {
    v[0] = 100.1;
    v[1] = -50.5;
    v[2] = 77.7;

    REQUIRE(v.e[0] == 100.1);
    REQUIRE(v.e[1] == -50.5);
    REQUIRE(v.e[2] == 77.7);
  }

  SECTION("toString produces expected string") {
    std::string expected = "2.000000 -76.300000 0.020000";

    REQUIRE(v.toString() == expected);
  }

  SECTION("iostream operator produces expected string") {
    std::string expected = "2 -76.3 0.02";

    std::stringstream ss;
    ss << v;
    REQUIRE(ss.str() == expected);
  }

}

TEST_CASE("03: member math functions work as expected") {
  vec3 v(2, -5, 4);
  vec3 v2(2, -5, 4);
  vec3 u(2, 1, -2);

  SECTION("comparison works") {
    REQUIRE(v == v2);
    REQUIRE(v != vec3());
  }

  SECTION("operator- (negation) works") {
    REQUIRE(-v == vec3(-2, 5, -4));
  }

  SECTION("operator+= works") {
    v += u;
    REQUIRE(v == vec3(4, -4, 2));
  }

  SECTION("operator*= (scalar multiplication) works") {
    v *= 3.0;
    REQUIRE(v == vec3(6, -15, 12));
  }

  SECTION("operator/= (scalar division) works") {
    v /= 2.0;
    REQUIRE(v == vec3(1, -2.5, 2));
  }
}

TEST_CASE("04: static math functions work as expected") {
  vec3 v(2, -5, 4);
  vec3 u(2, 1, -2);

  SECTION("operator+ (adding vectors) works") {
    REQUIRE(v + u == vec3(4, -4, 2));
  }

  SECTION("operator- (subtracting vectors) works") {
    REQUIRE(v - u == vec3(0, -6, 6));
  }

  SECTION("operator* (scalar multiplication) works") {
    REQUIRE(v * 1.5 == vec3(3, -7.5, 6));
    REQUIRE(1.5 * v == v * 1.5);
  }

  SECTION("operator* (multiplying vectors) works") {
    REQUIRE(v * u == vec3(4, -5, -8));
  }

  SECTION("operator/ (scalar division) works") {
    REQUIRE(v / 2 == vec3(1, -2.5, 2));
  }
}

TEST_CASE("05: basic linear algebra (member functions) work") {
  vec3 v(3, 4, 5);

  REQUIRE(v.length_squared() == 50);
  REQUIRE(v.length() == sqrt(50));
}

TEST_CASE("05: basic linear algebra (static functions) work") {
  vec3 v(2, 4, 1);
  vec3 u(2, 3, 4);
  const double SQRT_21 = sqrt(21);

  REQUIRE(dot(v, u) == 20);
  REQUIRE(unit_vector(v) == vec3(2 / SQRT_21, 4 / SQRT_21, 1 / SQRT_21));
  REQUIRE(normalize(v) == unit_vector(v));
}
