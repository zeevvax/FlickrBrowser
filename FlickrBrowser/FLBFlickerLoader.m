//
//  FLBFlickerLoader.m
//  FlickrBrowser
//
//  Created by Zeev Vax on 8/2/14.
//  Copyright (c) 2014 Zeev Vax. All rights reserved.
//

#import "FLBFlickerLoader.h"
#import "FlickrKit.h"
@interface FLBFlickerLoader()
@property (nonatomic, retain) FKFlickrNetworkOperation *flickrNetworkOperation;

@end

@implementation FLBFlickerLoader


-(void)dealloc
{
    [self.flickrNetworkOperation cancel];
}

- (void)loadPicturesWithCompletionBlock:(void (^)(NSArray *picturesURL, NSError *error))completionBlock
{
    FKFlickrInterestingnessGetList *interesting = [[FKFlickrInterestingnessGetList alloc] init];
	interesting.per_page = @"50";
	self.flickrNetworkOperation = [[FlickrKit sharedFlickrKit] call:interesting completion:^(NSDictionary *response, NSError *error)
    {
        NSMutableArray *photoURLs = [NSMutableArray new];
        if (response)
        {
            for (NSDictionary *photoDictionary in [response valueForKeyPath:@"photos.photo"]) {
                NSURL *url = [[FlickrKit sharedFlickrKit] photoURLForSize:FKPhotoSizeLarge1024 fromPhotoDictionary:photoDictionary];
                [photoURLs addObject:url];
            }
        }
        else
        {
            NSLog(@"Error: %@", error);
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            if (completionBlock)
                completionBlock(photoURLs, error);

        });
    }];
}
@end
