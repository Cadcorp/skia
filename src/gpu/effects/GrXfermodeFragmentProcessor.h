/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrXfermodeFragmentProcessor_DEFINED
#define GrXfermodeFragmentProcessor_DEFINED

#include "include/core/SkBlendMode.h"
#include "include/core/SkRefCnt.h"

class GrFragmentProcessor;

namespace GrXfermodeFragmentProcessor {

enum class ComposeBehavior {
    // Picks "ComposeOne" or "ComposeTwo" automatically depending on presence of src/dst FPs.
    kDefault = 0,

    // half(1) is passed as the input color to child FPs. No alpha channel trickery.
    kComposeOneBehavior,

    // sk_InColor.rgb1 is passed as the input color to child FPs. Alpha is manually blended.
    kComposeTwoBehavior,

    // half(1) is passed to src; sk_InColor.rgba is passed to dst. No alpha channel trickery.
    kSkModeBehavior,

    kLastComposeBehavior = kSkModeBehavior,
};

/** Blends src and dst inputs according to the blend mode.
 *  If either input is null, the input color (sk_InColor) is used instead.
 */
std::unique_ptr<GrFragmentProcessor> Make(std::unique_ptr<GrFragmentProcessor> src,
                                          std::unique_ptr<GrFragmentProcessor> dst,
                                          SkBlendMode mode,
                                          ComposeBehavior behavior = ComposeBehavior::kDefault);

};

#endif
