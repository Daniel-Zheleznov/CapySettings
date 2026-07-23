#include "CapySettings.h"

int main(void) {
	CapySettings settings;
	CSErrorType error = CapySettings_Init(&settings);

	error = CapySettings_ReadString("hello: u8 = 'w'", 0, &settings);
	CapySettings_PrintSettings(settings);

	error = CapySettings_DeInit(&settings);

	return 0;
}