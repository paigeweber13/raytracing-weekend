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
    const std::string PPM_FORMAT = "P3";
    const unsigned PPM_MAX_PIXEL_VALUE = 255;
    const double PIXEL_CONVERSION_VALUE = 255.999;

    std::string colorToString(dataStructures::color pixelColor);

    std::string outputToPPM(dataStructures::Image);

  };
}


#endif //WEBERRAYTRACING_IMAGE_HPP
