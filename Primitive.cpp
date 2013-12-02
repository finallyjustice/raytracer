/** File:		primitive.cpp
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

#include "Primitive.h"

int Sphere::intercect(Ray &ray, float &dist)
{
	float A = ray.direction.Dot(ray.direction);
	float B = 2*(ray.origin-center).Dot(ray.direction);
	float C = (ray.origin-center).Dot(ray.origin-center)-radius*radius;
	float delta = B*B-4*A*C;

	float t0;
	float t1;
	float t;

	if(delta < 0)
	{
		return 0;
	}
	else if(delta == 0)
	{
		t = (-B) / (2*A);
	}
	else
	{
		t0 = (-B - sqrt(delta)) / (2*A);
		t1 = (-B + sqrt(delta)) / (2*A);

		if(t0 >= t1)
		{
			t = t1;
		}
		else
		{
			t = t0;
		}
	}

	dist = t;
	
	return 1;
}

Vec3f Sphere::getNormal(Vec3f &pos)
{
	return (pos-center).genNormal();
}

int Plane::intercect(Ray &ray, float &dist)
{
	float test = normal.Dot(ray.direction);

	if(test >= 0)
	{
		return 0;
	}
	
	dist = (-planeD-ray.origin.Dot(normal)) / (ray.direction.Dot(normal));
	return 1;

	/*float d = normal.Dot(ray.direction);
	if (d != 0)
	{
		float adist = -(normal.Dot(ray.origin) + planeD) / d;
		if (adist > 0)
		{
			dist = adist;
			return 1;
		}
	}

	return 0;*/
}

Vec3f Plane::getNormal(Vec3f &pos)
{
	return normal.genNormal();
}
