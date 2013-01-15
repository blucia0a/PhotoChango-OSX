//
//  PhotoChangoMenuController.h
//  PhotoChango
//
//  Created by Brandon Lucia on 1/12/13.
//  Copyright (c) 2013 Brandon Lucia. All rights reserved.
//

#import <Foundation/Foundation.h>
extern unsigned long SCREEN_WIDTH;
extern unsigned long SCREEN_HEIGHT;
@interface PhotoChangoMenuController : NSObject
{
    
    NSInteger which;
    
    NSMatrix *radioMatrix;
    
}
- (IBAction)goFullScreen:(id)sender;

+ (void)DoIt:(id)sender;
- (IBAction)cellChanged:(id)sender;
- (IBAction)FreqSelected:(NSComboBox *)sender;

@property (assign) IBOutlet NSMatrix *radioMatrix;

@end
