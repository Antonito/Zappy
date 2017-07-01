#version 400

struct light_s
{
  vec3  position;
  float power;
  vec3  direction;
  vec3  color;
};

uniform light_s light0;
uniform light_s light1;
uniform light_s light2;
uniform light_s light3;
uniform light_s light4;
uniform light_s light5;
uniform light_s light6;
uniform light_s light7;
uniform light_s light8;
uniform light_s light9;
uniform light_s light10;
uniform light_s light11;
uniform light_s light12;
uniform light_s light13;
uniform light_s light14;
uniform light_s light15;
uniform int     nbLights;

out vec4 colorOut;

in vec3 normal2;
in vec3 eye2;
in vec3 lightDir2;
in vec4 color2;
in vec4 position2;

void main()
{
  float minimum = 0.4;

  vec3 lightDir = normalize(vec3(-1, -0.8, -1.2));

  float finalIntensity = max(minimum, -dot(normal2, lightDir));

  vec3  difference;
  float dist;
  float cprod;
  float coeff;
  float intensity = 0;

  //
  // Light 0
  //
  difference = vec3(position2) - light0.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light0.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light0.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light0.power - dist) / light0.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light0.power - dist) / light0.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 1
  //
  difference = vec3(position2) - light1.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light1.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light1.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light1.power - dist) / light1.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light1.power - dist) / light1.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 2
  //
  difference = vec3(position2) - light2.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light2.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light2.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light2.power - dist) / light2.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light2.power - dist) / light2.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 3
  //
  difference = vec3(position2) - light3.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light3.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light3.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light3.power - dist) / light3.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light3.power - dist) / light3.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 4
  //
  difference = vec3(position2) - light4.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light4.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light4.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light4.power - dist) / light4.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light4.power - dist) / light4.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 5
  //
  difference = vec3(position2) - light5.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light5.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light5.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light5.power - dist) / light5.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light5.power - dist) / light5.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 6
  //
  difference = vec3(position2) - light6.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light6.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light6.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light6.power - dist) / light6.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light6.power - dist) / light6.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 7
  //
  difference = vec3(position2) - light7.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light7.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light7.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light7.power - dist) / light7.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light7.power - dist) / light7.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 8
  //
  difference = vec3(position2) - light8.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light8.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light8.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light8.power - dist) / light8.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light8.power - dist) / light8.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 9
  //
  difference = vec3(position2) - light9.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light9.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light9.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light9.power - dist) / light9.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light9.power - dist) / light9.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 10
  //
  difference = vec3(position2) - light10.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light10.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light10.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light10.power - dist) / light10.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light10.power - dist) / light10.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 11
  //
  difference = vec3(position2) - light11.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light11.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light11.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light11.power - dist) / light11.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light11.power - dist) / light11.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 12
  //
  difference = vec3(position2) - light12.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light12.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light12.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light12.power - dist) / light12.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light12.power - dist) / light12.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 13
  //
  difference = vec3(position2) - light13.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light13.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light13.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light13.power - dist) / light13.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light13.power - dist) / light13.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 14
  //
  difference = vec3(position2) - light14.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light14.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light14.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light14.power - dist) / light14.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light14.power - dist) / light14.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  //
  // Light 15
  //
  difference = vec3(position2) - light15.position;
  dist = length(difference);

  difference = normalize(difference);

  cprod = dot(light15.direction, difference);
  coeff = min(1, dot(-difference, normal2) * 2.0);

  if (dist < light15.power && coeff > 0 && cprod > 0.55)
    {
      if (cprod > 0.65)
	{
	  intensity = min(1.0, (light15.power - dist) / light15.power);
	}
      else if (cprod > 0.55)
	{
	  float val = (cprod - 0.55) * 10.0;

	  intensity = min(1.0, (light15.power - dist) / light15.power * val);
	}
      finalIntensity += intensity * coeff;
    }

  colorOut = color2 * min(1.0, max(finalIntensity, minimum));
  if (colorOut.a == 0.0)
    discard;
}