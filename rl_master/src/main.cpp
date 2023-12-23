#include <stdio.h>
#include <tuple>
#include "utils.h"

int main() {

	Vec2d p = Vec2d(5, 7);
	Vec2d c = Vec2d(3, 3);
	auto d = c.copy();

	printf("Vector p.pos.x %f p.pos.y %f\n\n", p.pos.x, p.pos.y);
	printf("Vector c.pos.x %f c.pos.y %f\n\n", c.pos.x, c.pos.y);
	printf("Vector d.pos.x %f d.pos.y %f\n\n", d.pos.x, d.pos.y);
	c.set(4, 4);
	printf("Nach set: Vector c.pos.x %f c.pos.y %f\n", c.pos.x, c.pos.y);
	printf("Vector d.pos.x %f d.pos.y %f\n\n", d.pos.x, d.pos.y);

	Matrix3x1 p_rotated = rotate(p, c, 0.2f);
	printf("Bevor Drehung %f %f\n", p.pos.x, p.pos.y);
	printf("Nach Drehung %f %f\n", p_rotated.index[0], p_rotated.index[1]);
	printf("Nach Drehung als Vector p.x %f p.y %f\n\n", matrix3x1ToVec(p_rotated).pos.x, matrix3x1ToVec(p_rotated).pos.y);
	
	Vec2d a1(10, 10);
	Vec2d a2(100,100);
	Vec2d b1(100, 10);
	Vec2d b2(10, 100);

	std::tuple<float, Vec2d> sp = intersect(a1, a2, b1, b2);
	printf("Schnitt %f %f: ", std::get<1>(sp).pos.x, std::get<1>(sp).pos.y);
	printf("Laenge %f: ", std::get<0>(sp));


	return 0;
}