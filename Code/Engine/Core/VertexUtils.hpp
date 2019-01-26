#pragma once
#include <vector>
#include "Engine/Math/Vec2.hpp"

#define UNUSED(x) (void)(x);

struct Vertex_PCU;
struct AABB2;
struct Rgba;

void			AddVertsForDisc2D( std::vector<Vertex_PCU>& vertexArray, const Vec2& center, float radius, const Rgba& color, int numSides = 64 );
void			AddVertsForLine2D( std::vector<Vertex_PCU>& vertexArray, const Vec2& start, const Vec2& end, float thickness, const Rgba& color );
void			AddVertsForRing2D( std::vector<Vertex_PCU>& vertexArray, const Vec2& center, float radius, float thickness, const Rgba& color, int numSides = 64 );
void			AddVertsForAABB2D( std::vector<Vertex_PCU>& vertexArray, const AABB2& box, const Rgba& color, const Vec2& uvAtMins = Vec2(0.f,0.f), const Vec2& uvAtMaxs = Vec2(1.f,1.f) );


//TransformVertex2D(...) - relocated from MathUtils.cpp,hpp to VertexUtils.cpp,hpp
//TransformVertexArray2D(...) - relocated from MathUtils.cpp,hpp to VertexUtils.cpp,hpp

void			TransformVertex2D( Vertex_PCU& vertex, float uniformScale, float rotationDegreesOnZ, const Vec2& translateXY);
void			TransformVertexArray2D(int numVerts, Vertex_PCU* vertices, float uniformScale, float rotationDegreesOnZ, const Vec2& translateXY);
