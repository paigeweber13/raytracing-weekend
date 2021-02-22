
#include "imageOutput.hpp"

namespace wds = weberRaytracing::dataStructures;
namespace wio = weberRaytracing::imageOutput;

wds::Image createTestImage() {
  const int image_width = 256;
  const int image_height = 256;
  const double b = 0.25;

  wds::Image testImage(image_height, std::vector<wds::color>(image_width));

//  for (int j = image_height - 1; j >= 0; j--) {
  for (int j = 0; j < image_height; j++) {
    for (int i = 0; i < image_width; i++) {
      // as width increases (left to right), so does red
      auto r = double(i) / (image_width - 1);

      // as height increases (top to bottom), so does green
      auto g = double(j) / (image_height - 1);

      testImage[j][i] = wds::color{r, g, b};
    }
  }

  return testImage;
}

int main(int argc, char **argv) {
  fmt::print("{}", wio::outputToPPM(createTestImage()));

  return 0;
}
