#version 400

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

varying vec3 normal0;
varying float z0;

uniform mat4 transform;
uniform mat4 shadow_mat;
uniform vec4 light;
uniform vec4 color;

out vec3 normal2;
out vec3 eye2;
out vec3 lightDir2;
out vec4 color2;

void main () {

  vec4 pos = shadow_mat * vec4(position, 1.0);
  normal2 = vec3(normalize(shadow_mat * vec4(normal, 0.0)));
  normal2 = normal;
  lightDir2 = vec3(light - pos);
  eye2 = vec3(pos);
  color2 = color;

  gl_Position = transform * vec4(position, 1.0);
}