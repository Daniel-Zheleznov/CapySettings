typedef enum CSTokenType CSTokenType;
typedef struct CSToken CSToken;

typedef enum CSErrorType {
	CSErrorType_None,
} CSErrorType;

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

	CSetting* left;
	CSetting* right;
} CSetting;

typedef struct CapySettings {
	int         initalized_flag;

	CSErrorType error;
	int         line_count;
	int         position_in_line;

	CSetting*   settings;
	int         settings_count;
} CapySettings;

// CapySettings_Init
//     Initalizes a CapySettings struct
// Args:
//   - CapySettings* p_settings = pointer to an unintialized CapySettings struct
// Returns:
//   - CSErrorType
CSErrorType CapySettings_Init(CapySettings* p_settings);

// CapySettings_ReadString
//     Reads the string provided and outputs it into a CapySettings struct
// Args:
//   - char* string = string to be read
//   - int length = if length <= 0 { string is null-terminated } else { string is read till length }
//   - CapySettings* p_settings = pointer to a CapySettings struct
// Returns:
//   - CSErrorType
CSErrorType CapySettings_ReadString(char* string, int length, CapySettings* p_settings);

// CapySettings_PrintSettings
//     Prints all settings saved into the struct
// Args:
//   - CapySettings settings = CapySettings struct to read from
void CapySettings_PrintSettings(CapySettings settings);

// CapySettings_PrintSettings
//     Prints error within the CapySettings struct
// Args:
//   - CapySettings settings = CapySettings struct to read from
void CapySettings_PrintError(CapySettings settings);

// CapySettings_DeInit
//     Deinitalized a CapySettings struct
// Args:
//   - CapySettings* p_settings = pointer to an CapySettings struct
// Returns:
//   - CSErrorType
CSErrorType CapySettings_DeInit(CapySettings* p_settings);