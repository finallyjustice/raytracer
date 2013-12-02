/** File:		main.cpp
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

#include <GL\glut.h>
#include "RayTracer.h"

RayTracer *rt;

void myDisplay(void)
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

	glDrawPixels(rt->getWinWidth(), rt->getWinHeight(), GL_RGBA, GL_UNSIGNED_BYTE, rt->getPixel());

    glFlush();
}

int main(int argc, char **argv)
{
	rt = new RayTracer();
	rt->init();
	rt->run();

	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(rt->getWinWidth(), rt->getWinHeight());
    glutCreateWindow("CPU Ray Tracing");

	glutDisplayFunc(&myDisplay);
    glutMainLoop();

    delete rt;

    return 0;
}
