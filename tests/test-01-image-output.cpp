#include <catch2/catch.hpp>

#include "imageOutput.hpp"

TEST_CASE("01: get simple PPM output", "[weberRaytracing::imageOutput]") {
  // taken from the PPM example on this wikipedia page:
  // https://en.wikipedia.org/wiki/Netpbm#File_formats

  weberRaytracing::imageOutput::image testImage = {
      {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0},},
      {{1.0, 1.0, 0.0}, {1.0, 1.0, 1.0}, {0.0, 0.0, 0.0},},
  };

  auto expectedPPMString = "P3\n"
                           "3 2 1\n"
                           "1 0 0 0 1 0 0 0 1 1 1 0 1 1 1 0 0 0";

  REQUIRE(weberRaytracing::imageOutput::outputToPPM(testImage) ==
          expectedPPMString);
}
