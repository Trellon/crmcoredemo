
INTRODUCTION
------------

This module provides an API to define dependencies between entities and a useful
iterator.

BACKGROUND
----------

This project originated from the Deploy module, where it's used heavily, but
were later separated out for better code separation and reusability between
modules.

THE ITERATOR
------------

You construct the iterator with an array of entity type keys and entity id
values. Then, when iterating over the iterator you will get all entities AND
their dependencies out in a sane order (i.e. dependencies first).

Since the iterator only return "plain" entity objects and developers often need
more meta data around the entity (primarily the entity type) we are embedding
metadata within the entity object according to the OData protocol's JSON format
(http://www.odata.org/developers/protocols/json-format) which is a very simple
and lightweight way of solving the problem.

7.x-2.x
-------

The next major version should provide a more declarative API. Right now run-time
hooks are provided, which is a bit ineffective.
