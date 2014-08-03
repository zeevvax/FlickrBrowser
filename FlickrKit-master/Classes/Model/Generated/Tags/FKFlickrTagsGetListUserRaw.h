//
//  FKFlickrTagsGetListUserRaw.h
//  FlickrKit
//
//  Generated by FKAPIBuilder on 12 Jun, 2013 at 17:19.
//  Copyright (c) 2013 DevedUp Ltd. All rights reserved. http://www.devedup.com
//
//  DO NOT MODIFY THIS FILE - IT IS MACHINE GENERATED


#import "FKFlickrAPIMethod.h"

typedef enum {
	FKFlickrTagsGetListUserRawError_UserNotFound = 1,		 /* The calling user was not logged in. */
	FKFlickrTagsGetListUserRawError_InvalidAPIKey = 100,		 /* The API key passed was not valid or has expired. */
	FKFlickrTagsGetListUserRawError_ServiceCurrentlyUnavailable = 105,		 /* The requested service is temporarily unavailable. */
	FKFlickrTagsGetListUserRawError_FormatXXXNotFound = 111,		 /* The requested response format was not found. */
	FKFlickrTagsGetListUserRawError_MethodXXXNotFound = 112,		 /* The requested method was not found. */
	FKFlickrTagsGetListUserRawError_InvalidSOAPEnvelope = 114,		 /* The SOAP envelope send in the request could not be parsed. */
	FKFlickrTagsGetListUserRawError_InvalidXMLRPCMethodCall = 115,		 /* The XML-RPC request document could not be parsed. */
	FKFlickrTagsGetListUserRawError_BadURLFound = 116,		 /* One or more arguments contained a URL that has been used for abuse on Flickr. */

} FKFlickrTagsGetListUserRawError;

/*

Get the raw versions of a given tag (or all tags) for the currently logged-in user.


Response:

<who id="12037949754@N01">
    <tags>
        <tag clean="foo">
            <raw>foo</raw>
            <raw>Foo</raw>
            <raw>f:oo</raw>
        </tag>
    </tags>
</who>

*/
@interface FKFlickrTagsGetListUserRaw : NSObject <FKFlickrAPIMethod>

/* The tag you want to retrieve all raw versions for. */
@property (nonatomic, strong) NSString *tag;


@end
