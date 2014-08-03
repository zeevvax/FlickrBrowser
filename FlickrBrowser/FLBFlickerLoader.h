//
//  FLBFlickerLoader.h
//  FlickrBrowser
//
//  Created by Zeev Vax on 8/2/14.
//  Copyright (c) 2014 Zeev Vax. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FLBFlickerLoader : NSObject
- (void)loadPicturesWithCompletionBlock:(void (^)(NSArray *picturesURL, NSError *error))completionBlock;
@end
