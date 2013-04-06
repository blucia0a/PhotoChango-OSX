//
//  PhotoChangoMenuController.m
//  PhotoChango
//
//  Created by Brandon Lucia on 1/12/13.
//  Copyright (c) 2013 Brandon Lucia. All rights reserved.
//

#import "PhotoChangoMenuController.h"
#import "AppDelegate.h"

void Changomain(int argc, char **argv, int width, int height);
void tune(int which, float freq);
void tuneToToneSet(int which);
void handleFullScreen();
void processToneFileOpen(const char *string, int index);
void processToneFileSave(const char *string, int index);

static NSDictionary *toneMap;


@implementation PhotoChangoMenuController
@synthesize radioMatrix;// = _radioMatrix;
@synthesize toneFileField;// = _toneFileField;
@synthesize toneSet;// = _toneSet;
@synthesize filePath;// = _filePath;



+ (void)DoIt:(id)sender{
   
    NSArray *screenArray = [NSScreen screens];
    
    //unsigned long screenCount = [screenArray count];
    
    

    NSScreen *screen = [screenArray objectAtIndex: 0];
    NSRect screenRect = [screen visibleFrame];
        
    int height = screenRect.size.height;
    int width = screenRect.size.width;
    NSLog(@"Screen #%ld Frame: %@", 0l,  NSStringFromRect(screenRect));

    
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
    
    
    Changomain(0,0, width, height);
    
}


- (IBAction)goFullScreen:(id)sender {
    
    handleFullScreen();
    
}


- (IBAction)applySelectedToneSet:(id)sender {
    
    long tset = [[toneSet selectedCell] tag] - 1;
    
    fprintf(stderr,"got in here with tset = %ld\n",tset);
    int cell = 1;
    
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
        
        float val = toneSets[i*5 + j][tset];
        fprintf(stderr,"the value here is %f\n",val);
        

        int radioTag = cell;
        
       
        NSArray *temp = [toneMap allKeys];
        NSString *actualKey = NULL;
        for( NSString *k in temp){
            
            NSNumber *num = [toneMap objectForKey:k];
            if( [num floatValue] == val){
                
                actualKey = k;
                
                break;
                
            }

        }
        if( actualKey != NULL){

            [[radioMatrix cellWithTag: (radioTag)] setTitle: actualKey];
            
        }
            
        cell++;
        }

    }

    tuneToToneSet((int)tset);
    
    
    
}

- (IBAction)saveToneFile:(id)sender {
    
    int cell = (int)[[toneSet selectedCell] tag] - 1;
    fprintf(stderr,"here1\n");
    for(int i = 0; i < 25; i++){
    
        fprintf(stderr,"here2\n");
        
        int radioTag = i + 1;
        fprintf(stderr,"here2.1 %d\n", radioTag);
        
        NSString *radioLab = [[radioMatrix cellWithTag:radioTag] title];
        
      
        
        float val = [[toneMap objectForKey:radioLab] floatValue];
        
      
        
      
        
        int col = i / 5;
        int row = i % 5;

        toneSets[col * 5 + row][cell] = val;
     
        
    }
    
    fprintf(stderr,"here3 and cell was %d\n",cell);
    NSSavePanel *panel = [NSSavePanel savePanel];
    NSInteger clicked = [panel runModal];
    if( clicked == NSFileHandlingPanelOKButton ){
        
        
        NSString *thePath = [panel filename];
        
        [[toneSet selectedCell] setTitle:thePath];
            
        processToneFileSave([thePath cStringUsingEncoding:NSStringEncodingConversionAllowLossy], cell);
        processToneFileOpen([thePath cStringUsingEncoding:NSStringEncodingConversionAllowLossy], cell);
        
        
    }

    
}

- (IBAction)loadToneFile:(id)sender {
    
    NSOpenPanel *panel = [NSOpenPanel openPanel];
    [panel setCanChooseFiles:YES];
    [panel setCanChooseDirectories:NO];
    [panel setAllowsMultipleSelection:NO];
    NSInteger clicked = [panel runModal];
    if( clicked == NSFileHandlingPanelOKButton ){
        
        for(NSURL *url in [panel URLs]){
            
            NSString *thePath = [url path];
            
            [[toneSet selectedCell] setTitle:thePath];
            
            processToneFileOpen([thePath cStringUsingEncoding:NSStringEncodingConversionAllowLossy], (int)[[toneSet selectedCell] tag] - 1);
            
        }
        
    }
    

    
}




- (void) reTuneEmitter:(int)who toTone:(float)tone {
    
    fprintf(stderr,"Setting %d to %f",who,tone);
    NSNumber *n = [NSNumber numberWithFloat:tone];
    NSArray *temp = [toneMap allKeysForObject:(n)];
    NSString *key = [temp objectAtIndex:0];
    
    [[radioMatrix cellWithTag: who] setTitle: key];
    
}



- (IBAction)FreqSelected:(NSComboBox *)sender {
    
    int which = (int)[[radioMatrix selectedCell] tag] - 1;
    
    fprintf(stderr,"which is %d\n",which);
    
    double val = [[ toneMap objectForKey:([sender stringValue])] doubleValue];
    
    fprintf(stderr,"setting to %lf\n",val);
    
    int col = which / 5;
    int row = which % 5;
    
    fprintf(stderr,"tune() w/ col = %d, row = %d\n",col,row);
    
    tune(col * 5 + row, (float)val);
    
    fprintf(stderr,"and setting that little label to ");
    
    NSString *a = [sender stringValue];
    
    
    [[radioMatrix selectedCell] setTitle: a];
    
}




@end
