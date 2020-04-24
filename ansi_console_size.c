void get_console_size(int* w, int* h)
{
	printf("\033[2J");
	puts("Resize and Press enter twice");

	printf("\033[30m\033[999;999H");
	printf("\033[6n");

	scanf("\033[%d;%dR",h,w);
}
