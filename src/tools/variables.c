#include "../fsl_efi.h"

public bool set_new_variable(const string name, const string value)
{ return map_append(_FSLEFI_->variables, name, value); }