//
//  ViewController.mm
//  macOS-Example
//
//  Created by lvv.me on 2022/5/19.
//

#import "ViewController.h"
@import CAutoLayoutDSL;

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    NSView *blueView = [[NSView alloc] init];
    blueView.wantsLayer = YES;
    blueView.layer.backgroundColor = NSColor.blueColor.CGColor;
    [self.view addSubview:blueView];
    blueView.translatesAutoresizingMaskIntoConstraints = NO;

    NSView *redView = [[NSView alloc] init];
    redView.wantsLayer = YES;
    redView.layer.backgroundColor = NSColor.redColor.CGColor;
    [self.view addSubview:redView];
    redView.translatesAutoresizingMaskIntoConstraints = NO;

    NSView *yellowView = [[NSView alloc] init];
    yellowView.wantsLayer = YES;
    yellowView.layer.backgroundColor = NSColor.yellowColor.CGColor;
    [self.view addSubview:yellowView];
    yellowView.translatesAutoresizingMaskIntoConstraints = NO;

    CAutoLayoutDSL::activateConstraints({
        blueView.width == self.view.width * 0.5,
        blueView.height == self.view.height * 0.5,
        blueView.centerX == self.view.centerX,
        blueView.centerY == self.view.centerY,
        redView.width == 50,
        redView.height == 50,
        redView.top == blueView.top,
        redView.right == blueView.left - 10,
        yellowView.width == 50,
        yellowView.height == 50,
        yellowView.top == blueView.top,
        yellowView.left == blueView.right + 10
    });
}


- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}

@end
