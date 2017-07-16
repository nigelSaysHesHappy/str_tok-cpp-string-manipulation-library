# str_tok-cpp-string-manipulation-library
str_tok is a very useful and powerful stl strings manipluation and parsing library for C++. It is extremely undocumented.

Most of the functions provided in this library are based off the mIRC Scripting Language.
The ones that share a name with a mIRC identifier nearly function exactly the same as their mIRC counter-parts.
With the exception of anything with tokens; the delimiter is not limited to only one character, nor do you need to provide it as an ascii value.
For example:

mIRC: $gettok("Today was a good day.",2,32) = "was"

str_tok: gettok("Today was a good day.",2," ") = "was"

str_tok: gettok("Today was a good day.",1,"day") = "To"

str_tok: gettok("Today was a good day.",2,"day") = " was a good "

str_tok: gettok("Today was a good day.",3,"day") = "."


There are a few other differences as well, but they are extended features. If you provide the same paramter input as you do with mIRC, you will receive the exact same output with str_tok.
