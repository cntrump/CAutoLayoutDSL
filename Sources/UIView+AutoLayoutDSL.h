//
//  UIView+AutoLayoutDSL.h
//  CAutoLayoutDSL
//
//  Created by lvv.me on 2022/5/18.
//

#ifdef __cplusplus

#import "CLayoutAnchor.h"

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(10.7), ios(6.0), tvos(9.0))
@interface UIView (AutoLayoutDSL)

@property(nonatomic, readonly) CAutoLayoutDSL::CLayoutXAxisAnchor leading;
@property(nonatomic, readonly) CAutoLayoutDSL::CLayoutXAxisAnchor trailing;
@property(nonatomic, readonly) CAutoLayoutDSL::CLayoutYAxisAnchor top;
@property(nonatomic, readonly) CAutoLayoutDSL::CLayoutXAxisAnchor left;
@property(nonatomic, readonly) CAutoLayoutDSL::CLayoutYAxisAnchor bottom;
@property(nonatomic, readonly) CAutoLayoutDSL::CLayoutXAxisAnchor right;

@property(nonatomic, readonly) CAutoLayoutDSL::CLayoutXAxisAnchor centerX;
@property(nonatomic, readonly) CAutoLayoutDSL::CLayoutYAxisAnchor centerY;

@property(nonatomic, readonly) CAutoLayoutDSL::CLayoutDimension width;
@property(nonatomic, readonly) CAutoLayoutDSL::CLayoutDimension height;

@end

NS_ASSUME_NONNULL_END

#endif /* __cplusplus */
