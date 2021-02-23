//
// Created by riley on 2/12/21.
//

#ifndef WEBERRAYTRACING_IMAGE_HPP
#define WEBERRAYTRACING_IMAGE_HPP


// stl
#include <iostream>
#include <string>
#include <vector>

// first party
#include "dataStructures/vec3.hpp"

// third party
#include <fmt/core.h>

namespace weberRaytracing {
  namespace dataStructures {
    typedef std::vector<std::vector<color>> Image;
  }

  namespace imageOutput {
    std::string colorToString(dataStructures::color pixelColor);

    std::string outputToPPM(dataStructures::Image);

  };
}


#endif //WEBERRAYTRACING_IMAGE_HPP
