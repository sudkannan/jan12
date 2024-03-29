/*
 * Copyright 2008 The Native Client Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can
 * be found in the LICENSE file.
 */

/*
 * Wrapper for syscall.
 */

#include <stdio.h>
#include <stdlib.h>

#include <errno.h>
#include <sys/types.h>
#include <sys/nacl_syscalls.h>

#include "native_client/src/untrusted/nacl/syscall_bindings_trampoline.h"

int imc_mem_obj_create(size_t nbytes) {
  int retval = NACL_SYSCALL(imc_mem_obj_create)(nbytes);
  if (retval < 0) {
    errno = -retval;
    return -1;
  }

  fprintf(stderr, "ENTERING imc_mem_obj_create %d\n", retval);

  return retval;
}

//NVRAM chnages
unsigned long imc_nvram_obj_create(size_t nbytes) {


  unsigned long retval = NACL_SYSCALL(imc_nvram_obj_create)(nbytes);
  if (retval == 0) {
    errno = -retval;
    return 0;
  }

  printf("ENTERING imc_mem_obj_create, DUMMY FUNCTION %lu\n", retval);

  return retval;
  
}
//NVRAM changes
