//
//  AppDelegate.m
//  PhotoChango
//
//  Created by Brandon Lucia on 1/12/13.
//  Copyright (c) 2013 Brandon Lucia. All rights reserved.
//

#import "AppDelegate.h"
#import "PhotoChangoMenuController.h"

@implementation AppDelegate

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
   
    // Insert code here to initialize your application
    [PhotoChangoMenuController  DoIt:(self)];
    
}



@end


