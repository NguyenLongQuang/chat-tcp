#include <stdio.h>
#include "group_chat.h"

int main(int argc, char** argv)
{
#ifdef GROUP_CHAT
	printf("["FEATURE"] Hello from client!\n");
#endif
}
