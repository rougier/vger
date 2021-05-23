//  Copyright © 2021 Audulus LLC. All rights reserved.

#ifndef vger_types_h
#define vger_types_h

#ifndef __METAL_VERSION__
#include <simd/simd.h>
#endif

/// VGER supports simple primitive types.
typedef enum {
    
    /// Filled circle.
    vgerCircle,
    
    /// Stroked arc.
    vgerArc,
    
    /// Rounded corner rectangle.
    vgerRect,

    /// Stroked rounded rectangle.
    vgerRectStroke,
    
    /// Single-segment quadratic bezier curve.
    vgerBezier,
    
    /// line segment
    vgerSegment,
    
    /// Multi-segment bezier curve.
    vgerCurve,

    /// Connection wire. See https://www.shadertoy.com/view/NdsXRl
    vgerWire,

    /// Text rendering.
    vgerGlyph,

    /// Path fills.
    vgerPathFill

} vgerPrimType;

/// Primitive rendered by the GPU.
typedef struct {
    
    /// Type of primitive.
    vgerPrimType type;

    /// Stroke width.
    float width;
    
    /// Radius of circles. Corner radius for rounded rectangles.
    float radius;
    
    /// Control vertices.
    vector_float2 cvs[3];

    /// Start of the control vertices, if they're in a separate buffer.
    uint32_t start;
    
    /// Number of control vertices (vgerCurve and vgerPathFill)
    uint16_t count;

    /// Index of paint applied to drawing region.
    uint16_t paint;

    /// Glyph region index.
    uint16_t glyph;

    /// Index of transform applied to drawing region.
    uint16_t xform;
    
    /// Min and max coordinates of the quad we're rendering.
    vector_float2 quadBounds[2];
    
    /// Min and max coordinates in texture space.
    vector_float2 texBounds[2];

} vgerPrim;

/// Text alignment.
enum vgerAlign {
    // Horizontal align
    VGER_ALIGN_LEFT      = 1<<0, // Default, align text horizontally to left.
    VGER_ALIGN_CENTER    = 1<<1, // Align text horizontally to center.
    VGER_ALIGN_RIGHT     = 1<<2, // Align text horizontally to right.
    // Vertical align
    VGER_ALIGN_TOP       = 1<<3, // Align text vertically to top.
    VGER_ALIGN_MIDDLE    = 1<<4, // Align text vertically to middle.
    VGER_ALIGN_BOTTOM    = 1<<5, // Align text vertically to bottom.
    VGER_ALIGN_BASELINE  = 1<<6, // Default, align text vertically to baseline.
};

#endif /* vger_types_h */
