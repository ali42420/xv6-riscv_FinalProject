#ifndef _PINFO_H_
#define _PINFO_H_

#define NPROC 64

struct proc_info {
    int pid;             // شناسه فرآیند
    int state;           // وضعیت فرآیند (UNUSED, USED, SLEEPING, ...)
    int priority;        // اولویت فرآیند (برای بخش دوم)
    int tickets;         // تعداد بلیت‌ها (برای بخش سوم)
    char name[16];       // نام فرآیند
};

struct pinfo {
    struct proc_info procs[NPROC];
    int proc_count;      // تعداد کل فرآیندهای فعال یا موجود سیستم
};

#endif
