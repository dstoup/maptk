/*ckwg +5
 * Copyright 2013 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#ifndef MAPTK_CAMERA_INTRINSICS_H_
#define MAPTK_CAMERA_INTRINSICS_H_

#include <iostream>

#include "vector.h"
#include "matrix.h"

namespace maptk
{

/// A representation of camera intrinsic parameters
template <typename T>
class camera_intrinsics_
{
public:
  /// Default Constructor
  camera_intrinsics_<T>()
  : focal_length_(T(1)),
    principal_point_(T(0), T(0)),
    aspect_ratio_(T(1)),
    skew_(T(0))
  {}

  /// Constructor for camera intrinsics
  camera_intrinsics_<T>(T focal_length,
                        const vector_2_<T>& principal_point,
                        T aspect_ratio=1.0,
                        T skew=0.0)
  : focal_length_(focal_length),
    principal_point_(principal_point),
    aspect_ratio_(aspect_ratio),
    skew_(skew)
  {}

  /// Constructor - from a calibration matrix
  /// \note ignores values below the diagonal
  explicit camera_intrinsics_<T>(const matrix_<3,3,T>& K);

  /// Access the focal length
  const T& focal_length() const { return focal_length_; }
  /// Access the principal point
  const vector_2_<T>& principal_point() const { return principal_point_; }
  /// Access the aspect ratio
  const T& aspect_ratio() const { return aspect_ratio_; }
  /// Access the skew
  const T& skew() const { return skew_; }

  /// Set the focal length
  void set_focal_length(const T& focal_length) { focal_length_ = focal_length; }
  /// Set the principal point
  void set_principal_point(const vector_2_<T>& pp) { principal_point_ = pp; }
  /// Set the aspect_ratio
  void set_aspect_ratio(const T& aspect_ratio) { aspect_ratio_ = aspect_ratio; }
  /// Set the skew
  void set_skew(const T& skew) { skew_ = skew; }

  /// Convert to a 3x3 calibration matrix
  operator matrix_<3,3,T>() const;

protected:
  T focal_length_;
  vector_2_<T> principal_point_;
  T aspect_ratio_;
  T skew_;
};


typedef camera_intrinsics_<double> camera_intrinsics_d;
typedef camera_intrinsics_<float> camera_intrinsics_f;

/// output stream operator for camera intrinsics
template <typename T>
std::ostream&  operator<<(std::ostream& s, const camera_intrinsics_<T>& k);

/// input stream operator for camera intrinsics
template <typename T>
std::istream&  operator>>(std::istream& s, camera_intrinsics_<T>& c);


} // end namespace maptk


#endif // MAPTK_CAMERA_INTRINSICS_H_