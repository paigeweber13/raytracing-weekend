//
// Created by riley on 2/12/21.
//

#ifndef WEBERRAYTRACING_IMAGEOUTPUT_HPP
#define WEBERRAYTRACING_IMAGEOUTPUT_HPP


// stl
#include <string>
#include <vector>

// third party
#include <fmt/core.h>

namespace weberRaytracing {
  namespace dataStructures {
    struct RGBColor {
      double r;
      double g;
      double b;
    };
    typedef std::vector<std::vector<RGBColor>> Image;
  }

  namespace imageOutput {
    const std::string PPM_FORMAT = "P3";
    const unsigned MAX_PIXEL_VALUE = 255;

    std::string outputToPPM(dataStructures::Image);

  };
}


#endif //WEBERRAYTRACING_IMAGEOUTPUT_HPP
