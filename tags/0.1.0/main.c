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
    }

    
    return EXIT_SUCCESS;
}
