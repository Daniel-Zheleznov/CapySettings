typedef enum CSTokenType {
	CSTokenType_Identifier,
} CSTokenType;

typedef struct CSToken {
	int         start_position;
	int         length;
	CSTokenType type;
} CSToken;

static int TokenizeWithNull(char* string, CapySettings* p_CapySettings) {
}

int CapySettings_ReadString(char* string, int length, CapySettings* p_CapySettings) {
	if (length <= 0) {
		int result = TokenizeWithNull(string, p_CapySettings);
		if (result != 0) return result;
	}
}

void CapySettings_PrintSettings(CapySettings settings) {}