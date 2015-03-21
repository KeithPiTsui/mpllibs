#ifndef MPLLIBS_METAPARSE_V2_RANGE_C_HPP
#define MPLLIBS_METAPARSE_V2_RANGE_C_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/accept_when.hpp>
#include <mpllibs/metaparse/v2/one_char.hpp>
#include <mpllibs/metaparse/v2/util/in_range_c.hpp>
#include <mpllibs/metaparse/v2/error/unexpected_character.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      template <char From, char To>
      struct range_c :
        accept_when<
          one_char,
          util::in_range_c<char, From, To>,
          error::unexpected_character
        >
      {};
    }
  }
}

#endif
