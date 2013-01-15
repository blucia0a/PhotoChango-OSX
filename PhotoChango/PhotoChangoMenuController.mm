//
//  PhotoChangoMenuController.m
//  PhotoChango
//
//  Created by Brandon Lucia on 1/12/13.
//  Copyright (c) 2013 Brandon Lucia. All rights reserved.
//

#import "PhotoChangoMenuController.h"
void Changomain(int argc, char **argv);
void tune(int which, float freq);
void handleFullScreen();
static NSDictionary *toneMap;

@implementation PhotoChangoMenuController
//@synthesize radioMatrix;


+ (void)DoIt:(id)sender{
    
    fprintf(stderr,"HI HI HI HI HI");
   
    NSArray *screenArray = [NSScreen screens];
    NSScreen *mainScreen = [NSScreen mainScreen];
    unsigned long screenCount = [screenArray count];
    
    
    for (unsigned long index = 0; index < screenCount; index++)
    {
        NSScreen *screen = [screenArray objectAtIndex: index];
        NSRect screenRect = [screen visibleFrame];
        NSString *mString = ((mainScreen == screen) ? @"Main" : @"not-main");
        SCREEN_HEIGHT = screenRect.size.height;
        SCREEN_WIDTH = screenRect.size.width;
        //NSLog(@"Screen #%ld (%@) Frame: %@", index, mString, NSStringFromRect(screenRect));
    }
    
    toneMap = [[NSDictionary alloc] initWithObjectsAndKeys:
    [NSNumber numberWithDouble: 32.7032], @"C1",
    [NSNumber numberWithDouble: 34.6478], @"C#1",
    [NSNumber numberWithDouble: 36.7081], @"D1",
    [NSNumber numberWithDouble: 38.8909], @"D#1",
    [NSNumber numberWithDouble: 41.2034], @"E1",
    [NSNumber numberWithDouble: 43.6535], @"F1",
    [NSNumber numberWithDouble: 46.2493], @"F#1",
    [NSNumber numberWithDouble: 48.9994], @"G1",
    [NSNumber numberWithDouble: 51.9131], @"G#1",
    [NSNumber numberWithDouble: 55.0000], @"A1",
    [NSNumber numberWithDouble: 58.2705], @"A#1",
    [NSNumber numberWithDouble: 61.7354], @"B1",
    [NSNumber numberWithDouble: 65.4064], @"C2",
    [NSNumber numberWithDouble: 69.2957], @"C#2",
    [NSNumber numberWithDouble: 73.4162], @"D2",
    [NSNumber numberWithDouble: 77.7817], @"D#2",
    [NSNumber numberWithDouble: 82.4069], @"E2",
    [NSNumber numberWithDouble: 87.3071], @"F2",
    [NSNumber numberWithDouble: 92.4986], @"F#2",
    [NSNumber numberWithDouble: 97.9989], @"G2",
    [NSNumber numberWithDouble: 103.8262], @"G#2",
    [NSNumber numberWithDouble: 110.0000], @"A2",
    [NSNumber numberWithDouble: 116.5409], @"A#2",
    [NSNumber numberWithDouble: 123.4708], @"B2",
    [NSNumber numberWithDouble: 130.8128], @"C3",
    [NSNumber numberWithDouble: 138.5913], @"C#3",
    [NSNumber numberWithDouble: 146.8324], @"D3",
    [NSNumber numberWithDouble: 155.5635], @"D#3",
    [NSNumber numberWithDouble: 164.8138], @"E3",
    [NSNumber numberWithDouble: 174.6141], @"F3",
    [NSNumber numberWithDouble: 184.9972], @"F#3",
    [NSNumber numberWithDouble: 195.9977], @"G3",
    [NSNumber numberWithDouble: 207.6523], @"G#3",
    [NSNumber numberWithDouble: 220.0000], @"A3",
    [NSNumber numberWithDouble: 233.0819], @"A#3",
    [NSNumber numberWithDouble: 246.9417], @"B3",
    [NSNumber numberWithDouble: 261.6256], @"C4",
    [NSNumber numberWithDouble: 277.1826], @"C#4",
    [NSNumber numberWithDouble: 293.6648], @"D4",
    [NSNumber numberWithDouble: 311.1270], @"D#4",
    [NSNumber numberWithDouble: 329.6276], @"E4",
    [NSNumber numberWithDouble: 349.2282], @"F4",
    [NSNumber numberWithDouble: 369.9944], @"F#4",
    [NSNumber numberWithDouble: 391.9954], @"G4",
    [NSNumber numberWithDouble: 415.3047], @"G#4",
    [NSNumber numberWithDouble: 440.0000], @"A4",
    [NSNumber numberWithDouble: 466.1638], @"A#4",
    [NSNumber numberWithDouble: 493.8833], @"B4",
               [NSNumber numberWithDouble: 523.2511], @"C5",
               [NSNumber numberWithDouble: 554.3653], @"C#5",
               [NSNumber numberWithDouble: 587.3295], @"D5",
               [NSNumber numberWithDouble: 622.2540], @"D#5",
               [NSNumber numberWithDouble: 659.2551], @"E5",
               [NSNumber numberWithDouble: 698.4565], @"F5",
               [NSNumber numberWithDouble: 739.9888], @"F#5",
               [NSNumber numberWithDouble: 783.9909], @"G5",
               [NSNumber numberWithDouble: 830.6094], @"G#5",
               [NSNumber numberWithDouble: 880.0000], @"A5",
               [NSNumber numberWithDouble: 932.3275], @"A#5",
               [NSNumber numberWithDouble: 987.7666], @"B5",
               [NSNumber numberWithDouble: 1046.5023], @"C6",
               [NSNumber numberWithDouble: 1108.7305], @"C#6",
               [NSNumber numberWithDouble: 1174.6591], @"D6",
               [NSNumber numberWithDouble: 1244.5079], @"D#6",
               [NSNumber numberWithDouble: 1318.5102], @"E6",
               [NSNumber numberWithDouble: 1396.9129], @"F6",
               [NSNumber numberWithDouble: 1479.9777], @"F#6",
               [NSNumber numberWithDouble: 1567.9817], @"G6",
               [NSNumber numberWithDouble: 1661.2188], @"G#6",
               [NSNumber numberWithDouble: 1760.0000], @"A6",
               [NSNumber numberWithDouble: 1864.6550], @"A#6",
               [NSNumber numberWithDouble: 1975.5332], @"B6",
               [NSNumber numberWithDouble: 2093.0045], @"C7",
               [NSNumber numberWithDouble: 2217.4610], @"C#7",
               [NSNumber numberWithDouble: 2349.3181], @"D7",
               [NSNumber numberWithDouble: 2489.0159], @"D#7",
               [NSNumber numberWithDouble: 2637.0205], @"E7",
               [NSNumber numberWithDouble: 2793.8259], @"F7",
               [NSNumber numberWithDouble: 2959.9554], @"F#7",
               [NSNumber numberWithDouble: 3135.9635], @"G7",
               [NSNumber numberWithDouble: 3322.4376], @"G#7",
               [NSNumber numberWithDouble: 3520.0000], @"A7",
               [NSNumber numberWithDouble: 3729.3101], @"A#7",
               [NSNumber numberWithDouble: 3951.0664], @"B7",
               [NSNumber numberWithDouble: 4186.0090], @"C8",
                             nil];
    
    Changomain(0,0);
    
}

- (IBAction)cellChanged:(id)sender {
    which = [[sender selectedCell] tag] - 1;
}

- (IBAction)goFullScreen:(id)sender {
    fprintf(stderr,"IS IT FUCKING GOING?");
    handleFullScreen();
}

- (IBAction)FreqSelected:(NSComboBox *)sender {
    fprintf(stderr,"%ld %f\n",which,[[ toneMap objectForKey:([sender stringValue])] doubleValue] );
    double val = [[ toneMap objectForKey:([sender stringValue])] doubleValue];
    
    int col = which / 5;
    int row = which % 5;
    tune(col * 20 + row*2,val);
    tune(col * 20 + row*2 + 1,val);
    tune(col * 20 + row*2 + 10,val);
    tune(col * 20 + row*2 + 11,val);
    
   
    fprintf(stderr,"%d %d %d %d\n",col*20+row*2, col*20+row*2+1, col*20+row*2+10, col*20+row*2+11);
    
    NSString *a = [sender stringValue];
    
    [[radioMatrix selectedCell] setTitle: a];
    
}




@end
