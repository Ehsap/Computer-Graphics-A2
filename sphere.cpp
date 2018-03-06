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


std::vector<GLfloat> Sphere::subDivide(int numDivs) {
	std::vector<GLfloat> loopVertices = vertices; //Vertices in the sub divided polyhedron
	
	std::cout << "INDICES SIZE: " << indices.size()<<"!!!!";
	//Represents the three midpoints found from a triangular face
	std::vector<GLfloat> midPoints;
	
	loopVertices = vertices;
	
	if (numDivs == 0) {
		loopIndices = indices;
		return loopVertices;
	}
	else { // >= 1 subdivision. 
		//for (int i = 0; i <= 3; i+=3){
		for (int i = 0; i<= indices.size()-3; i+=3) {
		   
			//Represent the three vertices of a triangular face
			std::vector<GLfloat> v1;
			std::vector<GLfloat> v2;
			std::vector<GLfloat> v3;

			//Hold the indices of vertices corresponding to v1,v2,v3
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

			/*Split each triangle into four by connecting edge midpoints

			1.Calculate the midpoints between (v1,v2), (v1,v3), and (v2,v3)
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

			/*Create new edges between original vertices and midpoints
							   v1
							   / \
							  a___b   
							 / \ / \
							v2__c__v3

							 */
			//Create face between midpoints
			loopIndices.push_back(indices.size() + i); //a	
			loopIndices.push_back(indices.size() + i + 1); //b
			loopIndices.push_back(indices.size() + i + 2); //c

			//Create face between v1, a, and b
			loopIndices.push_back(indices[i]); //v1
			loopIndices.push_back(indices.size() + i); //a
			loopIndices.push_back(indices.size() + i + 1); //b

			//Create face between v2, a, and c
			loopIndices.push_back(indices[i + 1]); //v2
			loopIndices.push_back(indices.size() + i); //a
			loopIndices.push_back(indices.size() + i + 2); //c

			//Create face between v3, b, and c
			loopIndices.push_back(indices[i + 2]); //v3
			loopIndices.push_back(indices.size() + i + 1); //b
			loopIndices.push_back(indices.size() + i + 2); //c


		}
	}

	std::cout << "LOOP VERTICES SIZE: " << loopVertices.size() <<"!!!";
	return loopVertices;
	
}

/*Sphere constructor takes an integer 'numDivs' that determines how many times
  to subdivide the sphere.*/ 
Sphere::Sphere(int numDivs) : RenderShape() {
 
	const std::vector<GLfloat> vertexCopy = vertices;
	std::vector<GLfloat> loopVertices = subDivide(numDivs);
	// 42 vertices
	d_vertex.insert(d_vertex.end(), loopVertices.begin(), loopVertices.end());
	//d_vertex.insert(d_vertex.end(), vertexCopy.begin(), vertexCopy.end());

  // 80 faces
	//d_index.insert(d_index.end(), b.begin(), b.end());
	d_index.insert(d_index.end(), loopIndices.begin(), loopIndices.end());
	
}
