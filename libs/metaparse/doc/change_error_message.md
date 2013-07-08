# change_error_message

## Synopsis

```cpp
template <class P, class Msg>
struct change_error_message
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator taking a parser and an error message as arguments.
It applies the parser on the input. When the parser succeeds, the combinator
returns the result of the parser, otherwise the combinator generates an error
with the message `Msg`.

## Header

```cpp
#include <mpllibs/metaparse/change_error_message.hpp>
```

## Expression semantics

For any `p` parser and `m` error message, `s` compile-time string and `pos`
source position

```cpp
boost::mpl::apply<change_error_message<p, msg>, s, pos>
```

is equivalent to `boost::mpl::apply<p, s, pos>` when it doesn't return an error.
It is equivalent to `boost::mpl::apply<mpllibs::metaparse::fail<msg>, s, pos>`
otherwise.

## Example

```cpp
struct custom_error_message
{
  // ...
};

typedef
  change_error_message<mpllibs::metaparse::digit, custom_error_message>
  specialised_digit;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

