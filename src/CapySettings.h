static typedef enum CSTokenType {
	CSTokenType_Identifier,
} CSTokenType;

static typedef struct CSToken {
	int         start_position;
	int         length;
	CSTokenType type;
} CSToken;

typedef enum CSType {
	CSType_U8,
} CSType;

typedef struct CSName {
	char* name;
	int   length;
} CSName;

typedef union CSValue {
	unsigned char u8;
} CSValue;

typedef struct CSetting {
	CSName  name;
	CSType  type;
	CSValue value;
} CSetting;

typedef struct CapySettings {
	CSetting* settings;
	int       settings_count;
	int       settings_length;

	CSToken* __tokens__;
	int      __token_count__;
	int      __token_length__;
} CapySettings;

// CapySettings_ReadString
//     Reads the string provided and outputs it into a CapySettings struct
// Args:
//   - char* string = string to be read
//   - int length = if length <= 0 { string is null-terminated } else { string is read till length }
//   - CapySettings* p_CapySettings = pointer to uninitalized CapySettings struct
int CapySettings_ReadString(char* string, int length, CapySettings* p_CapySettings);