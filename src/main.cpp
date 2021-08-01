
#include "image.hpp"
#include "dataStructures/ray.hpp"

namespace wds = weberRaytracing::dataStructures;
namespace wio = weberRaytracing::imageOutput;

bool hit_sphere(const wds::point3 &center, double radius, const wds::ray &r) {
  // this function contains the hard-coded math to solve the polynomial
  // equation that tells us if a ray intercepts a sphere
  wds::vec3 oc = r.origin() - center;
  auto a = wds::dot(r.direction(), r.direction());
  auto b = 2.0 * dot(oc, r.direction());
  auto c = dot(oc, oc) - radius*radius;
  auto discriminant = b*b - 4*a*c;
  return (discriminant > 0);
}

wds::color ray_color(const wds::ray &r) {
  // place a sphere at -1 on the z axis, color the image red if ray
  // intercects it
  if (hit_sphere(wds::point3(0, 0, -1), 0.5, r))
    return wds::color(1, 0, 0);

  // all this does is show a background, which is a simple gradient
  wds::vec3 unit_direction = unit_vector(r.direction());
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * wds::color(1.0, 1.0, 1.0)
         + t * wds::color(0.5, 0.7, 1.0);
}

wds::Image createTestImage() {

  // Image

  const auto aspect_ratio = 16.0 / 9.0;
  const int image_width = 400;
  const int image_height = static_cast<int>(image_width / aspect_ratio);

  // each row is a vector of pixels, which we represent with color vectors
  wds::Image testImage(image_height, std::vector<wds::color>(image_width));


  // Camera

  auto viewport_height = 2.0; // standard -1.0 to 1.0
  auto viewport_width = aspect_ratio * viewport_height;
  // distance from camera to projection plane. This is the same meaning as in
  // photography, if we consider the external lens glass to be the projection
  // plane.
  auto focal_length = 1.0;

  auto origin = wds::point3(0.0, 0.0, 0.0);
  auto horizontal = wds::vec3(viewport_width, 0.0, 0.0);
  auto vertical = wds::vec3(0.0, viewport_height, 0.0);
  auto lower_left_corner = origin - horizontal / 2 - vertical / 2
                           - wds::vec3(0.0, 0.0, focal_length);


  // render

  for (int j = image_height - 1; j >= 0; j--) {
    for (int i = 0; i < image_width; i++) {
      auto u = double(i) / (image_width - 1);
      auto v = double(j) / (image_height - 1);
      wds::ray r(origin, lower_left_corner + u * horizontal + v * vertical
                         - origin);
      wds::color pixel_color = ray_color(r);

      testImage[j][i] = pixel_color;
    }
  }

  return testImage;
}

int main() {
  fmt::print("{}", wio::outputToPPM(createTestImage()));

  return 0;
}
