#ifndef _LIBRETRO_DOSBOX_H
#define _LIBRETRO_DOSBOX_H

#include <libco.h>
#include <string>
#include <stdint.h>
#include "config.h"
#include "libretro.h"

# define RETROLOG(msg) printf("%s\n", msg)

#ifdef __CELLOS_LV2__
#include <math.h>
#include <sys/time.h>
#include <sys/sys_time.h>
#include <sys/timer.h>
#include <dirent.h>
#include <sys/cdefs.h>
#include <ctype.h>
#include <sys/stat.h>
#define S_IREAD S_IRUSR
#define S_IWRITE S_IWUSR
#define	F_OK		0	/* test for existence of file */
#define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#define getenv(a)	"/dev_hdd0/SSNE10000/USRDIR/cores/"
#define	getcwd(a,b)	"/dev_hdd0/SSNE10000/USRDIR/"
struct timeb {
    time_t          time;
    unsigned short  millitm;
    short           timezone;
    short           dstflag;
};
char *dirname(char *path);
int gettimeofday(struct timeval* tv, void* /*tz*/);
int access(char *fpath, int /*mode*/);
#endif

enum core_timing_mode {
    CORE_TIMING_UNSYNCED,
    CORE_TIMING_MATCH_FPS,
    CORE_TIMING_SYNCED
};

extern retro_video_refresh_t video_cb;
extern retro_audio_sample_batch_t audio_batch_cb;
extern retro_input_poll_t poll_cb;
extern retro_input_state_t input_cb;
extern retro_environment_t environ_cb;
extern cothread_t emuThread;
extern cothread_t mainThread;
extern core_timing_mode core_timing;
extern float dosbox_aspect_ratio;
extern Bit8u dosbox_framebuffers[2][1024 * 768 * 4];
extern Bit8u *dosbox_frontbuffer;
extern bool dosbox_frontbuffer_uploaded;

bool update_dosbox_variable(bool autoexec, std::string section_string, std::string var_string, std::string val_string);

#endif
