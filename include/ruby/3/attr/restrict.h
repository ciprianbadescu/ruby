#ifndef RUBY3_ATTR_RESTRICT_H                        /*-*-C++-*-vi:se ft=cpp:*/
#define RUBY3_ATTR_RESTRICT_H
/**
 * @file
 * @author     Ruby developers <ruby-core@ruby-lang.org>
 * @copyright  This  file  is   a  part  of  the   programming  language  Ruby.
 *             Permission  is hereby  granted,  to  either redistribute  and/or
 *             modify this file, provided that  the conditions mentioned in the
 *             file COPYING are met.  Consult the file for details.
 * @warning    Symbols   prefixed   with   either  `RUBY3`   or   `ruby3`   are
 *             implementation details.   Don't take  them as canon.  They could
 *             rapidly appear then vanish.  The name (path) of this header file
 *             is also an  implementation detail.  Do not expect  it to persist
 *             at the place it is now.  Developers are free to move it anywhere
 *             anytime at will.
 * @note       To  ruby-core:  remember  that   this  header  can  be  possibly
 *             recursively included  from extension  libraries written  in C++.
 *             Do not  expect for  instance `__VA_ARGS__` is  always available.
 *             We assume C99  for ruby itself but we don't  assume languages of
 *             extension libraries. They could be written in C++98.
 * @brief      Defines #RUBY3_ATTR_RESTRICT.
 */
#include "ruby/3/compiler_since.h"
#include "ruby/3/has/attribute.h"
#include "ruby/3/token_paste.h"

/* :FIXME:  config.h  includes conflicting  `#define  restrict`.   MSVC can  be
 * detected  using  `RUBY3_COMPILER_SINCE()`, but  Clang  &  family cannot  use
 * `__has_declspec_attribute()` which involves macro substitution. */

/** Wraps (or simulates) `__declspec(restrict)` */
#if RUBY3_COMPILER_SINCE(MSVC, 14, 0, 0)
# define RUBY3_ATTR_RESTRICT() __declspec(RUBY3_TOKEN_PASTE(re, strict))

#elif RUBY3_HAS_ATTRIBUTE(malloc)
# define RUBY3_ATTR_RESTRICT() __attribute__((__malloc__))

#elif RUBY3_COMPILER_SINCE(SunPro, 5, 10, 0)
# define RUBY3_ATTR_RESTRICT() _Pragma("returns_new_memory")

#else
# define RUBY3_ATTR_RESTRICT() /* void */
#endif

#endif /* RUBY3_ATTR_RESTRICT_H */
