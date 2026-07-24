#include <stdio.h>
#include <string.h>

typedef struct Setting Setting;
typedef struct Setting {
	char* key;
	char* value;

	Setting* left;
	Setting* right;
} Setting;

typedef struct Settings {
	Setting* root;
	int size;
} Settings;

int malloc_counter = 0;

void Settings_Init(Settings* p_settings) {
	p_settings->size = 0;
	p_settings->root = NULL;
}

static Setting* Settings_AddHelper(Settings* p_settings, Setting* p_current, Setting* p_setting) {
	if (p_current == NULL) {
		p_settings->size++;
		return p_setting;
	}

	int comp = strcmp(p_setting->key, p_current->key);
	if (comp < 0) {
		// smaller
		p_current->left = Settings_AddHelper(p_settings, p_current->left, p_setting);
	}
	else if (comp > 0) {
		// larger
		p_current->right = Settings_AddHelper(p_settings, p_current->right, p_setting);
	}
	else {
		p_current->value = p_setting->value;
		free(p_setting);

		malloc_counter--;
		printf("DeAllocated memory, counter: %d", malloc_counter);
	}

	return p_current;
}

void Settings_AddSetting(Settings* p_settings, char* key, char* value) {
	Setting* p_setting = (Setting*) malloc(sizeof(Setting));
	p_setting->key = key;
	p_setting->value = value;
	p_setting->left = NULL;
	p_setting->right = NULL;
	
	malloc_counter++;
	printf("Allocated memory, counter: %d", malloc_counter);
	
	p_settings->root = Settings_AddHelper(p_settings, p_settings->root, p_setting);
}

void Settings_PrintSettings(Settings* p_settings) {}

void Settings_DeInit(Settings* p_settings) {
	Setting* p_parent;
	Setting* p_current = p_setings->root;

	if (p_current->right == NULL && p_current->left == NULL) {
		free(p_current);

		malloc_counter--;
		printf("DeAllocated memory, counter: %d", malloc_counter);

		return;
	}

	// Clean left

	// Clean right
}

int main(void) {

	Settings main;
	Settings_Init(&main);
	Settings_AddSetting(&main, "Name", "Daniel");
	//Settings_AddSetting(&main, "American", "true");
	//Settings_AddSetting(&main, "Birthdate", "2006-05-05");
	//Settings_AddSetting(&main, "CalendarDate", "2026-07-23");
	Settings_PrintSettings(&main);
	Settings_DeInit(&main);

	return 0;
}