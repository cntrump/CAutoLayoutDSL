//
//  CLayoutAnchor.h
//  CAutoLayoutDSL
//
//  Created by lvv.me on 2022/5/18.
//

#ifdef __cplusplus

#ifndef _CLayoutAnchor_h
#define _CLayoutAnchor_h

#import <TargetConditionals.h>

#if TARGET_OS_OSX
#import <AppKit/AppKit.h>
#define UIView NSView
#define UILayoutGuide NSLayoutGuide
#else
#import <UIKit/UIKit.h>
#endif

#import <initializer_list>
#import <algorithm>

namespace CAutoLayoutDSL {

template<typename T>
class API_AVAILABLE(macos(10.7), ios(6.0), tvos(9.0))
CLayoutAnchor {
public:
    CLayoutAnchor() = delete;

    CLayoutAnchor(id item, NSLayoutAttribute attr)
        : m_item(item)
        , m_attribute(attr)
        , m_multiplier(1)
        , m_constant(0)
    {}

    virtual ~CLayoutAnchor() {
        m_item = nil;
    }

    T& operator* (CGFloat m) {
        m_multiplier *= m;

        return *static_cast<T*>(this);
    }

    T& operator/ (CGFloat m) {
        m_multiplier /= m;

        return *static_cast<T*>(this);
    }

    T& operator+ (CGFloat c) {
        m_constant += c;

        return *static_cast<T*>(this);
    }

    T& operator- (CGFloat c) {
        m_constant -= c;

        return *static_cast<T*>(this);
    }

    NSLayoutConstraint* operator== (const T &rhs) {
        return [NSLayoutConstraint constraintWithItem:m_item
                                            attribute:m_attribute
                                            relatedBy:NSLayoutRelationEqual
                                               toItem:rhs.m_item
                                            attribute:rhs.m_attribute
                                           multiplier:rhs.m_multiplier
                                             constant:rhs.m_constant];
    }

    NSLayoutConstraint* operator>= (const T &rhs) {
        return [NSLayoutConstraint constraintWithItem:m_item
                                            attribute:m_attribute
                                            relatedBy:NSLayoutRelationGreaterThanOrEqual
                                               toItem:rhs.m_item
                                            attribute:rhs.m_attribute
                                           multiplier:rhs.m_multiplier
                                             constant:rhs.m_constant];
    }

    NSLayoutConstraint* operator<= (const T &rhs) {
        return [NSLayoutConstraint constraintWithItem:m_item
                                            attribute:m_attribute
                                            relatedBy:NSLayoutRelationLessThanOrEqual
                                               toItem:rhs.m_item
                                            attribute:rhs.m_attribute
                                           multiplier:rhs.m_multiplier
                                             constant:rhs.m_constant];
    }

    NSLayoutConstraint* operator== (CGFloat c) {
        return [NSLayoutConstraint constraintWithItem:m_item
                                            attribute:m_attribute
                                            relatedBy:NSLayoutRelationEqual
                                               toItem:nil
                                            attribute:NSLayoutAttributeNotAnAttribute
                                           multiplier:1
                                             constant:c];
    }

    NSLayoutConstraint* operator>= (CGFloat c) {
        return [NSLayoutConstraint constraintWithItem:m_item
                                            attribute:m_attribute
                                            relatedBy:NSLayoutRelationGreaterThanOrEqual
                                               toItem:nil
                                            attribute:NSLayoutAttributeNotAnAttribute
                                           multiplier:1
                                             constant:c];
    }

    NSLayoutConstraint* operator<= (CGFloat c) {
        return [NSLayoutConstraint constraintWithItem:m_item
                                            attribute:m_attribute
                                            relatedBy:NSLayoutRelationLessThanOrEqual
                                               toItem:nil
                                            attribute:NSLayoutAttributeNotAnAttribute
                                           multiplier:1
                                             constant:c];
    }

private:
    id m_item;
    NSLayoutAttribute m_attribute;
    CGFloat m_multiplier;
    CGFloat m_constant;
};

class CLayoutXAxisAnchor final : public CLayoutAnchor<CLayoutXAxisAnchor> {
    using CLayoutAnchor::CLayoutAnchor;
};

class CLayoutYAxisAnchor final : public CLayoutAnchor<CLayoutYAxisAnchor> {
    using CLayoutAnchor::CLayoutAnchor;
};

class CLayoutDimension final : public CLayoutAnchor<CLayoutDimension> {
    using CLayoutAnchor::CLayoutAnchor;
};

template<typename T = NSLayoutConstraint>
static inline void activateConstraints(std::initializer_list<T *> list) API_AVAILABLE(macos(10.10), ios(8.0), tvos(9.0)) {
    std::for_each(list.begin(), list.end(), [](auto item){
        item.active = YES;
    });
}

}

#endif /* _CLayoutAnchor_h */

#endif /* __cplusplus */
