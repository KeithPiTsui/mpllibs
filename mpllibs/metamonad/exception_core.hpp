#ifndef MPLLIBS_METAMONAD_EXCEPTION_CORE_HPP
#define MPLLIBS_METAMONAD_EXCEPTION_CORE_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/tmp_tag.hpp>

#include <mpllibs/metatest/to_stream_fwd.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    struct exception_tag : tmp_tag<exception_tag> {};
  
    template <class Data>
    struct exception : tmp_value<exception<Data>, exception_tag>
    {
      typedef Data data;
    };
  }
}

MPLLIBS_DEFINE_TO_STREAM_FOR_TEMPLATE(
  1,
  mpllibs::metamonad::exception,
  "exception"
)

#endif

