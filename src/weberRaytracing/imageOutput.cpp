//
// Created by riley on 2/12/21.
//

#include "imageOutput.hpp"

typedef weberRaytracing::dataStructures::Image Img;

//namespace wrtx = weberRaytracing;
namespace wds = weberRaytracing::dataStructures;
namespace imgOut = weberRaytracing::imageOutput;

std::string imgOut::colorToString(wds::color pixelColor) {
  // Write the translated [0,255] value of each color component.
  return fmt::format("{:d} {:d} {:d}\n",
                     static_cast<int>(255.999 * pixelColor.r()),
                     static_cast<int>(255.999 * pixelColor.g()),
                     static_cast<int>(255.999 * pixelColor.b()));
}

// Writing to format
std::string imgOut::outputToPPM(Img imageToOutput) {
  auto PPMString = fmt::format("{}\n", imgOut::PPM_FORMAT);
  PPMString += fmt::format("{:d} {:d}\n", imageToOutput.begin()->size(),
                           imageToOutput.size());
  PPMString += fmt::format("{:d}\n", imgOut::MAX_PIXEL_VALUE);

  for (size_t row_i = 0; row_i < imageToOutput.size(); row_i++) {
    fmt::print(stderr, "\rScanlines remaining: {:d}", imageToOutput.size() -
                                                      row_i);
    std::cerr.flush();
    for (auto const &pixel : imageToOutput[row_i]) {
      // only output one pixel per line. This is an easy way to stay within
      // the PPM standard's limit of 70 characters per line.
      PPMString += colorToString(pixel);
    }
  }

  fmt::print(stderr, "\nDone.\n");

  return PPMString;
}
