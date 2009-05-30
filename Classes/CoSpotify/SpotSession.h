//
//  SpotSession.h
//  Spot
//
//  Created by Joachim Bengtsson on 2009-05-16.
//  Copyright 2009 Third Cog Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "despotify.h"
#import "SpotPlayer.h"
#import "SpotURI.h"
#import "SpotItem.h"

@class SpotArtist;
@class SpotAlbum;
@class SpotTrack;

@interface SpotSession : NSObject {
	struct despotify_session *session;
	BOOL loggedIn;
  
  SpotPlayer *player;
  
  NSMutableDictionary *cache;
}
+(SpotSession*)defaultSession;
-(void)cleanup;

-(BOOL)authenticate:(NSString *)user password:(NSString*)password error:(NSError**)error;

-(NSArray*)playlists;

-(SpotArtist *)artistById:(NSString *)id_;
-(void *)imageById:(NSString*)id;
-(SpotAlbum *)albumById:(NSString *)id;
-(SpotTrack *)trackById:(NSString *)id;

-(SpotAlbum*)albumByURI:(SpotURI*)uri;
-(SpotArtist*)artistByURI:(SpotURI*)uri;
-(SpotTrack*)trackByURI:(SpotURI*)uri;
-(SpotPlaylist*)playlistByURI:(SpotURI*)uri;
-(SpotSearch*)searchByURI:(SpotURI*)uri;

-(SpotItem *)cachedItemId:(NSString *)id ensureFullProfile:(BOOL)full;

@property (nonatomic, readonly) BOOL loggedIn;
@property (readonly) NSString *username;
@property (readonly) NSString *country;
@property (readonly) NSString *accountType;
@property (readonly) NSDate *expires;
@property (readonly) NSString *serverHost;
@property (readonly) NSUInteger serverPort;
@property (readonly) NSDate *lastPing;
@property (readonly) SpotPlayer *player;

@property (readonly) struct despotify_session *session;
@end

extern NSString *SpotSessionErrorDomain;
typedef enum {
	SpotSessionErrorCodeDefault = 1
} SpotSessionErrorCode;
