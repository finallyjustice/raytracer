/** File:		Material.h
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

#ifndef __MATERiAL_H__
#define __MATERIAL_H__

#include "Vector3D.h"
#include <stdio.h>

class Material
{
public:
	Material(){}
	~Material(){}
	Vec3f getColor(){ return color; }
	void setColor(Vec3f &_color){ color=_color; }
	float getDiffRate(){ return diffRate; }
	void setDiffRate(float _diffRate){ diffRate=_diffRate; }
	float getReflecRate(){ return reflecRate; }
	void setReflecRate(float _reflecRate){ reflecRate=_reflecRate; }
	float getSpecRate(){ return specRate; }
	void setSpecRate(float _specRate){ specRate=_specRate; }
	float getRefracRate(){ return refracRate; }
	void setRefracRate(float _refracRate){ refracRate=_refracRate; }
	float getRafracIndex(){ return refracIndex; }
	void setRefracIndex(float _refracIndex){ refracIndex=_refracIndex; }

private:
	Vec3f color;
	float diffRate;
	float reflecRate;
	float specRate;
	float refracRate;
	float refracIndex;
};

#endif
