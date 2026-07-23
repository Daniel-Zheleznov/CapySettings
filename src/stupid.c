typedef struct setting setting;

typedef struct setting {
	char* name;
	char* value;

	setting* left;
	setting* right;
} setting;

typedef struct settings {
	setting* root;
	int count;
} settings;

void AddSetting(settings* p_settings, setting* p_setting) {
	if (p_settings->count <= 0) {
		p_settings->root = p_setting;
		p_settings->count++;
	
	} else {
		setting* p_current = p_settings->root;
	}
}

int main(void) {
	settings main = { .count = 0 };

	setting name = { .name = "name", .value = "Daniel", .left = -1, .right = -1 };
	AddSetting(&main, &name);

	return 0;
}