// ==========================================================================
// $Id: sphere.cpp,v 1.2 2018/02/17 03:21:09 jlang Exp $
// Simple structure for data
// ==========================================================================
// (C)opyright:
//
//   Jochen Lang
//   SITE, University of Ottawa
//   800 King Edward Ave.
//   Ottawa, On., K1N 6N5
//   Canada.
//   http://www.site.uottawa.ca
//
// Creator: jlang (Jochen Lang)
// Email:   jlang@site.uottawa.ca
// ==========================================================================
// $Log: sphere.cpp,v $
// Revision 1.2  2018/02/17 03:21:09  jlang
// Simplified shape hierarchy for simplifying modifications
//
// Revision 1.1  2018/01/28 05:45:57  jlang
// Switch to core
//
//
// ==========================================================================
#include "sphere.h"
#include <iostream>
#define GLM_ENABLE_EXPERIMENTAL

//Loop subdivision constructor
Sphere::Sphere(int x) : RenderShape(){
	if (x == 0) { //No subdivision
		// 42 vertices
		const std::vector<GLfloat> vertexCopy = vertices;

		d_vertex.insert(d_vertex.end(), vertexCopy.begin(), vertexCopy.end());
		d_index.insert(d_index.end(), {
			1, 0, 4,
			0, 1, 6,
			2, 3, 5,
			3, 2, 7,
			4, 5, 10,
			5, 4, 8,
			6, 7, 9,
			7, 6, 11,
			8, 9, 2,
			9, 8, 0,
			10, 11, 1,
			11, 10, 3,
			0, 8, 4,
			0, 6, 9,
			1, 4, 10,
			1, 11, 6,
			2, 5, 8,
			2, 9, 7,
			3, 10, 5,
			3, 7, 11
		});
	}
	else if (x > 0) { //Perform loop subdivision
		
	}
}



std::vector<GLfloat> Sphere::subDivide(int numDivs) {
	std::vector<GLfloat> loopVertices;
	std::vector<int> loopIndices;

	if (numDivs == 0) {
		loopVertices = vertices;
	}
	else { // >= 1 subdivision
		for (int i = 0; i < vertices.size; i += 3) {

		}
	}

	return loopVertices;
	
}

Sphere::Sphere() : RenderShape() {
  // 42 vertices
	const std::vector<GLfloat> a = subDivide(1);
	const std::vector<GLfloat> vertexCopy = vertices;

	d_vertex.insert(d_vertex.end(), vertexCopy.begin(), vertexCopy.end());
	std::vector<int>lol = getVertexfromIndex(2);
  // 80 faces
  d_index.insert(d_index.end(), {
    1, 0, 4, 
	0, 1, 6, 
	2, 3, 5, 
	3, 2, 7, 
	4, 5, 10, 
	5, 4, 8, 
	6, 7, 9, 
	7, 6, 11, 
	8, 9, 2, 
	9, 8, 0, 
	10, 11, 1, 
	11, 10, 3, 
	0, 8, 4, 
	0, 6, 9, 
	1, 4, 10, 
	1, 11, 6, 
	2, 5, 8, 
	2, 9, 7, 
	3, 10, 5, 
	3, 7, 11
    });
  std::cout << "VERTICES ARE" << d_vertex[4];
  // direct specification with all faces unrolled
  // - not supplied
}



