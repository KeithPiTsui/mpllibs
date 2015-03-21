#ifndef MPLLIBS_METAPARSE_V2_IMPL_ONE_OF_FWD_OP_HPP
#define MPLLIBS_METAPARSE_V2_IMPL_ONE_OF_FWD_OP_HPP

// Copyright Abel Sinkovics (abel@sinkovics.hu)  2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mpllibs/metaparse/v2/is_error.hpp>

#include <boost/mpl/eval_if.hpp>

namespace mpllibs
{
  namespace metaparse
  {
    namespace v2
    {
      namespace impl
      {
        template <class S, class Pos>
        struct one_of_fwd_op
        {
          typedef one_of_fwd_op type;

          template <class State, class P>
          struct apply :
            boost::mpl::eval_if<
              typename is_error<State>::type,
              boost::mpl::eval_if<
                typename is_error<typename P::template apply<S, Pos> >::type,
                State,
                typename P::template apply<S, Pos>
              >,
              State
            >
          {};
        };
      }
    }
  }
}

#endif

