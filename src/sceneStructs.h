#pragma once

#include <string>
#include <vector>
#include "glm/glm.hpp"

enum GeomType {
  SPHERE,
  CUBE,
};

struct Geom {
  enum GeomType type;
  int materialid;
  glm::vec3 translation;
  glm::vec3 rotation;
  glm::vec3 scale;
  glm::mat4 transform;
  glm::mat4 inverseTransform;
  glm::mat4 invTranspose;
};

struct Ray {
  glm::vec3 origin;
  glm::vec3 direction;
};

struct Camera {
  glm::ivec2 resolution;
  glm::vec3 position;
  glm::vec3 view;
  glm::vec3 up;
  glm::vec2 fov;
};

struct Material {
  glm::vec3 color;
  struct {
    float exponent;
    glm::vec3 color;
  } specular;
  float hasReflective;
  float hasRefractive;
  float indexOfRefraction;
  float emittance;
};

struct RenderState {
  Camera camera;
  unsigned int iterations;
  int traceDepth;
  std::vector<glm::vec3> image;
  std::string imageName;
};