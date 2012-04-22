//
//  EvernoteAsyncNoteStore.h
//  evernote-sdk-ios
//
//  Created by Matthew McGlincy on 4/22/12.
//  Copyright (c) 2012 n/a. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ENAPI.h"

@interface EvernoteAsyncNoteStore : ENAPI

// Get an instance, using the shared EvernoteSession.
+ (EvernoteAsyncNoteStore *)noteStore;

// Construct an instance with the given session.
- (id)initWithSession:(EvernoteSession *)session;

// NoteStore sync methods
- (void)getSyncStateWithSuccess:(void(^)(EDAMSyncState *syncState))success 
                        failure:(void(^)(NSError *error))failure;
- (void)getSyncChunkAfterUSN:(int32_t)afterUSN 
                  maxEntries:(int32_t)maxEntries
                fullSyncOnly:(BOOL)fullSyncOnly
                     success:(void(^)(EDAMSyncChunk *syncChunk))success
                     failure:(void(^)(NSError *error))failure;
- (void)getFilteredSyncChunkAfterUSN:(int32_t)afterUSN
                          maxEntries:(int32_t)maxEntries
                              filter:(EDAMSyncChunkFilter *)filter
                             success:(void(^)(EDAMSyncChunk *syncChunk))success
                             failure:(void(^)(NSError *error))failure;
- (void)getLinkedNotebookSyncState:(EDAMLinkedNotebook *)linkedNotebook
                           success:(void(^)(EDAMSyncState *syncState))success
                           failure:(void(^)(NSError *error))failure;

// NoteStore notebook methods
- (void)listNotebooksWithSuccess:(void(^)(NSArray *notebooks))success
                         failure:(void(^)(NSError *error))failure;
- (void)getNotebookWithGuid:(EDAMGuid)guid 
                    success:(void(^)(EDAMNotebook *syncState))success
                    failure:(void(^)(NSError *error))failure;
- (void)getLinkedNotebookSyncChunk:(EDAMLinkedNotebook *)linkedNotebook
                          afterUSN:(int32_t)afterUSN
                        maxEntries:(int32_t) maxEntries
                      fullSyncOnly:(BOOL)fullSyncOnly
                           success:(void(^)(EDAMSyncChunk *syncChunk))success
                           failure:(void(^)(NSError *error))failure;
- (void)getDefaultNotebookWithSuccess:(void(^)(EDAMNotebook *notebook))success
                              failure:(void(^)(NSError *error))failure;
- (void)createNotebook:(EDAMNotebook *)notebook
               success:(void(^)(EDAMNotebook *notebook))success
               failure:(void(^)(NSError *error))failure;
- (void)updateNotebook:(EDAMNotebook *)notebook
               success:(void(^)(int32_t usn))success
               failure:(void(^)(NSError *error))failure;
- (void)expungeNotebookWithGuid:(EDAMGuid)guid
                        success:(void(^)(int32_t usn))success
                        failure:(void(^)(NSError *error))failure;

@end
