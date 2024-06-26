//
//  MCLock.h
//  mailcore2
//
//  Created by Hoa V. DINH on 1/23/15.
//  Copyright (c) 2015 MailCore. All rights reserved.
//

#ifndef mailcore2_MCLock_h
#define mailcore2_MCLock_h

#if __APPLE__

#include <libkern/OSAtomic.h>

#define MC_LOCK_TYPE os_unfair_lock
#define MC_LOCK_INITIAL_VALUE OS_UNFAIR_LOCK_INIT
#define MC_LOCK(l) os_unfair_lock_lock(l)
#define MC_UNLOCK(l) os_unfair_lock_unlock(l)

#else

#include <pthread.h>

#define MC_LOCK_TYPE pthread_mutex_t
#define MC_LOCK_INITIAL_VALUE PTHREAD_MUTEX_INITIALIZER
#define MC_LOCK(l) pthread_mutex_lock(l)
#define MC_UNLOCK(l) pthread_mutex_unlock(l)

#endif

#endif
