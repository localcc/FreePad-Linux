#include <X11/Xlib.h>
#include <pulse/simple.h>
#include <pulse/error.h>
#include <pthread.h>
#include <stdio.h>
#include "wav_file.h"

typedef struct {
	unsigned int keycode;
	const char* path;
} Sound;

typedef struct {
	unsigned int switch_keycode;
	const Sound *sounds;
} Preset;


#include "config.h"
int selected_preset = 0;

/*void* play_sound_thread(void* args) {
	pa_simple* s = (pa_simple*)args[0];
	int key_code = (int)args[1];
	int presets_count = sizeof(settings) / sizeof(settings[0]);
	int i;
	for(i = 0; i < presets_count; i++) {
		if(settings[i].switch_keycode == key_code) {
			selected_preset = i;
			return;
		}
	}
	int sounds_count = sizeof(settings[selected_preset].sounds) / sizeof(settings[selected_preset].sounds[0]);
	for(i = 0; i < sounds_count; i++) {
		if(settings[selected_preset].sounds[i].keycode == key_code) {
			FILE* file = fopen(settings[selected_preset].sounds[i].path, "rb");
			long file_size = 0;
		
			return;
		}
	}
}*/

void main(void) {
	Display* d = XOpenDisplay(NULL);
	Window root = DefaultRootWindow(d);
	Window curFocus;
	int revert;
	XGetInputFocus(d, &curFocus, &revert);
	XSelectInput(d, curFocus, KeyPressMask|KeyReleaseMask|FocusChangeMask);
	int settings_length = sizeof(settings) / sizeof(settings[0]);
	int i = 0;
	printf("%d\n", settings_length);
	for(i = 0; i < settings_length; i++) {
		int sounds_lengths = sizeof(settings[i].sounds) / sizeof(settings[i].sounds[0]);
		int j = 0;
		for(j = 0; j < sounds_lengths; i++) {
			printf("%s\n", settings[i].sounds[j].path);
		}
	}
	pa_simple* s;
	pa_sample_spec ss;
	ss.format = PA_SAMPLE_S16NE;
	ss.channels = 2;
	ss.rate = 48000;

	s = pa_simple_new(NULL, "Freepad", PA_STREAM_PLAYBACK, NULL, "Freepad sound device", &ss, NULL, NULL, NULL);

	while(1) {
		XEvent event;
		XNextEvent(d, &event);
		switch(event.type) {
			case FocusOut:
				printf("Focus changed!\n");
				if(curFocus != root)
					XSelectInput(d, curFocus, 0);
				XGetInputFocus(d, &curFocus, &revert);
				if(curFocus == PointerRoot)
					curFocus = root;
				XSelectInput(d, curFocus, KeyPressMask|KeyReleaseMask|FocusChangeMask);
				break;
			case KeyPress:
				printf("Key!\n");
				printf("%d\n", event.xkey.keycode);
				break;
		}
	}

}
