#include "kernel/types.h"
#include "kernel/param.h"
#include "user/user.h"
#include "kernel/pinfo.h"

int main(int argc, char *argv[])
{
    struct pinfo info;
    
    // فراخوانی سیستم‌کالی که در گام‌های قبلی ساختیم
    if(getpinfo(&info) < 0) {
        printf("ps: failed to get process info\n");
        exit(1);
    }

    // چاپ هدر جدول
    printf("PID\tSTATE\t\tPRIO\tTICKETS\tNAME\n");
    
    // حلقه برای چاپ اطلاعات تک‌تک فرآیندها
    for(int i = 0; i < info.proc_count; i++) {
        char *state_str;
        
        // تبدیل وضعیت عددی فرآیند به متن قابل فهم
        switch(info.procs[i].state) {
            case 0: state_str = "UNUSED"; break;
            case 1: state_str = "USED"; break;
            case 2: state_str = "SLEEPING"; break;
            case 3: state_str = "RUNNABLE"; break;
            case 4: state_str = "RUNNING"; break;
            case 5: state_str = "ZOMBIE"; break;
            default: state_str = "UNKNOWN"; break;
        }

        // چاپ اطلاعات به صورت ستونی
        printf("%d\t%s\t\t%d\t%d\t%s\n", 
               info.procs[i].pid, 
               state_str, 
               info.procs[i].priority, 
               info.procs[i].tickets, 
               info.procs[i].name);
    }
    
    exit(0);
}

