#include <stdio.h> 
#include <sys/resource.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
  
int main() { 
  
    struct rlimit lim; 
  

    if( getrlimit(RLIMIT_NOFILE, &lim) == 0) 
        printf("Resource limits -> soft limit= %ld \t"
           " hard limit= %ld \n", lim.rlim_cur,  
                               lim.rlim_max); 
    else
        fprintf(stderr, "%s\n", strerror(errno)); 
      
 
    return 0; 
} 

/*
    soft limit: The soft limit is the actual limit enforced by the kernel for the corresponding resource.
    hard limit: The hard limit acts as a ceiling for the soft limit.
*/
