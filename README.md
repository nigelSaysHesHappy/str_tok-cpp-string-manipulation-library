# str_tok-cpp-string-manipulation-library
str_tok is a very useful and powerful stl strings manipluation and parsing library for C++. It is extremely undocumented.

Most of the functions provided in this library are based off the mIRC Script Language.
The ones that share a name with an identifier in mIRC function nearly exactly the same as their mIRC counter-parts.
With the exception of anything with tokes; the delimiter is not limited to only one character, nor do you need to provide it as an ascii value.
For example:

mIRC: $gettok("Today was a good day.",2,32) = "was"
str_tok: gettok("Today was a good day.",2," ") = "was"
str_tok: gettok("Today was a good day.",1,"day") = "To"
str_tok: gettok("Today was a good day.",2,"day") = " was a good "
str_tok: gettok("Today was a good day.",3,"day") = "."
