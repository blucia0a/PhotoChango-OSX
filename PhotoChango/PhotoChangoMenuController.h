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
    
    NSTextField *midiFileLabel;
    
    NSMatrix *radioMatrix;

    NSTextField *toneFileField;

    NSPathControl *filePath;
    
    NSMatrix *toneSet;
    
    __weak NSSlider *_amplitudeThresholdSlider;
    
    __weak NSTextField *_thresholdLabel;
    __weak NSTextFieldCell *_midiInputLabel;
}
- (IBAction)setMIDICaptureFile:(id)sender;
- (IBAction)applyMIDICaptureFile:(id)sender;

- (IBAction)sliderChange:(id)sender;
- (IBAction)applySelectedToneSet:(id)sender;
- (IBAction)saveToneFile:(id)sender;
- (IBAction)loadToneFile:(id)sender;
- (IBAction)goFullScreen:(id)sender;
- (void) reTuneEmitter:(int)who toTone:(float)tone;
- (IBAction)FreqSelected:(NSComboBox *)sender;


+ (void)DoIt:(id)sender;


@property (strong) IBOutlet NSMatrix *radioMatrix;
@property (strong) IBOutlet NSTextField *toneFileField;
@property (strong) IBOutlet NSPathControl *filePath;
@property (strong) IBOutlet NSMatrix *toneSet;



@property (weak) IBOutlet NSSlider *amplitudeThresholdSlider;
@property (weak) IBOutlet NSTextField *thresholdLabel;
@property (weak) IBOutlet NSTextField *midiFileLabel;
@property (weak) IBOutlet NSTextFieldCell *midiInputLabel;
@end
