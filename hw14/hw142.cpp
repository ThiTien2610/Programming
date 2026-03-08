// A normal execution path branching:
// *The if / else statement:

//save(Status::success, person.id()) when it is true

//save(Status::failure, person.id()) when it is false.

// *The logical OR operator || :

//If person.grade() == 10 is true, person.salary() is not evaluated.

//If it is false, then person.salary() is evaluated.

// Exception:

// person.name(), person.grade(), person.salary(), person.id() because Person is user-defined can throw exceptions(invalid/missing data,...).

// save(...) because usually involves external operations (file, database, network,...), which can throw exceptions.