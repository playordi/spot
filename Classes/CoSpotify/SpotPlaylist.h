//
//  SpotPlaylist.h
//  Spot
//
//  Created by Joachim Bengtsson on 2009-05-17.
//  Copyright 2009 Third Cog Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "despotify.h"
#import "SpotItem.h"
#import "SpotTrackList.h"

@class SpotTrack;
@class SpotURI;

//Represents a movable slot in the playlist (mainly so that the same track can live in multiple playlists)
@interface SpotTrackSlot : NSObject
{
  SpotTrack *track;
  SpotPlaylist *playlist;
  NSInteger position;
}


-(id)initWithPlaylist:(SpotPlaylist *)p track:(SpotTrack*)t position:(NSInteger)pos;

@property (readonly) SpotTrack *track;
@property (readonly) SpotPlaylist *playlist;
@property (readonly) NSInteger position;

@end

@interface SpotPlaylist : SpotItem {
  
  NSMutableArray *slots;
  
  NSString *name;
  NSString *author;
  NSString *playlistId;
  BOOL collaborative;
  NSInteger revision;
  NSInteger checksum;
  
}
-(id)initWithPlaylist:(struct playlist*)playlist_;
-(id)initWithName:(NSString *)name author:(NSString *)author tracks:(NSArray*)tracks;

-(SpotTrack*) trackBefore:(SpotTrack*)track;
-(SpotTrack*) trackAfter:(SpotTrack*)track;
-(NSInteger) positionOfTrack:(SpotTrack*)track;
-(SpotTrack *) trackAtPosition:(NSInteger)position;

@property (readonly, retain) NSString *name;
@property (readonly, nonatomic) NSString *author;
@property (readonly, nonatomic) BOOL collaborative;
@property (readonly, nonatomic) NSArray *tracks;

@end

@interface SpotMutablePlaylista : SpotPlaylist {

}

-(void) addTrack:(SpotTrack*)track;

@end