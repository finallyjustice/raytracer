/** File:		Vector3D.h
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

#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__

#include <math.h>

class Vec3f
{
public:
	float x;
	float y;
	float z;

public:
	Vec3f() {}
	Vec3f(float _x, float _y, float _z) { x=_x; y=_y; z=_z; };
	Vec3f(Vec3f &vec) { x=vec.x; y=vec.y; z=vec.z; };

	Vec3f operator + (const Vec3f &vec) const { return Vec3f(x+vec.x, y+vec.y, z+vec.z); }
	Vec3f operator - (const Vec3f &vec) const { return Vec3f(x-vec.x, y-vec.y, z-vec.z); }
	Vec3f operator * (const Vec3f &vec) const { return Vec3f(x*vec.x, y*vec.y, z*vec.z); }
	Vec3f operator / (const Vec3f &vec) const { return Vec3f(x/vec.x, y/vec.y, z/vec.z); }

	Vec3f operator + (float n) const { return Vec3f(x+n, y+n, z+n); }
	Vec3f operator - (float n) const { return Vec3f(x-n, y-n, z-n); }
	Vec3f operator * (float n) const { return Vec3f(x*n, y*n, z*n); }
	Vec3f operator / (float n) const { return Vec3f(x/n, y/n, z/n); }

	Vec3f Cross(const Vec3f &vec) const { return Vec3f(y*vec.z-z*vec.y, z*vec.x-x*vec.z, x*vec.y-y*vec.x); }
	float Dot(const Vec3f &vec) const { return x*vec.x+y*vec.y+z*vec.z; }
	Vec3f genNormal() const { return  *this / Length();} 
	void Normalize() { *this = *this / Length(); }

	float LengthSquared() const { return x*x+y*y+z*z; }
	float Length() const { return sqrt(LengthSquared()); }
};

#endif
