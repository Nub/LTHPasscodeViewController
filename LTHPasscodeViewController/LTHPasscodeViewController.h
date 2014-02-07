//
//  PasscodeViewController.h
//  LTHPasscodeViewController
//
//  Created by Roland Leth on 9/6/13.
//  Copyright (c) 2013 Roland Leth. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LTHPasscodeViewControllerDelegate <NSObject>
@optional
// This serves, mostly, as an "update stuff after dismissing"
- (void)passcodeViewControllerWasDismissed;
- (void)maxNumberOfFailedAttemptsReached;
- (void)passcodeWasEnteredSuccessfully;
@end

@interface LTHPasscodeViewController : UIViewController <UITextFieldDelegate>

@property (nonatomic, strong) UIView *coverView;
@property (nonatomic, weak) id<LTHPasscodeViewControllerDelegate> delegate;
@property (assign) BOOL isCurrentlyOnScreen;
@property (nonatomic) UIModalPresentationStyle showPresentationStyle;

- (void)showLockScreenWithAnimation:(BOOL)animated;
- (void)showForEnablingPasscodeInViewController:(UIViewController *)viewController;
- (void)showForChangingPasscodeInViewController:(UIViewController *)viewController;
- (void)showForTurningOffPasscodeInViewController:(UIViewController *)viewController;

- (void)prepareAsLockScreen;
- (void)prepareForChangingPasscode;
- (void)prepareForTurningOffPasscode;
- (void)prepareForEnablingPasscode;

+ (BOOL)passcodeExistsInKeychain;
+ (BOOL)didPasscodeTimerEnd;
+ (void)saveTimerStartTime;
+ (void)deletePasscodeFromKeychain;
+ (CGFloat)timerDuration;
+ (void)setTimerDuration:(float) duration;
+ (CGFloat)timerStartTime;
+ (LTHPasscodeViewController *)sharedUser;

@end