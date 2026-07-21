int TokenizeWithNull(char* string, CapySettings* p_CapySettings) {}

int CapySettings_ReadString(char* string, int length, CapySettings* p_CapySettings) {
	TokenizeWithNull(string, p_CapySettings);
}