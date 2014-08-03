//
//  FLBPicturesViewController.m
//  FlickrBrowser
//
//  Created by Zeev Vax on 8/3/14.
//  Copyright (c) 2014 Zeev Vax. All rights reserved.
//

#import "FLBPicturesViewController.h"
#import "FLBFlickerLoader.h"
#import "FLBCollectionViewCell.h"

@interface FLBPicturesViewController () <UICollectionViewDataSource, UICollectionViewDelegate, UICollectionViewDelegateFlowLayout>
@property (nonatomic, strong) FLBFlickerLoader *flickrLoader;
@property (nonatomic, strong) NSMutableArray *picturesURL;
@property (weak, nonatomic) IBOutlet UICollectionView *collectionView;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *activityIndicator;
@property (nonatomic, strong) NSOperationQueue *pictureLoaderQueue;
@end

@implementation FLBPicturesViewController

-(id)initWithCoder:(NSCoder *)decoder
{
    self = [super initWithCoder:decoder];
    if (self) {
        // Custom initialization
        _flickrLoader = [FLBFlickerLoader new];
        _pictureLoaderQueue = [[NSOperationQueue alloc] init];
    }
    return self;

}

-(void)dealloc
{
    [self.pictureLoaderQueue cancelAllOperations];
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.navigationController.navigationBarHidden = YES;
    [self.activityIndicator startAnimating];
    __weak FLBPicturesViewController  *weakSelf = self;
    [self.flickrLoader loadPicturesWithCompletionBlock:^(NSArray *picturesURL, NSError *error)
    {
        __strong FLBPicturesViewController *strongSelf = weakSelf;
        strongSelf.picturesURL = [picturesURL mutableCopy];
        [strongSelf.collectionView reloadData];
        [strongSelf.activityIndicator stopAnimating];
    }];
}

#pragma mark - cUICollectionViewDataSource

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    return [self.picturesURL count];
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    FLBCollectionViewCell *cell = [self.collectionView dequeueReusableCellWithReuseIdentifier:@"FLBCollectionViewCell" forIndexPath:indexPath];
    cell.imageView.image = nil;
    NSURL *url = self.picturesURL[indexPath.row];
    
    NSURLRequest *request = [NSURLRequest requestWithURL:url];
    [NSURLConnection sendAsynchronousRequest:request
                                       queue:self.pictureLoaderQueue //[NSOperationQueue mainQueue]
                           completionHandler:^(NSURLResponse *response, NSData *data, NSError *error)
    {
        dispatch_async(dispatch_get_main_queue(), ^{
            UIImage *image = [[UIImage alloc] initWithData:data];
            cell.imageView.image = image;
        });
    }];

    return cell;
}

#pragma mark - UICollectionViewDelegateFlowLayout
-(CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath {
    return self.collectionView.frame.size;
}

@end
