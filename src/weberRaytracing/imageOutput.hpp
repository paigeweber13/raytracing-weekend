//
// Created by riley on 2/12/21.
//

#ifndef WEBERRAYTRACING_IMAGEOUTPUT_HPP
#define WEBERRAYTRACING_IMAGEOUTPUT_HPP


// stl
#include <iostream>
#include <string>
#include <vector>

// first party
#include "linearAlgebra/vec3.hpp"

// third party
#include <fmt/core.h>

namespace weberRaytracing {
  namespace dataStructures {
    typedef weberRaytracing::linearAlgebra::color color;
    typedef std::vector<std::vector<color>> Image;
  }

  namespace imageOutput {
    const std::string PPM_FORMAT = "P3";
    const unsigned MAX_PIXEL_VALUE = 255;

    std::string colorToString(dataStructures::color pixelColor);

    std::string outputToPPM(dataStructures::Image);

  };
}


#endif //WEBERRAYTRACING_IMAGEOUTPUT_HPP
