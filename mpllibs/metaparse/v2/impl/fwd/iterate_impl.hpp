#ifndef MPLLIBS_METAPARSE_V2_IMPL_FWD_ITERATE_IMPL_HPP
#define MPLLIBS_METAPARSE_V2_IMPL_FWD_ITERATE_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/is_error.hpp>
#include <mpllibs/metaparse/v2/get_result.hpp>
#include <mpllibs/metaparse/v2/get_remaining.hpp>
#include <mpllibs/metaparse/v2/get_position.hpp>

#include <boost/mpl/deque.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/apply.hpp>
#include <boost/mpl/apply_wrap.hpp>
#include <boost/mpl/push_back.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace impl
      {
        template <int N, class P, class Accum>
        struct iterate_impl;
      }
    }
  }
}

#endif
