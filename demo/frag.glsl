#version 330 core

out vec3 color;

struct s_triangle {
	vec2 center;
	float size;
	float offsett;
};

uniform float nTriangles;
uniform s_triangle triangles[3];
uniform float time;

#define PI 3.1415926535897932384626433832795

// Source: http://www.blackpawn.com/texts/pointinpoly/
bool insideTriangle(vec2 A, vec2 B, vec2 C)
{
	vec2 P = gl_FragCoord.xy;

	// Compute vectors
	vec2 v0 = C - A;
	vec2 v1 = B - A;
	vec2 v2 = P - A;

	// Compute dot products
	float dot00 = dot(v0, v0);
	float dot01 = dot(v0, v1);
	float dot02 = dot(v0, v2);
	float dot11 = dot(v1, v1);
	float dot12 = dot(v1, v2);

	// Compute barycentric coordinates
	float invDenom = 1 / (dot00 * dot11 - dot01 * dot01);
	float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	float v = (dot00 * dot12 - dot01 * dot02) * invDenom;

	// Check if point is in triangle
	return ((u >= 0) && (v >= 0) && (u + v < 1));
}

bool triangle(vec2 center, float size, float offsett)
{
	vec2 A = center + vec2(sin(PI*2*1/3+offsett), cos(PI*2*1/3+offsett)) * size;
	vec2 B = center + vec2(sin(PI*2*2/3+offsett), cos(PI*2*2/3+offsett)) * size;
	vec2 C = center + vec2(sin(PI*2*3/3+offsett), cos(PI*2*3/3+offsett)) * size;

	return insideTriangle(A, B, C);
}

bool triangle(s_triangle tri)
{
	return triangle(tri.center, tri.size, tri.offsett);
}

void main()
{
	color = vec3(0, 0, 0);

	for(int i=0; i < nTriangles; ++i)
		if(triangle(triangles[i]))
			color = vec3(1, 1, 1);

}