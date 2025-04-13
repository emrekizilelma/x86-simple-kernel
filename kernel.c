#define WHITE_TEXT 0X07


void kernel_clear_screen() {
	char* video_ptr = (char* ) 0xb800;
	unsigned int i = 0;
	
	while(i < (80 * 25 * 2)) {
		video_ptr[i] = ' ';
		i++;
		video_ptr[i] = WHITE_TEXT;
		i++;
	}
}

unsigned int kernel_printf(char* message, unsigned int line) {
	char* video_ptr = (char* ) 0xB8000;
	unsigned int i = 0;
	
	i = (line * 80 * 2);
	
	while(*message != 0) {
		if(*message == '\n') {
			line ++;
			i = (line * 80 * 2);
			*message++;
		}

		else {
			video_ptr[i] = *message;
			*message++;
			i++;
			video_ptr[i] = WHITE_TEXT;
			i++;
		}
	}

	return 1;
}

void kernel_main() {
	kernel_clear_screen();
	kernel_printf("Hello World!", 0);
}
