#ifndef MPLLIBS_METAPARSE_GET_PREV_CHAR_HPP
#define MPLLIBS_METAPARSE_GET_PREV_CHAR_HPP

//    Copyright Abel Sinkovics (abel@sinkovics.hu) 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <boost/mpl/apply.hpp>
#include <boost/mpl/tag.hpp>

#include <iostream>

namespace mpllibs
{
  namespace metaparse
  {
    template <class P>
    struct get_prev_char_impl;
    
    template <class P>
    struct get_prev_char :
      boost::mpl::apply<
        get_prev_char_impl<typename boost::mpl::tag<typename P::type>::type>,
        typename P::type
      >
    {};
  }
}

#endif

