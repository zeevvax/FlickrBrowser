//
//  FKFlickrPhotosNotesAdd.h
//  FlickrKit
//
//  Generated by FKAPIBuilder on 12 Jun, 2013 at 17:19.
//  Copyright (c) 2013 DevedUp Ltd. All rights reserved. http://www.devedup.com
//
//  DO NOT MODIFY THIS FILE - IT IS MACHINE GENERATED


#import "FKFlickrAPIMethod.h"

typedef enum {
	FKFlickrPhotosNotesAddError_PhotoNotFound = 1,		 /* The photo id passed was not a valid photo id */
	FKFlickrPhotosNotesAddError_UserCannotAddNotes = 2,		 /* The calling user does not have permission to add a note to this photo */
	FKFlickrPhotosNotesAddError_MissingRequiredArguments = 3,		 /* One or more of the required arguments were not supplied. */
	FKFlickrPhotosNotesAddError_MaximumNumberOfNotesReached = 4,		 /* The maximum number of notes for the photo has been reached. */
	FKFlickrPhotosNotesAddError_InvalidSignature = 96,		 /* The passed signature was invalid. */
	FKFlickrPhotosNotesAddError_MissingSignature = 97,		 /* The call required signing but no signature was sent. */
	FKFlickrPhotosNotesAddError_LoginFailedOrInvalidAuthToken = 98,		 /* The login details or auth token passed were invalid. */
	FKFlickrPhotosNotesAddError_UserNotLoggedInOrInsufficientPermissions = 99,		 /* The method requires user authentication but the user was not logged in, or the authenticated method call did not have the required permissions. */
	FKFlickrPhotosNotesAddError_InvalidAPIKey = 100,		 /* The API key passed was not valid or has expired. */
	FKFlickrPhotosNotesAddError_ServiceCurrentlyUnavailable = 105,		 /* The requested service is temporarily unavailable. */
	FKFlickrPhotosNotesAddError_FormatXXXNotFound = 111,		 /* The requested response format was not found. */
	FKFlickrPhotosNotesAddError_MethodXXXNotFound = 112,		 /* The requested method was not found. */
	FKFlickrPhotosNotesAddError_InvalidSOAPEnvelope = 114,		 /* The SOAP envelope send in the request could not be parsed. */
	FKFlickrPhotosNotesAddError_InvalidXMLRPCMethodCall = 115,		 /* The XML-RPC request document could not be parsed. */
	FKFlickrPhotosNotesAddError_BadURLFound = 116,		 /* One or more arguments contained a URL that has been used for abuse on Flickr. */

} FKFlickrPhotosNotesAddError;

/*

Add a note to a photo. Coordinates and sizes are in pixels, based on the 500px image size shown on individual photo pages.


Response:

<note id="1234" />

*/
@interface FKFlickrPhotosNotesAdd : NSObject <FKFlickrAPIMethod>

/* The id of the photo to add a note to */
@property (nonatomic, strong) NSString *photo_id; /* (Required) */

/* The left coordinate of the note */
@property (nonatomic, strong) NSString *note_x; /* (Required) */

/* The top coordinate of the note */
@property (nonatomic, strong) NSString *note_y; /* (Required) */

/* The width of the note */
@property (nonatomic, strong) NSString *note_w; /* (Required) */

/* The height of the note */
@property (nonatomic, strong) NSString *note_h; /* (Required) */

/* The description of the note */
@property (nonatomic, strong) NSString *note_text; /* (Required) */


@end
