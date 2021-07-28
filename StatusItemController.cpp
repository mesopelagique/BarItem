//
//  StatusItemController.cpp
//  StatusItem
//
//  Created by Eric Marchand on 28/07/2021.
//

#include "StatusItemController.h"
#include "C_TEXT.h"

namespace ExecuteInProcess
{
    PA_Unichar* methodName;
    void call()
    {
        PA_long32 methodID = PA_GetMethodID(methodName);
        if (methodID>0) {
            PA_Variable parameters[0];
            PA_ExecuteMethodByID(methodID, parameters, 0);
        }
        // or
        // PA_Unistring key = PA_CreateUnistring(&methodName[0]);
        // PA_ExecuteMethod(&key);
    }
}

@implementation StatusItemController

@synthesize methodName;
@synthesize image;
@synthesize statusItem;

+ (id)shared
{
    static StatusItemController *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

- (void) setup {
    if([self.methodName length] == 0) {
        [self uninstall];
    } else {
        [self install];
    }
}

- (void) install {
    if(self.statusItem==nil) {
        self.statusItem = [[[NSStatusBar systemStatusBar] statusItemWithLength: NSSquareStatusItemLength] retain];
        self.statusItem.button.appearsDisabled = NO;
        self.statusItem.button.menu = nil;
        self.statusItem.button.target = self;
        self.statusItem.button.action = @selector(clicked:);
        [self.statusItem.button sendActionOn: NSEventMaskLeftMouseDown | NSEventMaskLeftMouseUp | NSEventMaskRightMouseDown| NSEventMaskRightMouseUp];
        NSLog(@"Status menu item created");
    }
    
    self.statusItem.button.image = self.image;
    // self.statusItem.button.imageScaling = NSImageScaleAxesIndependently; // comment to let user defined size
}

- (void) uninstall {
    if (self.statusItem) {
        [[NSStatusBar systemStatusBar] removeStatusItem: self.statusItem];
        self.statusItem = nil;
    }
}

- (void) clicked:(NSButton *)sender {
    NSLog(@"Status menu item clicked");
    C_TEXT methodNameText;
    methodNameText.setUTF16String(self.methodName);
    ExecuteInProcess::methodName = const_cast<PA_Unichar*>(methodNameText.getUTF16StringPtr());
    PA_NewProcess((void *) ExecuteInProcess::call, 0, (PA_Unichar *)"$\0s$\0t\0a\0t\0u\0s\0");
}

@end
