//
//  TSXPatternInputView.h
//  TransmitSecurity
//
//  Created by Renana Alexandron on 9/10/14.
//  Copyright (c) 2014 TransmitSecurity. All rights reserved.
//

@class TSXPatternInput;
@class TSXUIStyle;

@protocol TSXPatternInputViewDelegate <NSObject>

-(void)patternInputView:(id _Nonnull )sender drawingCompleteWithPattern:(TSXPatternInput*_Nonnull)pattern;
-(void)patternInputViewStartedPattern:(id _Nonnull )sender;

@end


@interface TSXPatternInputView : UIView

@property NSUInteger nDotsHorizontal;
@property NSUInteger nDotsVertical;
@property CGFloat internalSpacingHorizontal;
@property CGFloat internalSpacingVertical;

@property CGFloat dotSize;
@property CGFloat touchRadius;
@property CGFloat dotCenterSize;
@property CGFloat dotStrokeWidth;
@property (nonatomic, nullable) UIColor* dotStrokeColor;
@property (nonatomic, nullable) UIColor* dotFillOnTouchColor;
@property (nonatomic, nullable) UIColor* dotFillColor;
@property (nonatomic, nullable) UIColor* dotInnerFillColor;
@property BOOL centerIsFilled;

@property (nonatomic, nullable, strong) NSNumber* connectorWidth;
@property (nonatomic, nullable, strong) UIColor* connectorColor;

@property (nonatomic, nullable, weak) id<TSXPatternInputViewDelegate> delegate;
@property (nonatomic, assign, getter=isDisabled) BOOL disable;

@property (readonly, nullable) TSXPatternInput *currentInput;

- (void)clearDotsAnimated:(BOOL)animated withDelay:(NSTimeInterval)delay completion:(void (^ __nullable)(void))completion;



@end
