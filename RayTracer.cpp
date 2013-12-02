/** File:		RayTracer.cpp
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

#include <stdlib.h>
#include <string.h>
#include "RayTracer.h"
#include <stdio.h>

RayTracer::RayTracer()
{
	winWidth = 600;
	winHeight = 600;
	simWidth = 10.0f;
	simHeight = 10.0f;
	viewPlaneZ = 0.0f;
	viewPoint=Vec3f(5.0f, 5.0f, 5.0f);
	numPrim = 6;
	prims = new Primitive*[numPrim];

	pixel = (unsigned char *)malloc(sizeof(unsigned char)*winWidth*winHeight*4);
	memset(pixel, 0, sizeof(unsigned char)*winWidth*winHeight*4);

	Material newMaterial;
	newMaterial.setColor(Vec3f(1.0f, 0.0f, 0.1f));
	newMaterial.setDiffRate(0.9f);
	newMaterial.setReflecRate(0.4f);
	newMaterial.setSpecRate(0.7f);
	newMaterial.setRefracRate(0.8f);
	newMaterial.setRefracIndex(1.2f);
	prims[0] = new Sphere();
	prims[0]->setMaterial(newMaterial);
	((Sphere *)prims[0])->setCenter(Vec3f(10.0f, 4.0f, -6.0f));
	((Sphere *)prims[0])->setRadius(3.0f);
	prims[0]->disableLight();
	prims[0]->enable();

	//light
	newMaterial.setColor(Vec3f(1.0f, 1.0f, 1.0f));
	newMaterial.setDiffRate(0.6f);
	newMaterial.setReflecRate(0.0f);
	newMaterial.setSpecRate(0.7f);
	newMaterial.setRefracRate(0.0f);
	newMaterial.setRefracIndex(1.2f);
	prims[1] = new Sphere();
	prims[1]->setMaterial(newMaterial);
	((Sphere *)prims[1])->setCenter(Vec3f(1.0f, 6.0f, -1.0f));
	((Sphere *)prims[1])->setRadius(0.02f);
	prims[1]->enableLight();
	prims[1]->enable();

	newMaterial.setColor(Vec3f(0.0f, 1.0f, 0.0f));
	newMaterial.setDiffRate(0.9f);
	newMaterial.setReflecRate(0.2f);
	newMaterial.setSpecRate(0.1f);
	newMaterial.setRefracRate(0.0f);
	newMaterial.setRefracIndex(1.2f);
	prims[2] = new Plane();
	prims[2]->setMaterial(newMaterial);
	((Plane *)prims[2])->setNormal(Vec3f(0.0f, 1.0f, 0.0f));
	((Plane *)prims[2])->setPlaneD(1.0f);
	prims[2]->disableLight();
	prims[2]->enable();

	//light
	newMaterial.setColor(Vec3f(1.0f, 1.0f, 1.0f));
	newMaterial.setDiffRate(0.6f);
	newMaterial.setReflecRate(0.0f);
	newMaterial.setSpecRate(0.7f);
	newMaterial.setRefracRate(0.0f);
	newMaterial.setRefracIndex(1.2f);
	prims[3] = new Sphere();
	prims[3]->setMaterial(newMaterial);
	((Sphere *)prims[3])->setCenter(Vec3f(9.0f, 5.0f, -1.0f));
	((Sphere *)prims[3])->setRadius(0.02f);
	prims[3]->enableLight();
	prims[3]->enable();

	newMaterial.setColor(Vec3f(0.0f, 0.2f, 0.8f));
	newMaterial.setDiffRate(0.7f);
	newMaterial.setReflecRate(0.4f);
	newMaterial.setSpecRate(0.7f);
	newMaterial.setRefracRate(0.0f);
	newMaterial.setRefracIndex(1.2f);
	prims[4] = new Plane();
	prims[4]->setMaterial(newMaterial);
	((Plane *)prims[4])->setNormal(Vec3f(0.0f, 0.0f, 1.0f));
	((Plane *)prims[4])->setPlaneD(70.0f);
	prims[4]->disableLight();
	prims[4]->enable();

	newMaterial.setColor(Vec3f(0.5f, 0.5f, 0.1f));
	newMaterial.setDiffRate(0.9f);
	newMaterial.setReflecRate(0.4f);
	newMaterial.setSpecRate(0.7f);
	newMaterial.setRefracRate(0.0f);
	newMaterial.setRefracIndex(1.2f);
	prims[5] = new Sphere();
	prims[5]->setMaterial(newMaterial);
	((Sphere *)prims[5])->setCenter(Vec3f(4.0f, 5.0f, -9.0f));
	((Sphere *)prims[5])->setRadius(3.0f);
	prims[5]->disableLight();
	prims[5]->enable();

	newMaterial.setColor(Vec3f(0.9f, 0.1f, 0.1f));
	newMaterial.setDiffRate(0.9f);
	newMaterial.setReflecRate(0.4f);
	newMaterial.setSpecRate(0.7f);
	newMaterial.setRefracRate(0.8f);
	newMaterial.setRefracIndex(1.2f);
	prims[6] = new Sphere();
	prims[6]->setMaterial(newMaterial);
	((Sphere *)prims[6])->setCenter(Vec3f(1.0f, 4.0f, -5.0f));
	((Sphere *)prims[6])->setRadius(3.0f);
	prims[6]->disableLight();
	prims[6]->enable();
}
	
RayTracer::~RayTracer()
{

}

void RayTracer::init()
{

}

void RayTracer::run()
{
	int index;
	float viewPlaneX;
	float viewPlaneY;
	Ray ray;

	ray.origin = viewPoint;

	for(int i=0; i<winWidth; i++)
	{
		viewPlaneX = ((float)i)/((float)winWidth) * simWidth;

		for(int j=0; j<winHeight; j++)
		{
			Vec3f shadeColor(0.0f, 0.0f, 0.0f);
			viewPlaneY = ((float)j)/((float)winHeight) * simHeight;
			index = j*winWidth+i;
			ray.direction = Vec3f(viewPlaneX, viewPlaneY, viewPlaneZ) - viewPoint;

			rayTracing(ray, shadeColor, 0);

			pixel[index*4+0] = (unsigned char)(shadeColor.x*255.0f);
			pixel[index*4+1] = (unsigned char)(shadeColor.y*255.0f);
			pixel[index*4+2] = (unsigned char)(shadeColor.z*255.0f);
			pixel[index*4+3] = 255;
		}
	}
}
	
void RayTracer::rayTracing(Ray &ray, Vec3f &shadeColor, int depth)
{
	float curDist = MAX_DIST;
	float newDist;
	int pi = -1;

	for(int k=0; k<numPrim; k++)
	{	
		if(prims[k]->isEnabled() == false) continue;

		if(prims[k]->intercect(ray, newDist) == 1)
		{
			if(newDist < curDist)
			{
				curDist = newDist;
				pi = k;
			}
		}
	}

	if(pi != -1)
	{
		if(prims[pi]->isLightEnabled() == true)
		{
			//light source
			shadeColor = shadeColor + prims[pi]->getMaterial().getColor();
		}
		else
		{
			Vec3f pos = ray.origin+ray.direction*curDist;
			Vec3f N = prims[pi]->getNormal(pos);
			Vec3f R = ray.direction - N * ray.direction.Dot(N) * 2.0f;
			R = Vec3f(0.0f, 0.0f, 0.0f) - R;

			for(int l=0; l<numPrim; l++)
			{
				if(prims[l]->isLightEnabled() == false)
				{
					continue;
				}

				float viewLightDist = (((Sphere *)prims[l])->getCenter() - pos).Length();
				Vec3f L = (((Sphere *)prims[l])->getCenter() - pos).genNormal();

				//shadow light
				float shade = 1.0f;
				Ray rayShadow;
				rayShadow.direction = L;
				rayShadow.origin = pos;
				for(int s=0; s<numPrim; s++)
				{
					if(prims[s]->isLightEnabled() == true) continue;

					float tmpDist;
					if(prims[s]->intercect(rayShadow, tmpDist) == 1 && s != pi && viewLightDist > tmpDist)
					{
						shade = 1.0f;
						break;
					}
				}

				//diffusion light
				float dot = N.Dot(L);
				if(dot > 0)
				{
					float diff = dot * prims[pi]->getMaterial().getDiffRate();
					shadeColor= shadeColor + prims[pi]->getMaterial().getColor() * prims[l]->getMaterial().getColor() * diff * 1.0f;//shade;
				}

				//spec Light
				Vec3f V = ray.direction.genNormal();
				Vec3f LR = L - N * L.Dot(N) * 2.0f;
				dot = V.Dot(LR);
				if (dot > 0)
				{
					float spec = pow(dot, 20) * prims[pi]->getMaterial().getSpecRate();
					shadeColor = shadeColor + prims[l]->getMaterial().getColor() * spec;
				}
			}

			//reflection light
			float refl = prims[pi]->getMaterial().getReflecRate();
			if(depth < RAY_TRACE_DEPTH) 
			{
				Vec3f recColor(0.0f, 0.0f, 0.0f);
				Ray recRay;
				recRay.direction=R;
				recRay.origin=R * 0.00001f + pos;
				rayTracing(recRay, recColor, depth+1);
				shadeColor = shadeColor + recColor * prims[pi]->getMaterial().getColor() * refl;
			}

			//refraction light
			/*float rindex = prims[pi]->getMaterial().getRafracIndex();
			if(prims[pi]->getMaterial().getRefracRate() > 0.0f &&  depth < RAY_TRACE_DEPTH)
			{
				float n = -1.0f;
				Vec3f N = prims[pi]->getNormal(pos);
				float cosI = 0.0f - N.Dot(ray.direction);
				float cosT2 = 1.0f - n * n * (1.0f - cosI * cosI);
				if (cosT2 > 0.0f)
				{
					Vec3f T = (ray.direction * n) + N * (n * cosI - sqrtf( cosT2 ));
					Vec3f rcol(0.0f, 0.0f, 0.0f);
					Ray recRay;
					recRay.direction=T;
					recRay.origin=T + pos;
					rayTracing(recRay, rcol, depth+1);
					shadeColor = shadeColor + rcol * 5.0f;
				}
			}*/
		}

		if(shadeColor.x > 1.0f) shadeColor.x = 1.0f;
		if(shadeColor.y > 1.0f) shadeColor.y = 1.0f;
		if(shadeColor.z > 1.0f) shadeColor.z = 1.0f;
	}
	else
	{
		//nothing
	}
}
