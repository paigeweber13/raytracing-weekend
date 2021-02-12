//
// Created by riley on 2/12/21.
//

#ifndef HELLOFULLBUILDSYSTEM_IMAGEOUTPUT_HPP
#define HELLOFULLBUILDSYSTEM_IMAGEOUTPUT_HPP


#include <vector>

namespace weberRaytracing {
  class imageOutput {
  public:
    struct rgbColor {
      double r;
      double g;
      double b;
    };
    typedef std::vector<std::vector<rgbColor>> image;

  };
}


#endif //HELLOFULLBUILDSYSTEM_IMAGEOUTPUT_HPP
