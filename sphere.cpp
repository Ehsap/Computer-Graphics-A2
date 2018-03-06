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
	std::vector<GLfloat> loopVertices; //Vertices in the sub divided polyhedron
	std::vector<int> loopIndices; //Indices in the sub divided polyhedron
	std::cout << "INDICES SIZE: " << indices.size()<<"!!!!";
	//Represents the three midpoints found from a triangular face
	std::vector<GLfloat> midPoints;
	
	if (numDivs == 0) {
		loopVertices = vertices;
	}
	else { // >= 1 subdivision. 
		for (int i = 0; i < indices.size()-3; i+=3) {
		   
			//Represent the three vertices of a triangular face
			std::vector<GLfloat> v1;
			std::vector<GLfloat> v2;
			std::vector<GLfloat> v3;

			std::vector<int> temp;
			std::vector<int> tempB;
			std::vector<int> tempC;

			//Derive the vertices on a triangular face from its index
			temp = Sphere::getVertexfromIndex(indices[i]);
			tempB = Sphere::getVertexfromIndex(indices[i + 1]);
			tempC = Sphere::getVertexfromIndex(indices[i + 2]);

			//Load v1, v2, v3 with vectors from the original vertices
			v1.push_back(vertices[temp[0]]);
			v1.push_back(vertices[temp[1]]);
			v1.push_back(vertices[temp[2]]);

			v2.push_back(vertices[tempB[0]]);
			v2.push_back(vertices[tempB[1]]);
			v2.push_back(vertices[tempB[2]]);

			v3.push_back(vertices[tempC[0]]);
			v3.push_back(vertices[tempC[1]]);
			v3.push_back(vertices[tempC[2]]);

			/*Calculate the midpoints between (v1,v2), (v1,v3), and (v2,v3)
			          v1
					/   \
				   v2____v3 */

			//Midpoint between (v1,v2)
			loopVertices.push_back((v1[0] + v2[0]) / 2); //X
			loopVertices.push_back((v1[1] + v2[1]) / 2); //Y
			loopVertices.push_back((v1[2] + v2[2]) / 2); //Z

			//Midpoint between (v1, v3)
			loopVertices.push_back((v1[0] + v3[0]) / 2); //X
			loopVertices.push_back((v1[1] + v3[1]) / 2); //Y
			loopVertices.push_back((v1[2] + v3[2]) / 2); //Z

			//Midpoint between (v2, v3)
			loopVertices.push_back((v2[0] + v3[0]) / 2); //X
			loopVertices.push_back((v2[1] + v3[1]) / 2); //Y
			loopVertices.push_back((v2[2] + v3[2]) / 2); //Z

			//Find the new indices
		}
	}
	
	std::cout << "LOOP VERTICES SIZE: " << loopVertices.size() <<"!!!";
	return loopVertices;
	
}

Sphere::Sphere() : RenderShape() {
 
	//const std::vector<GLfloat> a = subDivide(1);
	const std::vector<GLushort> b = indices;
	const std::vector<GLfloat> vertexCopy = vertices;
	std::vector<GLfloat> test = subDivide(1);

	// 42 vertices
	d_vertex.insert(d_vertex.end(), test.begin(), test.end());
	//d_vertex.insert(d_vertex.end(), vertexCopy.begin(), vertexCopy.end());

  // 80 faces
	d_index.insert(d_index.end(), b.begin(), b.end());
}






