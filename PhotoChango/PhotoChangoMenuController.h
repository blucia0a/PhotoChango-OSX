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
extern float toneSets[100][10];

@interface PhotoChangoMenuController : NSObject
{
    
   
    
    NSMatrix *radioMatrix;

    NSTextField *toneFileField;

    NSPathControl *filePath;
    
    NSMatrix *toneSet;
    
}
- (IBAction)toneSetSelected:(id)sender;
- (IBAction)applySelectedToneSet:(id)sender;

- (IBAction)saveToneFile:(id)sender;
- (IBAction)loadToneFile:(id)sender;
- (IBAction)goFullScreen:(id)sender;
- (void) reTuneEmitter:(int)which toTone:(float)tone;


+ (void)DoIt:(id)sender;
+ (void) doRetune:(int)which toTone:(int)tone;


- (IBAction)cellChanged:(id)sender;
- (IBAction)FreqSelected:(NSComboBox *)sender;

@property (assign) IBOutlet NSMatrix *radioMatrix;

@property (copy) IBOutlet NSTextField *toneFileField;

@property (assign) IBOutlet NSPathControl *filePath;
@property (assign) IBOutlet NSMatrix *toneSet;
@end
