#include <string.h>
#include "dart_api.h"

// Forward declaration of ResolveName function.
Dart_NativeFunction ResolveName(Dart_Handle name, int argc, bool* auto_setup_scope);

// The name of the initialization function is the extension name followed
// by _Init.
DART_EXPORT Dart_Handle extension_Init(Dart_Handle parent_library) {
	if (Dart_IsError(parent_library)) return parent_library;

	Dart_Handle result_code =
		Dart_SetNativeResolver(parent_library, ResolveName, NULL);
	if (Dart_IsError(result_code)) return result_code;

	return Dart_Null();
}

Dart_Handle HandleError(Dart_Handle handle) {
	if (Dart_IsError(handle)) Dart_PropagateError(handle);
	return handle;
}

// Native functions get their arguments in a Dart_NativeArguments structure
// and return their results with Dart_SetReturnValue.
void get5(Dart_NativeArguments arguments) {
	Dart_Handle result = HandleError(Dart_NewInteger(5));
	Dart_SetReturnValue(arguments, result);
}

#if 0
void SystemSrand(Dart_NativeArguments arguments) {
	bool success = false;
	Dart_Handle seed_object =
		HandleError(Dart_GetNativeArgument(arguments, 0));
	if (Dart_IsInteger(seed_object)) {
		bool fits;
		HandleError(Dart_IntegerFitsIntoInt64(seed_object, &fits));
		if (fits) {
			int64_t seed;
			HandleError(Dart_IntegerToInt64(seed_object, &seed));
			srand(static_cast<unsigned>(seed));
			success = true;
		}
	}
	Dart_SetReturnValue(arguments, HandleError(Dart_NewBoolean(success)));
}
#endif

Dart_NativeFunction ResolveName(Dart_Handle name, int argc, bool* auto_setup_scope) {
	// If we fail, we return NULL, and Dart throws an exception.
	if (!Dart_IsString(name)) return NULL;
	Dart_NativeFunction result = NULL;
	const char* cname;
	HandleError(Dart_StringToCString(name, &cname));

	if (strcmp("get5", cname) == 0) result = get5;
	//if (strcmp("SystemSrand", cname) == 0) result = SystemSrand;
	return result;
}