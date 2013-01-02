DESCRIPTION
-----------

A library which helps modules to extend abstractions defined by other modules.
It simply dynamically extends more classes with one class. All of those classes
are defined and used outside of this module. It only generates code (files),
stores class definitions to the cache that can be then returned back to the
modules to work with. It was designed to be used for simulating something what
can be called "horizontal extensibility" of classes. The advantage of this approach
is that the only requirement on that target module is then if it has an interface
for registering new classes for use.

This module is meant to be an API module (library) for other modules to use.
It does nothing on it own. If you're not a developer, don't install this module
unless another module tells you to.
