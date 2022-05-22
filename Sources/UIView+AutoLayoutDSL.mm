//
//  UIView+AutoLayoutDSL.mm
//  CAutoLayoutDSL
//
//  Created by lvv.me on 2022/5/18.
//

#import "UIView+AutoLayoutDSL.h"

@implementation UIView (AutoLayoutDSL)

- (CAutoLayoutDSL::CLayoutXAxisAnchor)leading {
    return CAutoLayoutDSL::CLayoutXAxisAnchor(self, NSLayoutAttributeLeading);
}

- (CAutoLayoutDSL::CLayoutXAxisAnchor)trailing {
    return CAutoLayoutDSL::CLayoutXAxisAnchor(self, NSLayoutAttributeTrailing);
}

- (CAutoLayoutDSL::CLayoutYAxisAnchor)top {
    return CAutoLayoutDSL::CLayoutYAxisAnchor(self, NSLayoutAttributeTop);
}

- (CAutoLayoutDSL::CLayoutXAxisAnchor)left {
    return CAutoLayoutDSL::CLayoutXAxisAnchor(self, NSLayoutAttributeLeft);
}

- (CAutoLayoutDSL::CLayoutYAxisAnchor)bottom {
    return CAutoLayoutDSL::CLayoutYAxisAnchor(self, NSLayoutAttributeBottom);
}

- (CAutoLayoutDSL::CLayoutXAxisAnchor)right {
    return CAutoLayoutDSL::CLayoutXAxisAnchor(self, NSLayoutAttributeRight);
}

- (CAutoLayoutDSL::CLayoutXAxisAnchor)centerX {
    return CAutoLayoutDSL::CLayoutXAxisAnchor(self, NSLayoutAttributeCenterX);
}

- (CAutoLayoutDSL::CLayoutYAxisAnchor)centerY {
    return CAutoLayoutDSL::CLayoutYAxisAnchor(self, NSLayoutAttributeCenterY);
}

- (CAutoLayoutDSL::CLayoutDimension)width {
    return CAutoLayoutDSL::CLayoutDimension(self, NSLayoutAttributeWidth);
}

- (CAutoLayoutDSL::CLayoutDimension)height {
    return CAutoLayoutDSL::CLayoutDimension(self, NSLayoutAttributeHeight);
}

@end
