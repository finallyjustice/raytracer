/** File:		Primitive.h
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

#ifndef __PRIMITIVE_H__
#define __PRIMITIVE_H__

#include "Material.h"
#include "Ray.h"
#include "Vector3D.h"

class Primitive
{
public:
	Primitive(){}
	~Primitive(){}
	virtual int getType() = 0;
	virtual int intercect(Ray &ray, float &dist) = 0;
	virtual Vec3f getNormal(Vec3f &pos) = 0;
	
	Material getMaterial(){ return material; }
	void setMaterial(Material &_material){ material=_material; }
	bool isLightEnabled(){ return light; }
	void enableLight(){ light=true; }
	void disableLight(){ light=false; }
	void enable(){ inUse=true; }
	void disable(){ inUse=false; }
	bool isEnabled(){ return inUse; }

protected:
	Material material;
	bool light;
	bool inUse;

	enum
	{
		SPHERE = 1,
		PLANE
	};
};

class Sphere : public Primitive
{
public:
	Sphere(){}
	~Sphere(){}
	int getType(){ return SPHERE; }
	int intercect(Ray &ray, float &dist);
	Vec3f getNormal(Vec3f &pos);

	Vec3f getCenter(){ return center; }
	void setCenter(Vec3f &_center){ center=_center; }
	float getRadius(){ return radius; }
	void setRadius(float _radius){ radius=_radius; }

private:
	Vec3f center;
	float radius;
};

class Plane : public Primitive
{
public:
	Plane(){}
	~Plane(){}
	int getType(){ return PLANE; }
	int intercect(Ray &ray, float &dist);
	Vec3f getNormal(Vec3f &pos);

	Vec3f getNormal(){ return normal; }
	void setNormal(Vec3f &_normal){ normal=_normal; }
	float getPlaneD(){ return planeD; }
	void setPlaneD(float _planeD){ planeD=_planeD; }

private:
	Vec3f normal;
	float planeD;
};

#endif
