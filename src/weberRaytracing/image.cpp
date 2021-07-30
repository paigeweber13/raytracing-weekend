//
// Created by riley on 2/12/21.
//

#include "image.hpp"

typedef weberRaytracing::dataStructures::Image Img;

//namespace wrtx = weberRaytracing;
namespace wds = weberRaytracing::dataStructures;
namespace imgOut = weberRaytracing::imageOutput;

std::string imgOut::colorToString(wds::color pixelColor) {
  const double PIXEL_CONVERSION_VALUE = 255.999;

  // Write the translated [0,255] value of each color component.
  return fmt::format("{:d} {:d} {:d}\n",
                     static_cast<int>(PIXEL_CONVERSION_VALUE * pixelColor.r()),
                     static_cast<int>(PIXEL_CONVERSION_VALUE * pixelColor.g()),
                     static_cast<int>(PIXEL_CONVERSION_VALUE * pixelColor.b()));
}

// Writing to format
std::string imgOut::outputToPPM(Img imageToOutput) {
  const std::string PPM_FORMAT = "P3";
  const unsigned PPM_MAX_PIXEL_VALUE = 255;

  auto PPMString = fmt::format("{}\n", PPM_FORMAT);
  PPMString += fmt::format("{:d} {:d}\n", imageToOutput.begin()->size(),
                           imageToOutput.size());
  PPMString += fmt::format("{:d}\n", PPM_MAX_PIXEL_VALUE);

  for (int row_i = imageToOutput.size() - 1; row_i >= 0; row_i--) {

    if (row_i % 100 == 0) {
      fmt::print(stderr, "\rScan lines remaining: {:d}",
                 imageToOutput.size() - row_i);
      std::cerr.flush();
    }

    for (auto const &pixel : imageToOutput[row_i]) {
      // only output one pixel per line. This is an easy way to stay within
      // the PPM standard's limit of 70 characters per line.
      PPMString += colorToString(pixel);
    }
  }

  fmt::print(stderr, "\nDone.\n");

  return PPMString;
}
