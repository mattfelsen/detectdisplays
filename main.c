//
//  main.c
//  detectdisplays
//
//  Created by Jeff Kelley on January 20, 2010.
//  Copyright (c) 2010 Regents of The University of Michigan.
//  All Rights Reserved.
//
//  Permission to use, copy, modify, and distribute this software and its
//  documentation for any purpose and without fee is hereby granted, provided
//  that the above copyright notice appears in all copies and that both that
//  copyright notice and this permission notice appear in supporting
//  documentation, and that the name of The University of Michigan not be used
//  in advertising or publicity pertaining to distribution of the software
//  without specific, written prior permission. This software is supplied as is
//  without expressed or implied warranties of any kind.
//
//  Campus Computing Sites
//  The University of Michigan
//  c/o Jeff Kelley
//  B622A Michigan Union
//  530 S. State St.
//  Ann Arbor, MI 48109
//

#include <ApplicationServices/ApplicationServices.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/IOTypes.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_DISPLAYS    16

int main ( int argc, const char * argv[])
{
    CGDirectDisplayID displays[ MAX_DISPLAYS ];
    CGDisplayCount    displayCount = 0;
    
    CGDisplayErr err =
    CGGetOnlineDisplayList( MAX_DISPLAYS, displays, &displayCount );
    
    if ( err == kCGErrorSuccess ) {
        int i;
        
        for ( i = 0; i < displayCount; i++ ) {
            io_service_t service = CGDisplayIOServicePort( displays[ i ]);
            
            if ( service )
                IOServiceRequestProbe( service, kIOFBUserRequestProbe );
        }
    } else {
        fprintf( stderr, "CGGetOnlineDisplayList returned error code %d\n",
                 ( int )err );
        return ( int )err;
    }

    
    return EXIT_SUCCESS;
}
