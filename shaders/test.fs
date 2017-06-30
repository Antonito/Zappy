#version 400

uniform sampler2D diffuse;

out vec4 colorOut;

in  vec3 normal2;
in  vec3 eye2;
in  vec3 lightDir2;
in  vec4 color2;

void main() {
  float minimum = 0.2;
  float _diff = 1.0;
  float _ambiant = 0.1;
  float _spec = 0.75;
  float shininess = 0.8;

  vec4 diff = vec4(_diff, _diff, _diff, 1.0);
  vec4 ambient = vec4(_ambiant, _ambiant, _ambiant, 1.0);
  vec4 specular = vec4(_spec, _spec, _spec, 1.0);

  vec4 spec = vec4(0.0, 0.0, 0.0, 0.0);

  //vec3 lightDir = normalize(vec3(1, 1, 1));

  vec3 n = normalize(normal2);
  vec3 l = normalize(lightDir2);
  vec3 e = normalize(eye2);

  float intensity = max(dot(n,l), 0.0);
  if (intensity > 0.0) {
    vec3 h = normalize(l + e);
    float intSpec = max(dot(h,n), 0.0) / 5;
    spec = specular * pow(intSpec, shininess);
  }

  colorOut = color2 * max(intensity * diff + spec, ambient);

  //intensity = dot(normal2, lightDir);

  //colorOut = color2 * max(intensity, minimum);
  if (colorOut.a == 0.0)
    discard ;
}