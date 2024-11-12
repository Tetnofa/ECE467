int wrong_return();

void wrong_return() {}

int wrong_arg_type(int a);

int wrong_arg_type(bool a) { return 0; }

int different_arg_names(int a, int b);

int different_arg_names(int b, int a) {
  return 0;
}

// Assume that there is at most 1 proto and at most 1 def for a given name
// aka, this is not something we need to handle.
// int redef_proto();
// int redef_proto();
// int overload(int a);
// int overload(bool b);
