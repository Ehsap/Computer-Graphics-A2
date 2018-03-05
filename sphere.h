// ==========================================================================
// $Id: sphere.h,v 1.2 2018/02/17 03:21:09 jlang Exp $
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
// $Log: sphere.h,v $
// Revision 1.2  2018/02/17 03:21:09  jlang
// Simplified shape hierarchy for simplifying modifications
//
// Revision 1.1  2018/01/28 05:45:57  jlang
// Switch to core
//
//
// ==========================================================================
#ifndef CSI4130_SPHERE_H_
#define CSI4130_SPHERE_H_

#include "render_shape.h"
#include <iostream>

// gl types
#include <GL/glew.h>
// glm types
#include <glm/glm.hpp>

class Sphere : public RenderShape {
 public:
	 std::vector<GLfloat> vertices = { 
		 0, 0.8506508f, 0.5257311f,
		 0, 0.8506508f, -0.5257311f,
		 0, -0.8506508f, 0.5257311f,
		 0, -0.8506508f, -0.5257311f,
		 0.8506508f, 0.5257311f, 0,
		 0.8506508f, -0.5257311f, 0,
		 -0.8506508f, 0.5257311f, 0,
		 -0.8506508f, -0.5257311f, 0,
		 0.5257311f, 0, 0.8506508f,
		 -0.5257311f, 0, 0.8506508f,
		 0.5257311f, 0, -0.8506508f,
		 -0.5257311f, 0, -0.8506508f
	 };

	 std::vector<int>indices = {
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
		 3, 7, 11 };

  Sphere();
  Sphere(int x);
  std::vector<GLfloat> subDivide(int numDiv);
  //std::vector<int>getVertexfromIndex(int index);
  std::vector<int>getVertexfromIndex(int index) {
	  std::vector<int> vec;

	  if (index == 0) {
		  vec.push_back(0);
		  vec.push_back(1);
		  vec.push_back(2);
	  }	
	  else {
		  vec.push_back(index * 3);
		  vec.push_back(index * 3 + 1);
		  vec.push_back(index * 3 + 2);
	  }
	  std::cout << vec[0] << "," << vec[1] << "," << vec[2];
	  return vec;
  }
};
#endif
