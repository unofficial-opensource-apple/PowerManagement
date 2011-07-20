/*
 * Copyright (c) 2009 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/* BatteryFakerWindowController */

// Attempt to silence a bunch of bogus warnings generated by ImageCapture headers
#define __IMAGECAPTURE__


#import <Cocoa/Cocoa.h>
#import "FakeBatteryObject.h"
#import "FakeUPSObject.h"
#import "BatterySnapshotController.h"

@class FakeBatteryObject;
@class FakeUPSObject;

@interface BatteryFakerWindowController : NSWindowController
{
    IBOutlet id BattFakerKEXTStatus;
    IBOutlet id UPSPlugInStatus;
    IBOutlet id snapshotMenuID;
    IBOutlet id activeSnapshotTextID;
    IBOutlet id FCCOverDCTextID;
    IBOutlet id HealthTextID;
    IBOutlet id ConditionTextID;
    
    IBOutlet id BattStatusImage;
    IBOutlet id ACPresentCheck;
    IBOutlet id AmpsCell;
    IBOutlet id BattChargingCheck;
    IBOutlet id BattPercentageSlider;
    IBOutlet id BattPresentCheck;
    IBOutlet id CycleCountCell;
    IBOutlet id DesignCapCell;
    IBOutlet id MaxCapCell;
    IBOutlet id MaxErrCell;
    IBOutlet id VoltsCell;
    IBOutlet id PFStatusCell;
    IBOutlet id ErrorConditionCell;
    IBOutlet id DesignCap0x70Cell;
    IBOutlet id DesignCap0x9CCell;

    BatterySnapshotController   *snapshotController;
    FakeBatteryObject        *batt;
    FakeUPSObject            *ups;
    
    NSImage     *batteryImage[10];
    NSImage     *chargingImage[10];
}

- (NSImage *)batteryImage:(int)i isCharging:(bool)c;

- (IBAction)UIchange:(id)sender;

- (IBAction)kickBatteryMonitorMenu:(id)sender;

- (IBAction)enableMenuExtra:(id)sender;

- (IBAction)disableMenuExtra:(id)sender;

- (IBAction)openEnergySaverMenu:(id)sender;

- (IBAction)snapshotSelectedMenuAction:(id)sender;

- (NSDictionary *)batterySettingsFromWindow;

- (void)updateBatteryUI:(NSDictionary *)newUI;

- (int)runSUIDTool:(char *)loadArg;

- (void)updateKEXTLoadStatus;

- (void)updateUPSPlugInStatus;

- (void)populateSnapshotMenuBar;

- (void)windowWillClose:(NSNotification *)notification;

- (void)setHealthString:(NSString *)healthString;

- (void)setHealthConditionString:(NSString *)healthConditionString;

@end
