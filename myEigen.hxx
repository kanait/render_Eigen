////////////////////////////////////////////////////////////////////
//
// $Id: myEigen.hxx $
//
// Copyright (c) 2017 by Takashi Kanai. All rights reserved. 
//
////////////////////////////////////////////////////////////////////

#ifndef _MYEIGEN_HXX
#define _MYEIGEN_HXX 1

#include <cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Geometry>

// return (double)Math.acos(dot(v1)/v1.length()/v.length());
// Numerically, near 0 and PI are very bad condition for acos.
// In 3-space, |atan2(sin,cos)| is much stable.
template <typename T>
T angleT( Eigen::Matrix<T, 3, 1>& v1, Eigen::Matrix<T, 3, 1>& v2 ) {
  Eigen::Matrix<T, 3, 1> c = v1.cross(v2);
  T s = c.norm();

  return std::fabs(std::atan2(s, v1.dot(v2)));
};

//typedef angleT<float> anglef;

#if 0
float anglef( Eigen::Vector3f& v1, Eigen::Vector3f& v2 ) {
  // return (double)Math.acos(dot(v1)/v1.length()/v.length());
  // Numerically, near 0 and PI are very bad condition for acos.
  // In 3-space, |atan2(sin,cos)| is much stable.
  Eigen::Vector3f c = v1.cross(v2);
  float s = c.norm();

  return std::fabs(std::atan2(s, v1.dot(v2)));
};
#endif


#endif // _MYEIGEN_HXX

