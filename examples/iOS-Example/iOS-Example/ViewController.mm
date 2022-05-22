//
//  ViewController.mm
//  iOS-Example
//
//  Created by lvv.me on 2022/5/19.
//

#import "ViewController.h"
@import CAutoLayoutDSL;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    UIView *blueView = [[UIView alloc] init];
    blueView.backgroundColor = UIColor.blueColor;
    [self.view addSubview:blueView];
    blueView.translatesAutoresizingMaskIntoConstraints = NO;

    UIView *redView = [[UIView alloc] init];
    redView.backgroundColor = UIColor.redColor;
    [self.view addSubview:redView];
    redView.translatesAutoresizingMaskIntoConstraints = NO;

    UIView *yellowView = [[UIView alloc] init];
    yellowView.backgroundColor = UIColor.yellowColor;
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


@end
