//
//  StatusItemController.h
//  StatusItem
//
//  Created by Eric Marchand on 28/07/2021.
//

#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#import <Cocoa/Cocoa.h>

@interface StatusItemController : NSObject

@property (atomic, retain) NSStatusItem* statusItem;
@property (atomic, retain) NSString* methodName;
@property (atomic, retain) NSImage* image;

+ (id)shared;
- (void) setup;
- (void) install;
- (void) uninstall;
- (void) clicked:(NSButton *)sender;

@end

#endif /* MENU_CONTROLLER_H */
