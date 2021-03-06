#ifndef MPLLIBS_METAMONAD_V1_IMPL_EVAL_CASE_IMPL_HPP
#define MPLLIBS_METAMONAD_V1_IMPL_EVAL_CASE_IMPL_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metamonad/v1/fwd/exception.hpp>
#include <mpllibs/metamonad/v1/eval_syntax.hpp>

namespace mpllibs
{
  namespace metamonad
  {
    namespace v1
    {
      namespace impl
      {
        template <class E>
        struct eval_case_impl : eval_syntax<E> {};

        template <class E>
        struct eval_case_impl<exception<E> > : exception<E> {};
      }
    }
  }
}

#endif

