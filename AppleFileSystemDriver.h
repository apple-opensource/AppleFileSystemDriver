/* 
 * Copyright (c) 2004 Apple Computer, Inc.  All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
 
#ifdef KERNEL
#ifdef __cplusplus

#include <IOKit/IOService.h>
#include <IOKit/storage/IOMedia.h>
#include <uuid/uuid.h>

/*
 * Class
 */

class AppleFileSystemDriver : public IOService
{
    OSDeclareDefaultStructors(AppleFileSystemDriver)

protected:

    IONotifier *_notifier;
    uuid_t      _uuid;
    OSString   *_uuidString;
    OSString   *_apfsPrebootUUIDString;
    UInt32      _matched;
    
    struct ExpansionData { /* */ };
    ExpansionData * _expansionData;

public:

    virtual bool start(IOService * provider);

    virtual void free();
    
private:

    static bool mediaNotificationHandler(void * target, void * ref,
										 IOService * newService,
										 IONotifier * notifier);
    
    static IOReturn readHFSUUID(IOMedia *media, void **uuidPtr);
        
};

#endif /* KERNEL */
#endif /* __cplusplus */

