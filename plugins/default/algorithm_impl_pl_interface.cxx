/*ckwg +29
 * Copyright 2014 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file
 * \brief Defaults plugin algorithm registration plugin interface impl
 */

#include <maptk/plugin_interface/algorithm_impl_pl_interface.h>

#include "close_loops_bad_frames_only.h"
#include "close_loops_multi_method.h"
#include "compute_ref_homography_default.h"
#include "convert_image_default.h"
#include "hierarchical_bundle_adjust.h"
#include "match_features_homography.h"
#include "plugin_default_config.h"
#include "track_features_default.h"

#include <iostream>

#include <maptk/logging_macros.h>


#ifdef __cplusplus
extern "C"
{
#endif


PLUGIN_DEFAULT_EXPORT
int register_algo_impls(maptk::registrar &reg)
{
  LOG_DEBUG("plugin::default::register_algo_impls",
            "Registering DEFAULT plugin algo implementations (" << &reg << ")");

  int registered
    = maptk::algo::close_loops_bad_frames_only::register_self(reg)
    + maptk::algo::close_loops_multi_method::register_self(reg)
    + maptk::algo::compute_ref_homography_default::register_self(reg)
    + maptk::algo::convert_image_default::register_self(reg)
    + maptk::algo::hierarchical_bundle_adjust::register_self(reg)
    + maptk::algo::match_features_homography::register_self(reg)
    + maptk::algo::track_features_default::register_self(reg)
    ;

  LOG_DEBUG("plugin::default::register_algo_impls",
            "Registered algorithms. Returned: " << registered);
  return 7 - registered;
}


#ifdef __cplusplus
}
#endif
