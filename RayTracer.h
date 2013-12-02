/** File:		RayTracer.h
 ** Author:		Dongli Zhang
 ** Contact:	dongli.zhang0129@gmail.com
 **
 ** Copyright (C) Dongli Zhang 2013
 **
 ** This program is free software;  you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation; either version 2 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY;  without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 ** the GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program;  if not, write to the Free Software 
 ** Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef __RAYTRACER_H__
#define __RAYTRACER_H__

#include "Vector3D.h"
#include "Primitive.h"

#define RAY_TRACE_DEPTH 3

class RayTracer
{
public:
	RayTracer();
	~RayTracer();
	void init();
	void run();
	void rayTracing(Ray &ray, Vec3f &shadeColor, int depth);

	int getWinWidth(){ return winWidth; }
	int getWinHeight(){ return winHeight; }
	unsigned char* getPixel(){ return pixel; }

private:
	int winWidth;
	int winHeight;
	float simWidth;
	float simHeight;
	float viewPlaneZ;
	Vec3f viewPoint;
	int numPrim;
	Primitive **prims;

	unsigned char *pixel;
};

#endif
