//
//  ViewController.h
//  VRKitExample
//
//  Created by Jatupon Sukkasem on 4/10/17.
//  Copyright © 2017 Jatupon Sukkasem. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VRKit/VRKit-Swift.h"

@interface ViewController : UIViewController <VRPlayerDelegate, VRAdDelegate> {
    IBOutlet VRPlayer *player;
    IBOutlet UITextView *log;
    IBOutlet NSLayoutConstraint *logHeight;
    IBOutlet UIButton *startAdButton;
}

- (IBAction)startAd: (id)sender;

@end

